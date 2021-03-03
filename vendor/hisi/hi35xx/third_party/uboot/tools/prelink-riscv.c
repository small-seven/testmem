#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <compiler.h>
#ifndef EM_RISCV
#define EM_RISCV 243
#endif
#ifndef R_RISCV_32
#define R_RISCV_32 1
#endif
#ifndef R_RISCV_64
#define R_RISCV_64 2
#endif
#ifndef R_RISCV_RELATIVE
#define R_RISCV_RELATIVE 3
#endif
#define die(fmt, ...) \
#define PRELINK_BYTEORDER le
#define PRELINK_INC_BITS 32
#include "prelink-riscv.inc"
#undef PRELINK_BYTEORDER
#undef PRELINK_INC_BITS
#define PRELINK_BYTEORDER le
#define PRELINK_INC_BITS 64
#include "prelink-riscv.inc"
#undef PRELINK_BYTEORDER
#undef PRELINK_INC_BITS
#define PRELINK_BYTEORDER be
#define PRELINK_INC_BITS 32
#include "prelink-riscv.inc"
#undef PRELINK_BYTEORDER
#undef PRELINK_INC_BITS
#define PRELINK_BYTEORDER be
#define PRELINK_INC_BITS 64
#include "prelink-riscv.inc"
#undef PRELINK_BYTEORDER
#undef PRELINK_INC_BITS
