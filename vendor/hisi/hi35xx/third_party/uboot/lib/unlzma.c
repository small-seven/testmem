#define uint8_t       unsigned char
#define uint16_t      unsigned short
#define uint32_t      unsigned int
#define uint64_t      unsigned long long
#define size_t        unsigned long
#define int32_t       int
#define NULL          ((void *)0)
#define	MIN(a, b) (((a) < (b)) ? (a) : (b))
#define ENDIAN_CONVERT(x) \
#define LZMA_IOBUF_SIZE	0x10000
#define RC_TOP_BITS 24
#define RC_MOVE_BITS 5
#define RC_MODEL_TOTAL_BITS 11
#define LZMA_BASE_SIZE 1846
#define LZMA_LIT_SIZE 768
#define LZMA_NUM_POS_BITS_MAX 4
#define LZMA_LEN_NUM_LOW_BITS 3
#define LZMA_LEN_NUM_MID_BITS 3
#define LZMA_LEN_NUM_HIGH_BITS 8
#define LZMA_LEN_CHOICE 0
#define LZMA_LEN_CHOICE_2 (LZMA_LEN_CHOICE + 1)
#define LZMA_LEN_LOW (LZMA_LEN_CHOICE_2 + 1)
#define LZMA_LEN_MID (LZMA_LEN_LOW \
#define LZMA_LEN_HIGH (LZMA_LEN_MID \
#define LZMA_NUM_LEN_PROBS (LZMA_LEN_HIGH + (1 << LZMA_LEN_NUM_HIGH_BITS))
#define LZMA_NUM_STATES 12
#define LZMA_NUM_LIT_STATES 7
#define LZMA_START_POS_MODEL_INDEX 4
#define LZMA_END_POS_MODEL_INDEX 14
#define LZMA_NUM_FULL_DISTANCES (1 << (LZMA_END_POS_MODEL_INDEX >> 1))
#define LZMA_NUM_POS_SLOT_BITS 6
#define LZMA_NUM_LEN_TO_POS_STATES 4
#define LZMA_NUM_ALIGN_BITS 4
#define LZMA_MATCH_MIN_LEN 2
#define LZMA_IS_MATCH 0
#define LZMA_IS_REP (LZMA_IS_MATCH + (LZMA_NUM_STATES << LZMA_NUM_POS_BITS_MAX))
#define LZMA_IS_REP_G0 (LZMA_IS_REP + LZMA_NUM_STATES)
#define LZMA_IS_REP_G1 (LZMA_IS_REP_G0 + LZMA_NUM_STATES)
#define LZMA_IS_REP_G2 (LZMA_IS_REP_G1 + LZMA_NUM_STATES)
#define LZMA_IS_REP_0_LONG (LZMA_IS_REP_G2 + LZMA_NUM_STATES)
#define LZMA_POS_SLOT (LZMA_IS_REP_0_LONG \
#define LZMA_SPEC_POS (LZMA_POS_SLOT \
#define LZMA_ALIGN (LZMA_SPEC_POS \
#define LZMA_LEN_CODER (LZMA_ALIGN + (1 << LZMA_NUM_ALIGN_BITS))
#define LZMA_REP_LEN_CODER (LZMA_LEN_CODER + LZMA_NUM_LEN_PROBS)
#define LZMA_LITERAL (LZMA_REP_LEN_CODER + LZMA_NUM_LEN_PROBS)
