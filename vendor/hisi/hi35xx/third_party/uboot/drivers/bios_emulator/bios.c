#define __io
#include <common.h>
#include <asm/io.h>
#include "biosemui.h"
#ifdef CONFIG_X86EMU_DEBUG
#endif
#ifdef CONFIG_X86EMU_DEBUG
#endif
#define SUCCESSFUL          0x00
#define FUNC_NOT_SUPPORT    0x81
#define BAD_VENDOR_ID       0x83
#define DEVICE_NOT_FOUND    0x86
#define BAD_REGISTER_NUMBER 0x87
#define SET_FAILED          0x88
#define BUFFER_TOO_SMALL    0x89
#ifdef __KERNEL__
#else
#endif
#ifdef __KERNEL__
#else
#endif
#ifdef __KERNEL__
#ifdef CONFIG_DM_PCI
#else
#endif
#else
#endif
#ifdef __KERNEL__
# ifdef CONFIG_DM_PCI
# else
# endif
#else
#endif
#ifdef __KERNEL__
# ifdef CONFIG_DM_PCI
# else
# endif
#else
#endif
#ifdef __KERNEL__
# ifdef CONFIG_DM_PCI
# else
# endif
#else
#endif
#ifdef __KERNEL__
# ifdef CONFIG_DM_PCI
# else
# endif
#else
#endif
#ifdef __KERNEL__
# ifdef CONFIG_DM_PCI
# else
# endif
#else
#endif
#ifdef __KERNEL__
# ifdef CONFIG_DM_PCI
# else
# endif
#else
#endif
#define BE_constLE_32(v)    ((((((v)&0xff00)>>8)|(((v)&0xff)<<8))<<16)|(((((v)&0xff000000)>>8)|(((v)&0x00ff0000)<<8))>>16))
