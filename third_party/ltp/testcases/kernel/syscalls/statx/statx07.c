#define _GNU_SOURCE
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <linux/limits.h>
#include <sys/mount.h>
#include "tst_test.h"
#include "lapi/stat.h"
#define MODE(X) (X & (~S_IFMT))
#define FLAG_NAME(x) .flag = x, .flag_name = #x
#define BUFF_SIZE PATH_MAX
#define DEFAULT_MODE 0644
#define CURRENT_MODE 0777
#define CLI_PATH "client"
#define SERV_PATH "server"
#define CLI_FORCE_SYNC "client/force_sync_file"
#define CLI_DONT_SYNC "client/dont_sync_file"
#define SERV_FORCE_SYNC "server/force_sync_file"
#define SERV_DONT_SYNC "server/dont_sync_file"
