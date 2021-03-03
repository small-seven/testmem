#include "ace_mem_base.h"
#include "acelite_config.h"
#include "wrapper/js.h"
void JSRelease(JSValue value)
{
    return jerry_release_value(value);
}
