#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <getopt.h>
#include <pthread.h>
#include <limits.h>
#include <mqueue.h>
#include "posixtest.h"
#define MSG_SIZE	128
#define MAX_MSG		3
#define Max_Threads	10
#define Name_Size	20
typedef struct {
	int ThreadID;
	mqd_t mqID;
} mq_info;
#endif */
