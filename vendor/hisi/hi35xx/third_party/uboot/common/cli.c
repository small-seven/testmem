#include <common.h>
#include <cli.h>
#include <cli_hush.h>
#include <command.h>
#include <console.h>
#include <env.h>
#include <fdtdec.h>
#include <malloc.h>
#ifdef CONFIG_CMDLINE
#if !CONFIG_IS_ENABLED(HUSH_PARSER)
#else
#endif
#ifndef CONFIG_HUSH_PARSER
#else
#endif
#endif /* CONFIG_CMDLINE */
#ifdef CONFIG_HUSH_PARSER
#else
#endif
#ifdef CONFIG_HUSH_PARSER
#else
#ifdef CONFIG_CMDLINE
#else
#endif
#endif
#if defined(CONFIG_CMD_RUN)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#ifdef CONFIG_CMDLINE
#endif
#ifdef CONFIG_CMDLINE
#else
#endif
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
#ifdef CONFIG_HUSH_PARSER
#elif defined(CONFIG_CMDLINE)
#else
#endif /*CONFIG_HUSH_PARSER*/
#ifdef CONFIG_HUSH_PARSER
#endif
#if defined(CONFIG_HUSH_INIT_VAR)
#endif
