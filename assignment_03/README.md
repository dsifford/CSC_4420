---
title: Fun with Process Sync and Memory
due: 2018-03-22
---

## Problem 1 (10 pts)

> The producer-consumer problem can be extended to a system with multiple
> producers and consumers that write (or read) to (from) one shared buffer.
> Assume that each producer and consumer runs in its own thread. Will the
> solution presented in `Fig. 2-28`, using semaphores, work for this system?

`Fig. 2-28` is an extremely poor example. They only show a small snippet of
what's happening and, given the information they provide, there's no way to tell
if the consumer or producer blocks access to the shared buffer while it's
occupied.

Keeping that in mind, from the information provided, I would have to assume that
there is no blocking mechanism and, because of that, the solution would not work
for this system.

## Problem 2 (10 pts)

> Consider the following solution to the mutual-exclusion problem involving two
> processes P0 and P1. Assume that the variable turn is initialized to 0.
> Process P0’s code is presented below.

```c
/* Other code */

while (turn != 0) { } // Do nothing and wait
// Critical Section
turn = 0;

/* Other code */
```

> For process P1, replace 0 by 1 in above code. Determine if the solution meets
> all the required conditions for a correct mutual-exclusion solution.

Yes, this would fairly crudely achieve the required conditions for two-component
mutual exclusion.

## Problem 3 (10 pts)

> How could an operating system that can disable interrupts implement
> semaphores?

Just after a process enters the critical region, it would disable all interrupts
so that no other process could intervene while doing its task. When the task is
complete, the process would then re-enable interrupts and exit.

## Problem 4 (10 pts)

> Using the page table of `Fig. 3-9`, give the physical address corresponding to
> each of the following virtual addresses:
>
> *   (a) 20
> *   (b) 4100
> *   (c) 8300

```txt
a.) 4096 + (4095 * 1) +  20 = 8211
b.) 4096 + (4095 * 0) + 100 = 4196
c.) 4096 + (4095 * 5) + 300 = 24871
```

## Problem 5 (10 pts)

> If an instruction takes 1 nsec and a page fault takes an additional n nsec,
> give a formula for the effective instruction time if page faults occur every k
> instructions.

```
(k + n) / k
```

## Problem 6 (10 pts)

> You are given the following data about a virtual memory system:
>
> *   (a) The TLB can hold 1024 entries and can be accessed in 1 clock cycle (1
>     nsec).
> *   (b) A page table entry can be found in 100 clock cycles or 100 nsec.
> *   (c) The average page replacement time is 6 msec.
>
> If page references are handled by the TLB 99% of the time, and only 0.01% lead
> to a page fault, what is the effective address-translation time?

```
0.99 * 1 + 0.099 * 100 + 0.0001 * 6 * 10^6 = 602 clock cycles
```

## Problem 7 (10 pts)

> Consider the page sequence of `Fig. 3-15(b)`. Suppose that the R bits for the
> pages B through A are 11011011, respectively. Which page will second chance
> remove?

Second chance will remove the first page that doesn't have its R bit set, or `D`
in this example.

## Problem 8 (50 pts)

> **Managing Free Memory with Linked List** : write a **first fit** program to
> manage free memory using linked list as in `Fig. 3-6(c)`.
>
> Then test your program using the following memory use pattern by printing out
> the linked list after each memory use or free event: there are in total 10
> memory units, and the memory's use pattern is as follows:
>
> *   A (use 2 units)
> *   B (use 3 units)
> *   C (use 4 units)
> *   D (free 3 units of B)
> *   E (use 1 unit)
> *   F (free 4 units of C)
> *   G (free 2 units of A)
> *   H (use 5 units)
