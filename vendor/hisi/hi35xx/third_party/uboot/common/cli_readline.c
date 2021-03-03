#include <common.h>
#include <bootretry.h>
#include <cli.h>
#include <time.h>
#include <watchdog.h>
#ifdef CONFIG_CMDLINE_EDITING
#define putnstr(str, n)	printf("%.*s", (int)n, str)
#define CTL_CH(c)		((c) - 'a' + 1)
#define CTL_BACKSPACE		('\b')
#define DEL			((char)255)
#define DEL7			((char)127)
#define CREAD_HIST_CHAR		('!')
#define getcmd_putch(ch)	putc(ch)
#define getcmd_getch()		getc()
#define getcmd_cbeep()		getcmd_putch('\a')
#define HIST_MAX		20
#define HIST_SIZE		CONFIG_SYS_CBSIZE
#define add_idx_minus_one() ((hist_add_idx == 0) ? hist_max : hist_add_idx-1)
#ifndef CONFIG_CMDLINE_EDITING
#endif /* CONFIG_CMDLINE_EDITING */
#define BEGINNING_OF_LINE() {			\
#define ERASE_TO_EOL() {				\
#define REFRESH_TO_EOL() {			\
#ifdef CONFIG_AUTO_COMPLETE
#endif
#endif /* CONFIG_CMDLINE_EDITING */
#ifdef CONFIG_CMDLINE_EDITING
#endif	/* CONFIG_CMDLINE_EDITING */
#ifdef CONFIG_AUTO_COMPLETE
#endif
#ifdef CONFIG_CMDLINE_EDITING
#endif
