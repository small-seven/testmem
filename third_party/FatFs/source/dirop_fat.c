#include "dirop_fat.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"
#include "integer.h"
#include "inode/inode.h"
#include "fs/fs.h"
#include "fatfs.h"
#ifdef LOSCFG_FS_FAT
#ifdef __cplusplus
#if __cplusplus
#endif
#endif	/* __cplusplus */
#define SECTOR_SIZE		512
#define FIRST_MALLOC_SIZE	10
static struct fat_direntall **scandir_fat_remalloc_names(struct fat_direntall **names,
	UINT *names_size, UINT pos, bool *failed)
{
	struct fat_direntall **new_direntall = NULL;
	INT32 ret;

	if (pos == *names_size) {

		if (*names_size == 0) {
			*names_size = FIRST_MALLOC_SIZE;
		} else {
			*names_size <<= 1;
		}

		new_direntall = (struct fat_direntall **)malloc(*names_size * sizeof(struct fat_direntall *));
		if (new_direntall == NULL) {
			*failed = 1;
			return  names;
		}

		if (names != NULL) {
			ret = memcpy_s(new_direntall, (*names_size) * sizeof(struct fat_direntall *),
				names, pos * sizeof(struct fat_direntall *));
			if (ret != EOK){
				*failed = 1;
				free(new_direntall);
				return names;
			}
			free(names);
		}
		return new_direntall;
	}
	return names;
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif	/* __cplusplus */
#endif	/* CONFIG_FS_FAT */
