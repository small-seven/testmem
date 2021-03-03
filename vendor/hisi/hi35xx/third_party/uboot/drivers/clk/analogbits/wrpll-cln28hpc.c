#include <linux/bug.h>
#include <linux/err.h>
#include <linux/log2.h>
#include <linux/math64.h>
#include <linux/clk/analogbits-wrpll-cln28hpc.h>
#define MIN_INPUT_FREQ			7000000
#define MAX_INPUT_FREQ			600000000
#define MIN_POST_DIVR_FREQ		7000000
#define MAX_POST_DIVR_FREQ		200000000
#define MIN_VCO_FREQ			2400000000UL
#define MAX_VCO_FREQ			4800000000ULL
#define MAX_DIVQ_DIVISOR		64
#define MAX_DIVR_DIVISOR		64
#define MAX_LOCK_US			70
#define ROUND_SHIFT			20
