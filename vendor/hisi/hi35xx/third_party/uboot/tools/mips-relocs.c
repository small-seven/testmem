#include <assert.h>
#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <asm/relocs.h>
#define hdr_field(pfx, idx, field) ({				\
#define set_hdr_field(pfx, idx, field, val) ({			\
#define ehdr_field(field) \
#define phdr_field(idx, field) \
#define shdr_field(idx, field) \
#define set_phdr_field(idx, field, val) \
#define set_shdr_field(idx, field, val) \
#define shstr(idx) (&shstrtab[idx])
