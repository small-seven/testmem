#include <asm/io.h>
#include <clk.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#include <linux/ioport.h>
#include <mach/clk.h>
#include <spi.h>
#include <spi-mem.h>
#define QSPI_CR      0x0000  /* Control Register */
#define QSPI_MR      0x0004  /* Mode Register */
#define QSPI_RD      0x0008  /* Receive Data Register */
#define QSPI_TD      0x000c  /* Transmit Data Register */
#define QSPI_SR      0x0010  /* Status Register */
#define QSPI_IER     0x0014  /* Interrupt Enable Register */
#define QSPI_IDR     0x0018  /* Interrupt Disable Register */
#define QSPI_IMR     0x001c  /* Interrupt Mask Register */
#define QSPI_SCR     0x0020  /* Serial Clock Register */
#define QSPI_IAR     0x0030  /* Instruction Address Register */
#define QSPI_ICR     0x0034  /* Instruction Code Register */
#define QSPI_WICR    0x0034  /* Write Instruction Code Register */
#define QSPI_IFR     0x0038  /* Instruction Frame Register */
#define QSPI_RICR    0x003C  /* Read Instruction Code Register */
#define QSPI_SMR     0x0040  /* Scrambling Mode Register */
#define QSPI_SKR     0x0044  /* Scrambling Key Register */
#define QSPI_WPMR    0x00E4  /* Write Protection Mode Register */
#define QSPI_WPSR    0x00E8  /* Write Protection Status Register */
#define QSPI_VERSION 0x00FC  /* Version Register */
#define QSPI_CR_QSPIEN                  BIT(0)
#define QSPI_CR_QSPIDIS                 BIT(1)
#define QSPI_CR_SWRST                   BIT(7)
#define QSPI_CR_LASTXFER                BIT(24)
#define QSPI_MR_SMM                     BIT(0)
#define QSPI_MR_LLB                     BIT(1)
#define QSPI_MR_WDRBT                   BIT(2)
#define QSPI_MR_SMRM                    BIT(3)
#define QSPI_MR_CSMODE_MASK             GENMASK(5, 4)
#define QSPI_MR_CSMODE_NOT_RELOADED     (0 << 4)
#define QSPI_MR_CSMODE_LASTXFER         (1 << 4)
#define QSPI_MR_CSMODE_SYSTEMATICALLY   (2 << 4)
#define QSPI_MR_NBBITS_MASK             GENMASK(11, 8)
#define QSPI_MR_NBBITS(n)               ((((n) - 8) << 8) & QSPI_MR_NBBITS_MASK)
#define QSPI_MR_DLYBCT_MASK             GENMASK(23, 16)
#define QSPI_MR_DLYBCT(n)               (((n) << 16) & QSPI_MR_DLYBCT_MASK)
#define QSPI_MR_DLYCS_MASK              GENMASK(31, 24)
#define QSPI_MR_DLYCS(n)                (((n) << 24) & QSPI_MR_DLYCS_MASK)
#define QSPI_SR_RDRF                    BIT(0)
#define QSPI_SR_TDRE                    BIT(1)
#define QSPI_SR_TXEMPTY                 BIT(2)
#define QSPI_SR_OVRES                   BIT(3)
#define QSPI_SR_CSR                     BIT(8)
#define QSPI_SR_CSS                     BIT(9)
#define QSPI_SR_INSTRE                  BIT(10)
#define QSPI_SR_QSPIENS                 BIT(24)
#define QSPI_SR_CMD_COMPLETED	(QSPI_SR_INSTRE | QSPI_SR_CSR)
#define QSPI_SCR_CPOL                   BIT(0)
#define QSPI_SCR_CPHA                   BIT(1)
#define QSPI_SCR_SCBR_MASK              GENMASK(15, 8)
#define QSPI_SCR_SCBR(n)                (((n) << 8) & QSPI_SCR_SCBR_MASK)
#define QSPI_SCR_DLYBS_MASK             GENMASK(23, 16)
#define QSPI_SCR_DLYBS(n)               (((n) << 16) & QSPI_SCR_DLYBS_MASK)
#define QSPI_ICR_INST_MASK              GENMASK(7, 0)
#define QSPI_ICR_INST(inst)             (((inst) << 0) & QSPI_ICR_INST_MASK)
#define QSPI_ICR_OPT_MASK               GENMASK(23, 16)
#define QSPI_ICR_OPT(opt)               (((opt) << 16) & QSPI_ICR_OPT_MASK)
#define QSPI_IFR_WIDTH_MASK             GENMASK(2, 0)
#define QSPI_IFR_WIDTH_SINGLE_BIT_SPI   (0 << 0)
#define QSPI_IFR_WIDTH_DUAL_OUTPUT      (1 << 0)
#define QSPI_IFR_WIDTH_QUAD_OUTPUT      (2 << 0)
#define QSPI_IFR_WIDTH_DUAL_IO          (3 << 0)
#define QSPI_IFR_WIDTH_QUAD_IO          (4 << 0)
#define QSPI_IFR_WIDTH_DUAL_CMD         (5 << 0)
#define QSPI_IFR_WIDTH_QUAD_CMD         (6 << 0)
#define QSPI_IFR_INSTEN                 BIT(4)
#define QSPI_IFR_ADDREN                 BIT(5)
#define QSPI_IFR_OPTEN                  BIT(6)
#define QSPI_IFR_DATAEN                 BIT(7)
#define QSPI_IFR_OPTL_MASK              GENMASK(9, 8)
#define QSPI_IFR_OPTL_1BIT              (0 << 8)
#define QSPI_IFR_OPTL_2BIT              (1 << 8)
#define QSPI_IFR_OPTL_4BIT              (2 << 8)
#define QSPI_IFR_OPTL_8BIT              (3 << 8)
#define QSPI_IFR_ADDRL                  BIT(10)
#define QSPI_IFR_TFRTYP_MEM		BIT(12)
#define QSPI_IFR_SAMA5D2_WRITE_TRSFR	BIT(13)
#define QSPI_IFR_CRM                    BIT(14)
#define QSPI_IFR_NBDUM_MASK             GENMASK(20, 16)
#define QSPI_IFR_NBDUM(n)               (((n) << 16) & QSPI_IFR_NBDUM_MASK)
#define QSPI_IFR_APBTFRTYP_READ		BIT(24)	/* Defined in SAM9X60 */
#define QSPI_SMR_SCREN                  BIT(0)
#define QSPI_SMR_RVDIS                  BIT(1)
#define QSPI_WPMR_WPEN                  BIT(0)
#define QSPI_WPMR_WPKEY_MASK            GENMASK(31, 8)
#define QSPI_WPMR_WPKEY(wpkey)          (((wpkey) << 8) & QSPI_WPMR_WPKEY_MASK)
#define QSPI_WPSR_WPVS                  BIT(0)
#define QSPI_WPSR_WPVSRC_MASK           GENMASK(15, 8)
#define QSPI_WPSR_WPVSRC(src)           (((src) << 8) & QSPI_WPSR_WPVSRC)
