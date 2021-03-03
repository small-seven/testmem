#include <common.h>
#include <linux/compiler.h>
#include <ns16550.h>
#ifdef CONFIG_NS87308
#include <ns87308.h>
#endif
#include <serial.h>
#ifndef CONFIG_NS16550_MIN_FUNCTIONS
#if !defined(CONFIG_CONS_INDEX)
#elif (CONFIG_CONS_INDEX < 1) || (CONFIG_CONS_INDEX > 6)
#error	"Invalid console index value."
#endif
#if CONFIG_CONS_INDEX == 1 && !defined(CONFIG_SYS_NS16550_COM1)
#error	"Console port 1 defined but not configured."
#elif CONFIG_CONS_INDEX == 2 && !defined(CONFIG_SYS_NS16550_COM2)
#error	"Console port 2 defined but not configured."
#elif CONFIG_CONS_INDEX == 3 && !defined(CONFIG_SYS_NS16550_COM3)
#error	"Console port 3 defined but not configured."
#elif CONFIG_CONS_INDEX == 4 && !defined(CONFIG_SYS_NS16550_COM4)
#error	"Console port 4 defined but not configured."
#elif CONFIG_CONS_INDEX == 5 && !defined(CONFIG_SYS_NS16550_COM5)
#error	"Console port 5 defined but not configured."
#elif CONFIG_CONS_INDEX == 6 && !defined(CONFIG_SYS_NS16550_COM6)
#error	"Console port 6 defined but not configured."
#endif
#ifdef CONFIG_SYS_NS16550_COM1
#else
#endif
#ifdef CONFIG_SYS_NS16550_COM2
#else
#endif
#ifdef CONFIG_SYS_NS16550_COM3
#else
#endif
#ifdef CONFIG_SYS_NS16550_COM4
#else
#endif
#ifdef CONFIG_SYS_NS16550_COM5
#else
#endif
#ifdef CONFIG_SYS_NS16550_COM6
#else
#endif
#define PORT	serial_ports[port-1]
#define DECLARE_ESERIAL_FUNCTIONS(port) \
#define INIT_ESERIAL_STRUCTURE(port, __name) {	\
#if defined(CONFIG_SYS_NS16550_COM1)
#endif
#if defined(CONFIG_SYS_NS16550_COM2)
#endif
#if defined(CONFIG_SYS_NS16550_COM3)
#endif
#if defined(CONFIG_SYS_NS16550_COM4)
#endif
#if defined(CONFIG_SYS_NS16550_COM5)
#endif
#if defined(CONFIG_SYS_NS16550_COM6)
#endif
#if CONFIG_CONS_INDEX == 1
#elif CONFIG_CONS_INDEX == 2
#elif CONFIG_CONS_INDEX == 3
#elif CONFIG_CONS_INDEX == 4
#elif CONFIG_CONS_INDEX == 5
#elif CONFIG_CONS_INDEX == 6
#else
#error "Bad CONFIG_CONS_INDEX."
#endif
#if defined(CONFIG_SYS_NS16550_COM1)
#endif
#if defined(CONFIG_SYS_NS16550_COM2)
#endif
#if defined(CONFIG_SYS_NS16550_COM3)
#endif
#if defined(CONFIG_SYS_NS16550_COM4)
#endif
#if defined(CONFIG_SYS_NS16550_COM5)
#endif
#if defined(CONFIG_SYS_NS16550_COM6)
#endif
#endif /* !CONFIG_NS16550_MIN_FUNCTIONS */
