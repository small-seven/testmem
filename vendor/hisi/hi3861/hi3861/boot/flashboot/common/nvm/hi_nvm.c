#include "hi_nvm.h"
#include <hi_boot_err.h>
#include <hi_flashboot.h>
typedef hi_u32(*hi_nvm_changed_notify_f) (hi_u8 id);

typedef struct {
    hi_u8 min_id;
    hi_u8 max_id;
    hi_u16 count;
} nvm_changed_proc_stru;
typedef struct {
    hi_u32 base_addr;
    hi_u32 total_size;
    hi_u32 block_size;
} nvm_basic_info;
