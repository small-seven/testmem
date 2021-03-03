#define FORCE_INLINE static __always_inline
#include "bitstream.h" /* BIT_* */
#include "fse.h"       /* header compression */
#include "huf.h"
#include <linux/compiler.h>
#include <linux/kernel.h>
#include <linux/string.h> /* memcpy, memset */
#define HUF_STATIC_ASSERT(c)                                   \
typedef struct {
	BYTE maxTableLog;
	BYTE tableType;
	BYTE tableLog;
	BYTE reserved;
} DTableDesc;
typedef struct {
	BYTE byte;
	BYTE nbBits;
} HUF_DEltX2; /* single-symbol decoding */
#define HUF_DECODE_SYMBOLX2_0(ptr, DStreamPtr) *ptr++ = HUF_decodeSymbolX2(DStreamPtr, dt, dtLog)
#define HUF_DECODE_SYMBOLX2_1(ptr, DStreamPtr)         \
#define HUF_DECODE_SYMBOLX2_2(ptr, DStreamPtr) \
typedef struct {
	U16 sequence;
	BYTE nbBits;
	BYTE length;
} HUF_DEltX4; /* double-symbols decoding */
typedef struct {
	BYTE symbol;
	BYTE weight;
} sortedSymbol_t;
typedef U32 rankVal_t[HUF_TABLELOG_MAX][HUF_TABLELOG_MAX + 1];
typedef U32 rankValCol_t[HUF_TABLELOG_MAX + 1];

static void HUF_fillDTableX4(HUF_DEltX4 *DTable, const U32 targetLog, const sortedSymbol_t *sortedList, const U32 sortedListSize, const U32 *rankStart,
			     rankVal_t rankValOrigin, const U32 maxWeight, const U32 nbBitsBaseline)
{
	U32 rankVal[HUF_TABLELOG_MAX + 1];
	const int scaleLog = nbBitsBaseline - targetLog; /* note : targetLog >= srcLog, hence scaleLog <= 1 */
	const U32 minBits = nbBitsBaseline - maxWeight;
	U32 s;

	memcpy(rankVal, rankValOrigin, sizeof(rankVal));

	/* fill DTable */
	for (s = 0; s < sortedListSize; s++) {
		const U16 symbol = sortedList[s].symbol;
		const U32 weight = sortedList[s].weight;
		const U32 nbBits = nbBitsBaseline - weight;
		const U32 start = rankVal[weight];
		const U32 length = 1 << (targetLog - nbBits);

		if (targetLog - nbBits >= minBits) { /* enough room for a second symbol */
			U32 sortedRank;
			int minWeight = nbBits + scaleLog;
			if (minWeight < 1)
				minWeight = 1;
			sortedRank = rankStart[minWeight];
			HUF_fillDTableX4Level2(DTable + start, targetLog - nbBits, nbBits, rankValOrigin[nbBits], minWeight, sortedList + sortedRank,
					       sortedListSize - sortedRank, nbBitsBaseline, symbol);
		} else {
#define HUF_DECODE_SYMBOLX4_0(ptr, DStreamPtr) ptr += HUF_decodeSymbolX4(ptr, DStreamPtr, dt, dtLog)
#define HUF_DECODE_SYMBOLX4_1(ptr, DStreamPtr)         \
#define HUF_DECODE_SYMBOLX4_2(ptr, DStreamPtr) \
typedef struct {
	U32 tableTime;
	U32 decode256Time;
} algo_time_t;
typedef size_t (*decompressionAlgo)(void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize);

size_t HUF_decompress4X_DCtx_wksp(HUF_DTable *dctx, void *dst, size_t dstSize, const void *cSrc, size_t cSrcSize, void *workspace, size_t workspaceSize)
{
	/* validation checks */
	if (dstSize == 0)
		return ERROR(dstSize_tooSmall);
	if (cSrcSize > dstSize)
		return ERROR(corruption_detected); /* invalid */
	if (cSrcSize == dstSize) {
		memcpy(dst, cSrc, dstSize);
		return dstSize;
	} /* not compressed */
