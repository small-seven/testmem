#include <net/pfe_eth/pfe_eth.h>
#include <net/pfe_eth/pfe_firmware.h>
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
int pfe_eth_remove(struct udevice *dev)
{
	if (g_tx_desc)
		free(g_tx_desc);

	if (g_rx_desc)
		free(g_rx_desc);

	pfe_firmware_exit();

	return 0;
}
