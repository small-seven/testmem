#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mount.h>
#include "lapi/loop.h"
#include "tst_test.h"
#define DIO_MESSAGE "In dio mode"
#define NON_DIO_MESSAGE "In non dio mode"
