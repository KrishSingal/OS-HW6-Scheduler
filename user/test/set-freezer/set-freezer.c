#include <stdlib.h>
#include <stdio.h>
#include <sched.h>

struct sched_param sp;

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("please give PID to change to freezer");
		return -1;
	}
	int pid = atoi(argv[1]);
	int num = sched_getscheduler(pid);
	sp.sched_priority = 0;
	sched_setscheduler(pid, 7, &sp);
	printf("[%d] sched policy changed: %d --> 7\n", pid, num);
}