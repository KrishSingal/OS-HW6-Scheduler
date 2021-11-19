#include "sched.h"

/*
 * freezer scheduling policy implementation;
 * put the code in kernel/sched/freezer.c
 */
const struct sched_class freezer_sched_class = {
	.enqueue_task = NULL,
	.dequeue_task = NULL,
	.yield_task = NULL,
	.check_preempt_curr = NULL,

	.pick_next_task = NULL,

	.put_prev_task = NULL,
	.set_next_task = NULL,

#ifdef CONFIG_SMP

	.balance = NULL, // No need to implement
	.select_task_rq = NULL,

	.set_cpus_allowed = NULL,
#endif

	.task_tick = NULL,
	.switched_to = NULL,
	.prio_changed = NULL,

	.get_rr_interval = NULL,

	.update_curr = NULL,
	// updates statistics, not sure whether we need to have
	// non-empty implementation

};