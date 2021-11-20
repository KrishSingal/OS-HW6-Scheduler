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