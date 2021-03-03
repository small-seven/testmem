#ifndef ZSTD_MAXWINDOWSIZE_DEFAULT
#define ZSTD_MAXWINDOWSIZE_DEFAULT ((1 << ZSTD_WINDOWLOG_MAX) + 1) /* defined within zstd.h */
#endif
#include "fse.h"
#include "huf.h"
#include "mem.h" /* low level memory routines */
#include "zstd_internal.h"
#include <linux/kernel.h>
#include <linux/compat.h>
#include <linux/string.h> /* memcpy, memmove, memset */
#define ZSTD_PREFETCH(ptr) __builtin_prefetch(ptr, 0, 0)
#define ZSTD_isError ERR_isError /* for inlining */
#define FSE_isError ERR_isError
#define HUF_isError ERR_isError
typedef enum {
	ZSTDds_getFrameHeaderSize,
	ZSTDds_decodeFrameHeader,
	ZSTDds_decodeBlockHeader,
	ZSTDds_decompressBlock,
	ZSTDds_decompressLastBlock,
	ZSTDds_checkChecksum,
	ZSTDds_decodeSkippableHeader,
	ZSTDds_skipFrame
} ZSTD_dStage;
typedef struct {
	FSE_DTable LLTable[FSE_DTABLE_SIZE_U32(LLFSELog)];
	FSE_DTable OFTable[FSE_DTABLE_SIZE_U32(OffFSELog)];
	FSE_DTable MLTable[FSE_DTABLE_SIZE_U32(MLFSELog)];
	HUF_DTable hufTable[HUF_DTABLE_SIZE(HufLog)]; /* can accommodate HUF_decompress4X */
	U64 workspace[HUF_DECOMPRESS_WORKSPACE_SIZE_U32 / 2];
	U32 rep[ZSTD_REP_NUM];
} ZSTD_entropyTables_t;
}; /* typedef'd to ZSTD_DCtx within "zstd.h" */

size_t ZSTD_DCtxWorkspaceBound(void) { return ZSTD_ALIGN(sizeof(ZSTD_stack)) + ZSTD_ALIGN(sizeof(ZSTD_DCtx)); }
typedef struct {
	blockType_e blockType;
	U32 lastBlock;
	U32 origSize;
} blockProperties_t;
typedef union {
	FSE_decode_t realData;
	U32 alignedBy4;
} FSE_decode_t4;
typedef struct {
	size_t litLength;
	size_t matchLength;
	size_t offset;
	const BYTE *match;
} seq_t;
typedef struct {
	BIT_DStream_t DStream;
	FSE_DState_t stateLL;
	FSE_DState_t stateOffb;
	FSE_DState_t stateML;
	size_t prevOffset[ZSTD_REP_NUM];
	const BYTE *base;
	size_t pos;
	uPtrDiff gotoDict;
} seqState_t;
#define STORED_SEQS 4
#define STOSEQ_MASK (STORED_SEQS - 1)
#define ADVANCED_SEQS 4
}; /* typedef'd to ZSTD_DDict within "zstd.h" */

size_t ZSTD_DDictWorkspaceBound(void) { return ZSTD_ALIGN(sizeof(ZSTD_stack)) + ZSTD_ALIGN(sizeof(ZSTD_DDict)); }
typedef enum { zdss_init, zdss_loadHeader, zdss_read, zdss_load, zdss_flush } ZSTD_dStreamStage;

/* *** Resource management *** */
struct ZSTD_DStream_s {
	ZSTD_DCtx *dctx;
	ZSTD_DDict *ddictLocal;
	const ZSTD_DDict *ddict;
	ZSTD_frameParams fParams;
	ZSTD_dStreamStage stage;
	char *inBuff;
	size_t inBuffSize;
	size_t inPos;
	size_t maxWindowSize;
	char *outBuff;
	size_t outBuffSize;
	size_t outStart;
	size_t outEnd;
	size_t blockSize;
	BYTE headerBuffer[ZSTD_FRAMEHEADERSIZE_MAX]; /* tmp buffer to store frame header */
	size_t lhSize;
	ZSTD_customMem customMem;
	void *legacyContext;
	U32 previousLegacyVersion;
	U32 legacyVersion;
	U32 hostageByte;
}; /* typedef'd to ZSTD_DStream within "zstd.h" */
