#include "hb-test.h"
typedef enum {
  BUFFER_EMPTY,
  BUFFER_ONE_BY_ONE,
  BUFFER_UTF32,
  BUFFER_UTF16,
  BUFFER_UTF8,
  BUFFER_NUM_TYPES,
} buffer_type_t;
typedef struct
{
  hb_buffer_t *buffer;
} fixture_t;
typedef struct {
  const char utf8[8];
  const uint32_t codepoints[8];
} utf8_conversion_test_t;
typedef struct {
  const char *utf8;
  int max_len;
  unsigned int offset;
  gboolean valid;
} utf8_validity_test_t;
#if 0 /* We don't consider U+FFFE / U+FFFF and similar invalid. */
#endif
typedef struct {
  const uint16_t utf16[8];
  const uint32_t codepoints[8];
} utf16_conversion_test_t;
typedef struct {
  const uint32_t utf32[8];
  const uint32_t codepoints[8];
} utf32_conversion_test_t;
