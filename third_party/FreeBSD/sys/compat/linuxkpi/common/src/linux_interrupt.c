#include "linux/interrupt.h"
#include "los_hwi.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
void linux_free_irq(unsigned int irq, void *devID)
{
    HwiIrqParam irqParam;

    if (OS_INT_ACTIVE) {
        return;
    }

    irqParam.swIrq = (INT32)irq;
    irqParam.pDevId = devID;

    (VOID)LOS_HwiDelete(irq, &irqParam);
    return;
}
#ifdef WORKQUEUE_SUPPORT_PRIORITY
#else
#endif
#ifdef WORKQUEUE_SUPPORT_PRIORITY
#endif
#ifdef WORKQUEUE_SUPPORT_PRIORITY
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
