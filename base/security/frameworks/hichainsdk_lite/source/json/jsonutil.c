#include "jsonutil.h"
#include "mem_stat.h"
#include "cJSON.h"
void free_json(json_handle hanlde)
{
    if (hanlde != NULL) {
        cJSON_Delete((cJSON *)hanlde);
    }
}
json_pobject create_json_object(void)
{
    return cJSON_CreateObject();
}
void free_json_string(char *json_str)
{
    FREE(json_str);
}
