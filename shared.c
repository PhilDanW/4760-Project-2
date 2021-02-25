#include "shared.h"

void touchFile(char* path) {
	FILE* fp = fopen(path, "w");
	if (fp == NULL) perror("Failed to touch file");
	fclose(fp);
}

void usage(char **argv, int status) {
	if (status != EXIT_SUCCESS) perror("Try '%s -h' for more information.\n");
	else {
		printf("NAME\n");
		printf("       %s - shared memorty summation app by Philip Wright", argv[0]);
		printf("\nUSAGE\n");
		printf("       %s [-h]\n", argv[0]);
		printf("       %s [-n x] [-s x] [-t time] infile", argv[0]);
		printf("\nDESCRIPTION\n");
		printf("       -h       : Print a help message or usage, and exit\n");
		printf("       -s x     : Number of children allowed to exist concurrently (default 20)\n");
		printf("       -t time  : Time, in seconds, after which the program will terminate (default 100)\n");
    printf("       -infile  : Input file containing a list of integers\n");
	}
	exit(status);
}
