#include "includes.h"
#define LIBXML_VALID_ENABLED
#include <libxml/tree.h>
#include <libxml/xmlschemastypes.h>
#include "common.h"
#include "base64.h"
#include "xml-utils.h"
#define MAX_STR 1000
void xml_node_free(struct xml_node_ctx *ctx, xml_node_t *node)
{
	xmlFreeNode((xmlNodePtr) node);
}
void xml_node_get_attr_value_free(struct xml_node_ctx *ctx, char *val)
{
	if (val)
		xmlFree((xmlChar *) val);
}
void xml_node_get_text_free(struct xml_node_ctx *ctx, char *val)
{
	if (val)
		xmlFree((xmlChar *) val);
}
