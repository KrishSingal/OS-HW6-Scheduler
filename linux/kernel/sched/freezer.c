#include "sched.h"

/*
* freezer scheduling policy implementation;
* put the code in kernel/sched/freezer.c
*/
struct sched_class freezer_sched_class {
//
	void (*enqueue_task) (struct rq *rq, struct task_struct *p, int flags);
	void (*dequeue_task) (struct rq *rq, struct task_struct *p, int flags);
	void (*yield_task)   (struct rq *rq);

	void (*check_preempt_curr)(struct rq *rq, struct task_struct *p, int flags);

	struct task_struct *(*pick_next_task)(struct rq *rq);

	void (*put_prev_task)(struct rq *rq, struct task_struct *p);
	void (*set_next_task)(struct rq *rq, struct task_struct *p, bool first);

#ifdef CONFIG_SMP
	int (*balance)(struct rq *rq, struct task_struct *prev, struct rq_flags *rf); // No need to implement
	int  (*select_task_rq)(struct task_struct *p, int task_cpu, int sd_flag, int flags);

	void (*set_cpus_allowed)(struct task_struct *p,
				 const struct cpumask *newmask);
#endif

	void (*task_tick)(struct rq *rq, struct task_struct *p, int queued);

	/*
	 * The switched_from() call is allowed to drop rq->lock, therefore we
	 * cannot assume the switched_from/switched_to pair is serliazed by
	 * rq->lock. They are however serialized by p->pi_lock.
	 */
	void (*switched_to)  (struct rq *this_rq, struct task_struct *task);
	void (*prio_changed) (struct rq *this_rq, struct task_struct *task,
			      int oldprio);

	unsigned int (*get_rr_interval)(struct rq *rq,
					struct task_struct *task);

	void (*update_curr)(struct rq *rq); // updates statistics, not sure whether we need to have non-empty implementation 

};
