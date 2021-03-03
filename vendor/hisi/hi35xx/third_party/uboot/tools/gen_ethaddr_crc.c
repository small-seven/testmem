#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <u-boot/crc.h>
#define ARP_HLEN 6 /* Length of hardware address */
#define ARP_HLEN_ASCII (ARP_HLEN * 2) + (ARP_HLEN - 1) /* with separators */
#define ARP_HLEN_LAZY (ARP_HLEN * 2) /* separatorless hardware address length */
