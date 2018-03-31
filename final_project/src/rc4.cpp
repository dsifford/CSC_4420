#include <openssl/rc4.h>
#include <iostream>
#include <unistd.h>

#include "rc4.h"

int transform_rc4(int fd) {
	RC4_KEY key;
	off_t offset = lseek(fd, 0, SEEK_END);

	if (offset < 0) {
		perror("Cannot obtain file offset");
		exit(EXIT_FAILURE);
	}

	lseek(fd, 0, SEEK_SET);

	unsigned char input_buffer[offset];
	unsigned char *output_buffer = (unsigned char*)malloc(offset+1);

	if (pread(fd, &input_buffer, offset, 0) == -1) {
		perror("Could not read file");
		exit(EXIT_FAILURE);
	}
	
	RC4_set_key(&key, RC4_KEY_LEN, (const unsigned char *)RC4_HASH_KEY);
	RC4(&key, offset, input_buffer, output_buffer);

	if (pwrite(fd, output_buffer, offset, 0) == -1) {
		perror("Could not write file");
		exit(EXIT_FAILURE);
	}

	free(output_buffer);
	return 0;
};

