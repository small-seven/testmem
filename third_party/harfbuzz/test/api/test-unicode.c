#include "hb-test.h"
#ifdef HAVE_GLIB
#include <hb-glib.h>
#endif
#ifdef HAVE_ICU
#include <hb-icu.h>
#endif
#define MAGIC0 0x12345678
#define MAGIC1 0x76543210
typedef struct {
  int value;
  gboolean freed;
} data_t;
typedef struct {
  hb_codepoint_t unicode;
  unsigned int   value;
} test_pair_t;
typedef unsigned int (*get_func_t)         (hb_unicode_funcs_t *ufuncs,
					    hb_codepoint_t      unicode,
					    void               *user_data);
typedef unsigned int (*func_setter_func_t) (hb_unicode_funcs_t *ufuncs,
					    get_func_t          func,
					    void               *user_data,
					    hb_destroy_func_t   destroy);
typedef unsigned int (*getter_func_t)      (hb_unicode_funcs_t *ufuncs,
					    hb_codepoint_t      unicode);

typedef struct {
  const char         *name;
  func_setter_func_t  func_setter;
  getter_func_t       getter;
  const test_pair_t  *tests;
  unsigned int        num_tests;
  const test_pair_t  *tests_more;
  unsigned int        num_tests_more;
  unsigned int        default_value;
} property_t;
#define RETURNS_UNICODE_ITSELF ((unsigned int) -1)
#define PROPERTY(name, DEFAULT) \
#undef PROPERTY
typedef struct {
  data_t data[2];
} data_fixture_t;
#ifdef HAVE_GLIB
#endif
#ifdef HAVE_ICU
#endif
  typedef hb_script_t (*roundtrip_func_t) (hb_script_t);
  roundtrip_func_t roundtrip_func = (roundtrip_func_t) user_data;
  unsigned int i;
  gboolean failed = FALSE;

  for (i = 0; i < G_N_ELEMENTS (script_tests); i++) {
    const test_pair_t *test = &script_tests[i];
    hb_script_t script = test->value;

    g_test_message ("Test script roundtrip #%d: %x", i, script);
    g_assert_cmphex (script, ==, roundtrip_func (script));
  }
#ifdef HAVE_GLIB
#endif
#ifdef HAVE_ICU
#endif
