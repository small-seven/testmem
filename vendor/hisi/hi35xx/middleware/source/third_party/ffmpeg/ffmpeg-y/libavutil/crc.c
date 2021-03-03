#include "config.h"
#include "thread.h"
#include "avassert.h"
#include "bswap.h"
#include "common.h"
#include "crc.h"
#if CONFIG_HARDCODED_TABLES
#else
#if CONFIG_SMALL
#define CRC_TABLE_SIZE 257
#else
#define CRC_TABLE_SIZE 1024
#endif
#define DECLARE_CRC_INIT_TABLE_ONCE(id, le, bits, poly)                                       \
#define CRC_INIT_TABLE_ONCE(id) ff_thread_once(&id ## _once_control, id ## _init_table_once)
#endif
#if !CONFIG_SMALL
#endif
#if !CONFIG_HARDCODED_TABLES
#endif
#if !CONFIG_SMALL
#endif
