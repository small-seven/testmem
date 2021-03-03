#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <linux/asn1_ber_bytecode.h>
#define _(X) [DIRECTIVE_##X] = #X
#define verbose(fmt, ...) do { if (verbose_opt) printf(fmt, ## __VA_ARGS__); } while (0)
#define debug(fmt, ...) do { if (debug_opt) printf(fmt, ## __VA_ARGS__); } while (0)
#if 0
#endif
#define ELEMENT_IMPLICIT	0x0001
#define ELEMENT_EXPLICIT	0x0002
#define ELEMENT_TAG_SPECIFIED	0x0004
#define ELEMENT_RENDERED	0x0008
#define ELEMENT_SKIPPABLE	0x0010
#define ELEMENT_CONDITIONAL	0x0020
#define TYPE_STOP_MARKER	0x0001
#define TYPE_BEGIN		0x0002
#if 0
#endif
