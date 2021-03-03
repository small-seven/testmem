#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/wait.h>
#include "config.h"
#include "test.h"
#ifdef HAVE_SYS_EPOLL_H
#include <sys/epoll.h>
#if !defined(TRUE) && !defined(FALSE)
#define TRUE  1
#define FALSE 0
#endif
#define NUM_RAND_ATTEMPTS 16
#define BACKING_STORE_SIZE_HINT 32
#define PROTECT_REGION_START		\
#define PROTECT_REGION_EXIT(errval) return (errval);
#define PROTECT_REGION_END(result, errval)					\
#define PROTECT_FUNC(fn, errval, epoll_fd) (					\
#define RES_PASS 0
#define RES_FAIL_RETV_MIS_ERRNO_MAT 1
#define RES_FAIL_RETV_BAD_ERRNO_MAT 2
#define RES_FAIL_RETV_MAT_ERRNO_MIS 3
#define RES_FAIL_RETV_BAD_ERRNO_MIS 4
#define RES_FAIL_RETV_MIS_ERRNO_IGN 5
#define RES_FAIL_RETV_BAD_ERRNO_IGN 6
#define RES_PASS_RETV_MAT_ERRNO_IGN 7
#define EPOLL_CTL_TEST_RESULTS_SHOW_PARAMS 1
#if EPOLL_CTL_TEST_RESULTS_SHOW_PARAMS
#define EPOLL_CTL_TEST_FAIL(msg , ...) \
#define EPOLL_CTL_TEST_PASS(msg , ...) \
#else
#define EPOLL_CTL_TEST_FAIL(msg , ...) tst_resm(TFAIL, msg , ##__VA_ARGS__)
#define EPOLL_CTL_TEST_PASS(msg , ...) tst_resm(TPASS, msg , ##__VA_ARGS__)
#endif
#ifdef DEBUG
#else
#endif
#else
#endif
