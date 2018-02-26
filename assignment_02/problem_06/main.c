#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

/**
 * Design and run an experiment to measure the CPU time used by _fork_.
 * (You may want to use the system call _times_.) Also report the CPU of the
 * machine you run the experiment.
 */

int main() {
	struct tms start_cpu;
	struct tms end_cpu;
	clock_t start = times(&start_cpu);

	if (fork() == 0) {
        // Arbitrary function calls to burn time
		for (size_t i = 0; i < 1000000000; i++) {
			(void) (time(NULL) + time(NULL));
		}
		exit(EXIT_SUCCESS);
	}
	else {
		wait(NULL);
		clock_t end = times(&end_cpu);
		printf("Wall time elapsed: %jd\n", (intmax_t) ((end - start) / sysconf(_SC_CLK_TCK)));
		printf("Child process user time: %f\n", (double) (end_cpu.tms_cutime - start_cpu.tms_cutime) / sysconf(_SC_CLK_TCK));
		printf("Child process kernel time: %f\n", (double) (end_cpu.tms_cstime - start_cpu.tms_cstime) / sysconf(_SC_CLK_TCK));
	}

	return 0;
}
