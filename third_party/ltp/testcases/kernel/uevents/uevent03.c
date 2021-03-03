#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/sysmacros.h>
#include <linux/uinput.h>
#include "tst_test.h"
#include "tst_uinput.h"
#include "uevent.h"
#define MINOR_MAJOR_SIZE 32
