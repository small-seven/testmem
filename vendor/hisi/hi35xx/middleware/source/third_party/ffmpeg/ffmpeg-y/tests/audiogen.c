#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHANNELS 12
#define FRAC_BITS 16
#define FRAC_ONE (1 << FRAC_BITS)
#define COS_TABLE_BITS 7
#define CSHIFT (FRAC_BITS - COS_TABLE_BITS - 2)
#define HEADER_SIZE      46
#define FMT_SIZE         18
#define SAMPLE_SIZE       2
#define WFORMAT_PCM  0x0001
