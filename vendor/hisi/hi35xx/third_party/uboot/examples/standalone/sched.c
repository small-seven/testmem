#include <common.h>
#include <exports.h>
#define MAX_THREADS 8
#define CTX_SIZE 512
#define STK_SIZE 8*1024
#define STATE_EMPTY 0
#define STATE_RUNNABLE 1
#define STATE_STOPPED 2
#define STATE_TERMINATED 2
#define MASTER_THREAD 0
#define RC_FAILURE	(-1)
#define	RC_SUCCESS	(0)
typedef	vu_char *jmp_ctx;
unsigned long setctxsp (vu_char *sp);
int ppc_setjmp(jmp_ctx env);
void ppc_longjmp(jmp_ctx env, int val);
#define setjmp	ppc_setjmp
#define longjmp	ppc_longjmp

struct lthread {
	int state;
	int retval;
	char stack[STK_SIZE];
	uchar context[CTX_SIZE];
	int (*func) (void *);
	void *arg;
};
#define PDEBUG(fmt, args...)	 {					\
#if 0							/* not used yet */
#endif							/* not used yet */
#define NUMTHREADS 7
#define SWITCH(new)							\
#if 0	/* not used so far */
#endif	/* not used so far */
