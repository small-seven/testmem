#include <stdint.h>
#include "libavutil/arm/cpu.h"
#include "libavutil/attributes.h"
#include "libavcodec/mlpdsp.h"
#define DECLARE_PACK(order,channels,shift) \
#define ENUMERATE_PACK(order,channels,shift) \
#define PACK_CHANNELS(macro,order,channels) \
#define PACK_ORDER(macro,order) \
#define PACK_ALL(macro) \
#define ff_mlp_pack_output_outoforder_2ch_mixedshift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_mixedshift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_mixedshift_armv6 0
#if CONFIG_THUMB
#define ff_mlp_pack_output_outoforder_2ch_0shift_armv6 0
#define ff_mlp_pack_output_outoforder_2ch_1shift_armv6 0
#define ff_mlp_pack_output_outoforder_2ch_2shift_armv6 0
#define ff_mlp_pack_output_outoforder_2ch_3shift_armv6 0
#define ff_mlp_pack_output_outoforder_2ch_4shift_armv6 0
#define ff_mlp_pack_output_outoforder_2ch_5shift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_0shift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_1shift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_2shift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_3shift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_4shift_armv6 0
#define ff_mlp_pack_output_outoforder_6ch_5shift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_0shift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_1shift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_2shift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_3shift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_4shift_armv6 0
#define ff_mlp_pack_output_outoforder_8ch_5shift_armv6 0
#endif
#if CONFIG_THUMB
#else
#endif
