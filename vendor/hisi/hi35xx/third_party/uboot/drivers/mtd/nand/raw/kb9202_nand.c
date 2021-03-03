#include <common.h>
#include <asm/io.h>
#include <asm/arch/AT91RM9200.h>
#include <asm/arch/hardware.h>
#include <nand.h>
#define MASK_ALE        (1 << 22)       /* our ALE is A22 */
#define MASK_CLE        (1 << 21)       /* our CLE is A21 */
#define KB9202_NAND_NCE (1 << 28) /* EN* on D28 */
#define KB9202_NAND_BUSY (1 << 29) /* RB* on D29 */
#define KB9202_SMC2_NWS (1 << 2)
#define KB9202_SMC2_TDF (1 << 8)
#define KB9202_SMC2_RWSETUP (1 << 24)
#define KB9202_SMC2_RWHOLD (1 << 29)
