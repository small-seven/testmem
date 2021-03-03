#include <common.h>
#include <env.h>
#include <dm/device.h>
#include <dm/uclass-internal.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <mtd.h>
#define MTD_NAME_MAX_LEN 20
#if defined(CONFIG_SYS_MTDPARTS_RUNTIME)
#elif defined(MTDIDS_DEFAULT)
#elif defined(CONFIG_MTDIDS_DEFAULT)
#endif
#if IS_ENABLED(CONFIG_DM_MTD)
#else
#endif
#if defined(CONFIG_MTD_PARTITIONS)
#define MTDPARTS_MAXLEN         512
#if defined(CONFIG_SYS_MTDPARTS_RUNTIME)
#elif defined(MTDPARTS_DEFAULT)
#elif defined(CONFIG_MTDPARTS_DEFAULT)
#endif
#else
#endif /* defined(CONFIG_MTD_PARTITIONS) */
