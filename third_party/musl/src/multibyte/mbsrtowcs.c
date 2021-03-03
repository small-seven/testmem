#include <stdint.h>
#include <wchar.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "internal.h"
#ifdef __GNUC__
		typedef uint32_t __attribute__((__may_alias__)) w32;
		if (*s-1u < 0x7f && (uintptr_t)s%4 == 0) {
			while (!(( *(w32*)s | *(w32*)s-0x01010101) & 0x80808080)) {
				s += 4;
				wn -= 4;
			}
#endif
#ifdef __GNUC__
		typedef uint32_t __attribute__((__may_alias__)) w32;
		if (*s-1u < 0x7f && (uintptr_t)s%4 == 0) {
			while (wn>=5 && !(( *(w32*)s | *(w32*)s-0x01010101) & 0x80808080)) {
				*ws++ = *s++;
				*ws++ = *s++;
				*ws++ = *s++;
				*ws++ = *s++;
				wn -= 4;
			}
#endif
