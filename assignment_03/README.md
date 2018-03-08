---
title: Fun with Process Sync and Memory
due: 2018-03-22
---

## Problem 1 (10 pts) 

> The producer-consumer problem can be extended to a system with multiple producers and consumers that write (or read) to (from) one shared buffer. Assume that each pro- ducer and consumer runs in its own thread. Will the solution presented in Fig. 2-28, using semaphores, work for this system?

## Problem 2 (10 pts)

> Consider the following solution to the mutual-exclusion problem involving two processes P0 and P1. Assume that the variable turn is initialized to 0. Process P0’s code is presented below.

```c
/* Other code */

while (turn != 0) { } // Do nothing and wait
// Critical Section 
turn = 0;

/* Other code */
```

> For process P1, replace 0 by 1 in above code. Determine if the solution meets all the required conditions for a correct mutual-exclusion solution.

## Problem 3 (10 pts)

> How could an operating system that can disable interrupts implement semaphores?

## Problem 4 (10 pts)

> Using the page table of Fig. 3-9, give the physical address corresponding to each of the following virtual addresses:
> (a) 20
> (b) 4100
> (c) 8300

## Problem 5 (10 pts)

> If an instruction takes 1 nsec and a page fault takes an additional n nsec, give a formula for the effective instruction time if page faults occur every k instructions.

## Problem 6 (10 pts)

> You are given the following data about a virtual memory system:
> - (a) The TLB can hold 1024 entries and can be accessed in 1 clock cycle (1 nsec).
> - (b) A page table entry can be found in 100 clock cycles or 100 nsec.
> - (c) The average page replacement time is 6 msec.
>
> If page references are handled by the TLB 99% of the time, and only 0.01% lead to a page fault, what is the effective address-translation time?

## Problem 7 (10 pts)

> Consider the page sequence of Fig. 3-15(b).
> Suppose that the R bits for the pages B through A are 11011011, respectively. Which page will second chance remove?

## Problem 8 (50 pts)

> **Managing Free Memory with Linked List** : write a **first fit** program to manage free memory using linked list as in Figure 3-6(c).
>
> Then test your program using the following memory use pattern by
> printing out the linked list after each memory use or free event:
> there are in total 10 memory units, and the memory's use pattern is as
> follows: 
> - A (use 2 units)
> - B (use 3 units)
> - C (use 4 units)
> - D (free 3 units of B)
> - E (use 1 unit)
> - F (free 4 units of C)
> - G (free 2 units of A)
> - H (use 5 units)
