#include "includes.h"
#include "common.h"
#include "base64.h"
#include "json.h"
#define JSON_MAX_DEPTH 10
#define JSON_MAX_TOKENS 500
void json_free(struct json_token *json)
{
	if (!json)
		return;
	json_free(json->child);
	json_free(json->sibling);
	os_free(json->name);
	os_free(json->string);
	os_free(json);
}
