#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "ebizzy.h"
typedef size_t record_t;
static unsigned int record_size = sizeof(record_t);
static char *cmd;
static record_t **mem;
static char **hole_mem;
static unsigned int page_size;
static time_t start_time;
static volatile int threads_go;
static unsigned int records_read;

static void usage(void)
{
	fprintf(stderr, "Usage: %s [options]\n"
		"-T\t\t Just 'touch' the allocated pages\n"
		"-l\t\t Don't use library memcpy\n"
		"-m\t\t Always use mmap instead of malloc\n"
		"-M\t\t Never use mmap\n"
		"-n <num>\t Number of memory chunks to allocate\n"
		"-p \t\t Prevent mmap coalescing using permissions\n"
		"-P \t\t Prevent mmap coalescing using holes\n"
		"-R\t\t Randomize size of memory to copy and search\n"
		"-s <size>\t Size of memory chunks, in bytes\n"
		"-S <seconds>\t Number of seconds to run\n"
		"-t <num>\t Number of threads (2 * number cpus by default)\n"
		"-v[v[v]]\t Be verbose (more v's for more verbose)\n"
		"-z\t\t Linear search instead of binary search\n", cmd);
	exit(1);
}
static void my_memcpy(void *dest, void *src, size_t len)
{
	char *d = (char *)dest;
	char *s = (char *)src;
	int i;

	for (i = 0; i < len; i++)
		d[i] = s[i];
	return;
}
static void allocate(void)
{
	int i;

	mem = alloc_mem(chunks * sizeof(record_t *));

	if (use_holes)
		hole_mem = alloc_mem(chunks * sizeof(record_t *));

	for (i = 0; i < chunks; i++) {
		mem[i] = (record_t *) alloc_mem(chunk_size);
		/* Prevent coalescing using holes */
		if (use_holes)
			hole_mem[i] = alloc_mem(page_size);
	}

	/* Free hole memory */
	if (use_holes)
		for (i = 0; i < chunks; i++)
			free_mem(hole_mem[i], page_size);

	if (verbose)
		printf("Allocated memory\n");
}
