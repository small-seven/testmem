#include <assert.h>
#include <stdbool.h>
#include <getopt.h>
#include "os_support.h"
#ifndef __packed
#define __packed		__attribute__((packed))
#endif
#define KiB			1024
#define ALIGN(x, a)		__ALIGN_MASK((x), (typeof(x))(a) - 1)
#define __ALIGN_MASK(x, mask)	(((x) + (mask)) & ~(mask))
#define ARRAY_SIZE(x)		(sizeof(x) / sizeof((x)[0]))
#define min(x, y) ({				\
#define max(x, y) ({				\
#define ERROR(...) { fprintf(stderr, "E: " __VA_ARGS__); }
#define INFO(...) { if (verbose > 0) fprintf(stderr, "INFO: " __VA_ARGS__); }
#define DEBUG(...) { if (verbose > 1) fprintf(stderr, "DEBUG: " __VA_ARGS__); }
#define BPDT_SIGNATURE				(0x000055AA)
#define BPDT_HEADER_SIZE			(sizeof(struct bpdt_header))
#define BPDT_ENTRY_SIZE			(sizeof(struct bpdt_entry))
#define BPDT_MIN_SIZE			((size_t)512)
#define SUBPART_DIR_HEADER_SIZE			\
#define SUBPART_DIR_MARKER				0x44504324
#define SUBPART_DIR_HEADER_VERSION_SUPPORTED	1
#define SUBPART_DIR_ENTRY_VERSION_SUPPORTED	1
#define SUBPART_DIR_ENTRY_SIZE			\
#define DWORD_SIZE				4
#define MANIFEST_HDR_SIZE			(sizeof(struct manifest_header))
#define MANIFEST_ID_MAGIC			(0x324e4d24)
#define MODULE_SIZE				(sizeof(struct module))
#define SIGNED_PKG_INFO_EXT_TYPE		0x15
#define SIGNED_PKG_INFO_EXT_SIZE		\
#define DUMMY_IBB_SIZE			(4 * KiB)
