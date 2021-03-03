#define _GNU_SOURCE
#include <config.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/syscall.h>
#include "ptrace.h"
#include "test.h"
#include "spawn_ptrace_child.h"
#include "syscalls.h"
#define _decode(name, val) \
#define decode(reg) _decode(#reg, pt->reg)
#define decode_user(name, offset) \
#define decode_sysnum(nr) printf("%s ", get_sysnum(nr))
#if defined(__bfin__)
#elif defined(__i386__)
#elif defined(__x86_64__)
#elif defined(__sparc__)
#define G1 u_regs[0]
#define G2 u_regs[1]
#define G3 u_regs[2]
#define G4 u_regs[3]
#define G5 u_regs[4]
#define G6 u_regs[5]
#define G7 u_regs[6]
#define O0 u_regs[7]
#define O1 u_regs[8]
#define O2 u_regs[9]
#define O3 u_regs[10]
#define O4 u_regs[11]
#define O5 u_regs[12]
#define O6 u_regs[13]
#define O7 u_regs[14]
#else
#warning "no idea how to decode your arch"
#endif
