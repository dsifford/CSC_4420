/**
 * Write a simple test program to find out the _parent process id_ of a
 * process **before** and **after** its parent process terminates. Based on your
 * test results, answer the following question: what is a process's parent
 * process after its original parent process terminates?
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {

	if (fork() == 0) {
		// Need the child process to run before the parent. This is random and
		// will only work on certain occasions.
		if (getppid() == 1) {
			exit(EXIT_FAILURE);
		}
		printf("Parent process ID while running is: %d\n", getppid());
		sleep(1);
		printf("Parent process ID after exit is: %d\n", getppid());
        exit(0);
	}
	else {
		exit(0);
	}

	exit(0);
	return 0;
}

