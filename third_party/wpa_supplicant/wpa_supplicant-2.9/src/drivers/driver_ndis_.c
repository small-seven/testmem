#include "includes.h"
#include "common.h"
#include "driver.h"
#include "eloop.h"
typedef struct _ADAPTER * LPADAPTER;
#include "driver_ndis.h"


void wpa_driver_ndis_event_connect(struct wpa_driver_ndis_data *drv);
void wpa_driver_ndis_event_disconnect(struct wpa_driver_ndis_data *drv);
void wpa_driver_ndis_event_media_specific(struct wpa_driver_ndis_data *drv,
					  const u8 *data, size_t data_len);
void wpa_driver_ndis_event_adapter_arrival(struct wpa_driver_ndis_data *drv);
void wpa_driver_ndis_event_adapter_removal(struct wpa_driver_ndis_data *drv);


enum event_types { EVENT_CONNECT, EVENT_DISCONNECT,
		   EVENT_MEDIA_SPECIFIC, EVENT_ADAPTER_ARRIVAL,
		   EVENT_ADAPTER_REMOVAL };
