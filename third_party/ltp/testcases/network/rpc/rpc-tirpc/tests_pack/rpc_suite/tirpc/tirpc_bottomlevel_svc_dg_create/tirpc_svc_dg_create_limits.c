#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rpc.h"
#define PROCNUM 1
#define VERSNUM 1
#define NBCASE 4
#define ADDRBUFSIZE 100
typedef struct {
	//List parameters here
	int bufsnd;
	int bufrec;
} params;
