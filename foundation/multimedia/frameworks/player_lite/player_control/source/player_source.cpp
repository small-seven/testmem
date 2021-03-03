#include "player_source.h"
#include "player_demux.h"
#include "format_type.h"
#include "hi_liteplayer.h"
#include <memory>
#include <vector>
#include "media_log.h"
#define CHECK_FAILED_RETURN(value, target, ret, printfString) \
