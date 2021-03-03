#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "ilbcdata.h"
#define LPC_N_20MS            1
#define LPC_N_30MS            2
#define LPC_N_MAX             2
#define LSF_NSPLIT            3
#define NASUB_MAX             4
#define LPC_FILTERORDER       10
#define NSUB_MAX              6
#define SUBL                  40
#define ST_MEM_L_TBL          85
#define MEM_LF_TBL            147
#define STATE_SHORT_LEN_20MS  57
#define STATE_SHORT_LEN_30MS  58
#define BLOCKL_MAX            240
#define CB_MEML               147
#define CB_NSTAGES            3
#define CB_HALFFILTERLEN      4
#define CB_FILTERLEN          8
#define ENH_NBLOCKS_TOT 8
#define ENH_BLOCKL     80
#define ENH_BUFL     (ENH_NBLOCKS_TOT)*ENH_BLOCKL
#define ENH_BUFL_FILTEROVERHEAD  3
#define BLOCKL_MAX      240
#define NSUB_20MS         4
#define NSUB_30MS         6
#define NSUB_MAX          6
#define NASUB_20MS        2
#define NASUB_30MS        4
#define NASUB_MAX         4
#define STATE_LEN        80
#define STATE_SHORT_LEN_30MS  58
#define STATE_SHORT_LEN_20MS  57
#define SPL_MUL_16_16(a, b) ((int32_t) (((int16_t)(a)) * ((int16_t)(b))))
#define SPL_MUL_16_16_RSFT(a, b, c) (SPL_MUL_16_16(a, b) >> (c))
typedef struct ILBCFrame {
    int16_t  lsf[LSF_NSPLIT*LPC_N_MAX];
    int16_t  cb_index[CB_NSTAGES*(NASUB_MAX + 1)];
    int16_t  gain_index[CB_NSTAGES*(NASUB_MAX + 1)];
    int16_t  ifm;
    int16_t  state_first;
    int16_t  idx[STATE_SHORT_LEN_30MS];
    int16_t  firstbits;
    int16_t  start;
} ILBCFrame;
typedef struct ILBCContext {
    AVClass         *class;
    int              enhancer;

    int              mode;
    GetBitContext    gb;
    ILBCFrame        frame;

    int              prev_enh_pl;
    int              consPLICount;
    int              last_lag;
    int              state_short_len;
    int              lpc_n;
    int16_t          nasub;
    int16_t          nsub;
    int              block_samples;
    int16_t          no_of_words;
    int16_t          no_of_bytes;
    int16_t          lsfdeq[LPC_FILTERORDER*LPC_N_MAX];
    int16_t          lsfold[LPC_FILTERORDER];
    int16_t          syntMem[LPC_FILTERORDER];
    int16_t          lsfdeqold[LPC_FILTERORDER];
    int16_t          weightdenum[(LPC_FILTERORDER + 1) * NSUB_MAX];
    int16_t          syntdenum[NSUB_MAX * (LPC_FILTERORDER + 1)];
    int16_t          old_syntdenum[NSUB_MAX * (LPC_FILTERORDER + 1)];
    int16_t          enh_buf[ENH_BUFL+ENH_BUFL_FILTEROVERHEAD];
    int16_t          enh_period[ENH_NBLOCKS_TOT];
    int16_t          prevResidual[NSUB_MAX*SUBL];
    int16_t          decresidual[BLOCKL_MAX];
    int16_t          plc_residual[BLOCKL_MAX + LPC_FILTERORDER];
    int16_t          seed;
    int16_t          prevPLI;
    int16_t          prevScale;
    int16_t          prevLag;
    int16_t          per_square;
    int16_t          prev_lpc[LPC_FILTERORDER + 1];
    int16_t          plc_lpc[LPC_FILTERORDER + 1];
    int16_t          hpimemx[2];
    int16_t          hpimemy[4];
} ILBCContext;
static void reverse_memcpy(int16_t *dest, int16_t *source, int length)
{
    int16_t* destPtr = dest;
    int16_t* sourcePtr = source;
    int j;

    for (j = 0; j < length; j++)
        *destPtr-- = *sourcePtr++;
}
#define SPL_SHIFT_W32(x, c) (((c) >= 0) ? ((x) << (c)) : ((x) >> (-(c))))
