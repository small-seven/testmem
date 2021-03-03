#define W25Q256FV_CR_4BYTE_MASK     0x1
#define WB_SPI_NOR_SR_ADS_MASK  1
#define wb_spi_nor_get_4byte_by_sr(sr)  ((sr) & WB_SPI_NOR_SR_ADS_MASK)
#define SPI_CMD_FIRST_RESET_4ADDR  0x66
#define SPI_CMD_SECOND_RESET_4ADDR 0x99
