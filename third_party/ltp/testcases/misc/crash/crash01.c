#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"
#define MAX_TRY_TIME 5
#define BLOCK_TRIGGER 80
#ifdef DEBUG_LATE_BADBOY
#else
#endif
#define STATUS_MAX 256
typedef void (*BADBOY) ();

BADBOY badboy;
char *the_data;

int offset = 0;
int next_offset = 0;

char *bad_malloc(int n);
void my_signal(int sig, void (*func) ());
void again_handler(int sig);
void compute_block_badboy(int n);
void compute_badboy();
BADBOY castaway(char *dat);
void try_one_crash();
void set_up_signals();

/* badboy "entry" point */
void badboy_loop(void)
{
	int i;

	if (malloc_flag == 0) {
		the_data = bad_malloc((nbytes < 0) ? -nbytes : nbytes);
		badboy = castaway(the_data);
		printf("Badboy at %p\n", badboy);
	}
char *bad_malloc(int n)
{
	char *data;
	data = malloc(n);
#ifdef pyr
	if (mprotect(((int)data / PAGSIZ) * PAGSIZ, (n / PAGSIZ + 1) * PAGSIZ,
		     PROT_READ | PROT_WRITE | PROT_EXEC))
		perror("mprotect");
#endif
	return (data);
}
#ifdef SIGTRAP
#endif
#ifdef SIGBUS
#endif
#ifdef SIGIOT
#endif
#ifdef SIGEMT
#endif
#ifdef SIGALRM
#endif
#ifdef SIGTRAP
#endif
#ifdef SIGBUS
#endif
#ifdef SIGIOT
#endif
#ifdef SIGEMT
#endif
#ifdef SIGALRM
#endif
#ifdef WANT_SLOW_RAND
#else
#endif
#ifdef __powerpc__
#endif
