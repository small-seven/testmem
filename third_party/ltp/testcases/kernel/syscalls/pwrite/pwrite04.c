#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>
#include <errno.h>
#include "test.h"
#define PASSED 1
#define FAILED 0
#define K1    		1024
#define K2    		(K1 * 2)
#define K3    		(K1 * 3)
#define K4    		(K1 * 4)
#define K5    		(K1 * 5)
#define	NBUFS 		4
#define DATA_FILE	"pwrite04_file"
