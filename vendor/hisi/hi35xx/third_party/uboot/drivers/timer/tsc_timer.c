#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <time.h>
#include <timer.h>
#include <asm/cpu.h>
#include <asm/io.h>
#include <asm/i8254.h>
#include <asm/ibmpc.h>
#include <asm/msr.h>
#include <asm/u-boot-x86.h>
#define MAX_NUM_FREQS	9
#define INTEL_FAM6_SKYLAKE_MOBILE	0x4E
#define INTEL_FAM6_ATOM_GOLDMONT	0x5C /* Apollo Lake */
#define INTEL_FAM6_SKYLAKE_DESKTOP	0x5E
#define INTEL_FAM6_ATOM_GOLDMONT_X	0x5F /* Denverton */
#define INTEL_FAM6_KABYLAKE_MOBILE	0x8E
#define INTEL_FAM6_KABYLAKE_DESKTOP	0x9E
#define id_to_freq(cpu_index, freq_id) \
#define MAX_QUICK_PIT_MS 50
#define MAX_QUICK_PIT_ITERATIONS (MAX_QUICK_PIT_MS * PIT_TICK_RATE / 1000 / 256)
#if defined(CONFIG_QEMU) && defined(CONFIG_SMP)
#else
#endif
