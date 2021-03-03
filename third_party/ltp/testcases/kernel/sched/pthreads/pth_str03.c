#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <sys/types.h>
#include "test.h"
#define MAXTHREADS 1000
typedef struct kid_info c_info;

/* Global variables */
int depth = 3;
int breadth = 4;
int timeout = 30;		/* minutes */
int cdepth;			/* current depth */
int debug = 0;

c_info *child_info;		/* pointer to info array */
int node_count;			/* number of nodes created so far */
pthread_mutex_t node_mutex;	/* mutex for the node_count */
pthread_cond_t node_condvar;	/* condition variable for node_count */
pthread_attr_t attr;		/* attributes for created threads */

int num_nodes(int, int);
int synchronize_children(c_info *);
void *doit(void *);

char *TCID = "pth_str03";
int TST_TOTAL = 1;

void testexit(int value)
{
	if (value == 0)
		tst_resm(TPASS, "Test passed");
	else
		tst_resm(TFAIL, "Test failed");

	exit(value);
}
