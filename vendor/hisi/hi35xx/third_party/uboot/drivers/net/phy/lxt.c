#include <common.h>
#include <phy.h>
#define MIIM_LXT971_SR2                     0x11  /* Status Register 2  */
#define MIIM_LXT971_SR2_SPEED_MASK 0x4200
#define MIIM_LXT971_SR2_10HDX     0x0000  /*  10 Mbit half duplex selected */
#define MIIM_LXT971_SR2_10FDX     0x0200  /*  10 Mbit full duplex selected */
#define MIIM_LXT971_SR2_100HDX    0x4000  /* 100 Mbit half duplex selected */
#define MIIM_LXT971_SR2_100FDX    0x4200  /* 100 Mbit full duplex selected */
