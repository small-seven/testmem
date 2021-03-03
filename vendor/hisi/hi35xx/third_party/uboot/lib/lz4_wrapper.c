#include <common.h>
#include <compiler.h>
#include <image.h>
#include <lz4.h>
#include <linux/kernel.h>
#include <linux/types.h>
typedef  uint8_t BYTE;
typedef uint16_t U16;
typedef uint32_t U32;
typedef  int32_t S32;
typedef uint64_t U64;

#define FORCE_INLINE static inline __attribute__((always_inline))

/* Unaltered (except removing unrelated code) from github.com/Cyan4973/lz4. */
#include "lz4.c"	/* #include for inlining, do not link! */

struct lz4_frame_header {
	u32 magic;
	union {
		u8 flags;
		struct {
			u8 reserved0:2;
			u8 has_content_checksum:1;
			u8 has_content_size:1;
			u8 has_block_checksum:1;
			u8 independent_blocks:1;
			u8 version:2;
		};
