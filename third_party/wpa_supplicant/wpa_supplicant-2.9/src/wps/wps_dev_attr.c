#include "includes.h"
#include "common.h"
#include "wps_i.h"
#include "wps_dev_attr.h"
#ifndef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#ifndef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#ifndef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#ifndef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#ifndef CONFIG_WPS_STRICT
#endif /* CONFIG_WPS_STRICT */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
void wps_device_data_free(struct wps_device_data *dev)
{
	os_free(dev->device_name);
	dev->device_name = NULL;
	os_free(dev->manufacturer);
	dev->manufacturer = NULL;
	os_free(dev->model_name);
	dev->model_name = NULL;
	os_free(dev->model_number);
	dev->model_number = NULL;
	os_free(dev->serial_number);
	dev->serial_number = NULL;
}
