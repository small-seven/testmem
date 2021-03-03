#include "libavutil/intreadwrite.h"
#include "avio_internal.h"
#include "avformat.h"
#include "internal.h"
#define MAX_AUDIO_SUBPACKETS 100
typedef struct VIV_SB_block {
    int size, n_packets;
    int64_t byte_offset;
    int64_t packet_offset;
} VIV_SB_block;
typedef struct VIV_SB_entry {
    int size, flag;
} VIV_SB_entry;
typedef struct VIV_AudioSubpacket {
    int start, pcm_bytes;
} VIV_AudioSubpacket;
typedef struct VividasDemuxContext {
    int n_sb_blocks;
    VIV_SB_block *sb_blocks;
    int num_audio;

    uint32_t sb_key;
    int64_t sb_offset;

    int current_sb, current_sb_entry;
    uint8_t *sb_buf;
    AVIOContext *sb_pb;
    int n_sb_entries;
    VIV_SB_entry *sb_entries;

    int n_audio_subpackets;
    int current_audio_subpacket;

    int64_t audio_sample;

    VIV_AudioSubpacket audio_subpackets[MAX_AUDIO_SUBPACKETS];
} VividasDemuxContext;
