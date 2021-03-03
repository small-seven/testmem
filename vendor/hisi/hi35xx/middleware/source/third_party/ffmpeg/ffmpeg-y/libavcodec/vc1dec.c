#include "avcodec.h"
#include "blockdsp.h"
#include "get_bits.h"
#include "hwaccel.h"
#include "internal.h"
#include "mpeg_er.h"
#include "mpegvideo.h"
#include "msmpeg4.h"
#include "msmpeg4data.h"
#include "profiles.h"
#include "vc1.h"
#include "vc1data.h"
#include "libavutil/avassert.h"
#if CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER
typedef struct SpriteData {
    /**
     * Transform coefficients for both sprites in 16.16 fixed point format,
     * in the order they appear in the bitstream:
     *  x scale
     *  rotation 1 (unused)
     *  x offset
     *  rotation 2 (unused)
     *  y scale
     *  y offset
     *  alpha
     */
    int coefs[2][7];

    int effect_type, effect_flag;
    int effect_pcount1, effect_pcount2;   ///< amount of effect parameters stored in effect_params
    int effect_params1[15], effect_params2[10]; ///< effect parameters in 16.16 fixed point format
} SpriteData;
#endif
#define transpose(x) (((x) >> 3) | (((x) & 7) << 3))
#if CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER
#endif
#if CONFIG_VC1_DXVA2_HWACCEL
#endif
#if CONFIG_VC1_D3D11VA_HWACCEL
#endif
#if CONFIG_VC1_NVDEC_HWACCEL
#endif
#if CONFIG_VC1_VAAPI_HWACCEL
#endif
#if CONFIG_VC1_VDPAU_HWACCEL
#endif
#if CONFIG_VC1_DXVA2_HWACCEL
#endif
#if CONFIG_VC1_D3D11VA_HWACCEL
#endif
#if CONFIG_VC1_D3D11VA2_HWACCEL
#endif
#if CONFIG_VC1_NVDEC_HWACCEL
#endif
#if CONFIG_VC1_VAAPI_HWACCEL
#endif
#if CONFIG_VC1_VDPAU_HWACCEL
#endif
#if CONFIG_WMV3_DECODER
#if CONFIG_WMV3_DXVA2_HWACCEL
#endif
#if CONFIG_WMV3_D3D11VA_HWACCEL
#endif
#if CONFIG_WMV3_D3D11VA2_HWACCEL
#endif
#if CONFIG_WMV3_NVDEC_HWACCEL
#endif
#if CONFIG_WMV3_VAAPI_HWACCEL
#endif
#if CONFIG_WMV3_VDPAU_HWACCEL
#endif
#endif
#if CONFIG_WMV3IMAGE_DECODER
#endif
#if CONFIG_VC1IMAGE_DECODER
#endif
