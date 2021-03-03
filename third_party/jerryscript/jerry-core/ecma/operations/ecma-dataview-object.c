#include "ecma-arraybuffer-object.h"
#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-helpers.h"
#include "ecma-dataview-object.h"
#include "ecma-typedarray-object.h"
#include "ecma-objects.h"
#if defined(JERRY_FOR_IAR_CONFIG)
#include "jerryscript-core.h"
#endif
#if ENABLED (JERRY_ES2015_BUILTIN_DATAVIEW)
typedef union
{
  uint32_t number; /**< for write numeric data */
  char data[sizeof (uint32_t)]; /**< for read numeric data */
} ecma_dataview_endiannes_check_t;
#if defined(JERRY_FOR_IAR_CONFIG)
#endif
#if defined(JERRY_FOR_IAR_CONFIG)
#else
#endif
#if defined(JERRY_FOR_IAR_CONFIG)
#else
#endif
#endif /* ENABLED (JERRY_ES2015_BUILTIN_DATAVIEW */
