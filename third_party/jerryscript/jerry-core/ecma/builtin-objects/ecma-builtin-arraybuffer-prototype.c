#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-arraybuffer-object.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#include "jrt-libc-includes.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-arraybuffer-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID arraybuffer_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
