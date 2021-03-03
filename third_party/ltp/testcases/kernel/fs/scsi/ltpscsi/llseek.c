#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/unistd.h>	/* for __NR_llseek */
#if defined(__GNUC__) || defined(HAS_LONG_LONG)
typedef long long llse_loff_t;
#else
typedef long llse_loff_t;
#endif

extern llse_loff_t llse_llseek(unsigned int, llse_loff_t, unsigned int);

#ifdef __linux__

#if defined(__alpha__) || defined(__ia64__)

#ifdef __NR_lseek
static off_t my_lseek(int fd, off_t off, int whence)
{
	return syscall(__NR_lseek, fd, off, whence);
}
#else /* undefined __NR_lseek */
#endif /* __NR_lseek */
#define my_llseek my_lseek
#else /* !__alpha__ && !__ia64__ */
#ifndef __NR_llseek
#else
#endif
#endif /* __alpha__ */
#else /* !linux */
#endif /* linux */
