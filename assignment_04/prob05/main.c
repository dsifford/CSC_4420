#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Write a program that reverses the bytes of a file, so that the last byte is
 * now first and the first byte is now last. It must work with an arbitrarily
 * long file, but try to make it reasonably efficient.
 **/

int main(int argc, char *argv []) {

	int fd;
	off_t offset;

	if (argc != 2) {
		puts("Must pass a file path as first argument");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1) {
		perror("Cannot open provided file path");
		exit(EXIT_FAILURE);
	}

	if ((offset = lseek(fd, 0, SEEK_END)) == -1) {
		perror("Error retrieving file offset");
		exit(EXIT_FAILURE);
	}

	char *input_buffer = malloc(sizeof(char) * offset);
	char *output_buffer = malloc(sizeof(char) * offset);

	if (lseek(fd, 0, SEEK_SET) == -1) {
		perror("Error resetting file offset");
		exit(EXIT_FAILURE);
	}

	if (read(fd, input_buffer, offset) == -1) {
		perror("Error reading file");
		exit(EXIT_FAILURE);
	}

	if (close(fd) == -1) {
		perror("Error closing file");
		exit(EXIT_FAILURE);
	}

	off_t i = 0;
	while (i <= offset) {
		output_buffer[i] = input_buffer[offset - (i + 1)];
		i++;
	}

	if ((fd = open(argv[1], O_WRONLY, O_TRUNC)) == -1) {
		perror("Error opening writable file");
		exit(EXIT_FAILURE);
	}

	if (write(fd, output_buffer, offset) == -1) {
		perror("Error writing file");
		exit(EXIT_FAILURE);
	}

	if (close(fd) == -1) {
		perror("Error closing writable file");
		exit(EXIT_FAILURE);
	}

	free(input_buffer);
	free(output_buffer);

	return 0;
}
