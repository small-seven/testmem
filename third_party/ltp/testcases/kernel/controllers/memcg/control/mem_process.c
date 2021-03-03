#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define STATUS_PIPE "status_pipe"
void mem_map(void)
{
	static char *p;

	if (flag_allocated) {
		if (munmap(p, memsize) == -1)
			err(5, "munmap failed");
	} else {
		p = mmap(NULL, memsize, PROT_READ | PROT_WRITE,
			 MAP_SHARED | MAP_ANONYMOUS, 0, 0);
		if (p == MAP_FAILED)
			err(4, "mmap failed");
		touch_memory(p);
	}
	flag_allocated = !flag_allocated;
}
