#ifdef GUNZIP
#endif
#ifdef GUNZIP
#  define UPDATE(check, buf, len) \
#else
#  define UPDATE(check, buf, len) adler32(check, buf, len)
#endif
#ifdef GUNZIP
#  define CRC2(check, word) \
#  define CRC4(check, word) \
#endif
#define LOAD() \
#define RESTORE() \
#define INITBITS() \
#define PULLBYTE() \
#define NEEDBITS(n) \
#define BITS(n) \
#define DROPBITS(n) \
#define BYTEBITS() \
#define REVERSE(q) \
#ifdef GUNZIP
#endif
#ifdef GUNZIP
#else
#endif
#ifdef GUNZIP
#endif
#ifndef PKZIP_BUG_WORKAROUND
#endif
#ifdef INFLATE_STRICT
#endif
#ifdef GUNZIP
#endif
#ifdef GUNZIP
#endif
