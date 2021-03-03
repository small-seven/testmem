#if defined( __VMS) && !defined( OPENSSL_NO_DECC_INIT) && \
# define USE_DECC_INIT 1
#endif
#ifdef USE_DECC_INIT
# include <stdio.h>
# include <stdlib.h>
# include <unixlib.h>
# include "apps.h"
typedef struct {
    char *name;
    int value;
} decc_feat_t;
# pragma nostandard
# pragma extern_model save
# if __INITIAL_POINTER_SIZE == 64
#  define PSECT_ALIGN 3
# else
#  define PSECT_ALIGN 2
# endif
# pragma extern_model strict_refdef "LIB$INITIALIZ" PSECT_ALIGN, nopic, nowrt
# pragma extern_model strict_refdef "LIB$INITIALIZE" PSECT_ALIGN, nopic, nowrt
# pragma extern_model restore
# pragma extern_model save
# pragma extern_model strict_refdef
# pragma extern_model restore
# pragma standard
#else                           /* def USE_DECC_INIT */
#endif                          /* def USE_DECC_INIT */
