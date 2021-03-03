#define _GNU_SOURCE
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"
#include "safe_macros.h"
#include "usctest.h"
#include "ltp_priv.h"
#include "tst_ansi_color.h"
#define VERBOSE      1
#define NOPASS       3
#define DISCARD      4
#define MAXMESG      80		/* max length of internal messages */
#define USERMESG     2048	/* max length of user message */
#define TRUE         1
#define FALSE        0
#define EXPAND_VAR_ARGS(buf, arg_fmt, buf_len) do {\
#ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
# ifdef __ANDROID__
#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
# else
#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP  { {PTHREAD_MUTEX_RECURSIVE} }
# endif
#endif
#define PAIR(def) [def] = {.name = #def, .val = def},
#define STRPAIR(key, value) [key] = {.name = value, .val = key},
#define PAIR_LOOKUP(pair_arr, idx) do {                       \
#include "errnos.h"
#include "signame.h"
typedef void (*tst_res_func_t)(const char *file, const int lineno,
		int ttype, const char *fmt, ...);

void tst_resm_hexd_(const char *file, const int lineno, int ttype,
	const void *buf, size_t size, const char *arg_fmt, ...)
{
	char tmesg[USERMESG];
	static const size_t symb_num	= 2; /* xx */
	static const size_t size_max	= 16;
	size_t offset;
	size_t i;
	char *pmesg = tmesg;
	tst_res_func_t res_func;

	if (tst_test)
		res_func = tst_res_;
	else
		res_func = tst_res__;

	EXPAND_VAR_ARGS(tmesg, arg_fmt, USERMESG);
	offset = strlen(tmesg);

	if (size > size_max || size == 0 ||
		(offset + size * (symb_num + 1)) >= USERMESG)
		res_func(file, lineno, ttype, "%s", tmesg);
	else
		pmesg += offset;

	for (i = 0; i < size; ++i) {
		/* add space before byte except first one */
		if (pmesg != tmesg)
			*(pmesg++) = ' ';

		sprintf(pmesg, "%02x", ((unsigned char *)buf)[i]);
		pmesg += symb_num;
		if ((i + 1) % size_max == 0 || i + 1 == size) {
			res_func(file, lineno, ttype, "%s", tmesg);
			pmesg = tmesg;
		}
