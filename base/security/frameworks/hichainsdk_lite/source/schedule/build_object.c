#include "build_object.h"
#include <securec.h>
#include "log.h"
#include "auth_info.h"
typedef const struct object_relation *object_relation_ptr;

static uint32_t select_relation_map(const struct object_relation *map, uint32_t n, int32_t modular, bool is_client,
    object_relation_ptr *select_map)
{
    uint32_t count = 0;

    for (uint32_t i = 0; i < n; i++) {
        if ((modular == map[i].src_modular) && (is_client == map[i].src_is_client)) {
            select_map[count] = &map[i];
            count++;
        }
typedef void *(*build_sub_object)(struct hichain *hichain, const void *params);
struct build_sub_object_map {
    int32_t modular;
    bool is_client;
    build_sub_object build_func;
};
