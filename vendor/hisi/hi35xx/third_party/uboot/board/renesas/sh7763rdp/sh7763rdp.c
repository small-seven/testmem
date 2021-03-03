#include <common.h>
#include <asm/io.h>
#include <asm/processor.h>
#define CPU_CMDREG	0xB1000006
#define PDCR        0xffef0006
#define PECR        0xffef0008
#define PFCR        0xffef000a
#define PGCR        0xffef000c
#define PHCR        0xffef000e
#define PJCR        0xffef0012
#define PKCR        0xffef0014
#define PLCR        0xffef0016
#define PMCR        0xffef0018
#define PSEL1       0xffef0072
#define PSEL2       0xffef0074
#define PSEL3       0xffef0076
