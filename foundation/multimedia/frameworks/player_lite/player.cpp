#include "player.h"
#include <cinttypes>
#include <sys/stat.h>
#include "media_log.h"
#include "player_impl.h"
#include "pms_interface.h"
#define CHK_NULL_RETURN(ptr) \
int32_t Player::Release()
{
    MEDIA_INFO_LOG("process in");
    CHK_NULL_RETURN(impl_);
    return impl_->Release();
}
