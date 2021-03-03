#include "includes.h"
#include <net/if.h>
#ifdef CONFIG_SQLITE
#include <sqlite3.h>
#endif /* CONFIG_SQLITE */
#include "common.h"
#include "radius.h"
#include "eloop.h"
#include "eap_server/eap.h"
#include "ap/ap_config.h"
#include "crypto/tls.h"
#include "radius_server.h"
#define RADIUS_SESSION_TIMEOUT 60
#define RADIUS_SESSION_MAINTAIN 5
#define RADIUS_MAX_SESSION 1000
#define RADIUS_MAX_MSG_LEN 3000
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_RADIUS_TEST
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#define RADIUS_DEBUG(args...) \
#define RADIUS_ERROR(args...) \
#define RADIUS_DUMP(args...) \
#define RADIUS_DUMP_ASCII(args...) \
#ifdef CONFIG_SQLITE
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
static void radius_server_session_free(struct radius_server_data *data,
				       struct radius_session *sess)
{
	eloop_cancel_timeout(radius_server_session_timeout, data, sess);
	eloop_cancel_timeout(radius_server_session_remove_timeout, data, sess);
	eap_server_sm_deinit(sess->eap);
	radius_msg_free(sess->last_msg);
	os_free(sess->last_from_addr);
	radius_msg_free(sess->last_reply);
	os_free(sess->username);
	os_free(sess->nas_ip);
	os_free(sess);
	data->num_sess--;
}
static void radius_server_session_remove(struct radius_server_data *data,
					 struct radius_session *sess)
{
	struct radius_client *client = sess->client;
	struct radius_session *session, *prev;

	eloop_cancel_timeout(radius_server_session_remove_timeout, data, sess);

	prev = NULL;
	session = client->sessions;
	while (session) {
		if (session == sess) {
			if (prev == NULL) {
				client->sessions = sess->next;
			} else {
				prev->next = sess->next;
			}
			radius_server_session_free(data, sess);
			break;
		}
		prev = session;
		session = session->next;
	}
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_HS20
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#endif /* CONFIG_HS20 */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_RADIUS_TEST
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_HS20
#define HS20_MOBILE_ID_HASH_LEN 16
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#endif /* CONFIG_HS20 */
#ifdef CONFIG_RADIUS_TEST
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#if defined(IP_MTU_DISCOVER) && defined(IP_PMTUDISC_DONT)
#endif
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifndef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_RADIUS_TEST
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_RADIUS_TEST
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_SQLITE
#endif /* CONFIG_SQLITE */
#ifdef CONFIG_SQLITE
#else /* CONFIG_SQLITE */
#endif /* CONFIG_SQLITE */
