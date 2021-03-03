#include <common.h>
#include <dm.h>
#include <errno.h>
#include <regmap.h>
#include <syscon.h>
#include <power/pmic.h>
#include <power/regulator.h>
#define STM32MP_PWR_CR3 0xc
#define STM32MP_PWR_CR3_USB33DEN BIT(24)
#define STM32MP_PWR_CR3_USB33RDY BIT(26)
#define STM32MP_PWR_CR3_REG18DEN BIT(28)
#define STM32MP_PWR_CR3_REG18RDY BIT(29)
#define STM32MP_PWR_CR3_REG11DEN BIT(30)
#define STM32MP_PWR_CR3_REG11RDY BIT(31)
