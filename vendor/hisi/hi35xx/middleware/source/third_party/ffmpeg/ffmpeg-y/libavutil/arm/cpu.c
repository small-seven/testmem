#include "libavutil/cpu.h"
#include "libavutil/cpu_internal.h"
#include "config.h"
#define CORE_FLAG(f) \
#define CORE_CPU_FLAGS                          \
#if defined __linux__ || defined __ANDROID__
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/avstring.h"
#define AT_HWCAP        16
#define HWCAP_VFP       (1 << 6)
#define HWCAP_EDSP      (1 << 7)
#define HWCAP_THUMBEE   (1 << 11)
#define HWCAP_NEON      (1 << 12)
#define HWCAP_VFPv3     (1 << 13)
#define HWCAP_TLS       (1 << 15)
#define check_cap(cap, flag) do {               \
#else
#endif
