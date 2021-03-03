#include <string.h>
#include <sys/utsname.h>
#include "tst_test.h"
#include "lapi/personality.h"
#define CHECK_FIELD(field_name) \
#ifdef HAVE_STRUCT_UTSNAME_DOMAINNAME
#endif
#undef CHECK_FIELD
