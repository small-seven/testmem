#ifdef WPA_TRACE_BFD
#define _GNU_SOURCE
#include <link.h>
#endif /* WPA_TRACE_BCD */
#include "includes.h"
#include "common.h"
#include "trace.h"
#ifdef WPA_TRACE
#ifdef WPA_TRACE_BFD
#include <bfd.h>
#define DMGL_PARAMS      (1 << 0)
#define DMGL_ANSI        (1 << 1)
#else /* WPA_TRACE_BFD */
#define wpa_trace_bfd_init() do { } while (0)
#define wpa_trace_bfd_addr(pc) do { } while (0)
#define wpa_trace_bfd_addr2func(pc) NULL
#endif /* WPA_TRACE_BFD */
#ifdef WPA_TRACE_BFD
#endif /* WPA_TRACE_BFD */
#endif /* WPA_TRACE */
