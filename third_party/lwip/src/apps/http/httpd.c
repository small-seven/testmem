#include "lwip/init.h"
#include "lwip/apps/httpd.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/apps/fs.h"
#include "httpd_structs.h"
#include "lwip/def.h"
#include "lwip/altcp.h"
#include "lwip/altcp_tcp.h"
#if HTTPD_ENABLE_HTTPS
#include "lwip/altcp_tls.h"
#endif
#ifdef LWIP_HOOK_FILENAME
#include LWIP_HOOK_FILENAME
#endif
#if LWIP_HTTPD_TIMING
#include "lwip/sys.h"
#endif /* LWIP_HTTPD_TIMING */
#include <string.h> /* memset */
#include <stdlib.h> /* atoi */
#include <stdio.h>
#if LWIP_TCP && LWIP_CALLBACK_API
#define MIN_REQ_LEN   7
#define CRLF "\r\n"
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#define HTTP11_CONNECTIONKEEPALIVE  "Connection: keep-alive"
#define HTTP11_CONNECTIONKEEPALIVE2 "Connection: Keep-Alive"
#endif
#if LWIP_HTTPD_DYNAMIC_FILE_READ
#define HTTP_IS_DYNAMIC_FILE(hs) ((hs)->buf != NULL)
#else
#define HTTP_IS_DYNAMIC_FILE(hs) 0
#endif
#ifndef HTTP_IS_DATA_VOLATILE
#define HTTP_IS_DATA_VOLATILE(hs)       (HTTP_IS_DYNAMIC_FILE(hs) ? TCP_WRITE_FLAG_COPY : 0)
#endif
#ifndef HTTP_IS_HDR_VOLATILE
#define HTTP_IS_HDR_VOLATILE(hs, ptr)   0
#endif
#define HTTP_DATA_TO_SEND_FREED    3
#define HTTP_DATA_TO_SEND_BREAK    2
#define HTTP_DATA_TO_SEND_CONTINUE 1
#define HTTP_NO_DATA_TO_SEND       0
typedef struct {
  const char *name;
  u8_t shtml;
} default_filename;
#define NUM_DEFAULT_FILENAMES LWIP_ARRAYSIZE(httpd_default_filenames)
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_SUPPORT_POST
#if LWIP_HTTPD_POST_MAX_RESPONSE_URI_LEN > LWIP_HTTPD_MAX_REQUEST_URI_LEN
#define LWIP_HTTPD_URI_BUF_LEN LWIP_HTTPD_POST_MAX_RESPONSE_URI_LEN
#endif
#endif
#ifndef LWIP_HTTPD_URI_BUF_LEN
#define LWIP_HTTPD_URI_BUF_LEN LWIP_HTTPD_MAX_REQUEST_URI_LEN
#endif
#if LWIP_HTTPD_URI_BUF_LEN
#endif
#if LWIP_HTTPD_DYNAMIC_HEADERS
#define NUM_FILE_HDR_STRINGS 5
#define HDR_STRINGS_IDX_HTTP_STATUS           0 /* e.g. "HTTP/1.0 200 OK\r\n" */
#define HDR_STRINGS_IDX_SERVER_NAME           1 /* e.g. "Server: "HTTPD_SERVER_AGENT"\r\n" */
#define HDR_STRINGS_IDX_CONTENT_LEN_KEEPALIVE 2 /* e.g. "Content-Length: xy\r\n" and/or "Connection: keep-alive\r\n" */
#define HDR_STRINGS_IDX_CONTENT_LEN_NR        3 /* the byte count, when content-length is used */
#define HDR_STRINGS_IDX_CONTENT_TYPE          4 /* the content type (or default answer content type including default document) */
#define LWIP_HTTPD_MAX_CONTENT_LEN_OFFSET 3
#ifndef LWIP_HTTPD_MAX_CONTENT_LEN_SIZE
#define LWIP_HTTPD_MAX_CONTENT_LEN_SIZE   (9 + LWIP_HTTPD_MAX_CONTENT_LEN_OFFSET)
#endif
#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_SSI
#define HTTPD_LAST_TAG_PART 0xFFFF
#if !LWIP_HTTPD_SSI_INCLUDE_TAG
#endif /* !LWIP_HTTPD_SSI_INCLUDE_TAG */
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED
#endif /* LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_DYNAMIC_FILE_READ
#endif /* LWIP_HTTPD_DYNAMIC_FILE_READ */
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#endif /* LWIP_HTTPD_SUPPORT_11_KEEPALIVE */
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_CGI
#endif /* LWIP_HTTPD_CGI */
#if LWIP_HTTPD_DYNAMIC_HEADERS
#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_TIMING
#endif /* LWIP_HTTPD_TIMING */
#if LWIP_HTTPD_SUPPORT_POST
#if LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_POST_MANUAL_WND */
#endif /* LWIP_HTTPD_SUPPORT_POST*/
#if HTTPD_USE_MEM_POOL
#if LWIP_HTTPD_SSI
#define HTTP_FREE_SSI_STATE(x)  LWIP_MEMPOOL_FREE(HTTPD_SSI_STATE, (x))
#define HTTP_ALLOC_SSI_STATE()  (struct http_ssi_state *)LWIP_MEMPOOL_ALLOC(HTTPD_SSI_STATE)
#endif /* LWIP_HTTPD_SSI */
#define HTTP_ALLOC_HTTP_STATE() (struct http_state *)LWIP_MEMPOOL_ALLOC(HTTPD_STATE)
#define HTTP_FREE_HTTP_STATE(x) LWIP_MEMPOOL_FREE(HTTPD_STATE, (x))
#else /* HTTPD_USE_MEM_POOL */
#define HTTP_ALLOC_HTTP_STATE() (struct http_state *)mem_malloc(sizeof(struct http_state))
#define HTTP_FREE_HTTP_STATE(x) mem_free(x)
#if LWIP_HTTPD_SSI
#define HTTP_ALLOC_SSI_STATE()  (struct http_ssi_state *)mem_malloc(sizeof(struct http_ssi_state))
#define HTTP_FREE_SSI_STATE(x)  mem_free(x)
#endif /* LWIP_HTTPD_SSI */
#endif /* HTTPD_USE_MEM_POOL */
#if LWIP_HTTPD_FS_ASYNC_READ
#endif /* LWIP_HTTPD_FS_ASYNC_READ */
#if LWIP_HTTPD_SSI
#if !LWIP_HTTPD_SSI_RAW
#endif /* !LWIP_HTTPD_SSI_RAW */
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_CGI
#define http_cgi_params     hs->params
#define http_cgi_param_vals hs->param_vals
#elif LWIP_HTTPD_CGI_SSI
#endif /* LWIP_HTTPD_CGI */
#if LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED
#if LWIP_HTTPD_SSI
#else /* LWIP_HTTPD_SSI */
#endif /* LWIP_HTTPD_SSI */
#else /* LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED */
#define http_add_connection(hs)
#define http_remove_connection(hs)
#endif /* LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED */
#if LWIP_HTTPD_SSI
#if LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED
#endif /* LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED */
http_ssi_state_free(struct http_ssi_state *ssi)
{
  if (ssi != NULL) {
    HTTP_FREE_SSI_STATE(ssi);
  }
}
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_DYNAMIC_HEADERS
#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED
#endif /* LWIP_HTTPD_KILL_OLD_ON_CONNECTIONS_EXCEEDED */
#if LWIP_HTTPD_TIMING
#endif /* LWIP_HTTPD_TIMING */
#if LWIP_HTTPD_DYNAMIC_FILE_READ
#endif /* LWIP_HTTPD_DYNAMIC_FILE_READ */
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
http_state_free(struct http_state *hs)
{
  if (hs != NULL) {
    http_state_eof(hs);
    http_remove_connection(hs);
    HTTP_FREE_HTTP_STATE(hs);
  }
}
#ifdef HTTPD_MAX_WRITE_LEN
#endif /* HTTPD_MAX_WRITE_LEN */
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#endif
#if LWIP_HTTPD_SUPPORT_POST
#if LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_POST_MANUAL_WND */
#endif /* LWIP_HTTPD_SUPPORT_POST*/
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#endif /* LWIP_HTTPD_SUPPORT_11_KEEPALIVE */
#if LWIP_HTTPD_CGI || LWIP_HTTPD_CGI_SSI
#endif /* LWIP_HTTPD_CGI || LWIP_HTTPD_CGI_SSI */
#if LWIP_HTTPD_SSI
#if LWIP_HTTPD_SSI_RAW
#else /* LWIP_HTTPD_SSI_RAW */
#endif /* LWIP_HTTPD_SSI_RAW */
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#if LWIP_HTTPD_SSI_RAW
#endif
#if !LWIP_HTTPD_SSI_RAW
#endif /* !LWIP_HTTPD_SSI_RAW */
#if LWIP_HTTPD_SSI_RAW
#else /* LWIP_HTTPD_SSI_RAW */
#endif /* LWIP_HTTPD_SSI_RAW */
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#if LWIP_HTTPD_FILE_STATE
#endif /* LWIP_HTTPD_FILE_STATE */
#if LWIP_HTTPD_SSI_RAW
#endif /* LWIP_HTTPD_SSI_RAW */
#define UNKNOWN_TAG1_TEXT "<b>***UNKNOWN TAG "
#define UNKNOWN_TAG1_LEN  18
#define UNKNOWN_TAG2_TEXT "***</b>"
#define UNKNOWN_TAG2_LEN  7
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_DYNAMIC_HEADERS
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#endif
#if LWIP_HTTPD_OMIT_HEADER_FOR_EXTENSIONLESS_URI
#endif /* LWIP_HTTPD_OMIT_HEADER_FOR_EXTENSIONLESS_URI */
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#else /* LWIP_HTTPD_SUPPORT_11_KEEPALIVE */
#endif /* LWIP_HTTPD_SUPPORT_11_KEEPALIVE */
#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_DYNAMIC_FILE_READ
#ifdef HTTPD_MAX_WRITE_LEN
#endif /* HTTPD_MAX_WRITE_LEN */
#endif /* LWIP_HTTPD_DYNAMIC_FILE_READ */
#if LWIP_HTTPD_DYNAMIC_FILE_READ
#ifdef HTTPD_MAX_WRITE_LEN
#endif /* HTTPD_MAX_WRITE_LEN */
#if LWIP_HTTPD_FS_ASYNC_READ
#else /* LWIP_HTTPD_FS_ASYNC_READ */
#endif /* LWIP_HTTPD_FS_ASYNC_READ */
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#else /* LWIP_HTTPD_DYNAMIC_FILE_READ */
#endif /* LWIP_HTTPD_SSI || LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_SSI
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#if !LWIP_HTTPD_SSI_INCLUDE_TAG
#endif /* !LWIP_HTTPD_SSI_INCLUDE_TAG*/
#if LWIP_HTTPD_SSI_INCLUDE_TAG
#else /* LWIP_HTTPD_SSI_INCLUDE_TAG*/
#endif /* LWIP_HTTPD_SSI_INCLUDE_TAG*/
#if !LWIP_HTTPD_SSI_INCLUDE_TAG
#endif /* !LWIP_HTTPD_SSI_INCLUDE_TAG*/
#if LWIP_HTTPD_SSI_INCLUDE_TAG
#else /* LWIP_HTTPD_SSI_INCLUDE_TAG*/
#endif /* LWIP_HTTPD_SSI_INCLUDE_TAG*/
#if !LWIP_HTTPD_SSI_INCLUDE_TAG
#endif /* !LWIP_HTTPD_SSI_INCLUDE_TAG*/
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#if LWIP_HTTPD_SSI_MULTIPART
#endif /* LWIP_HTTPD_SSI_MULTIPART */
#if !LWIP_HTTPD_SSI_INCLUDE_TAG
#endif /* !LWIP_HTTPD_SSI_INCLUDE_TAG*/
#if LWIP_HTTPD_DYNAMIC_FILE_READ && !LWIP_HTTPD_SSI_INCLUDE_TAG
#endif /* LWIP_HTTPD_DYNAMIC_FILE_READ && !LWIP_HTTPD_SSI_INCLUDE_TAG */
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND */
#if LWIP_HTTPD_FS_ASYNC_READ
#endif /* LWIP_HTTPD_FS_ASYNC_READ */
#if LWIP_HTTPD_DYNAMIC_HEADERS
#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_SUPPORT_EXTSTATUS
#else /* LWIP_HTTPD_SUPPORT_EXTSTATUS */
#define http_find_error_file(hs, error_nr) ERR_ARG
#endif /* LWIP_HTTPD_SUPPORT_EXTSTATUS */
#if LWIP_HTTPD_SUPPORT_POST
#if LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_POST_MANUAL_WND */
#if LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND
#endif
#if LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND
#endif
#if LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND */
#define HTTP_HDR_CONTENT_LEN                "Content-Length: "
#define HTTP_HDR_CONTENT_LEN_LEN            16
#define HTTP_HDR_CONTENT_LEN_DIGIT_MAX_LEN  10
#if LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_POST_MANUAL_WND */
#if LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_POST_MANUAL_WND */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#else /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_POST_MANUAL_WND */
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_FS_ASYNC_READ
#endif /* LWIP_HTTPD_FS_ASYNC_READ */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_SUPPORT_V09
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#endif /* LWIP_HTTPD_SUPPORT_V09 */
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#endif /* LWIP_HTTPD_SUPPORT_11_KEEPALIVE */
#if LWIP_HTTPD_SUPPORT_POST
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#else /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_SSI && (LWIP_HTTPD_SSI_BY_FILE_EXTENSION == 1)
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_CGI
#endif /* LWIP_HTTPD_CGI */
#if !LWIP_HTTPD_SSI
#endif /* !LWIP_HTTPD_SSI */
#if LWIP_HTTPD_MAX_REQUEST_URI_LEN
#else /* LWIP_HTTPD_MAX_REQUEST_URI_LEN */
#endif /* LWIP_HTTPD_MAX_REQUEST_URI_LEN */
#if LWIP_HTTPD_MAX_REQUEST_URI_LEN
#endif /* LWIP_HTTPD_MAX_REQUEST_URI_LEN */
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_CGI
#endif /* LWIP_HTTPD_CGI */
#if LWIP_HTTPD_SSI
#if LWIP_HTTPD_SSI_BY_FILE_EXTENSION
#endif /* LWIP_HTTPD_SSI_BY_FILE_EXTENSION */
#endif /* LWIP_HTTPD_SSI */
#if !LWIP_HTTPD_SUPPORT_V09
#endif
#if !LWIP_HTTPD_DYNAMIC_FILE_READ
#endif
#if LWIP_HTTPD_SSI
#else /* LWIP_HTTPD_SSI */
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_CGI_SSI
#if LWIP_HTTPD_CGI
#endif
#if defined(LWIP_HTTPD_FILE_STATE) && LWIP_HTTPD_FILE_STATE
#endif /* LWIP_HTTPD_FILE_STATE */
#else /* LWIP_HTTPD_CGI_SSI */
#endif /* LWIP_HTTPD_CGI_SSI */
#if LWIP_HTTPD_CUSTOM_FILES
#endif /* LWIP_HTTPD_CUSTOM_FILES */
#if LWIP_HTTPD_TIMING
#endif /* LWIP_HTTPD_TIMING */
#if !LWIP_HTTPD_DYNAMIC_HEADERS
#endif /* !LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_SUPPORT_V09
#endif /* LWIP_HTTPD_SUPPORT_V09*/
#if LWIP_HTTPD_DYNAMIC_HEADERS
#else /* LWIP_HTTPD_DYNAMIC_HEADERS */
#endif /* LWIP_HTTPD_DYNAMIC_HEADERS */
#if LWIP_HTTPD_SUPPORT_11_KEEPALIVE
#if LWIP_HTTPD_SSI
#endif /* LWIP_HTTPD_SSI */
#endif /* LWIP_HTTPD_SUPPORT_11_KEEPALIVE */
#if LWIP_HTTPD_ABORT_ON_CLOSE_MEM_ERROR
#endif /* LWIP_HTTPD_ABORT_ON_CLOSE_MEM_ERROR */
#if LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND
#endif /* LWIP_HTTPD_SUPPORT_POST && LWIP_HTTPD_POST_MANUAL_WND */
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if LWIP_HTTPD_SUPPORT_REQUESTLIST
#endif /* LWIP_HTTPD_SUPPORT_REQUESTLIST */
#if LWIP_HTTPD_SUPPORT_POST
#endif /* LWIP_HTTPD_SUPPORT_POST */
#if HTTPD_USE_MEM_POOL
#if LWIP_HTTPD_SSI
#endif
#endif
#if HTTPD_ENABLE_HTTPS
#if LWIP_ALTCP_TLS
#else /* LWIP_ALTCP_TLS */
#endif /* LWIP_ALTCP_TLS */
#endif /* HTTPD_ENABLE_HTTPS */
#if LWIP_HTTPD_SSI
#if LWIP_HTTPD_SSI_RAW
#else /* LWIP_HTTPD_SSI_RAW */
#endif /* !LWIP_HTTPD_SSI_RAW */
#endif /* LWIP_HTTPD_SSI */
#if LWIP_HTTPD_CGI
#endif /* LWIP_HTTPD_CGI */
#endif /* LWIP_TCP && LWIP_CALLBACK_API */
