#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "rc4.h"
using namespace std;

int main() {

	int fd = open("foo.txt", O_RDWR);

	transform_rc4(fd);
	transform_rc4(fd);

	close(fd);
	return 0;
}
