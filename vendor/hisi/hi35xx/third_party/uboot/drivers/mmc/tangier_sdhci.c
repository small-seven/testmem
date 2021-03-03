#include <common.h>
#include <dm.h>
#include <dm/device.h>
#include <linux/io.h>
#include <linux/sizes.h>
#include <malloc.h>
#include <mmc.h>
#include <sdhci.h>
#define SDHCI_TANGIER_FMAX	200000000
#define SDHCI_TANGIER_FMIN	400000
