#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#define FAIL 0
#define SUCCESS 1
#define MAXNUM 0x100000
#define  MAXERROR 1024
#define MAXFSIZE (192*1024)
#define AVEFSIZE (MAXFSIZE/2)
#define POOLDISKSPACE (AVEFSIZE*128)
#include <sys/stat.h>
#include <unistd.h>
