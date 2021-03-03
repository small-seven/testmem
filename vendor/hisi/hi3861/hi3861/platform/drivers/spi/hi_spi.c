#include <hi3861_platform_base.h>
#include <hi_event.h>
#include <hi_isr.h>
#include <hi_mem.h>
#include <hi_sem.h>
#include <hi_spi.h>
#include <hi_stdlib.h>
#include <hi_time.h>
#include <hi_types_base.h>
#ifdef CONFIG_SPI_DMA_SUPPORT
#include <hi_dma.h>
#endif
#include <time.h>
#include "spi.h"
#define SPI_HOST_OPT_BASE (SPI_OPT_ENABLE_SPI |  \
#define SPI_SLAVE_OPT_READ (SPI_OPT_ENABLE_SPI |  \
#define SPI_SLAVE_OPT_WRITE (SPI_OPT_ENABLE_SPI |  \
#define CLKEN_SPI0 5
#define CLKEN_SPI1 0
#ifdef CONFIG_SPI_DMA_SUPPORT
#endif
#ifdef CONFIG_SPI_DMA_SUPPORT
#else
#endif
#ifdef CONFIG_SPI_DMA_SUPPORT
#else
#endif
#ifdef CONFIG_SPI_DMA_SUPPORT
#else
#endif
#ifdef CONFIG_SPI_DMA_SUPPORT
#endif
#ifdef CONFIG_SPI_DMA_SUPPORT
#endif
#ifdef CONFIG_SPI_DMA_SUPPORT
#endif
