#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "jcontext.h"
#include "jrt-bit-fields.h"
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
typedef const ecma_builtin_property_descriptor_t *ecma_builtin_property_list_reference_t;

/**
 * Definition of built-in dispatch routine function pointer.
 */
typedef ecma_value_t (*ecma_builtin_dispatch_routine_t)(uint16_t builtin_routine_id,
                                                        ecma_value_t this_arg,
                                                        const ecma_value_t arguments_list[],
                                                        ecma_length_t arguments_number);
/**
 * Definition of built-in dispatch call function pointer.
 */
typedef ecma_value_t (*ecma_builtin_dispatch_call_t)(const ecma_value_t arguments_list[],
                                                     ecma_length_t arguments_number);
/**
 * Definition of a builtin descriptor which contains the builtin object's:
 * - prototype objects's id (13-bits)
 * - type (3-bits)
 *
 * Layout:
 *
 * |----------------------|---------------|
 *     prototype_id(13)      obj_type(3)
 */
typedef uint16_t ecma_builtin_descriptor_t;

/**
 * Bitshift index for get the prototype object's id from a builtin descriptor
 */
#define ECMA_BUILTIN_PROTOTYPE_ID_SHIFT 3

/**
 * Bitmask for get the object's type from a builtin descriptor
 */
#define ECMA_BUILTIN_OBJECT_TYPE_MASK ((1 << ECMA_BUILTIN_PROTOTYPE_ID_SHIFT) - 1)

/**
 * Create a builtin descriptor value
 */
#define ECMA_MAKE_BUILTIN_DESCRIPTOR(type, proto_id) \
  (((proto_id) << ECMA_BUILTIN_PROTOTYPE_ID_SHIFT) | (type))

/**
 * List of the built-in descriptors.
 */
static const ecma_builtin_descriptor_t ecma_builtin_descriptors[] =
{
/** @cond doxygen_suppress */
#define BUILTIN(a, b, c, d, e)
#define BUILTIN_ROUTINE(builtin_id, \
                        object_type, \
                        object_prototype_builtin_id, \
                        is_extensible, \
                        lowercase_name) \
  ECMA_MAKE_BUILTIN_DESCRIPTOR (object_type, object_prototype_builtin_id),
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
#define BUILTIN_ROUTINE(a, b, c, d, e)
#define BUILTIN(builtin_id, \
                object_type, \
                object_prototype_builtin_id, \
                is_extensible, \
                lowercase_name) \
  ECMA_MAKE_BUILTIN_DESCRIPTOR (object_type, object_prototype_builtin_id),
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
/** @endcond */
};
#ifndef JERRY_NDEBUG
#define BUILTIN(a, b, c, d, e)
#define BUILTIN_ROUTINE(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
#define BUILTIN_ROUTINE(a, b, c, d, e)
#define BUILTIN(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
#endif /* !JERRY_NDEBUG */
#define BUILTIN(a, b, c, d, e)
#define BUILTIN_ROUTINE(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
#define BUILTIN_ROUTINE(a, b, c, d, e)
#define BUILTIN(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
#define BUILTIN(a, b, c, d, e)
#define BUILTIN_ROUTINE(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN_ROUTINE
#undef BUILTIN
#define BUILTIN(a, b, c, d, e)
#define BUILTIN_ROUTINE(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN_ROUTINE
#undef BUILTIN
#define BUILTIN(a, b, c, d, e)
#define BUILTIN_ROUTINE(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN
#undef BUILTIN_ROUTINE
#define BUILTIN_ROUTINE(a, b, c, d, e)
#define BUILTIN(builtin_id, \
#include "ecma-builtins.inc.h"
#undef BUILTIN_ROUTINE
#undef BUILTIN
#if ENABLED (JERRY_BUILTIN_ARRAY)
#endif /* ENABLED (JERRY_BUILTIN_ARRAY) */
#if ENABLED (JERRY_BUILTIN_STRING)
#endif /* ENABLED (JERRY_BUILTIN_STRING) */
#if ENABLED (JERRY_BUILTIN_NUMBER)
#endif /* ENABLED (JERRY_BUILTIN_NUMBER) */
#if ENABLED (JERRY_BUILTIN_BOOLEAN)
#endif /* ENABLED (JERRY_BUILTIN_BOOLEAN) */
#if ENABLED (JERRY_BUILTIN_DATE)
#endif /* ENABLED (JERRY_BUILTIN_DATE) */
#if ENABLED (JERRY_BUILTIN_REGEXP)
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_BUILTIN_NUMBER) */
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
