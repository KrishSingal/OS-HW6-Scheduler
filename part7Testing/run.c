#include <sched.h>

struct sched_param sp;

int main(void)
{
	sp.sched_priority = 0;

	sched_setscheduler(0, 7, &sp);
	int i = 1;

	while (1) {
		i++;
		i--;
	}
}
