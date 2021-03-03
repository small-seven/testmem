#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#include <ctype.h>		/* to declare isupper(), tolower() */
#ifdef NEED_SIGNAL_CATCHER
#include <signal.h>		/* to declare signal() */
#endif
#ifdef USE_SETMODE
#include <fcntl.h>		/* to declare setmode()'s parameter macros */
#include <io.h>			/* to declare setmode() */
#endif
#ifdef NEED_SIGNAL_CATCHER
#ifdef SIGINT			/* not all systems have SIGINT */
#endif
#ifdef SIGTERM			/* not all systems have SIGTERM */
#endif
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef USE_SETMODE		/* need to hack file mode? */
#endif
#ifdef USE_FDOPEN		/* need to re-open in binary mode? */
#endif
#ifdef USE_SETMODE		/* need to hack file mode? */
#endif
#ifdef USE_FDOPEN		/* need to re-open in binary mode? */
#endif
