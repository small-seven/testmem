#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <limits.h>
#include <stdint.h>
#include <ctype.h>
#include "tre.h"
#include <assert.h>
typedef struct {
  int position;
  int code_min;
  int code_max;
  int *tags;
  int assertions;
  tre_ctype_t class;
  tre_ctype_t *neg_classes;
  int backref;
} tre_pos_and_tags_t;
typedef enum {
  LITERAL,
  CATENATION,
  ITERATION,
  UNION
} tre_ast_type_t;
#define EMPTY	  -1   /* Empty leaf (denotes empty string). */
#define ASSERTION -2   /* Assertion leaf. */
#define TAG	  -3   /* Tag leaf. */
#define BACKREF	  -4   /* Back reference leaf. */
#define IS_SPECIAL(x)	((x)->code_min < 0)
#define IS_EMPTY(x)	((x)->code_min == EMPTY)
#define IS_ASSERTION(x) ((x)->code_min == ASSERTION)
#define IS_TAG(x)	((x)->code_min == TAG)
#define IS_BACKREF(x)	((x)->code_min == BACKREF)
typedef struct {
  tre_ast_type_t type;   /* Type of the node. */
  void *obj;             /* Pointer to actual node. */
  int nullable;
  int submatch_id;
  int num_submatches;
  int num_tags;
  tre_pos_and_tags_t *firstpos;
  tre_pos_and_tags_t *lastpos;
} tre_ast_node_t;
typedef struct {
  long code_min;
  long code_max;
  int position;
  tre_ctype_t class;
  tre_ctype_t *neg_classes;
} tre_literal_t;
typedef struct {
  tre_ast_node_t *left;
  tre_ast_node_t *right;
} tre_catenation_t;
typedef struct {
  /* Subexpression to match. */
  tre_ast_node_t *arg;
  /* Minimum number of consecutive matches. */
  int min;
  /* Maximum number of consecutive matches. */
  int max;
  /* If 0, match as many characters as possible, if 1 match as few as
     possible.	Note that this does not always mean the same thing as
     matching as many/few repetitions as possible. */
  unsigned int minimal:1;
} tre_iteration_t;
typedef struct {
  tre_ast_node_t *left;
  tre_ast_node_t *right;
} tre_union_t;
typedef struct tre_stack_rec tre_stack_t;

/* Creates a new stack object.	`size' is initial size in bytes, `max_size'
   is maximum size, and `increment' specifies how much more space will be
   allocated with realloc() if all space gets used up.	Returns the stack
   object or NULL if out of memory. */
static tre_stack_t *
tre_stack_new(int size, int max_size, int increment);

/* Frees the stack object. */
static void
tre_stack_destroy(tre_stack_t *s);

/* Returns the current number of objects in the stack. */
static int
tre_stack_num_objects(tre_stack_t *s);

/* Each tre_stack_push_*(tre_stack_t *s, <type> value) function pushes
   `value' on top of stack `s'.  Returns REG_ESPACE if out of memory.
   This tries to realloc() more space before failing if maximum size
   has not yet been reached.  Returns REG_OK if successful. */
#define declare_pushf(typetag, type)					      \
  static reg_errcode_t tre_stack_push_ ## typetag(tre_stack_t *s, type value)

declare_pushf(voidptr, void *);
declare_pushf(int, int);

/* Each tre_stack_pop_*(tre_stack_t *s) function pops the topmost
   element off of stack `s' and returns it.  The stack must not be
   empty. */
#define declare_popf(typetag, type)		  \
  static type tre_stack_pop_ ## typetag(tre_stack_t *s)

declare_popf(voidptr, void *);
declare_popf(int, int);

/* Just to save some typing. */
#define STACK_PUSH(s, typetag, value)					      \
  do									      \
    {									      \
      status = tre_stack_push_ ## typetag(s, value);			      \
    }									      \
#define STACK_PUSHX(s, typetag, value)					      \
#define STACK_PUSHR(s, typetag, value)					      \
tre_stack_destroy(tre_stack_t *s)
{
  xfree(s->stack);
  xfree(s);
}
#define define_pushf(typetag, type)  \
#define define_popf(typetag, type)		    \
typedef struct {
	/* Memory allocator. The AST is allocated using this. */
	tre_mem_t mem;
	/* Stack used for keeping track of regexp syntax. */
	tre_stack_t *stack;
	/* The parsed node after a parse function returns. */
	tre_ast_node_t *n;
	/* Position in the regexp pattern after a parse function returns. */
	const char *s;
	/* The first character of the last subexpression parsed. */
	const char *start;
	/* Current submatch ID. */
	int submatch_id;
	/* Current position (number of literal). */
	int position;
	/* The highest back reference or -1 if none seen so far. */
	int max_backref;
	/* Compilation flags. */
	int cflags;
} tre_parse_ctx_t;
#define MAX_NEG_CLASSES 64
#define PUSHPTR(err, s, v) do { \
#define PUSHINT(err, s, v) do { \
typedef enum {
  ADDTAGS_RECURSE,
  ADDTAGS_AFTER_ITERATION,
  ADDTAGS_AFTER_UNION_LEFT,
  ADDTAGS_AFTER_UNION_RIGHT,
  ADDTAGS_AFTER_CAT_LEFT,
  ADDTAGS_AFTER_CAT_RIGHT,
  ADDTAGS_SET_SUBMATCH_END
} tre_addtags_symbol_t;
typedef struct {
  int tag;
  int next_tag;
} tre_tag_states_t;
typedef enum {
  COPY_RECURSE,
  COPY_SET_RESULT_PTR
} tre_copyast_symbol_t;
#define COPY_REMOVE_TAGS	 1
#define COPY_MAXIMIZE_FIRST_TAG	 2
typedef enum {
  EXPAND_RECURSE,
  EXPAND_AFTER_ITER
} tre_expand_ast_symbol_t;
typedef enum {
  NFL_RECURSE,
  NFL_POST_UNION,
  NFL_POST_CATENATION,
  NFL_POST_ITERATION
} tre_nfl_stack_symbol_t;
#if 0
#endif
#define ERROR_EXIT(err)		  \
#ifdef TRE_DEBUG
#endif /* TRE_DEBUG */
regfree(regex_t *preg)
{
  tre_tnfa_t *tnfa;
  unsigned int i;
  tre_tnfa_transition_t *trans;

  tnfa = (void *)preg->TRE_REGEX_T_FIELD;
  if (!tnfa)
    return;

  for (i = 0; i < tnfa->num_transitions; i++)
    if (tnfa->transitions[i].state)
      {
	if (tnfa->transitions[i].tags)
	  xfree(tnfa->transitions[i].tags);
	if (tnfa->transitions[i].neg_classes)
	  xfree(tnfa->transitions[i].neg_classes);
      }
  if (tnfa->transitions)
    xfree(tnfa->transitions);

  if (tnfa->initial)
    {
      for (trans = tnfa->initial; trans->state; trans++)
	{
	  if (trans->tags)
	    xfree(trans->tags);
	}
      xfree(tnfa->initial);
    }

  if (tnfa->submatch_data)
    {
      for (i = 0; i < tnfa->num_submatches; i++)
	if (tnfa->submatch_data[i].parents)
	  xfree(tnfa->submatch_data[i].parents);
      xfree(tnfa->submatch_data);
    }

  if (tnfa->tag_directions)
    xfree(tnfa->tag_directions);
  if (tnfa->firstpos_chars)
    xfree(tnfa->firstpos_chars);
  if (tnfa->minimal_tags)
    xfree(tnfa->minimal_tags);
  xfree(tnfa);
}
