#include <common.h>
#include <clk.h>
#include <dm.h>
#include <i2c.h>
#include <wait_bit.h>
#include <asm/io.h>
#define XIIC_MSB_OFFSET 0
#define XIIC_REG_OFFSET (0x100+XIIC_MSB_OFFSET)
#define XIIC_CR_REG_OFFSET   (0x00+XIIC_REG_OFFSET)	/* Control Register   */
#define XIIC_SR_REG_OFFSET   (0x04+XIIC_REG_OFFSET)	/* Status Register    */
#define XIIC_DTR_REG_OFFSET  (0x08+XIIC_REG_OFFSET)	/* Data Tx Register   */
#define XIIC_DRR_REG_OFFSET  (0x0C+XIIC_REG_OFFSET)	/* Data Rx Register   */
#define XIIC_ADR_REG_OFFSET  (0x10+XIIC_REG_OFFSET)	/* Address Register   */
#define XIIC_TFO_REG_OFFSET  (0x14+XIIC_REG_OFFSET)	/* Tx FIFO Occupancy  */
#define XIIC_RFO_REG_OFFSET  (0x18+XIIC_REG_OFFSET)	/* Rx FIFO Occupancy  */
#define XIIC_TBA_REG_OFFSET  (0x1C+XIIC_REG_OFFSET)	/* 10 Bit Address reg */
#define XIIC_RFD_REG_OFFSET  (0x20+XIIC_REG_OFFSET)	/* Rx FIFO Depth reg  */
#define XIIC_GPO_REG_OFFSET  (0x24+XIIC_REG_OFFSET)	/* Output Register    */
#define XIIC_CR_ENABLE_DEVICE_MASK        0x01	/* Device enable = 1      */
#define XIIC_CR_TX_FIFO_RESET_MASK        0x02	/* Transmit FIFO reset=1  */
#define XIIC_CR_MSMS_MASK                 0x04	/* Master starts Txing=1  */
#define XIIC_CR_DIR_IS_TX_MASK            0x08	/* Dir of tx. Txing=1     */
#define XIIC_CR_NO_ACK_MASK               0x10	/* Tx Ack. NO ack = 1     */
#define XIIC_CR_REPEATED_START_MASK       0x20	/* Repeated start = 1     */
#define XIIC_CR_GENERAL_CALL_MASK         0x40	/* Gen Call enabled = 1   */
#define XIIC_SR_GEN_CALL_MASK             0x01	/* 1=a mstr issued a GC   */
#define XIIC_SR_ADDR_AS_SLAVE_MASK        0x02	/* 1=when addr as slave   */
#define XIIC_SR_BUS_BUSY_MASK             0x04	/* 1 = bus is busy        */
#define XIIC_SR_MSTR_RDING_SLAVE_MASK     0x08	/* 1=Dir: mstr <-- slave  */
#define XIIC_SR_TX_FIFO_FULL_MASK         0x10	/* 1 = Tx FIFO full       */
#define XIIC_SR_RX_FIFO_FULL_MASK         0x20	/* 1 = Rx FIFO full       */
#define XIIC_SR_RX_FIFO_EMPTY_MASK        0x40	/* 1 = Rx FIFO empty      */
#define XIIC_SR_TX_FIFO_EMPTY_MASK        0x80	/* 1 = Tx FIFO empty      */
#define XIIC_INTR_ARB_LOST_MASK           0x01	/* 1 = arbitration lost   */
#define XIIC_INTR_TX_ERROR_MASK           0x02	/* 1=Tx error/msg complete */
#define XIIC_INTR_TX_EMPTY_MASK           0x04	/* 1 = Tx FIFO/reg empty  */
#define XIIC_INTR_RX_FULL_MASK            0x08	/* 1=Rx FIFO/reg=OCY level */
#define XIIC_INTR_BNB_MASK                0x10	/* 1 = Bus not busy       */
#define XIIC_INTR_AAS_MASK                0x20	/* 1 = when addr as slave */
#define XIIC_INTR_NAAS_MASK               0x40	/* 1 = not addr as slave  */
#define XIIC_INTR_TX_HALF_MASK            0x80	/* 1 = TX FIFO half empty */
#define IIC_RX_FIFO_DEPTH         16	/* Rx fifo capacity               */
#define IIC_TX_FIFO_DEPTH         16	/* Tx fifo capacity               */
#define XIIC_TX_DYN_START_MASK            0x0100 /* 1 = Set dynamic start */
#define XIIC_TX_DYN_STOP_MASK             0x0200 /* 1 = Set dynamic stop */
#define XIIC_DGIER_OFFSET    0x1C /* Device Global Interrupt Enable Register */
#define XIIC_IISR_OFFSET     0x20 /* Interrupt Status Register */
#define XIIC_IIER_OFFSET     0x28 /* Interrupt Enable Register */
#define XIIC_RESETR_OFFSET   0x40 /* Reset Register */
#define XIIC_RESET_MASK             0xAUL
