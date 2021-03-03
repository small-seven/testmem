#include <lzmaram.h>
#include <hi_boot_err.h>
#include <hi_boot_rom.h>
#define LZMA_DIC_MIN   (1 << 12)
#define LZMA_BASE_SIZE 1846
#define LZMA_LIT_SIZE  768
#define IN_BUF_SIZE    0x1000
#define OUT_BUF_SIZE   0x1000
static void lzma_free(hi_pbyte unused, hi_pbyte address)
{
    hi_unref_param(unused);
    if (address == HI_NULL) {
        return;
    }

    boot_free(address);
}
