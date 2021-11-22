This file should contain:

-	Nikhil Mehta nm3077, Krish kys2117. Eilam Lehrman esl2160
-	HW6

The description should indicate whether your solution for the part is working
or not. You may also want to include anything else you would like to
communicate to the grader, such as extra functionality you implemented or how
you tried to fix your non-working code.

Parts 1-5: Completed successfully

Part 6: Completed. Kernel compiles and we can boot into it.

Part 7: Completed! Works as expected.

We ran four inifite loop processes, put them all on the same CPU and then changed their scheduling policy to freezer. We saw that they all used about 25% of the CPU!

Below is a sample output from a shell session from changing one process to freezer:


user@debian:~/cs4118/hw6-16-Kernel_Panic_0x21_At_The_Distro/user/test/set-freezer$ ./../../../part1/run &
[1] 5656
user@debian:~/cs4118/hw6-16-Kernel_Panic_0x21_At_The_Distro/user/test/set-freezer$ ./set-freezer 5656
[5656] sched policy changed: 0 --> 7

Here is the output of the ps command after we run the first command above and after we run the second command above.

0 TS    3 98.6 98    5656 user      |           \_ ./../../../part1/run
7 #7    3 98.7 98    5656 user      |           \_ ./../../../part1/run


Part 8: Working!!!!!!!!

Here are our debug steps:

We performed a lot of debugging for part 8 that helped us to eventually get the scheduler to work. Below are some of the more important techniques we used

Printing: During the development process, we had multiple issues booting into the kernel when all processes were supposed on the SCHED_FREEZER policy. To gain insight into the boot process, we added prints into the freezer.c functions, core.c, init, and bugs.c. We traced through the entire boot process and were able to glean important checkpoints such as which processes were enqueued onto the freezer run queue before the boot failed. For example, we found in one instance that after PID 1 was added to the freezer run queue, the kernel boot failed. This helped us find an issue with how we initialized the init_task.

Bootlin Deep dive: We painstakingly read through multiple linux source files to find possible issues such as the task_fork function within sched_class and other nuances dealing with alternate_instructions, put_prev_task, and set_next_task. Most importantly, we used analog functions in rt, fair, deadline, and idle to inform our decisions on what to include in our implementation. Functions such as update_curr and balance heavily relied on this technique. This technique also helped us further understand slightly unrelated (but interesting) topics such as compiler optimizations.

Compiling On different Hardware: We made sure to compile and boot our kernels on different hardware because we noted discrepancies earlier.


Here are our testing steps:
We ran several of our 1 infinite loop processes from part 1 at the same time. We noticed that the VM became very slow but continuted to work. We then tried to play around with the VM GUI which was incredibly slow but we still found that it worked. We then killed our infinite loop processes and launched a bunch of chrome youtube tabs to stream hi-res video. This worked but was also very slow. With every way that we tested, we found that the more processes that we ran/more things we did on the VM, the slower our VM became.

We verified all new processes ran on freezer with the ps command. We verified that processes shared resources equally with the top command. We verified that most all processes (all the ones we expected/desired) were running with freezer when we checked the ps command just after boot.