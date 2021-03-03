#include "includes.h"
#ifdef __linux__
#include <sys/mman.h>
#endif /* __linux__ */
#include "common.h"
#include "ext_password_i.h"
#ifdef CONFIG_EXT_PASSWORD_TEST
#endif /* CONFIG_EXT_PASSWORD_TEST */
#ifdef __linux__
#endif /* __linux__ */
void ext_password_free(struct wpabuf *pw)
{
	if (pw == NULL)
		return;
	os_memset(wpabuf_mhead(pw), 0, wpabuf_len(pw));
#ifdef __linux__
	if (munlock(wpabuf_head(pw), wpabuf_len(pw)) < 0) {
		wpa_printf(MSG_ERROR, "EXT PW: munlock failed: %s",
			   strerror(errno));
	}
#endif /* __linux__ */
	wpabuf_free(pw);
}
