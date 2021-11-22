#include "sched.h"
#include <linux/printk.h>

/*
 * freezer scheduling policy implementation
 */
static void update_curr_freezer(struct rq *rq)
{
	// updates statistics
	struct task_struct *curr = rq->curr;
	// struct sched_freezer_entity *fr_se = &curr->fr;
	u64 delta_exec;
	u64 now;

	//pr_info("update curr");
	if (curr->sched_class != &freezer_sched_class)
		return;

	now = rq_clock_task(rq);
	delta_exec = now - curr->se.exec_start;
	if (unlikely((s64)delta_exec <= 0))
		return;
	schedstat_set(curr->se.statistics.exec_max,
		      max(curr->se.statistics.exec_max, delta_exec));
	curr->se.sum_exec_runtime += delta_exec;
	curr->se.exec_start = now;
}

static void
enqueue_task_freezer(struct rq *rq, struct task_struct *p, int flags)
{
	if (p->fr.on_rq)
		return;
	list_add_tail(&p->fr.run_list, &rq->fr.active);
	rq->fr.fr_nr_running++;
	p->fr.on_rq = 1;
}

static void
dequeue_task_freezer(struct rq *rq, struct task_struct *p, int flags)
{
	if (!p->fr.on_rq)
		return;

	update_curr_freezer(rq);
	list_del(&p->fr.run_list);
	rq->fr.fr_nr_running--;
	p->fr.on_rq = 0;
}

static void yield_task_freezer(struct rq *rq)
{
	list_move_tail(&rq->curr->fr.run_list, &rq->fr.active);
	update_curr_freezer(rq);
}

static void
check_preempt_curr_freezer(struct rq *rq, struct task_struct *p, int flags)
{
	//Don't need to reschedule since we dont deal with priority
}

struct task_struct *pick_next_task_freezer(struct rq *rq)
{
	struct sched_freezer_entity *fr_se;
	struct task_struct *p;

	if (rq->fr.fr_nr_running == 0)
		return NULL;

	fr_se = list_first_entry(&rq->fr.active, struct sched_freezer_entity, run_list);
	p = container_of(fr_se, struct task_struct, fr);
	p->se.exec_start = rq_clock_task(rq);
	return p;
}

static void put_prev_task_freezer(struct rq *rq, struct task_struct *p)
{
	if (!p->fr.on_rq)
		return;
	list_move_tail(&p->fr.run_list, &rq->fr.active);
	update_curr_freezer(rq);
}

static void
set_next_task_freezer(struct rq *rq, struct task_struct *p, bool first)
{
	list_move(&p->fr.run_list, &rq->fr.active);
	p->se.exec_start = rq_clock_task(rq);
}

#ifdef CONFIG_SMP
static int
balance_freezer(struct rq *rq, struct task_struct *p, struct rq_flags *rf)
{
	return sched_stop_runnable(rq) || sched_dl_runnable(rq) ||
		sched_rt_runnable(rq) || rq->fr.fr_nr_running > 0;
}

static int
select_task_rq_freezer(struct task_struct *p, int cpu, int sd_flag, int flags)
{
	int i;
	int min_cpu = task_cpu(p);
	int min = ((int)(~0U >> 1)); //MAX INT

	for_each_cpu(i, p->cpus_ptr) {
		struct rq *rq = cpu_rq(i);

		if (rq->fr.fr_nr_running < min) {
			min = rq->fr.fr_nr_running;
			min_cpu = i;
		}
	}
	return min_cpu;
}
#endif

static void task_tick_freezer(struct rq *rq, struct task_struct *p, int queued)
{
	update_curr_freezer(rq);

	if (--p->fr.time_slice)
		return;

	p->fr.time_slice = FREEZER_TIMESLICE;

	//Move to back of list if not only element
	if (p->fr.run_list.prev != p->fr.run_list.next) { //check nr_running?
		list_move_tail(&p->fr.run_list, &rq->fr.active);
		resched_curr(rq);
		return;
	}
}

static void switched_from_freezer(struct rq *rq, struct task_struct *p)
{
	//No Op
}

static void switched_to_freezer(struct rq *rq, struct task_struct *p)
{
	//check if task is on rq and not dl and not rt call resched
	if (p->fr.on_rq && !task_has_dl_policy(p) && !task_has_rt_policy(p) && rq->curr != p)
		resched_curr(rq);
}

static void
prio_changed_freezer(struct rq *rq, struct task_struct *p, int oldprio)
{
	//No Op?
}

static unsigned int
get_rr_interval_freezer(struct rq *rq, struct task_struct *task)
{
	return FREEZER_TIMESLICE;
}

const struct sched_class freezer_sched_class
	__section("__freezer_sched_class") = {
	.enqueue_task = enqueue_task_freezer,
	.dequeue_task = dequeue_task_freezer,
	.yield_task = yield_task_freezer,

	.check_preempt_curr = check_preempt_curr_freezer,

	.pick_next_task = pick_next_task_freezer,

	.put_prev_task = put_prev_task_freezer,
	.set_next_task = set_next_task_freezer,

#ifdef CONFIG_SMP

	.balance = balance_freezer,
	.select_task_rq = select_task_rq_freezer,

	.set_cpus_allowed = set_cpus_allowed_common,
#endif

	.task_tick = task_tick_freezer,
	.switched_from = switched_from_freezer,
	.switched_to = switched_to_freezer,
	.prio_changed = prio_changed_freezer,

	.get_rr_interval = get_rr_interval_freezer,

	.update_curr = update_curr_freezer,

};

void init_fr_rq(struct freezer_rq *fr_rq)
{
	INIT_LIST_HEAD(&fr_rq->active);
	fr_rq->fr_nr_running = 0;
}