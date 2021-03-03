#include <common.h>
#include <linux/lzo.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include "lzodefs.h"
#define HAVE_IP(x, ip_end, ip) ((size_t)(ip_end - ip) < (x))
#define HAVE_OP(x, op_end, op) ((size_t)(op_end - op) < (x))
#define HAVE_LB(m_pos, out, op) (m_pos < out || m_pos >= op)
#define COPY4(dst, src)	\
#define HEADER_HAS_FILTER	0x00000800L
