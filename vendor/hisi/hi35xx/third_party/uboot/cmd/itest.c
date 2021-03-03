#include <common.h>
#include <config.h>
#include <command.h>
#include <env.h>
#include <mapmem.h>
#include <asm/io.h>
#define EQ	0
#define NE	1
#define LT	2
#define GT	3
#define LE	4
#define GE	5
typedef struct op_tbl_s op_tbl_t;

static const op_tbl_t op_table [] = {
	{ "-lt", LT },
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_PHYS_64BIT
#else
#endif
