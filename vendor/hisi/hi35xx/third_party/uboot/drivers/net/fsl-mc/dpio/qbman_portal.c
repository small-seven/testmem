#include <asm/arch/clock.h>
#include "qbman_portal.h"
#define QBMAN_MC_ACQUIRE       0x30
#define QBMAN_WQCHAN_CONFIGURE 0x46
#define QBMAN_CINH_SWP_EQAR    0x8c0
#define QBMAN_CINH_SWP_DCAP    0xac0
#define QBMAN_CINH_SWP_SDQCR   0xb00
#define QBMAN_CINH_SWP_RAR     0xcc0
#define QBMAN_CENA_SWP_EQCR(n) (0x000 + ((uint32_t)(n) << 6))
#define QBMAN_CENA_SWP_DQRR(n) (0x200 + ((uint32_t)(n) << 6))
#define QBMAN_CENA_SWP_RCR(n)  (0x400 + ((uint32_t)(n) << 6))
#define QBMAN_CENA_SWP_CR      0x600
#define QBMAN_CENA_SWP_RR(vb)  (0x700 + ((uint32_t)(vb) >> 1))
#define QBMAN_CENA_SWP_VDQCR   0x780
#define QBMAN_IDX_FROM_DQRR(p) (((unsigned long)p & 0x1ff) >> 6)
#define CODE_SDQCR_DQSRC(n) QB_CODE(0, n, 1)
#ifdef QBMAN_CHECKING
#endif
#ifdef QBMAN_CHECKING
#endif
#ifdef QBMAN_CHECKING
#endif
#ifdef QBMAN_CHECKING
#endif
#ifdef QBMAN_CHECKING
#endif
#ifdef QBMAN_CHECKING
#endif
#ifdef QBMAN_CHECKING
#endif
#define EQAR_IDX(eqar)     ((eqar) & 0x7)
#define EQAR_VB(eqar)      ((eqar) & 0x80)
#define EQAR_SUCCESS(eqar) ((eqar) & 0x100)
#define QBMAN_DQRR_RESPONSE_DQ        0x60
#define QBMAN_DQRR_RESPONSE_FQRN      0x21
#define QBMAN_DQRR_RESPONSE_FQRNI     0x22
#define QBMAN_DQRR_RESPONSE_FQPN      0x24
#define QBMAN_DQRR_RESPONSE_FQDAN     0x25
#define QBMAN_DQRR_RESPONSE_CDAN      0x26
#define QBMAN_DQRR_RESPONSE_CSCN_MEM  0x27
#define QBMAN_DQRR_RESPONSE_CGCU      0x28
#define QBMAN_DQRR_RESPONSE_BPSCN     0x29
#define QBMAN_DQRR_RESPONSE_CSCN_WQ   0x2a
#define RAR_IDX(rar)     ((rar) & 0x7)
#define RAR_VB(rar)      ((rar) & 0x80)
#define RAR_SUCCESS(rar) ((rar) & 0x100)
