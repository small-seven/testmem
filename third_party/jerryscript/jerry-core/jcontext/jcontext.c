#include "jcontext.h"
#if !ENABLED (JERRY_EXTERNAL_CONTEXT)
#if !ENABLED (JERRY_SYSTEM_ALLOCATOR)
#ifdef JERRY_FOR_IAR_CONFIG // ACELite changes, align heap by 8bytes for IAR
#pragma data_alignment = JMEM_ALIGNMENT
#else
#endif
#endif /* !ENABLED (JERRY_SYSTEM_ALLOCATOR) */
#endif /* !ENABLED (JERRY_EXTERNAL_CONTEXT) */
