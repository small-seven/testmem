#include <efi_driver.h>
static int efi_uc_destroy(struct uclass *class)
{
	printf("Destroying  UCLASS_EFI\n");
	return 0;
}
