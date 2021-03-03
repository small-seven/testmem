#include "set_thread_area.h"
#if defined(HAVE_ASM_LDT_H) && defined(HAVE_STRUCT_USER_DESC)
#define VALUE_AND_STRING(val) val, #val
#else
#endif
