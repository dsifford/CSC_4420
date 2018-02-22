**due on Mar. 6, 2018.**

**Fun with Processes**

Do every problem by yourself. **Do NOT** search for solutions from
internet, previous classes or other students. Read Sec. 2.1.7 before you
start the problems.

1.  (10 pts) A computer has 4 GB of RAM of which the operating system occupies 512 MB. The processes are all 256 MB (for simplicity) and have the same characteristics. If the goal is 99% CPU utilization, what is the maximum I/O wait that can be tolerated?

2.  (10 pts) Multiple jobs can run in parallel and finish faster than if they had run sequentially. Suppose that two jobs, each needing 20 minutes of CPU time, start simultaneously. How long will the last one take to complete if they run sequentially? How long if they run in parallel? Assume 50% I/O wait.

3.  (10 pts) Write a simple test program to find out the *parent process
    id* of a process **before** and **after** its parent process
    terminates. Based on your test results, answer the following
    question: what is a process\'s parent process after its original
    parent process terminates?

4.  (10 pts) Write a simple test program to find out PIDs of ALL
    ancestor (i.e., parent, grandparent ) processes of the current
    process or a given process specified by a PID. A parent process\'s
    PID of a given process pid can be found in /proc/\$pid/status

5.  (20 pts) Problem 1.35. Run the program on your **OWN**
    laptop/desktop, and record the maximum number of child processes you
    see before your system crashes, as well as your machine\'s memory
    size.

> ( For those who doesn\'t have this edition of the textbook, the
> problem is as follows: If you have a personal UNIX-like system
> available that you can safely crash and reboot, write a shell script
> that attempts to create an unlimited number of child processes and
> observe what happens. Before running the experiment, type sync to the
> shell to flush the file system buffers to disk to avoid ruining the
> file system. )
>
> Again, do **NOT** run the experiment on any shared system. You can
> write a C/C++ program instead of shell script for this experiment. Do
> **NOT** search for solutions. ( There is one on internet, but I doubt
> you would understand it, otherwise you wouldn\'t need to take this
> course now. )

6.  (20 pts) Design and run an experiment to measure the CPU time used
    by *fork* . ( You may want to use the system call *times* . ) Also
    report the CPU of the machine you run the experiment.
