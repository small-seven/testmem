#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <errno.h>
#include "tst_test.h"
#include "lapi/execveat.h"
#include "lapi/fcntl.h"
#include "execveat.h"
#define TESTDIR "testdir"
#define TEST_APP "execveat_child"
#define TEST_REL_APP TESTDIR"/"TEST_APP
