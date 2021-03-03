#include <common.h>
#include <clk.h>
#include <dm.h>
#include <syscon.h>
#include <wdt.h>
#include <asm/io.h>
#include <linux/iopoll.h>
#define IWDG_KR		0x00	/* Key register */
#define IWDG_PR		0x04	/* Prescaler Register */
#define IWDG_RLR	0x08	/* ReLoad Register */
#define IWDG_SR		0x0C	/* Status Register */
#define KR_KEY_RELOAD	0xAAAA	/* Reload counter enable */
#define KR_KEY_ENABLE	0xCCCC	/* Peripheral enable */
#define KR_KEY_EWA	0x5555	/* Write access enable */
#define PR_256		0x06	/* Prescaler set to 256 */
#define RLR_MAX		0xFFF	/* Max value supported by reload register */
#define SR_PVU		BIT(0)	/* Watchdog prescaler value update */
#define SR_RVU		BIT(1)	/* Watchdog counter reload value update */
