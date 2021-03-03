#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <errno.h>
#include <atsha204a-i2c.h>
#include <u-boot/crc.h>
#define ATSHA204A_TWLO			60
#define ATSHA204A_TRANSACTION_TIMEOUT	100000
#define ATSHA204A_TRANSACTION_RETRY	5
#define ATSHA204A_EXECTIME		5000
