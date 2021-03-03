#include "lwip/apps/smtp.h"
#if LWIP_TCP && LWIP_CALLBACK_API
#include "lwip/sys.h"
#include "lwip/sockets.h"
#include "lwip/altcp.h"
#include "lwip/dns.h"
#include "lwip/mem.h"
#include "lwip/altcp_tcp.h"
#include "lwip/altcp_tls.h"
#include <string.h> /* strlen, memcpy */
#include <stdlib.h>
#define SMTP_POLL_INTERVAL      4
#define SMTP_TIMEOUT_DATABLOCK  ( 3 * 60 * SMTP_POLL_INTERVAL / 2)
#define SMTP_TIMEOUT_DATATERM   (10 * 60 * SMTP_POLL_INTERVAL / 2)
#define SMTP_TIMEOUT            ( 2 * 60 * SMTP_POLL_INTERVAL / 2)
#define SMTP_DEBUG_TRACE        (SMTP_DEBUG | LWIP_DBG_TRACE)
#define SMTP_DEBUG_STATE        (SMTP_DEBUG | LWIP_DBG_STATE)
#define SMTP_DEBUG_WARN         (SMTP_DEBUG | LWIP_DBG_LEVEL_WARNING)
#define SMTP_DEBUG_WARN_STATE   (SMTP_DEBUG | LWIP_DBG_LEVEL_WARNING | LWIP_DBG_STATE)
#define SMTP_DEBUG_SERIOUS      (SMTP_DEBUG | LWIP_DBG_LEVEL_SERIOUS)
#define SMTP_RX_BUF_LEN         255
#define SMTP_TX_BUF_LEN         255
#define SMTP_CRLF               "\r\n"
#define SMTP_CRLF_LEN           2
#define SMTP_RESP_220           "220"
#define SMTP_RESP_235           "235"
#define SMTP_RESP_250           "250"
#define SMTP_RESP_334           "334"
#define SMTP_RESP_354           "354"
#define SMTP_RESP_LOGIN_UNAME   "VXNlcm5hbWU6"
#define SMTP_RESP_LOGIN_PASS    "UGFzc3dvcmQ6"
#define SMTP_KEYWORD_AUTH_SP    "AUTH "
#define SMTP_KEYWORD_AUTH_EQ    "AUTH="
#define SMTP_KEYWORD_AUTH_LEN   5
#define SMTP_AUTH_PARAM_PLAIN   "PLAIN"
#define SMTP_AUTH_PARAM_LOGIN   "LOGIN"
#define SMTP_CMD_EHLO_1           "EHLO ["
#define SMTP_CMD_EHLO_1_LEN       6
#define SMTP_CMD_EHLO_2           "]\r\n"
#define SMTP_CMD_EHLO_2_LEN       3
#define SMTP_CMD_AUTHPLAIN_1      "AUTH PLAIN "
#define SMTP_CMD_AUTHPLAIN_1_LEN  11
#define SMTP_CMD_AUTHPLAIN_2      "\r\n"
#define SMTP_CMD_AUTHPLAIN_2_LEN  2
#define SMTP_CMD_AUTHLOGIN        "AUTH LOGIN\r\n"
#define SMTP_CMD_AUTHLOGIN_LEN    12
#define SMTP_CMD_MAIL_1           "MAIL FROM: <"
#define SMTP_CMD_MAIL_1_LEN       12
#define SMTP_CMD_MAIL_2           ">\r\n"
#define SMTP_CMD_MAIL_2_LEN       3
#define SMTP_CMD_RCPT_1           "RCPT TO: <"
#define SMTP_CMD_RCPT_1_LEN       10
#define SMTP_CMD_RCPT_2           ">\r\n"
#define SMTP_CMD_RCPT_2_LEN       3
#define SMTP_CMD_DATA             "DATA\r\n"
#define SMTP_CMD_DATA_LEN         6
#define SMTP_CMD_HEADER_1         "From: <"
#define SMTP_CMD_HEADER_1_LEN     7
#define SMTP_CMD_HEADER_2         ">\r\nTo: <"
#define SMTP_CMD_HEADER_2_LEN     8
#define SMTP_CMD_HEADER_3         ">\r\nSubject: "
#define SMTP_CMD_HEADER_3_LEN     12
#define SMTP_CMD_HEADER_4         "\r\n\r\n"
#define SMTP_CMD_HEADER_4_LEN     4
#define SMTP_CMD_BODY_FINISHED    "\r\n.\r\n"
#define SMTP_CMD_BODY_FINISHED_LEN 5
#define SMTP_CMD_QUIT             "QUIT\r\n"
#define SMTP_CMD_QUIT_LEN         6
#if defined(SMTP_STAT_TX_BUF_MAX) && SMTP_STAT_TX_BUF_MAX
#define SMTP_TX_BUF_MAX(len) LWIP_MACRO(if((len) > smtp_tx_buf_len_max) smtp_tx_buf_len_max = (len);)
#else /* SMTP_STAT_TX_BUF_MAX */
#define SMTP_TX_BUF_MAX(len)
#endif /* SMTP_STAT_TX_BUF_MAX */
#if SMTP_COPY_AUTHDATA
#define SMTP_USERNAME(session)        (session)->username
#define SMTP_PASS(session)            (session)->pass
#define SMTP_AUTH_PLAIN_DATA(session) (session)->auth_plain
#define SMTP_AUTH_PLAIN_LEN(session)  (session)->auth_plain_len
#else /* SMTP_COPY_AUTHDATA */
#define SMTP_USERNAME(session)        smtp_username
#define SMTP_PASS(session)            smtp_pass
#define SMTP_AUTH_PLAIN_DATA(session) smtp_auth_plain
#define SMTP_AUTH_PLAIN_LEN(session)  smtp_auth_plain_len
#endif /* SMTP_COPY_AUTHDATA */
#if SMTP_BODYDH
#ifndef SMTP_BODYDH_MALLOC
#define SMTP_BODYDH_MALLOC(size)      mem_malloc(size)
#define SMTP_BODYDH_FREE(ptr)         mem_free(ptr)
#endif
#define BDHALLDATASENT                2
#define BDHSOMEDATASENT               1
#endif
#ifdef LWIP_DEBUG
#endif /* LWIP_DEBUG */
#if SMTP_BODYDH
#endif /* SMTP_BODYDH */
#if SMTP_COPY_AUTHDATA
#endif /* SMTP_COPY_AUTHDATA */
#if SMTP_BODYDH
#endif /* SMTP_BODYDH */
#if LWIP_ALTCP && LWIP_ALTCP_TLS
#endif
#if SMTP_CHECK_DATA
#endif /* SMTP_CHECK_DATA */
#if LWIP_DNS
#endif /* LWIP_DNS */
#if SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN
#endif /* SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN */
#if SMTP_BODYDH
#endif /* SMTP_BODYDH */
#ifdef LWIP_DEBUG
#endif /* LWIP_DEBUG */
#if LWIP_ALTCP && LWIP_ALTCP_TLS
#endif
#if SMTP_SUPPORT_AUTH_LOGIN || SMTP_SUPPORT_AUTH_PLAIN
#else /* SMTP_SUPPORT_AUTH_LOGIN || SMTP_SUPPORT_AUTH_PLAIN */
#endif /* SMTP_SUPPORT_AUTH_LOGIN || SMTP_SUPPORT_AUTH_PLAIN */
#if SMTP_BODYDH
#else /* SMTP_BODYDH */
#define smtp_free_struct(x) SMTP_STATE_FREE(x)
#endif /* SMTP_BODYDH */
#if LWIP_ALTCP && LWIP_ALTCP_TLS
#endif
#if SMTP_CHECK_DATA
#if SMTP_BODYDH
#endif /* SMTP_BODYDH */
#endif /* SMTP_CHECK_DATA */
#if SMTP_COPY_AUTHDATA
#endif /* SMTP_COPY_AUTHDATA */
#if LWIP_DNS
#else /* LWIP_DNS */
#endif /* LWIP_DNS */
#if SMTP_CHECK_DATA
#endif /* SMTP_CHECK_DATA */
smtp_free(struct smtp_session *s, u8_t result, u16_t srv_err, err_t err)
{
  smtp_result_fn fn = s->callback_fn;
  void *arg = s->callback_arg;
  if (s->p != NULL) {
    pbuf_free(s->p);
  }
  smtp_free_struct(s);
  if (fn != NULL) {
    fn(arg, result, srv_err, err);
  }
}
#if LWIP_DNS
#endif /* LWIP_DNS */
#if SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN
#endif /* SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN */
#if SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN
#if SMTP_SUPPORT_AUTH_PLAIN
#endif /* SMTP_SUPPORT_AUTH_PLAIN */
#if SMTP_SUPPORT_AUTH_LOGIN
#endif /* SMTP_SUPPORT_AUTH_LOGIN */
#endif /* SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN */
#if SMTP_SUPPORT_AUTH_LOGIN
#endif /* SMTP_SUPPORT_AUTH_LOGIN */
#if SMTP_BODYDH
#endif /* SMTP_BODYDH */
#if SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN
#endif /* SMTP_SUPPORT_AUTH_PLAIN || SMTP_SUPPORT_AUTH_LOGIN */
#if SMTP_SUPPORT_AUTH_LOGIN
#endif /* SMTP_SUPPORT_AUTH_LOGIN */
#if SMTP_BODYDH
#endif /* SMTP_BODYDH */
#endif /* LWIP_TCP && LWIP_CALLBACK_API */
