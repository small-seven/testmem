#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "posixtest.h"
#define NAMESIZE 50
#define MSG1 "1234567890"
#define PRI1 10
#define MSG2 "234567890"
#define PRI2 8
#define MSG3 "34567890"
#define PRI3 2
#define MSG4 "4567890"
#define PRI4 2
#define MSG5 "567890"
#define PRI5 1
#define BUFFER 40
#define MAXMSG 10
