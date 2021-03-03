#include <stdint.h>
#include <elf.h>
#include "pthread_impl.h"
#include "libc.h"
#define HWCAP_TLS (1 << 15)
#define __a_barrier_kuser 0xffff0fa0
#define __a_barrier_oldkuser (uintptr_t)__a_barrier_oldkuser
#define __a_barrier_v6 (uintptr_t)__a_barrier_v6
#define __a_barrier_v7 (uintptr_t)__a_barrier_v7
#define __a_cas_kuser 0xffff0fc0
#define __a_cas_v6 (uintptr_t)__a_cas_v6
#define __a_cas_v7 (uintptr_t)__a_cas_v7
#define __a_gettp_kuser 0xffff0fe0
#define __a_gettp_cp15 (uintptr_t)__a_gettp_cp15
#ifdef SYS_set_thread_area
#else
#if !__ARM_ARCH_7A__ && !__ARM_ARCH_7R__ && __ARM_ARCH < 7
#endif
#endif
