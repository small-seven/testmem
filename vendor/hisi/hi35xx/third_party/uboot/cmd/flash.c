#include <common.h>
#include <command.h>
#if defined(CONFIG_CMD_MTDPARTS)
#include <jffs2/jffs2.h>
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#include <flash.h>
#include <mtd/cfi_flash.h>
#endif /* CONFIG_MTD_NOR_FLASH */
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif /* CONFIG_MTD_NOR_FLASH */
#ifdef CONFIG_MTD_NOR_FLASH
#if defined(CONFIG_CMD_MTDPARTS)
#endif
#if defined(CONFIG_CMD_MTDPARTS)
#endif
#else
#endif /* CONFIG_MTD_NOR_FLASH */
#ifdef CONFIG_MTD_NOR_FLASH
#endif /* CONFIG_MTD_NOR_FLASH */
#ifdef CONFIG_MTD_NOR_FLASH
#if defined(CONFIG_CMD_MTDPARTS)
#endif
#endif /* CONFIG_MTD_NOR_FLASH */
#if defined(CONFIG_MTD_NOR_FLASH)
#endif
#if defined(CONFIG_MTD_NOR_FLASH)
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#else
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#else
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#if defined(CONFIG_CMD_MTDPARTS)
#endif
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#else
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#endif /* CONFIG_MTD_NOR_FLASH */
#ifdef CONFIG_MTD_NOR_FLASH
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#else
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#endif	/* CONFIG_SYS_FLASH_PROTECTION */
#endif /* CONFIG_MTD_NOR_FLASH */
#if defined(CONFIG_CMD_MTDPARTS)
# define TMP_ERASE	"erase <part-id>\n    - erase partition\n"
# define TMP_PROT_ON	"protect on <part-id>\n    - protect partition\n"
# define TMP_PROT_OFF	"protect off <part-id>\n    - make partition writable\n"
#else
# define TMP_ERASE	/* empty */
# define TMP_PROT_ON	/* empty */
# define TMP_PROT_OFF	/* empty */
#endif
#undef	TMP_ERASE
#undef	TMP_PROT_ON
#undef	TMP_PROT_OFF
