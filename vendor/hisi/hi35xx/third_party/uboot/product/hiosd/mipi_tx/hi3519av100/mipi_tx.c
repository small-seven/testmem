#include "mipi_tx.h"
#include <common.h>
#include "type.h"
#include "mipi_tx_hal.h"
#include "hi3519av100_vo.h"
#define MIPI_TX_DEV_NAME  "hi_mipi_tx"
#define MIPI_TX_PROC_NAME "mipi_tx"
#define HIMEDIA_DYNAMIC_MINOR 255
typedef struct {
    combo_dev_cfg_t dev_cfg;
} mipi_tx_dev_ctx_t;
