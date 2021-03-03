#include "includes.h"
#include <assert.h>
#include "common.h"
#include "trace.h"
#include "list.h"
#include "eloop.h"
#if defined(CONFIG_ELOOP_POLL) && defined(CONFIG_ELOOP_EPOLL)
#error Do not define both of poll and epoll
#endif
#if defined(CONFIG_ELOOP_POLL) && defined(CONFIG_ELOOP_KQUEUE)
#error Do not define both of poll and kqueue
#endif
#if !defined(CONFIG_ELOOP_POLL) && !defined(CONFIG_ELOOP_EPOLL) && \
#define CONFIG_ELOOP_SELECT
#endif
#ifdef CONFIG_ELOOP_POLL
#include <poll.h>
#endif /* CONFIG_ELOOP_POLL */
#ifdef CONFIG_ELOOP_EPOLL
#include <sys/epoll.h>
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#include <sys/event.h>
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#if defined(CONFIG_ELOOP_EPOLL) || defined(CONFIG_ELOOP_KQUEUE)
#endif /* CONFIG_ELOOP_EPOLL || CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef WPA_TRACE
#else /* WPA_TRACE */
#define eloop_trace_sock_add_ref(table) do { } while (0)
#define eloop_trace_sock_remove_ref(table) do { } while (0)
#endif /* WPA_TRACE */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#if defined(CONFIG_ELOOP_EPOLL) || defined(CONFIG_ELOOP_KQUEUE)
#endif /* CONFIG_ELOOP_EPOLL || CONFIG_ELOOP_KQUEUE */
#ifdef WPA_TRACE
#endif /* WPA_TRACE */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_EPOLL */
#if defined(CONFIG_ELOOP_EPOLL) || defined(CONFIG_ELOOP_KQUEUE)
#endif /* CONFIG_ELOOP_EPOLL || CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#if defined(CONFIG_ELOOP_EPOLL) || defined(CONFIG_ELOOP_KQUEUE)
#endif /* CONFIG_ELOOP_EPOLL || CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#if defined(CONFIG_ELOOP_EPOLL) || defined(CONFIG_ELOOP_KQUEUE)
#endif /* CONFIG_ELOOP_EPOLL || CONFIG_ELOOP_KQUEUE */
static void eloop_sock_table_remove_sock(struct eloop_sock_table *table,
                                         int sock)
{
#ifdef CONFIG_ELOOP_KQUEUE
	struct kevent ke;
#endif /* CONFIG_ELOOP_KQUEUE */
	int i;

	if (table == NULL || table->table == NULL || table->count == 0)
		return;

	for (i = 0; i < table->count; i++) {
		if (table->table[i].sock == sock)
			break;
	}
	if (i == table->count)
		return;
	eloop_trace_sock_remove_ref(table);
	if (i != table->count - 1) {
		os_memmove(&table->table[i], &table->table[i + 1],
			   (table->count - i - 1) *
			   sizeof(struct eloop_sock));
	}
	table->count--;
	eloop.count--;
	table->changed = 1;
	eloop_trace_sock_add_ref(table);
#ifdef CONFIG_ELOOP_EPOLL
	if (epoll_ctl(eloop.epollfd, EPOLL_CTL_DEL, sock, NULL) < 0) {
		wpa_printf(MSG_ERROR, "%s: epoll_ctl(DEL) for fd=%d failed: %s",
			   __func__, sock, strerror(errno));
		return;
	}
	os_memset(&eloop.fd_table[sock], 0, sizeof(struct eloop_sock));
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
	EV_SET(&ke, sock, event_type_kevent_filter(table->type), EV_DELETE, 0,
	       0, 0);
	if (kevent(eloop.kqueuefd, &ke, 1, NULL, 0, NULL) < 0) {
		wpa_printf(MSG_ERROR, "%s: kevent(DEL) for fd=%d failed: %s",
			   __func__, sock, strerror(errno));
		return;
	}
	os_memset(&eloop.fd_table[sock], 0, sizeof(struct eloop_sock));
#endif /* CONFIG_ELOOP_KQUEUE */
}
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
static void eloop_sock_table_destroy(struct eloop_sock_table *table)
{
	if (table) {
		int i;
		for (i = 0; i < table->count && table->table; i++) {
			wpa_printf(MSG_INFO, "ELOOP: remaining socket: "
				   "sock=%d eloop_data=%p user_data=%p "
				   "handler=%p",
				   table->table[i].sock,
				   table->table[i].eloop_data,
				   table->table[i].user_data,
				   table->table[i].handler);
			wpa_trace_dump_funcname("eloop unregistered socket "
						"handler",
						table->table[i].handler);
			wpa_trace_dump("eloop sock", &table->table[i]);
		}
		os_free(table->table);
	}
}
static void eloop_remove_timeout(struct eloop_timeout *timeout)
{
	dl_list_del(&timeout->list);
	wpa_trace_remove_ref(timeout, eloop, timeout->eloop_data);
	wpa_trace_remove_ref(timeout, user, timeout->user_data);
	os_free(timeout);
}
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_NATIVE_WINDOWS
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#if defined(CONFIG_ELOOP_POLL) || defined(CONFIG_ELOOP_EPOLL)
#endif /* defined(CONFIG_ELOOP_POLL) || defined(CONFIG_ELOOP_EPOLL) */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_EKQUEUE */
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
#ifdef CONFIG_ELOOP_EPOLL
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
void eloop_destroy(void)
{
	struct eloop_timeout *timeout, *prev;
	struct os_reltime now;

	os_get_reltime(&now);
	dl_list_for_each_safe(timeout, prev, &eloop.timeout,
			      struct eloop_timeout, list) {
		int sec, usec;
		sec = timeout->time.sec - now.sec;
		usec = timeout->time.usec - now.usec;
		if (timeout->time.usec < now.usec) {
			sec--;
			usec += 1000000;
		}
		wpa_printf(MSG_INFO, "ELOOP: remaining timeout: %d.%06d "
			   "eloop_data=%p user_data=%p handler=%p",
			   sec, usec, timeout->eloop_data, timeout->user_data,
			   timeout->handler);
		wpa_trace_dump_funcname("eloop unregistered timeout handler",
					timeout->handler);
		wpa_trace_dump("eloop timeout", timeout);
		eloop_remove_timeout(timeout);
	}
	eloop_sock_table_destroy(&eloop.readers);
	eloop_sock_table_destroy(&eloop.writers);
	eloop_sock_table_destroy(&eloop.exceptions);
	os_free(eloop.signals);

#ifdef CONFIG_ELOOP_POLL
	os_free(eloop.pollfds);
	os_free(eloop.pollfds_map);
#endif /* CONFIG_ELOOP_POLL */
#if defined(CONFIG_ELOOP_EPOLL) || defined(CONFIG_ELOOP_KQUEUE)
	os_free(eloop.fd_table);
#endif /* CONFIG_ELOOP_EPOLL || CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_EPOLL
	os_free(eloop.epoll_events);
	close(eloop.epollfd);
#endif /* CONFIG_ELOOP_EPOLL */
#ifdef CONFIG_ELOOP_KQUEUE
	os_free(eloop.kqueue_events);
	close(eloop.kqueuefd);
#endif /* CONFIG_ELOOP_KQUEUE */
}
#ifdef CONFIG_ELOOP_POLL
#endif /* CONFIG_ELOOP_POLL */
#if defined(CONFIG_ELOOP_SELECT) || defined(CONFIG_ELOOP_EPOLL)
#endif /* defined(CONFIG_ELOOP_SELECT) || defined(CONFIG_ELOOP_EPOLL) */
#ifdef CONFIG_ELOOP_KQUEUE
#endif /* CONFIG_ELOOP_KQUEUE */
#ifdef CONFIG_ELOOP_SELECT
#undef CONFIG_ELOOP_SELECT
#endif /* CONFIG_ELOOP_SELECT */
