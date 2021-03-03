#include "ddr3_init.h"
#include "mv_ddr_training_db.h"
#include "ddr_training_ip_db.h"
#include "mv_ddr_regs.h"
#define WL_ITERATION_NUM	10
#if defined(CONFIG_ARMADA_38X) /* JIRA #1498 for 16 bit with ECC */
#endif
#define RD_FIFO_PTR_LOW_STAT_INDIR_ADDR		0x9a
#define RD_FIFO_PTR_HIGH_STAT_INDIR_ADDR	0x9b
#define RD_FIFO_DQS_FALL_EDGE_POS_0		0x1
#define RD_FIFO_DQS_FALL_EDGE_POS_1		0x2
#define RD_FIFO_DQS_FALL_EDGE_POS_2		0x4
#define RD_FIFO_DQS_FALL_EDGE_POS_3		0x8
#define RD_FIFO_DQS_FALL_EDGE_POS_4		0x10 /* lock */
#define RD_FIFO_DQS_RISE_EDGE_POS_0		0x1fff
#define RD_FIFO_DQS_RISE_EDGE_POS_1		0x3ffe
#define RD_FIFO_DQS_RISE_EDGE_POS_2		0x3ffd
#define RD_FIFO_DQS_RISE_EDGE_POS_3		0x3ffb
#define RD_FIFO_DQS_RISE_EDGE_POS_4		0x3ff7 /* lock */
#define TEST_ADDR		0x8
#define TAPS_PER_UI		32
#define UI_PER_RD_SAMPLE	4
#define TAPS_PER_RD_SAMPLE	((UI_PER_RD_SAMPLE) * (TAPS_PER_UI))
#define MAX_RD_SAMPLES		32
#define MAX_RL_VALUE		((MAX_RD_SAMPLES) * (TAPS_PER_RD_SAMPLE))
#define RD_FIFO_DLY		8
#define STEP_SIZE		64
#define RL_JITTER_WIDTH_LMT	20
#define ADLL_TAPS_IN_CYCLE	64
