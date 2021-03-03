#include "zutil.h"
#include "inftrees.h"
#include "inflate.h"
#include "inffast.h"
#if defined( __GNUC__ ) && defined( __amd64__ ) && ! defined( __i386 )
#define PAD_AVAIL_IN 6
#define PAD_AVAIL_OUT 258
#else
#define PAD_AVAIL_IN 5
#define PAD_AVAIL_OUT 257
#endif
#if defined( __GNUC__ ) && defined( __amd64__ ) && ! defined( __i386 )
#elif ( defined( __GNUC__ ) || defined( __ICC ) ) && defined( __i386 )
#elif defined( _MSC_VER ) && ! defined( _M_AMD64 )
#else
#error "x86 architecture not defined"
#endif
