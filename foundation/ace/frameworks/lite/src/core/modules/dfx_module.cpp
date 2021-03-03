#include "dfx_module.h"
#include "ace_log.h"
#include "ui_dump_dom_tree.h"
#ifdef FEATURE_ACELITE_MC_DFX_MODULE
#include "ui_snapshot.h"
#elif defined(FEATURE_ACELITE_LITE_DFX_MODULE)
#include "ability_env.h"
#include "ace_mem_base.h"
#include "js_fwk_common.h"
#include "ui_screenshot.h"
#endif
#ifdef FEATURE_ACELITE_DFX_MODULE
#ifdef FEATURE_ACELITE_MC_DFX_MODULE
#elif defined(FEATURE_ACELITE_LITE_DFX_MODULE)
#endif
#endif
#ifdef FEATURE_ACELITE_LITE_DFX_MODULE
#else
#endif
#ifdef FEATURE_ACELITE_LITE_DFX_MODULE
#endif
