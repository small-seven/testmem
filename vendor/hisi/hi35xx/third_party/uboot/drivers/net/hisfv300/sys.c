#include <config.h>
#include "hieth.h"
#include "sys.h"
#if defined(CONFIG_GODBOX) || defined(CONFIG_GODBOX_V1)
#define HIETH_CRG_REG (REG_BASE_CRG + REG_PERI_CRG26)
#else
#define HIETH_CRG_REG (CRG_REG_BASE + REG_ETH_CRG)
#endif
#define ETH_SOFT_RESET bit(0)
#if defined(CONFIG_GODBOX) || defined(CONFIG_GODBOX_V1)
#define ETH_CLK_ENABLE bit(8)
#elif defined(CONFIG_TARGET_HI3521DV200) || defined(CONFIG_TARGET_HI3520DV500)
#define ETH_CLK_ENABLE bit(4)
#else
#define ETH_CLK_ENABLE bit(1)
#endif
#if defined(HISFV_RESET_PHY_BY_CRG)
#if defined(CONFIG_TARGET_HI3521DV200) || defined(CONFIG_TARGET_HI3520DV500)
#define ETH_EXTERNAL_PHY_RESET bit(0)
#else
#define ETH_EXTERNAL_PHY_RESET bit(3)
#endif
#endif
#if defined(CONFIG_TARGET_HI3521DV200) || defined(CONFIG_TARGET_HI3520DV500)
#define ETH_CORE_CLK_SELECT_54M bit(12)
#else
#define ETH_CORE_CLK_SELECT_54M bit(7)
#endif
#if defined(CONFIG_HI3520D)
#define HIETH_SYSCTL_REG       (SYS_CTRL_REG_BASE + PERIPHCTRL24)
#define ETH_INTERNAL_PHY_RESET bit(2)
#define HIETH_EFUSE_REG        (CRG_REG_BASE + EFUSE_CTRL_CRG)
#define HIETH_EFUSE_DATA_REG   (EFUSE_REG_BASE + EFUSE_DATA_SEL)
#elif defined(CONFIG_HI3536DV100)
#define HIETH_SYSCTL_REG        (MISC_REG_BASE + REG_FEPHY_CTRL1)
#define BIT_FEPHY_SEL           bit(5)
#define BIT_PHY_RMII_MODE       bit(8)
#define ETH_INTERNAL_PHY_RESET  bit(9)
#define ETH_INTERNAL_PHY_CLK_EN bit(10)
#endif
#if defined(CONFIG_TARGET_HI3516EV200)
#define HIETH_SYSCTL_REG        (SYS_CTRL_REG_BASE + MISC_CTRL9)
#define ETH_INTERNAL_PHY_RESET  bit(3)
#define ETH_INTERNAL_PHY_CLK_EN bit(2)
#endif
#if defined(CONFIG_TARGET_HI3521DV200) || defined(CONFIG_TARGET_HI3520DV500)
#define HIETH_SYSCTL_REG        (SYS_CTRL_REG_BASE + REG_FEPHY_CTRL0)
#define ETH_INTERNAL_PHY_RESET  bit(0)
#define ETH_INTERNAL_PHY_CLK_EN bit(4)
#endif
#if defined(CONFIG_TARGET_HI3521DV200) || defined(CONFIG_TARGET_HI3520DV500)
#define HIETH_CRG_INPHY_CLK_REG   (CRG_REG_BASE + REG_INFEPHY_CLK_RST)
#define HIETH_CRG_EXTPHY_CLK_REG  (CRG_REG_BASE + REG_EXTFEPHY_CLK_RST)
#else
#define HIETH_CRG_INPHY_CLK_REG   HIETH_CRG_REG
#define HIETH_CRG_EXTPHY_CLK_REG  HIETH_CRG_REG
#endif
#if defined(CONFIG_TARGET_HI3516EV300)
#define HIETH_SYSCTL_REG        (SYS_CTRL_REG_BASE + MISC_CTRL9)
#define ETH_INTERNAL_PHY_RESET  bit(3)
#define ETH_INTERNAL_PHY_CLK_EN bit(2)
#endif
#if defined(CONFIG_TARGET_HI3518EV300)
#define HIETH_SYSCTL_REG        (SYS_CTRL_REG_BASE + MISC_CTRL9)
#define ETH_INTERNAL_PHY_RESET  bit(3)
#define ETH_INTERNAL_PHY_CLK_EN bit(2)
#endif
#if defined(CONFIG_TARGET_HI3516DV200)
#define HIETH_SYSCTL_REG        (SYS_CTRL_REG_BASE + MISC_CTRL9)
#define ETH_INTERNAL_PHY_RESET  bit(3)
#define ETH_INTERNAL_PHY_CLK_EN bit(2)
#endif
#if defined(CONFIG_HI3536DV100)
#endif
#if defined(INNER_PHY) && defined(CONFIG_HI3520D)
#else
#endif
#ifdef INNER_PHY
#if defined(CONFIG_HI3536DV100)
#endif
#else
#endif
#if defined(INNER_PHY) && defined(CONFIG_HI3520D)
#define MDIO_RWCTRL      0x1100
#define tmp_mdio_ready() \
#else
#endif
#if defined(INNER_PHY) && defined(CONFIG_HI3520D)
#define MDIO_RWCTRL      0x1100
#define tmp_mdio_ready() \
#else
#endif
#if defined(CONFIG_HI3536DV100) || defined(INNER_PHY)
#endif
#if defined(CONFIG_HI3536DV100)
#endif
#ifdef INNER_PHY
#if defined(CONFIG_HI3536DV100)
#endif
#if defined(CONFIG_HI3536DV100)
#endif
#endif
#if defined(HISFV_RESET_PHY_BY_CRG)
#endif
#ifdef HISFV_RESET_GPIO_EN
#endif
