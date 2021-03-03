#include "js-parser-internal.h"
#if ENABLED (JERRY_PARSER)
#define CBC_OPCODE(arg1, arg2, arg3, arg4) \
#undef CBC_OPCODE
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#define CBC_OPCODE(arg1, arg2, arg3, arg4) #arg1,
#undef CBC_OPCODE
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#endif /* ENABLED (JERRY_PARSER) */
