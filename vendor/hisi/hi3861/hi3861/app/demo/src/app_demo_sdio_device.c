#include <hi_early_debug.h>
#include <hi_watchdog.h>
#include <hi_sdio_device.h>
#include <hi_cipher.h>
#include <hi_cpu.h>
#define  DATA_BLOCK         32768 /* sdio data block size:32768 */
#define SEND_RCV_DATA_SIZE  1024  /* send/recv 1024 byte per cycle */
