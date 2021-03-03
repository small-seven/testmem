#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "tst_test.h"
#include "lapi/keyctl.h"
#define ASSOC_ARRAY_FAN_OUT 16
#define PAYLOAD "payload"
