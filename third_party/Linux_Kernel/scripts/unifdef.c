#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef enum {
	LT_TRUEI,		/* a true #if with ignore flag */
	LT_FALSEI,		/* a false #if with ignore flag */
	LT_IF,			/* an unknown #if */
	LT_TRUE,		/* a true #if */
	LT_FALSE,		/* a false #if */
	LT_ELIF,		/* an unknown #elif */
	LT_ELTRUE,		/* a true #elif */
	LT_ELFALSE,		/* a false #elif */
	LT_ELSE,		/* #else */
	LT_ENDIF,		/* #endif */
	LT_DODGY,		/* flag: directive is not on one line */
	LT_DODGY_LAST = LT_DODGY + LT_ENDIF,
	LT_PLAIN,		/* ordinary line */
	LT_EOF,			/* end of file */
	LT_ERROR,		/* unevaluable #if */
	LT_COUNT
} Linetype;
typedef enum {
	IS_OUTSIDE,
	IS_FALSE_PREFIX,	/* false #if followed by false #elifs */
	IS_TRUE_PREFIX,		/* first non-false #(el)if is true */
	IS_PASS_MIDDLE,		/* first non-false #(el)if is unknown */
	IS_FALSE_MIDDLE,	/* a false #elif after a pass state */
	IS_TRUE_MIDDLE,		/* a true #elif after a pass state */
	IS_PASS_ELSE,		/* an else after a pass state */
	IS_FALSE_ELSE,		/* an else after a true state */
	IS_TRUE_ELSE,		/* an else after only false states */
	IS_FALSE_TRAILER,	/* #elifs after a true are false */
	IS_COUNT
} Ifstate;
typedef enum {
	NO_COMMENT = false,	/* outside a comment */
	C_COMMENT,		/* in a comment like this one */
	CXX_COMMENT,		/* between // and end of line */
	STARTING_COMMENT,	/* just after slash-backslash-newline */
	FINISHING_COMMENT,	/* star-backslash-newline in a C comment */
	CHAR_LITERAL,		/* inside '' */
	STRING_LITERAL		/* inside "" */
} Comment_state;
typedef enum {
	LS_START,		/* only space and comments on this line */
	LS_HASH,		/* only space, comments, and a hash */
	LS_DIRTY		/* this line can't be a preprocessor line */
} Line_state;
#define	MAXDEPTH        64			/* maximum #if nesting */
#define	MAXLINE         4096			/* maximum length of line */
#define	MAXSYMS         4096			/* maximum number of symbols */
#define	EDITSLOP        10
#define TEMPLATE        "unifdef.XXXXXX"
#define endsym(c) (!isalnum((unsigned char)c) && c != '_')
typedef void state_fn(void);

/* report an error */
static void Eelif (void) { error("Inappropriate #elif"); }
typedef Linetype eval_fn(const struct ops *, int *, const char **);

static eval_fn eval_table, eval_unary;

/*
 * The precedence table. Expressions involving binary operators are evaluated
 * in a table-driven way by eval_table. When it evaluates a subexpression it
 * calls the inner function with its first argument pointing to the next
 * element of the table. Innermost expressions have special non-table-driven
 * handling.
 */
static const struct ops {
	eval_fn *inner;
	struct op {
		const char *str;
		Linetype (*fn)(int *, Linetype, int, Linetype, int);
	} op[5];
