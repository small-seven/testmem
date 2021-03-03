#include <common.h>
#include <compiler.h>
typedef unsigned char           hi_u8;
typedef unsigned char           hi_uchar;
typedef unsigned short          hi_u16;
typedef unsigned int            hi_u32;
typedef unsigned long           hi_ul;

typedef char                    hi_s8;
typedef short                   hi_s16;
typedef int                     hi_s32;

typedef char                    hi_char;
typedef char                   *hi_pchar;


#define CYCLE_MAGIC_HEAD        0x6379636c

#define CYCLE_MAGIC_ITEM_START  0x63796373

#define CYCLE_MAGIC_ITEM_END    0x63796365

/** Cycle Head Infomation */
typedef struct hicycle_head_s {
	hi_u32 u32magichead;
	hi_u32 u32cycleflashsize; /**<include cycle_head size */
	hi_u32 u32compress: 2;
	hi_u32 u32writeflag: 3;
	hi_u32 u32reserved: 27;
	hi_u32 u32alignsize;
} hi_cycle_head_s;
typedef struct hicycle_item_start_s {
	hi_u32 u32magicitemstart;
	hi_u32 u32itemlen;
	hi_u32 u32itemalllen;
	hi_u32 u32itemoriginlen;
} hi_cycle_item_start_s;
#define DIVIDE 3
#define BYTE_ALIGN ((hi_u32)16)  /**<needed by decompress */
#if (defined CONFIG_TARGET_HI3559AV100) || (defined CONFIG_HI3559AV100) ||\
#endif
#if ((defined CONFIG_TARGET_HI3559V200) || (defined CONFIG_TARGET_HI3556V200) ||\
#endif
#define cycle_err(fmt, args...) printf("ERR: <%s:%d> "fmt, __FUNCTION__,\
#define cycle_dbg(fmt, args...) printf("DBG: <%s:%d> "fmt, __FUNCTION__,\
#if (defined CONFIG_TARGET_HI3559AV100) || (defined CONFIG_HI3559AV100) || \
#endif
#if ((defined CONFIG_TARGET_HI3559V200) || (defined CONFIG_TARGET_HI3556V200) || \
#endif
