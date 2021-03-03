#ifdef WINDOWS
#include <windows.h>
#else
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#endif
#include <time.h>
#include <string.h>
#include "defs.h"
#include "globals.h"
#include "main.h"
#include "threading.h"
#include "sfunc.h"
#ifdef WINDOWS
#endif
