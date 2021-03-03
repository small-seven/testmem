#include <common.h>
#include <env.h>
#include <linux/types.h>
#include <api_public.h>
#include "glue.h"
#define errf(fmt, args...) do { printf("ERROR @ %s(): ", __func__); printf(fmt, ##args); } while (0)
#define BUF_SZ		2048
#define WAIT_SECS	5
