#define _GNU_SOURCE
#include <pthread.h>
#include <stdio.h>
#include "hugetlb.h"
#include "lapi/mmap.h"
#define ARSZ 50
#define LOOP 5
