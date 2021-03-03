#include <common.h>
#include <phy.h>
#include <fm_eth.h>
#include <asm/io.h>
#include <asm/immap_85xx.h>
#include <asm/fsl_serdes.h>
#define FSL_CORENET_RCWSR13_EC1			0x60000000 /* bits 417..418 */
#define FSL_CORENET_RCWSR13_EC1_FM2_DTSEC5_RGMII	0x00000000
#define FSL_CORENET_RCWSR13_EC1_FM2_GPIO		0x40000000
#define FSL_CORENET_RCWSR13_EC2			0x18000000 /* bits 419..420 */
#define FSL_CORENET_RCWSR13_EC2_FM1_DTSEC5_RGMII	0x00000000
#define FSL_CORENET_RCWSR13_EC2_FM2_DTSEC6_RGMII	0x08000000
#define FSL_CORENET_RCWSR13_EC2_FM1_GPIO		0x10000000
