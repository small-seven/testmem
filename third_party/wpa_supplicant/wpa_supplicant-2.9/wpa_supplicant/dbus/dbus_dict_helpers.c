#include "includes.h"
#include <dbus/dbus.h>
#include "common.h"
#include "wpabuf.h"
#include "dbus_dict_helpers.h"
#define BYTE_ARRAY_CHUNK_SIZE 34
#define BYTE_ARRAY_ITEM_SIZE (sizeof(char))
#define STR_ARRAY_CHUNK_SIZE 8
#define STR_ARRAY_ITEM_SIZE (sizeof(char *))
#define BIN_ARRAY_CHUNK_SIZE 10
#define BIN_ARRAY_ITEM_SIZE (sizeof(struct wpabuf *))
