#include <common.h>
#include <cpu_func.h>
#include <efi_loader.h>
#include <pe.h>
#if defined(__aarch64__)
#elif defined(__arm__)
#endif
#if defined(__x86_64__)
#elif defined(__i386__)
#endif
#if defined(__riscv) && (__riscv_xlen == 32)
#endif
#if defined(__riscv) && (__riscv_xlen == 64)
#endif
#ifdef __riscv
#endif
