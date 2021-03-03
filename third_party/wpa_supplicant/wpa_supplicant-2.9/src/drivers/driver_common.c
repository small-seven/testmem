#include "includes.h"
#include "utils/common.h"
#include "driver.h"
void wpa_scan_results_free(struct wpa_scan_results *res)
{
	size_t i;

	if (res == NULL)
		return;

	for (i = 0; i < res->num; i++)
		os_free(res->res[i]);
	os_free(res->res);
	os_free(res);
}
#define E2S(n) case EVENT_ ## n: return #n
#undef E2S
#define CHECK_TRIGGER(trigger) \
#undef CHECK_TRIGGER
#define DF2S(x) case WPA_DRIVER_FLAGS_ ## x: return #x
#undef DF2S
