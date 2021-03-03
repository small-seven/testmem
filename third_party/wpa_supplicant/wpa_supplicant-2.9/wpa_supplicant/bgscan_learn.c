#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "list.h"
#include "common/ieee802_11_defs.h"
#include "drivers/driver.h"
#include "config_ssid.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "scan.h"
#include "bgscan.h"
static void bss_free(struct bgscan_learn_bss *bss)
{
	os_free(bss->neigh);
	os_free(bss);
}
#define MAX_BSS 50
