#include "common.h"
#ifdef CONFIG_DRIVER_HDF
#include "drivers/wpa_hal_cmd.h"
#endif /* CONFIG_DRIVER_HDF */
#include "securec.h"
#ifdef CONFIG_DRIVER_HDF
#endif /* CONFIG_DRIVER_HDF */
#ifdef CONFIG_DRIVER_HDF
#endif /* CONFIG_DRIVER_HDF */
#ifdef CONFIG_DRIVER_HDF
#endif /* CONFIG_DRIVER_HDF */
#ifdef CONFIG_DRIVER_HDF
#endif /* CONFIG_DRIVER_HDF */
void l2_packet_deinit(struct l2_packet_data *l2)
{
    if (l2 == NULL)
        return;

#ifdef CONFIG_DRIVER_HDF
        (void)WifiWpaEapolDisable(l2->ifname);
#endif /* CONFIG_DRIVER_HDF */

    os_free(l2);
}
