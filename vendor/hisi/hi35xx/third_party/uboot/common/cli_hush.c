#define __U_BOOT__
#ifdef __U_BOOT__
#include <common.h>         /* readline */
#include <env.h>
#include <malloc.h>         /* malloc, free, realloc*/
#include <linux/ctype.h>    /* isalpha, isdigit */
#include <console.h>
#include <bootretry.h>
#include <cli.h>
#include <cli_hush.h>
#include <command.h>        /* find_cmd */
#ifndef CONFIG_SYS_PROMPT_HUSH_PS2
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif
#endif
#ifndef __U_BOOT__
#include <ctype.h>     /* isalpha, isdigit */
#include <unistd.h>    /* getpid */
#include <stdlib.h>    /* getenv, atoi */
#include <string.h>    /* strchr */
#include <stdio.h>     /* popen etc. */
#include <glob.h>      /* glob, of course */
#include <stdarg.h>    /* va_list */
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>    /* should be pretty obvious */
#include <sys/stat.h>  /* ulimit */
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#if 1
#include "busybox.h"
#include "cmdedit.h"
#else
#define applet_name "hush"
#include "standalone.h"
#define hush_main main
#undef CONFIG_FEATURE_SH_FANCY_PROMPT
#define BB_BANNER
#endif
#endif
#define SPECIAL_VAR_SYMBOL 03
#define SUBSTED_VAR_SYMBOL 04
#ifndef __U_BOOT__
#define FLAG_EXIT_FROM_LOOP 1
#define FLAG_PARSE_SEMICOLON (1 << 1)		/* symbol ';' is special for parser */
#define FLAG_REPARSING       (1 << 2)		/* >= 2nd pass */
#endif
#ifdef __U_BOOT__
#define EXIT_SUCCESS 0
#define EOF -1
#define syntax() syntax_err()
#define xstrdup strdup
#define error_msg printf
#else
typedef enum {
	REDIRECT_INPUT     = 1,
	REDIRECT_OVERWRITE = 2,
	REDIRECT_APPEND    = 3,
	REDIRECT_HEREIS    = 4,
	REDIRECT_IO        = 5
} redir_type;
#endif
typedef enum {
	PIPE_SEQ = 1,
	PIPE_AND = 2,
	PIPE_OR  = 3,
	PIPE_BG  = 4,
} pipe_style;
typedef enum {
	RES_NONE  = 0,
	RES_IF    = 1,
	RES_THEN  = 2,
	RES_ELIF  = 3,
	RES_ELSE  = 4,
	RES_FI    = 5,
	RES_FOR   = 6,
	RES_WHILE = 7,
	RES_UNTIL = 8,
	RES_DO    = 9,
	RES_DONE  = 10,
	RES_XXXX  = 11,
	RES_IN    = 12,
	RES_SNTX  = 13
} reserved_style;
#define FLAG_END   (1<<RES_NONE)
#define FLAG_IF    (1<<RES_IF)
#define FLAG_THEN  (1<<RES_THEN)
#define FLAG_ELIF  (1<<RES_ELIF)
#define FLAG_ELSE  (1<<RES_ELSE)
#define FLAG_FI    (1<<RES_FI)
#define FLAG_FOR   (1<<RES_FOR)
#define FLAG_WHILE (1<<RES_WHILE)
#define FLAG_UNTIL (1<<RES_UNTIL)
#define FLAG_DO    (1<<RES_DO)
#define FLAG_DONE  (1<<RES_DONE)
#define FLAG_IN    (1<<RES_IN)
#define FLAG_START (1<<RES_XXXX)
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif /*__U_BOOT__ */
#define B_CHUNK (100)
#define B_NOSPAC 1
typedef struct {
	char *data;
	int length;
	int maxlen;
	int quote;
	int nonnull;
} o_string;
#define NULL_O_STRING {NULL,0,0,0,0}
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#define b_getch(input) ((input)->get(input))
#define b_peek(input) ((input)->peek(input))
#ifndef __U_BOOT__
#define JOB_STATUS_FORMAT "[%d] %-22s %.40s\n"
#endif
#if 0
#define DEBUG_SHELL
#endif
#ifdef DEBUG_SHELL
#ifndef __U_BOOT__
#else
#define debug_printf(fmt,args...)	printf (fmt ,##args)
#endif
#else
#endif
#define final_printf debug_printf
#ifdef __U_BOOT__
#else
#define syntax() __syntax(__FILE__, __LINE__)
#endif
#ifdef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
static void b_free(o_string *o)
{
	b_reset(o);
	free(o->data);
	o->data = NULL;
	o->maxlen = 0;
}
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#ifndef CONFIG_FEATURE_SH_FANCY_PROMPT
#else
#endif
#ifndef CONFIG_FEATURE_SH_FANCY_PROMPT
#else
#endif
#endif
#ifdef __U_BOOT__
#ifdef CONFIG_CMDLINE_PS_SUPPORT
#endif
#endif
#ifndef __U_BOOT__
#ifdef CONFIG_FEATURE_COMMAND_EDITING
#else
#endif
#else
#ifdef CONFIG_BOOT_RETRY_TIME
#  ifdef CONFIG_RESET_TO_RETRY
#  else
#	error "This currently only works with CONFIG_RESET_TO_RETRY enabled"
#  endif
#endif
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#ifdef CONFIG_FEATURE_SH_STANDALONE_SHELL
#ifdef CONFIG_FEATURE_SH_APPLETS_ALWAYS_WIN
#endif
#endif
#if 0
#endif
#endif
#ifndef __U_BOOT__
# if __GNUC__
# endif
#else
# if __GNUC__
# endif
#endif	/* __U_BOOT__ */
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#if 0
#endif
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#define NRES (sizeof(reserved_list)/sizeof(struct reserved_combo))
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#if 1
#if 0
#define SURROGATE "surrogate response"
#else
#endif
#else
#endif
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#if 0
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif /* __U_BOOT__ */
#ifndef __U_BOOT__
#else
#endif	/* __U_BOOT__ */
#ifdef __U_BOOT__
#endif
#ifdef __U_BOOT__
#endif
#ifndef __U_BOOT__
#else
#endif
#ifndef __U_BOOT__
#else
#endif
#ifdef __U_BOOT__
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
static void *xmalloc(size_t size)
{
	void *p = NULL;

	if (!(p = malloc(size))) {
	    printf("ERROR : memory not allocated\n");
	    for(;;);
	}
	return p;
}
static void *xrealloc(void *ptr, size_t size)
{
	void *p = NULL;

	if (!(p = realloc(ptr, size))) {
	    printf("ERROR : memory not allocated\n");
	    for(;;);
	}
	return p;
}
#endif /* __U_BOOT__ */
#ifndef __U_BOOT__
#ifdef CONFIG_FEATURE_COMMAND_EDITING
#else
#endif
#ifndef BB_VER
#else
#endif
#ifndef CONFIG_FEATURE_SH_EXTRA_QUIET
#endif
#ifdef CONFIG_FEATURE_CLEAN_UP
#endif
#endif
#ifdef __U_BOOT__
#endif
