#define SS_SPI_CMD_BRRD         0x16    /* Read Bank Register */
#define SS_SPI_CMD_BRWR         0x17    /* Write Bank Register */
#define SS_SPI_NOR_BR_LEN       1
#define SS_SPI_NOR_BR_EAE_SHIFT     7
#define SS_SPI_NOR_BR_EAE_MASK      (1 << SS_SPI_NOR_BR_EAE_SHIFT)
#define ss_spi_nor_get_eae_by_br(br)    (((br) & SS_SPI_NOR_BR_EAE_MASK) \
