#include <config.h>
#include <linux/stddef.h>
#include <jffs2/jffs2.h>
#include <jffs2/compr_rubin.h>
typedef unsigned long lzo_ptr_t;
typedef long lzo_sptr_t;

/* data type definitions */
#define U32 unsigned long
#define S32 signed long
#define I32 long
#define U16 unsigned short
#define S16 signed short
#define I16 short
#define U8 unsigned char
#define S8 signed char
#define I8 char

#define M1_MAX_OFFSET	0x0400
#define M2_MAX_OFFSET	0x0800
#define M3_MAX_OFFSET	0x4000
#define M4_MAX_OFFSET	0xbfff

#define __COPY4(dst,src)  * (lzo_uint32p)(dst) = * (const lzo_uint32p)(src)
#define COPY4(dst,src)	__COPY4((lzo_ptr_t)(dst),(lzo_ptr_t)(src))

#define TEST_IP		(ip < ip_end)
#define TEST_OP		(op <= op_end)

#define NEED_IP(x) \
	    if ((lzo_uint)(ip_end - ip) < (lzo_uint)(x))  goto input_overrun
#define NEED_OP(x) \
	    if ((lzo_uint)(op_end - op) < (lzo_uint)(x))  goto output_overrun
#define TEST_LOOKBEHIND(m_pos,out)    if (m_pos < out) goto lookbehind_overrun

typedef U32 lzo_uint32;
typedef I32 lzo_int32;
typedef U32 lzo_uint;
typedef I32 lzo_int;
typedef int lzo_bool;

#define lzo_byte		U8
#define lzo_bytep		U8 *
#define lzo_charp		char *
#define lzo_voidp		void *
#define lzo_shortp		short *
#define lzo_ushortp		unsigned short *
#define lzo_uint32p		lzo_uint32 *
#define lzo_int32p		lzo_int32 *
#define lzo_uintp		lzo_uint *
#define lzo_intp		lzo_int *
#define lzo_voidpp		lzo_voidp *
#define lzo_bytepp		lzo_bytep *
#define lzo_sizeof_dict_t		sizeof(lzo_bytep)

#define LZO_E_OK		    0
#define LZO_E_ERROR		    (-1)
#define LZO_E_OUT_OF_MEMORY	    (-2)	/* not used right now */
#define LZO_E_NOT_COMPRESSIBLE	    (-3)	/* not used right now */
#define LZO_E_INPUT_OVERRUN	    (-4)
#define LZO_E_OUTPUT_OVERRUN	    (-5)
#define LZO_E_LOOKBEHIND_OVERRUN    (-6)
#define LZO_E_EOF_NOT_FOUND	    (-7)
#define LZO_E_INPUT_NOT_CONSUMED    (-8)

#define PTR(a)				((lzo_ptr_t) (a))
#define PTR_LINEAR(a)		PTR(a)
#define PTR_ALIGNED_4(a)	((PTR_LINEAR(a) & 3) == 0)
#define PTR_ALIGNED_8(a)	((PTR_LINEAR(a) & 7) == 0)
#define PTR_ALIGNED2_4(a,b)	(((PTR_LINEAR(a) | PTR_LINEAR(b)) & 3) == 0)
#define PTR_ALIGNED2_8(a,b)	(((PTR_LINEAR(a) | PTR_LINEAR(b)) & 7) == 0)
#define PTR_LT(a,b)			(PTR(a) < PTR(b))
#define PTR_GE(a,b)			(PTR(a) >= PTR(b))
#define PTR_DIFF(a,b)		((lzo_ptrdiff_t) (PTR(a) - PTR(b)))
#define pd(a,b)			((lzo_uint) ((a)-(b)))

typedef ptrdiff_t lzo_ptrdiff_t;

static int
lzo1x_decompress (const lzo_byte * in, lzo_uint in_len,
		  lzo_byte * out, lzo_uintp out_len, lzo_voidp wrkmem)
{
	register lzo_byte *op;
	register const lzo_byte *ip;
	register lzo_uint t;

	register const lzo_byte *m_pos;

	const lzo_byte *const ip_end = in + in_len;
	lzo_byte *const op_end = out + *out_len;

	*out_len = 0;

	op = out;
	ip = in;

	if (*ip > 17)
	{
		t = *ip++ - 17;
		if (t < 4)
			goto match_next;
		NEED_OP (t);
		NEED_IP (t + 1);
		do
			*op++ = *ip++;
		while (--t > 0);
		goto first_literal_run;
	}
