#include <common.h>
#include <debug_uart.h>
#include <errno.h>
#include <linux/err.h>
#include <linux/types.h>
#include <efi.h>
#include <efi_api.h>
static void efi_memset(void *ptr, int ch, int size)
{
	char *dest = ptr;

	while (size-- > 0)
		*dest++ = ch;
}
void *efi_malloc(struct efi_priv *priv, int size, efi_status_t *retp)
{
	struct efi_boot_services *boot = priv->boot;
	void *buf = NULL;

	*retp = boot->allocate_pool(priv->image_data_type, size, &buf);

	return buf;
}
void efi_free(struct efi_priv *priv, void *ptr)
{
	struct efi_boot_services *boot = priv->boot;

	boot->free_pool(ptr);
}
