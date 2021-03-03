#include "lsmtd.h"
void scan_free(void)
{
	int i;

	for (i = 0; i < num_ubi_devices; ++i)
		free(ubi_dev[i].vol_info);

	free(ubi_dev);
	free(mtd_dev);
}
