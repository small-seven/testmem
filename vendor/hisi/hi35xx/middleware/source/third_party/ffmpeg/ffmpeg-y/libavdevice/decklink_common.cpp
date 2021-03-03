#include "libavformat/internal.h"
#include <DeckLinkAPI.h>
#ifdef _WIN32
#include <DeckLinkAPI_i.c>
#else
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-prototypes"
#endif
#include <DeckLinkAPIDispatch.cpp>
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif
#include "libavformat/avformat.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/bswap.h"
#include "avdevice.h"
#include "decklink_common.h"
#ifdef _WIN32
#else
#endif
#if BLACKMAGIC_DECKLINK_API_VERSION >= 0x0b000000
#else
#endif
#if BLACKMAGIC_DECKLINK_API_VERSION >= 0x0b000000
#else
#endif
#if BLACKMAGIC_DECKLINK_API_VERSION >= 0x0b000000
#else
#endif
#if BLACKMAGIC_DECKLINK_API_VERSION >= 0x0b000000
#else
#endif
