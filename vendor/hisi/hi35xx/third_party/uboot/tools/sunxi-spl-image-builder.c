#include <linux/bch.h>
#include <getopt.h>
#include <version.h>
#define BCH_PRIMITIVE_POLY	0x5803
#define ARRAY_SIZE(arr)		(sizeof(arr) / sizeof((arr)[0]))
#define DIV_ROUND_UP(n,d)	(((n) + (d) - 1) / (d))
