#include "config.h"
#include "test.h"
#if defined(__i386__) && defined(HAVE_MODIFY_LDT)
#ifdef HAVE_ASM_LDT_H
# include <asm/ldt.h>
#endif
#include <asm/unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "safe_macros.h"
#ifdef HAVE_STRUCT_USER_DESC
# define SIZE sizeof(struct user_desc)
#else
# define SIZE 16
#endif
#elif HAVE_MODIFY_LDT
#else /* if defined(__i386__) */
#endif /* if defined(__i386__) */
