#include <fenv.h>
#include <features.h>
#if __HAVE_68881__ || __mcffpu__
#else
#include "../fenv.c"
#endif
