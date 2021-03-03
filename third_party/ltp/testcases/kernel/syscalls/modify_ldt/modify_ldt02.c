#include "config.h"
#include "test.h"
#if defined(__i386__) && defined(HAVE_MODIFY_LDT)
#ifdef HAVE_ASM_LDT_H
#include <asm/ldt.h>
#endif
#include <asm/unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#ifdef HAVE_STRUCT_USER_DESC
typedef struct user_desc modify_ldt_s;
#elif  HAVE_STRUCT_MODIFY_LDT_LDT_S
typedef struct modify_ldt_ldt_s modify_ldt_s;
#else
typedef struct modify_ldt_ldt_t {
	unsigned int entry_number;
	unsigned long int base_addr;
	unsigned int limit;
	unsigned int seg_32bit:1;
	unsigned int contents:2;
	unsigned int read_exec_only:1;
	unsigned int limit_in_pages:1;
	unsigned int seg_not_present:1;
	unsigned int useable:1;
	unsigned int empty:25;
} modify_ldt_s;
#endif
#define FAILED 1
#elif HAVE_MODIFY_LDT
#else /* if defined(__i386__) */
#endif /* if defined(__i386__) */
