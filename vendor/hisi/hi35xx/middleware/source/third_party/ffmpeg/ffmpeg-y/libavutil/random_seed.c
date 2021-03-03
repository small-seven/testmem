#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_BCRYPT
#include <windows.h>
#include <bcrypt.h>
#endif
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "avassert.h"
#include "internal.h"
#include "intreadwrite.h"
#include "timer.h"
#include "random_seed.h"
#include "sha.h"
#ifndef TEST
#define TEST 0
#endif
#if HAVE_UNISTD_H
#else
#endif
#ifdef AV_READ_TIME
#endif
#ifdef AV_READ_TIME
#endif
#if HAVE_BCRYPT
#endif
#if HAVE_ARC4RANDOM
#endif
