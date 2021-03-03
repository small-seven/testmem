#include "curl_setup.h"
#if !defined(CURL_DISABLE_LDAP) && defined(USE_OPENLDAP)
#include <ldap.h>
#include "urldata.h"
#include <curl/curl.h>
#include "sendf.h"
#include "vtls/vtls.h"
#include "transfer.h"
#include "curl_ldap.h"
#include "curl_base64.h"
#include "connect.h"
#include "curl_printf.h"
#include "curl_memory.h"
#include "memdebug.h"
#ifndef _LDAP_PVT_H
#endif
#ifdef USE_SSL
#endif
typedef struct ldapreqinfo {
  int msgid;
  int nument;
} ldapreqinfo;
#ifdef USE_SSL
#endif
#ifdef CURL_OPENLDAP_DEBUG
#endif
#ifdef USE_SSL
#endif
#ifdef USE_SSL
#endif
#ifdef USE_SSL
ldapsb_tls_remove(Sockbuf_IO_Desc *sbiod)
{
  sbiod->sbiod_pvt = NULL;
  return 0;
}
#endif /* USE_SSL */
#endif /* !CURL_DISABLE_LDAP && USE_OPENLDAP */
