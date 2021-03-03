#include "parsedata.h"
#include <securec.h>
#include "mem_stat.h"
#include "jsonutil.h"
#include "log.h"
void free_data(struct pass_through_data *data)
{
    if (data != NULL) {
        if (data->payload_data != NULL) {
            FREE(data->payload_data);
        }
        FREE(data);
    }
}
void free_payload(char *data, enum json_object_data_type data_type)
{
    if (data_type == JSON_STRING_DATA) {
        free_json(data);
    } else {
        return;
    }
}
