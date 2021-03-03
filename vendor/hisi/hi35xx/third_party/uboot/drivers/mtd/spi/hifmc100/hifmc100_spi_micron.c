#define SPI_CMD_FIRST_RESET_4ADDR  0x66
#define SPI_CMD_SECOND_RESET_4ADDR 0x99
#define SPI_CMD_FLAG_SR_MICRON  0x70  /* READ FLAG STATUS REGISTER */
#define SPI_CMD_RD_RDCR_MICRON  0xB5  /* READ NONVOLATILE CONFIGURATION
#define SPI_CMD_WR_RDCR_MICRON  0xB1 /* WRITE NONVOLATILE CONFIGURATION
#define SPI_NOR_ADS_MASK    0x1
#define spi_nor_get_4byte_by_flag_sr(sr)     ((sr) & SPI_NOR_ADS_MASK)
#define spi_nor_ads_set_4byte(cr)        ((cr) & (~SPI_NOR_ADS_MASK))
#define spi_nor_ads_get_4byte(cr)        ((cr) & SPI_NOR_ADS_MASK)
