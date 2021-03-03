#include "config.h"
#ifdef __APPLE__
#include <sys/sysctl.h>
#elif defined(__linux__)
#include <asm/cputable.h>
#include <linux/auxvec.h>
#include <fcntl.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#elif defined(__OpenBSD__)
#include <sys/param.h>
#include <sys/sysctl.h>
#include <machine/cpu.h>
#elif defined(__AMIGAOS4__)
#include <exec/exec.h>
#include <interfaces/exec.h>
#include <proto/exec.h>
#endif /* __APPLE__ */
#include "libavutil/avassert.h"
#include "libavutil/cpu.h"
#include "libavutil/cpu_internal.h"
#if HAVE_ALTIVEC
#ifdef __AMIGAOS4__
#elif defined(__APPLE__) || defined(__OpenBSD__)
#ifdef __OpenBSD__
#else
#endif
#elif defined(__linux__)
#ifdef PPC_FEATURE_HAS_VSX
#endif
#ifdef PPC_FEATURE2_ARCH_2_07
#endif
#elif CONFIG_RUNTIME_CPUDETECT && defined(__linux__)
#define PVR_G4_7400  0x000C
#define PVR_G5_970   0x0039
#define PVR_G5_970FX 0x003C
#define PVR_G5_970MP 0x0044
#define PVR_G5_970GX 0x0045
#define PVR_POWER6   0x003E
#define PVR_POWER7   0x003F
#define PVR_POWER8   0x004B
#define PVR_CELL_PPU 0x0070
#else
#endif /* __AMIGAOS4__ */
#endif /* HAVE_ALTIVEC */
