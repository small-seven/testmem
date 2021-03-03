#include <common.h>
#include <exports.h>
#include <linux/compiler.h>
#define FO(x) offsetof(struct jt_funcs, x)
#if defined(CONFIG_X86)
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#elif defined(CONFIG_PPC)
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#elif defined(CONFIG_ARM)
#ifdef CONFIG_ARM64
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#else
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#endif
#elif defined(CONFIG_MIPS)
#ifdef CONFIG_CPU_MIPS64
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#else
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#endif
#elif defined(CONFIG_NIOS2)
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#elif defined(CONFIG_M68K)
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#elif defined(CONFIG_MICROBLAZE)
#define EXPORT_FUNC(f, a, x, ...)				\
#x ":\n"					\
#elif defined(CONFIG_SH)
#define EXPORT_FUNC(f, a, x, ...)					\
#elif defined(CONFIG_NDS32)
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n"				\
#elif defined(CONFIG_RISCV)
#ifdef CONFIG_ARCH_RV64I
#define EXPORT_FUNC(f, a, x, ...)	\
#x ":\n"				\
#else
#define EXPORT_FUNC(f, a, x, ...)	\
#x ":\n"				\
#endif
#elif defined(CONFIG_ARC)
#define EXPORT_FUNC(f, a, x, ...) \
#x ":\n" \
#elif defined(CONFIG_XTENSA)
#if defined(__XTENSA_CALL0_ABI__)
#define EXPORT_FUNC(f, a, x, ...)	\
#x ":\n"				\
#elif defined(__XTENSA_WINDOWED_ABI__)
#if XCHAL_HAVE_BE
# define SFT "8"
#else
# define SFT "12"
#endif
#define EXPORT_FUNC(f, a, x, ...)	\
#x ":\n"				\
#else
#error Unsupported Xtensa ABI
#endif
#else
#error stubs definition missing for this architecture
#endif
#if GCC_VERSION < 30400
#endif /* GCC_VERSION */
#include <_exports.h>
#include <asm/sections.h>
#if defined(CONFIG_X86)
#endif
#undef EXPORT_FUNC
