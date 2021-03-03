#include <asm/io.h>
#include <common.h>
#include <command.h>
#include <malloc.h>
#include <net.h>
#include <miiphy.h>
#include "ks8851_mll.h"
#define DRIVERNAME			"ks8851_mll"
#define MAX_RECV_FRAMES			32
#define MAX_BUF_SIZE			2048
#define TX_BUF_SIZE			2000
#define RX_BUF_SIZE			2000
#define BE3             0x8000      /* Byte Enable 3 */
#define BE2             0x4000      /* Byte Enable 2 */
#define BE1             0x2000      /* Byte Enable 1 */
#define BE0             0x1000      /* Byte Enable 0 */
