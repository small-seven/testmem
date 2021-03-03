#include <common.h>
#include <ahci.h>
#include <dm.h>
#include <scsi.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/gpio.h>
#define AHCI_PHYCS0R 0x00c0
#define AHCI_PHYCS1R 0x00c4
#define AHCI_PHYCS2R 0x00c8
#define AHCI_RWCR    0x00fc
