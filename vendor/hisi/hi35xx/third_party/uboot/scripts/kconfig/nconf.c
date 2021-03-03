#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <string.h>
#include <stdlib.h>
#include "lkc.h"
#include "nconf.h"
#include <ctype.h>
#define MAX_MENU_ITEMS 4096
typedef void (*function_key_handler_t)(int *key, struct menu *menu);
static void handle_f1(int *key, struct menu *current_item);
static void handle_f2(int *key, struct menu *current_item);
static void handle_f3(int *key, struct menu *current_item);
static void handle_f4(int *key, struct menu *current_item);
static void handle_f5(int *key, struct menu *current_item);
static void handle_f6(int *key, struct menu *current_item);
static void handle_f7(int *key, struct menu *current_item);
static void handle_f8(int *key, struct menu *current_item);
static void handle_f9(int *key, struct menu *current_item);

struct function_keys {
	const char *key_str;
	const char *func;
	function_key key;
	function_key_handler_t handler;
};
typedef enum {MATCH_TINKER_PATTERN_UP, MATCH_TINKER_PATTERN_DOWN,
	FIND_NEXT_MATCH_DOWN, FIND_NEXT_MATCH_UP} match_f;
#if NCURSES_REENTRANT
#else
#endif
