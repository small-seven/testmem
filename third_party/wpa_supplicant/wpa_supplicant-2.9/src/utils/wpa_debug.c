#include "includes.h"
#include "common.h"
#ifdef CONFIG_DEBUG_SYSLOG
#include <syslog.h>
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define WPAS_TRACE_PFX "wpas <%d>: "
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_ANDROID_LOG
#include <android/log.h>
#ifndef ANDROID_LOG_NAME
#define ANDROID_LOG_NAME	"wpa_supplicant"
#endif /* ANDROID_LOG_NAME */
#endif /* CONFIG_ANDROID_LOG */
#ifndef CONFIG_NO_STDOUT_DEBUG
#ifdef CONFIG_DEBUG_FILE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif /* CONFIG_DEBUG_FILE */
#ifndef CONFIG_ANDROID_LOG
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#endif /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_SYSLOG
#ifndef LOG_HOSTAPD
#define LOG_HOSTAPD LOG_DAEMON
#endif /* LOG_HOSTAPD */
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_ANDROID_LOG
#else /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#endif /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_ANDROID_LOG
#else /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#endif /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_LINUX_TRACING
#endif /* CONFIG_DEBUG_LINUX_TRACING */
#ifdef CONFIG_ANDROID_LOG
#else /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_SYSLOG
#endif /* CONFIG_DEBUG_SYSLOG */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#endif /* CONFIG_ANDROID_LOG */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_FILE
#else /* CONFIG_DEBUG_FILE */
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_FILE
#ifdef __linux__
#endif /* __linux__ */
#ifndef _WIN32
#endif /* _WIN32 */
#else /* CONFIG_DEBUG_FILE */
#endif /* CONFIG_DEBUG_FILE */
#ifdef CONFIG_DEBUG_FILE
#endif /* CONFIG_DEBUG_FILE */
#ifndef _WIN32
#endif /* _WIN32 */
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifndef CONFIG_NO_WPA_MSG
#endif /* CONFIG_NO_WPA_MSG */
#ifndef CONFIG_NO_HOSTAPD_LOGGER
#endif /* CONFIG_NO_HOSTAPD_LOGGER */
