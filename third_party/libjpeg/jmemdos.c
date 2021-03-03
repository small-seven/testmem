#ifndef XMS_SUPPORTED
#define XMS_SUPPORTED  1
#endif
#ifndef EMS_SUPPORTED
#define EMS_SUPPORTED  1
#endif
#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jmemsys.h"		/* import the system-dependent declarations */
#ifndef HAVE_STDLIB_H		/* <stdlib.h> should declare these */
#endif
#ifdef NEED_FAR_POINTERS
#ifdef __TURBOC__
#include <alloc.h>		/* need farmalloc(), farfree() */
#define far_malloc(x)	farmalloc(x)
#define far_free(x)	farfree(x)
#else
#include <malloc.h>		/* need _fmalloc(), _ffree() */
#define far_malloc(x)	_fmalloc(x)
#define far_free(x)	_ffree(x)
#endif
#else /* not NEED_FAR_POINTERS */
#define far_malloc(x)	malloc(x)
#define far_free(x)	free(x)
#endif /* NEED_FAR_POINTERS */
#ifdef DONT_USE_B_MODE		/* define mode parameters for fopen() */
#define READ_BINARY	"r"
#else
#define READ_BINARY	"rb"
#endif
#ifndef USE_MSDOS_MEMMGR	/* make sure user got configuration right */
#endif
#if MAX_ALLOC_CHUNK >= 65535L	/* make sure jconfig.h got this right */
#endif
typedef void far * XMSDRIVER;	/* actually a pointer to code */
typedef struct {		/* registers for calling XMS driver */
	unsigned short ax, dx, bx;
	void far * ds_si;
      } XMScontext;
typedef struct {		/* registers for calling EMS driver */
	unsigned short ax, dx, bx;
	void far * ds_si;
      } EMScontext;
#ifndef DEFAULT_MAX_MEM		/* so can override from makefile */
#define DEFAULT_MAX_MEM		300000L /* for total usage about 450K */
#endif
#if XMS_SUPPORTED
typedef union {			/* either long offset or real-mode pointer */
	long offset;
	void far * ptr;
      } XMSPTR;
typedef struct {		/* XMS move specification structure */
	long length;
	XMSH src_handle;
	XMSPTR src;
	XMSH dst_handle;
	XMSPTR dst;
      } XMSspec;
#define ODD(X)	(((X) & 1L) != 0)
#endif /* XMS_SUPPORTED */
#if EMS_SUPPORTED
typedef void far * EMSPTR;

typedef union {			/* EMS move specification structure */
	long length;		/* It's easy to access first 4 bytes */
	char bytes[18];		/* Misaligned fields in here! */
      } EMSspec;
#define FIELD_AT(spec,offset,type)  (*((type *) &(spec.bytes[offset])))
#define SRC_TYPE(spec)		FIELD_AT(spec,4,char)
#define SRC_HANDLE(spec)	FIELD_AT(spec,5,EMSH)
#define SRC_OFFSET(spec)	FIELD_AT(spec,7,unsigned short)
#define SRC_PAGE(spec)		FIELD_AT(spec,9,unsigned short)
#define SRC_PTR(spec)		FIELD_AT(spec,7,EMSPTR)
#define DST_TYPE(spec)		FIELD_AT(spec,11,char)
#define DST_HANDLE(spec)	FIELD_AT(spec,12,EMSH)
#define DST_OFFSET(spec)	FIELD_AT(spec,14,unsigned short)
#define DST_PAGE(spec)		FIELD_AT(spec,16,unsigned short)
#define DST_PTR(spec)		FIELD_AT(spec,14,EMSPTR)
#define EMSPAGESIZE	16384L	/* gospel, see the EMS specs */
#define HIBYTE(W)  (((W) >> 8) & 0xFF)
#define LOBYTE(W)  ((W) & 0xFF)
#endif /* EMS_SUPPORTED */
#if XMS_SUPPORTED
#endif
#if EMS_SUPPORTED
#endif
#ifdef NEED_FHEAPMIN
#endif
