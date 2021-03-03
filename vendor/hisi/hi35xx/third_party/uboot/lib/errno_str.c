#include <common.h>
#include <errno.h>
#define ERRNO_MSG(errno, msg)	msg
#define SAME_AS(x)		(const char *)&errno_message[x]
