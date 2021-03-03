#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "test-common.h"
typedef struct
{
  ecma_number_t num;
  uint32_t uint32_num;
} uint32_test_case_t;
typedef struct
{
  ecma_number_t num;
  int32_t int32_num;
} int32_test_case_t;
#define TEST_CASE(num, uint32) { num, uint32 }
#undef TEST_CASE
#define TEST_CASE(num, int32) { num, int32 }
#undef TEST_CASE
