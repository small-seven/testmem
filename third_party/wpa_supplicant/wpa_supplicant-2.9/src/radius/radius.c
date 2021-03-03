#include "utils/includes.h"
#include "utils/common.h"
#include "utils/wpabuf.h"
#include "crypto/md5.h"
#include "crypto/crypto.h"
#include "radius.h"
void radius_msg_free(struct radius_msg *msg)
{
	if (msg == NULL)
		return;

	wpabuf_free(msg->buf);
	os_free(msg->attr_pos);
	os_free(msg);
}
#define RADIUS_ATTRS ARRAY_SIZE(radius_attrs)
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
