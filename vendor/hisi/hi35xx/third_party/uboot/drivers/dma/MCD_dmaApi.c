#include <common.h>
#include <MCD_dma.h>
#include <MCD_tasksInit.h>
#include <MCD_progCheck.h>
#ifdef MCD_INCLUDE_EU
#else
#endif
#define DBG_CTL_COMP1_TASK	(0x00002000)
#define DBG_CTL_ENABLE		(DBG_CTL_AUTO_ARM	| \
#define DBG_CTL_DISABLE		(DBG_CTL_AUTO_ARM	| \
#define DBG_KILL_ALL_STAT	(0xFFFFFFFF)
#define CSAVE_OFFSET		10
#define MCD_BYTE_SWAP_KILLER	0xFFF8888F
#define MCD_NO_BYTE_SWAP_ATALL	0x00040000
#define MAC			0	/* legacy - not used */
#define LUAC			1	/* legacy - not used */
#define CRC			2	/* legacy - not used */
#define LURC			3	/* Logic Unit with CRC */
#define TASK_CHAINNOEU		0
#define TASK_SINGLENOEU		1
#ifdef MCD_INCLUDE_EU
#define TASK_CHAINEU		2
#define TASK_SINGLEEU		3
#define TASK_FECRX		4
#define TASK_FECTX		5
#else
#define TASK_CHAINEU		0
#define TASK_SINGLEEU		1
#define TASK_FECRX		2
#define TASK_FECTX		3
#endif
typedef struct MCD_remVariants_struct MCD_remVariant;
struct MCD_remVariants_struct {
	int remDestRsdIncr[NCHANNELS];	/* -1,0,1 */
	int remSrcRsdIncr[NCHANNELS];	/* -1,0,1 */
	s16 remDestIncr[NCHANNELS];	/* DestIncr */
	s16 remSrcIncr[NCHANNELS];	/* srcIncr */
	u32 remXferSize[NCHANNELS];	/* xferSize */
};
#ifdef MCD_INCLUDE_EU
#endif
#ifdef MCD_INCLUDE_EU
#else
#endif
#ifdef MCD_NEED_ADDR_TRANS
#endif
#ifdef MCD_INCLUDE_EU
#endif
#ifndef MCD_INCLUDE_EU
#endif
#ifdef MCD_DEBUG
#endif
#if 1
#endif
#ifdef MCD_INCLUDE_EU
#endif
#if 1
#else
#endif
#define STABTIME 0
#ifdef MCD_INCLUDE_EU
#else
#endif
#ifdef MCD_INCLUDE_EU
#else
#endif
#define MCD_REV_MAJOR   0x00
#define MCD_REV_MINOR   0x03
static void MCD_memcpy(int *dest, int *src, u32 size)
{
	u32 i;

	for (i = 0; i < size; i += sizeof(int), dest++, src++)
		*dest = *src;
}
