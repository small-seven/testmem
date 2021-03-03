#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <rpc/rpc.h>
#define PROCNUM 1
#define VERSNUM 1
#define NBCASE 4
typedef struct {
	//List parameters here
	int bufsnd;
	int bufrec;
} params;
