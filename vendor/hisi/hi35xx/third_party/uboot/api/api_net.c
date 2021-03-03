#include <config.h>
#include <common.h>
#include <net.h>
#include <linux/types.h>
#include <api_public.h>
#define DEBUG
#undef DEBUG
#ifdef DEBUG
#define debugf(fmt, args...) do { printf("%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define debugf(fmt, args...)
#endif
#define errf(fmt, args...) do { printf("ERROR @ %s(): ", __func__); printf(fmt, ##args); } while (0)
#if defined(CONFIG_CMD_NET) && !defined(CONFIG_DM_ETH)
#else
#endif
