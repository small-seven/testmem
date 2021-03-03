#include "includes.h"
#include "common.h"
#include "eap_defs.h"
#include "eap_common.h"
struct wpabuf * eap_msg_alloc(int vendor, EapType type, size_t payload_len,
			      u8 code, u8 identifier)
{
	struct wpabuf *buf;
	struct eap_hdr *hdr;
	size_t len;

	len = sizeof(struct eap_hdr) + (vendor == EAP_VENDOR_IETF ? 1 : 8) +
		payload_len;
	buf = wpabuf_alloc(len);
	if (buf == NULL)
		return NULL;

	hdr = wpabuf_put(buf, sizeof(*hdr));
	hdr->code = code;
	hdr->identifier = identifier;
	hdr->length = host_to_be16(len);

	if (vendor == EAP_VENDOR_IETF) {
		wpabuf_put_u8(buf, type);
	} else {
		wpabuf_put_u8(buf, EAP_TYPE_EXPANDED);
		wpabuf_put_be24(buf, vendor);
		wpabuf_put_be32(buf, type);
	}

	return buf;
}
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
