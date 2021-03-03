#define FORCE_INLINE static __always_inline
#include "bitstream.h"
#include "fse.h"
#include <linux/compiler.h>
#include <linux/kernel.h>
#include <linux/string.h> /* memcpy, memset */
#define FSE_isError ERR_isError
#define FSE_STATIC_ASSERT(c)                                   \
#define CHECK_F(f)                  \
#ifndef FSE_FUNCTION_EXTENSION
#error "FSE_FUNCTION_EXTENSION must be defined"
#endif
#ifndef FSE_FUNCTION_TYPE
#error "FSE_FUNCTION_TYPE must be defined"
#endif
#define FSE_CAT(X, Y) X##Y
#define FSE_FUNCTION_NAME(X, Y) FSE_CAT(X, Y)
#define FSE_TYPE_NAME(X, Y) FSE_CAT(X, Y)
#define FSE_GETSYMBOL(statePtr) fast ? FSE_decodeSymbolFast(statePtr, &bitD) : FSE_decodeSymbol(statePtr, &bitD)
