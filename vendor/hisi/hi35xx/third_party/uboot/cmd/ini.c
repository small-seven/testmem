#include <common.h>
#include <command.h>
#include <env.h>
#include <linux/ctype.h>
#include <linux/string.h>
#ifdef CONFIG_INI_MAX_LINE
#define MAX_LINE CONFIG_INI_MAX_LINE
#else
#define MAX_LINE 200
#endif
#ifdef CONFIG_INI_MAX_SECTION
#define MAX_SECTION CONFIG_INI_MAX_SECTION
#else
#define MAX_SECTION 50
#endif
#ifdef CONFIG_INI_MAX_NAME
#define MAX_NAME CONFIG_INI_MAX_NAME
#else
#define MAX_NAME 50
#endif
#if CONFIG_INI_ALLOW_MULTILINE
#endif
#ifdef CONFIG_INI_CASE_INSENSITIVE
#endif
#ifdef CONFIG_INI_CASE_INSENSITIVE
#endif
