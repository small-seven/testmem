#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rpc.h"
#define PROCNUM 1
#define VERSNUM 1
#define NBCASE 3
typedef struct {
	int init_tout;
	int next_tout;
} params;
