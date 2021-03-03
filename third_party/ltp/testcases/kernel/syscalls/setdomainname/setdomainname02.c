#include "setdomainname.h"
#define ERRNO_DESC(x) .exp_errno = x, .errno_desc = #x
#define MAX_NAME_LENGTH _UTSNAME_DOMAIN_LENGTH - 1
