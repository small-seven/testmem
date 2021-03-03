#define SPI_NOR_ISSI_QE_SHIFT      6
#define SPI_NOR_ISSI_SRWD_MASK      (1 << 7)
#define SPI_NOR_ISSI_QE_MASK        (1 << SPI_NOR_ISSI_QE_SHIFT)
#define spi_nor_issi_get_qe(sr)        (((sr) & SPI_NOR_ISSI_QE_MASK) \
