#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <limits.h>
#include <stdint.h>
#include <regex.h>
#include "tre.h"
#include <assert.h>
#define GET_NEXT_WCHAR() do {                                                 \
#define IS_WORD_CHAR(c)	 ((c) == L'_' || tre_isalnum(c))
#define CHECK_ASSERTIONS(assertions)					      \
#define CHECK_CHAR_CLASSES(trans_i, tnfa, eflags)                             \
typedef struct {
  tre_tnfa_transition_t *state;
  regoff_t *tags;
} tre_tnfa_reach_t;
typedef struct {
  regoff_t pos;
  regoff_t **tags;
} tre_reach_pos_t;
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
typedef struct {
  regoff_t pos;
  const char *str_byte;
  tre_tnfa_transition_t *state;
  int state_id;
  int next_c;
  regoff_t *tags;
#ifdef TRE_MBSTATE
  mbstate_t mbstate;
#endif /* TRE_MBSTATE */
} tre_backtrack_item_t;
typedef struct tre_backtrack_struct {
  tre_backtrack_item_t item;
  struct tre_backtrack_struct *prev;
  struct tre_backtrack_struct *next;
} *tre_backtrack_t;
#ifdef TRE_MBSTATE
#define BT_STACK_MBSTATE_IN  stack->item.mbstate = (mbstate)
#define BT_STACK_MBSTATE_OUT (mbstate) = stack->item.mbstate
#else /* !TRE_MBSTATE */
#define BT_STACK_MBSTATE_IN
#define BT_STACK_MBSTATE_OUT
#endif /* !TRE_MBSTATE */
#define tre_bt_mem_new		  tre_mem_new
#define tre_bt_mem_alloc	  tre_mem_alloc
#define tre_bt_mem_destroy	  tre_mem_destroy
#define BT_STACK_PUSH(_pos, _str_byte, _str_wide, _state, _state_id, _next_c, _tags, _mbstate) \
#define BT_STACK_POP()							      \
#undef MIN
#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
#if 0 /* XXX - it's important not to look at all transitions here to keep
#endif
#ifdef TRE_MBSTATE
#endif /* TRE_MBSTATE */
#ifndef TRE_USE_ALLOCA
#endif /* !TRE_USE_ALLOCA */
