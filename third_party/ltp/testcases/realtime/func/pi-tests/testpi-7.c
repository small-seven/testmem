#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <librttest.h>
#define HIGH_PRIO 15
#define MED_PRIO 10
#define LOW_PRIO  5
#define ITERATIONS 100
#define MED_WORK_MS 20
#define NS_PER_MS 1000000
typedef enum {
	LOW_START_CYCLE = 1,	// 1
	MED_START_WORK,		// 2
	HIGH_GRAB_MUTEX,	// 3
	LOW_DROP_MUTEX,		// 4
	END_OF_CYCLE,		// 5
	END_OF_GAME		// 6
} phase_t;
#define read_flag(A) _read_flag(__FUNCTION__,__LINE__)
#define write_flag(A) _write_flag(__FUNCTION__,__LINE__,A)
#define while_not_flag(A,B) while (read_flag() != (A) && !thread_quit(B))
#define MP "\t\t\t"
#undef MP
#define HP "\t\t\t\t\t"
#undef HP
