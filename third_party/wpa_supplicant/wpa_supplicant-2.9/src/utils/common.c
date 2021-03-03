#include "includes.h"
#include "common/ieee802_11_defs.h"
#include "common.h"
#ifdef CONFIG_ANSI_C_EXTRA
#ifdef _WIN32_WCE
#endif /* _WIN32_WCE */
#endif /* CONFIG_ANSI_C_EXTRA */
#ifdef CONFIG_NATIVE_WINDOWS
#ifdef UNICODE
#endif /* UNICODE */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#endif /* CONFIG_NATIVE_WINDOWS */
void str_clear_free(char *str)
{
	if (str) {
		size_t len = os_strlen(str);
		forced_memzero(str, len);
		os_free(str);
	}
}
void bin_clear_free(void *bin, size_t len)
{
	if (bin) {
		forced_memzero(bin, len);
		os_free(bin);
	}
}
void forced_memzero(void *ptr, size_t len)
{
	memset_func(ptr, 0, len);
	if (len)
		forced_memzero_val = ((u8 *) ptr)[0];
}
