#include "player_impl.h"
#include <cinttypes>
#include <climits>
#include <string>
#include <sys/prctl.h>
#include "unistd.h"
#include "securec.h"
#include "format_type.h"
#include "hi_liteplayer_err.h"
#include "hi_liteplayer.h"
#include "player_define.h"
#include "media_log.h"
#include "codec_interface.h"
#include "hal_display.h"
#define CHECK_FAILED_PRINT(func, target, printfString) \
#define CHK_NULL_RETURN(ptr) \
int32_t Player::PlayerImpl::Release()
{
    std::lock_guard<std::mutex> valueLock(lock_);
    MEDIA_INFO_LOG("process in");
    CHK_NULL_RETURN(m_player);
    m_released = true;
    return 0;
}
