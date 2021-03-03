#include <common.h>
#include <autoboot.h>
#include <bootretry.h>
#include <cli.h>
#include <command.h>
#include <console.h>
#include <env.h>
#include <fdtdec.h>
#include <hash.h>
#include <memalign.h>
#include <menu.h>
#include <post.h>
#include <time.h>
#include <u-boot/sha256.h>
#include <bootcount.h>
#define MAX_DELAY_STOP_STR 32
#ifndef DEBUG_BOOTKEYS
#define DEBUG_BOOTKEYS 0
#endif
#define debug_bootkeys(fmt, args...)		\
#ifdef CONFIG_AUTOBOOT_ENCRYPTION
#define AUTOBOOT_STOP_STR_SHA256 CONFIG_AUTOBOOT_STOP_STR_SHA256
#else
#define AUTOBOOT_STOP_STR_SHA256 ""
#endif
#ifdef CONFIG_USE_AUTOBOOT_MENUKEY
#define AUTOBOOT_MENUKEY CONFIG_USE_AUTOBOOT_MENUKEY
#else
#define AUTOBOOT_MENUKEY 0
#endif
#  ifdef CONFIG_AUTOBOOT_DELAY_STR
#  endif
#  ifdef CONFIG_AUTOBOOT_STOP_STR
#  endif
#  ifdef CONFIG_AUTOBOOT_PROMPT
#  endif
#ifdef CONFIG_SYS_TEXT_BASE
#endif /* CONFIG_SYS_TEXT_BASE */
#ifdef CONFIG_POST
#endif /* CONFIG_POST */
