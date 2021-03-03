#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#include <ctype.h>		/* to declare isdigit(), isspace() */
#ifdef C_MULTISCAN_FILES_SUPPORTED
#define MAX_SCANS  100		/* quite arbitrary limit */
#endif /* C_MULTISCAN_FILES_SUPPORTED */
