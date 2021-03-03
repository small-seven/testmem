#include <common.h>
#include <command.h>
#include <fs.h>
#define OP_INVALID	0
#define OP_NOT		1
#define OP_OR		2
#define OP_AND		3
#define OP_STR_EMPTY	4
#define OP_STR_NEMPTY	5
#define OP_STR_EQ	6
#define OP_STR_NEQ	7
#define OP_STR_LT	8
#define OP_STR_GT	9
#define OP_INT_EQ	10
#define OP_INT_NEQ	11
#define OP_INT_LT	12
#define OP_INT_LE	13
#define OP_INT_GT	14
#define OP_INT_GE	15
#define OP_FILE_EXISTS	16
#ifdef DEBUG
#endif
#undef true
#undef false
