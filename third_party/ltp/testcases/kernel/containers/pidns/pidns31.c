#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mqueue.h>
#include "lapi/syscalls.h"
#include "pidns_helper.h"
#include "test.h"
#define CHILD_PID       1
#define PARENT_PID      0
#define MSG      "HOW ARE YOU"
#define MSG_PRIO 1
#define NO_STEP -1
#define F_STEP_0 0x00
#define F_STEP_1 0x01
#define F_STEP_2 0x02
#define F_STEP_3 0x03
#define C_STEP_0 0x10
#define C_STEP_1 0x11
