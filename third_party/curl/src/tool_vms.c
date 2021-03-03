#include "tool_setup.h"
#ifdef __VMS
#if defined(__DECC) && !defined(__VAX) && \
#include <unixlib.h>
#endif
#define ENABLE_CURLX_PRINTF
#include "curlx.h"
#include "curlmsg_vms.h"
#include "tool_vms.h"
#include "memdebug.h" /* keep this as LAST include */
#if __CRTL_VER >= 70000000
#endif
#if defined(__DECC) && !defined(__VAX) && \
typedef struct {
  char *name;
  int value;
} decc_feat_t;
#pragma nostandard
#pragma extern_model save
#pragma extern_model strict_refdef "LIB$INITIALIZ" 2, nopic, nowrt
#pragma extern_model strict_refdef "LIB$INITIALIZE" 2, nopic, nowrt
#pragma extern_model restore
#pragma extern_model save
#pragma extern_model strict_refdef
#pragma extern_model restore
#pragma standard
#endif /* __DECC && !__VAX && __CRTL_VER && __CRTL_VER >= 70301000 */
#endif /* __VMS */
