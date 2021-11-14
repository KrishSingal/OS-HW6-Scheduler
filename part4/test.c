#define _GNU_SOURCE

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sched.h>



int main(void) 
{
	pid_t pid[5];
	for (int i = 0; i < 5; i++) {
		pid[i] = fork();
		if (pid[i] == 0) {
			cpu_set_t mask;
			CPU_ZERO(&mask);
			CPU_SET(3, &mask);
			sched_setaffinity(pid[i], sizeof(mask), &mask);
			for (int j = 0; j < 100000; j++) {
				for (int k = 0; k < 100000; k++) {
					;
				}
			}
			printf("child done\n");
			return 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		waitpid(pid[i], NULL, 0);
	}
	printf("done\n");
}