#include "includes.h"
#include "common.h"
#include "trace.h"
#include "wpabuf.h"
#ifdef WPA_TRACE
#define WPABUF_MAGIC 0x51a974e3
#endif /* WPA_TRACE */
#ifdef WPA_TRACE
#endif /* WPA_TRACE */
#ifdef WPA_TRACE
#endif /* WPA_TRACE */
#ifdef WPA_TRACE
#endif /* WPA_TRACE */
#ifdef WPA_TRACE
#else /* WPA_TRACE */
#endif /* WPA_TRACE */
struct wpabuf * wpabuf_alloc(size_t len)
{
#ifdef WPA_TRACE
	struct wpabuf_trace *trace = os_zalloc(sizeof(struct wpabuf_trace) +
					       sizeof(struct wpabuf) + len);
	struct wpabuf *buf;
	if (trace == NULL)
		return NULL;
	trace->magic = WPABUF_MAGIC;
	buf = (struct wpabuf *) (trace + 1);
#else /* WPA_TRACE */
	struct wpabuf *buf = os_zalloc(sizeof(struct wpabuf) + len);
	if (buf == NULL)
		return NULL;
#endif /* WPA_TRACE */

	buf->size = len;
	buf->buf = (u8 *) (buf + 1);
	return buf;
}
struct wpabuf * wpabuf_alloc_ext_data(u8 *data, size_t len)
{
#ifdef WPA_TRACE
	struct wpabuf_trace *trace = os_zalloc(sizeof(struct wpabuf_trace) +
					       sizeof(struct wpabuf));
	struct wpabuf *buf;
	if (trace == NULL)
		return NULL;
	trace->magic = WPABUF_MAGIC;
	buf = (struct wpabuf *) (trace + 1);
#else /* WPA_TRACE */
	struct wpabuf *buf = os_zalloc(sizeof(struct wpabuf));
	if (buf == NULL)
		return NULL;
#endif /* WPA_TRACE */

	buf->size = len;
	buf->used = len;
	buf->buf = data;
	buf->flags |= WPABUF_FLAG_EXT_DATA;

	return buf;
}
struct wpabuf * wpabuf_alloc_copy(const void *data, size_t len)
{
	struct wpabuf *buf = wpabuf_alloc(len);
	if (buf)
		wpabuf_put_data(buf, data, len);
	return buf;
}
void wpabuf_free(struct wpabuf *buf)
{
#ifdef WPA_TRACE
	struct wpabuf_trace *trace;
	if (buf == NULL)
		return;
	trace = wpabuf_get_trace(buf);
	if (trace->magic != WPABUF_MAGIC) {
		wpa_printf(MSG_ERROR, "wpabuf_free: invalid magic %x",
			   trace->magic);
		wpa_trace_show("wpabuf_free magic mismatch");
		abort();
	}
	if (buf->flags & WPABUF_FLAG_EXT_DATA)
		os_free(buf->buf);
	os_free(trace);
#else /* WPA_TRACE */
	if (buf == NULL)
		return;
	if (buf->flags & WPABUF_FLAG_EXT_DATA)
		os_free(buf->buf);
	os_free(buf);
#endif /* WPA_TRACE */
}
void wpabuf_clear_free(struct wpabuf *buf)
{
	if (buf) {
		os_memset(wpabuf_mhead(buf), 0, wpabuf_len(buf));
		wpabuf_free(buf);
	}
}
