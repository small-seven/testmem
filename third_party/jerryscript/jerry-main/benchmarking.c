#ifdef __GNUC__
#define gettimeofday __prevent_conflicting_gettimeofday_declarations__
#include <sys/time.h>
#undef gettimeofday
#endif /* __GNUC__ */
