#define _GNU_SOURCE

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct stat_node {
	struct stat *stat;
	struct stat_node *next;
} StatNode;

typedef struct stat_list {
	StatNode *first;
} StatList;

/* Write a program that starts at a given directory and descends the file tree */
/* from that point recording the sizes of all the files it finds. When it is */
/* all done, it should print a histogram of the file sizes using a bin width */
/* specified as a parameter (e.g., with 1024, file sizes of 0 to 1023 go in one */
/* bin, 1024 to 2047 go in the next bin, etc.). */

int recurse_dir(StatNode *, const char *);

int main(int argc, char *argv []) {

	struct stat s;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <pathname> <binwidth>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if (stat(argv[1], &s) == -1) {
		perror("Couldn't stat input");
		exit(EXIT_FAILURE);
	}
	if (!S_ISDIR(s.st_mode)) {
		fputs("Input path is not a directory", stderr);
		exit(EXIT_FAILURE);
	}

	StatList list;
	list.first = malloc(sizeof(StatNode));

	if (recurse_dir(list.first, argv[1]) != 0) {
		exit(EXIT_FAILURE);
	}
	;

	StatNode *n = list.first;

	int bin_size = atoi(argv[2]);
	off_t largest = 0;
	while (n != NULL && n->stat != NULL) {
		if (n->stat->st_size > largest) {
			largest = n->stat->st_size;
		}
		n = n->next;
	}
	n = list.first;

	int n_bins = (int) ceil(largest / bin_size) + 1;
	int bins[n_bins];
	memset(bins, 0, sizeof bins);
	while (n != NULL && n->stat != NULL) {
		bins[n->stat->st_size / bin_size]++;
		n = n->next;
	}
	n = list.first;

	puts("Histogram of directory tree:");
	for (int i = 0; i < n_bins; i++) {
		printf("%5d - %5d\t| ", bin_size * i, bin_size * (i + 1));
		for (int j = 0; j < bins[i]; j++) {
			printf("%s", "X");
		}
		printf("\n");
	}

	return 0;
}

int recurse_dir(StatNode *s, const char *pathname) {

	DIR *dirp;
	int dir_fd;
	struct dirent *dirent;

	if ((dirp = opendir(pathname)) == NULL) {
		fprintf(stderr, "Unable to open directory: %s\n", pathname);
		return errno;
	}

	if ((dir_fd = dirfd(dirp)) == -1) {
		fprintf(stderr, "Unable to obtain directory file descriptor of: %s\n", pathname);
		return errno;
	}

	while ((dirent = readdir(dirp)) != NULL) {
		if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
			continue;
		}

		struct stat *statbuf = malloc(sizeof(struct stat));
		if (fstatat(dir_fd, dirent->d_name, statbuf, 0) == -1) {
			int e = errno;
			free(statbuf);
			fprintf(stderr, "Unable to stat file: %s\n", dirent->d_name);
			return e;
		}
		switch (statbuf->st_mode & S_IFMT) {
			case S_IFREG:
				s->next = malloc(sizeof(StatNode));
				s->stat = statbuf;
				s = s->next;
				continue;
			case S_IFDIR: {
				int e;
				char *path = malloc(strlen(pathname) + strlen(dirent->d_name) + 2);
				sprintf(path, "%s/%s", pathname, dirent->d_name);
				if ((e = recurse_dir(s, path)) != 0) {
					fprintf(stderr, "Unable to recurse directory: %s\n", dirent->d_name);
					return e;
				}
				free(path);
				break;
			}
		}
		free(statbuf);
	}

	if (closedir(dirp) == -1) {
		fprintf(stderr, "Unable to close directory: %s\n", pathname);
		return errno;
	}

	return 0;
}
