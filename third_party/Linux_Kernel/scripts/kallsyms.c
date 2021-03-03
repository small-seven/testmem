#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#endif
#define KSYM_NAME_LEN		128
#define text_range_text     (&text_ranges[0])
#define text_range_inittext (&text_ranges[1])
