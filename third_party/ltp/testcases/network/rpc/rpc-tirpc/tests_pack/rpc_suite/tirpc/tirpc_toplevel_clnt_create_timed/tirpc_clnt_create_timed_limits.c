#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rpc.h"
#define PROCNUM 1
#define VERSNUM 1
#define NBCASE 1
typedef struct {
	//List parameters here
	int init_tout;
	int next_tout;
} params;
