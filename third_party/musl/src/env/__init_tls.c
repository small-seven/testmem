#define SYSCALL_NO_TLS 1
#include <elf.h>
#include <limits.h>
#include <sys/mman.h>
#include <string.h>
#include <stddef.h>
#include "pthread_impl.h"
#include "libc.h"
#include "atomic.h"
#include "syscall.h"
#include "stdio_impl.h"
#include "lock.h"
#if 0
#endif
#define MIN_TLS_ALIGN offsetof(struct builtin_tls, pt)
#ifdef TLS_ABOVE_TP
#else
#endif
#if ULONG_MAX == 0xffffffff
typedef Elf32_Phdr Phdr;
#else
typedef Elf64_Phdr Phdr;
#endif

extern weak hidden const size_t _DYNAMIC[];

static void static_init_tls(size_t *aux)
{
	unsigned char *p;
	size_t n;
	Phdr *phdr, *tls_phdr=0;
	size_t base = 0;
	void *mem;

	for (p=(void *)aux[AT_PHDR],n=aux[AT_PHNUM]; n; n--,p+=aux[AT_PHENT]) {
		phdr = (void *)p;
		if (phdr->p_type == PT_PHDR)
			base = aux[AT_PHDR] - phdr->p_vaddr;
		if (phdr->p_type == PT_DYNAMIC && _DYNAMIC)
			base = (size_t)_DYNAMIC - phdr->p_vaddr;
		if (phdr->p_type == PT_TLS)
			tls_phdr = phdr;
		if (phdr->p_type == PT_GNU_STACK &&
		    phdr->p_memsz > __default_stacksize)
			__default_stacksize =
				phdr->p_memsz < DEFAULT_STACK_MAX ?
				phdr->p_memsz : DEFAULT_STACK_MAX;
	}
#ifdef TLS_ABOVE_TP
#else
#endif
#ifdef TLS_ABOVE_TP
#endif
#ifndef SYS_mmap2
#define SYS_mmap2 SYS_mmap
#endif
