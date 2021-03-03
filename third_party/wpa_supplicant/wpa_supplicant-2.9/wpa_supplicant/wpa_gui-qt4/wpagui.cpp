#ifdef CONFIG_NATIVE_WINDOWS
#include <windows.h>
#endif /* CONFIG_NATIVE_WINDOWS */
#include <cstdio>
#include <unistd.h>
#include <QMessageBox>
#include <QCloseEvent>
#include <QImageReader>
#include <QSettings>
#include "wpagui.h"
#include "dirent.h"
#include "common/wpa_ctrl.h"
#include "userdatarequest.h"
#include "networkconfig.h"
#ifndef QT_NO_DEBUG
#define debug(M, ...) qDebug("DEBUG %d: " M, __LINE__, ##__VA_ARGS__)
#else
#define debug(M, ...) do {} while (0)
#endif
#ifdef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef QT_NO_SESSIONMANAGER
#endif
#ifdef CONFIG_CTRL_IFACE_UDP
#endif /* CONFIG_CTRL_IFACE_UDP */
#ifdef CONFIG_CTRL_IFACE_UNIX
#ifdef _DIRENT_HAVE_D_TYPE
#endif /* _DIRENT_HAVE_D_TYPE */
#endif /* CONFIG_CTRL_IFACE_UNIX */
#ifdef CONFIG_CTRL_IFACE_NAMED_PIPE
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_CTRL_IFACE_UNIX
#else /* CONFIG_CTRL_IFACE_UNIX */
#endif /* CONFIG_CTRL_IFACE_UNIX */
#if defined(CONFIG_CTRL_IFACE_UNIX) || defined(CONFIG_CTRL_IFACE_UDP)
#endif
#ifdef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_CTRL_IFACE_NAMED_PIPE
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifndef CONFIG_CTRL_IFACE_NAMED_PIPE
#endif /* CONFIG_CTRL_IFACE_NAMED_PIPE */
#ifdef CONFIG_NATIVE_WINDOWS
#ifndef WPASVC_NAME
#define WPASVC_NAME TEXT("wpasvc")
#endif
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef QT_NO_SESSIONMANAGER
#endif
