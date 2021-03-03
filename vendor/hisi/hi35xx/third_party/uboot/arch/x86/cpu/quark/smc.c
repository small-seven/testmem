#include <common.h>
#include <pci.h>
#include <asm/arch/device.h>
#include <asm/arch/mrc.h>
#include <asm/arch/msg_port.h>
#include "mrc_util.h"
#include "hte.h"
#include "smc.h"
#ifdef BACKUP_WCTL
#endif
#ifdef BACKUP_WCMD
#endif
#ifdef BACKUP_RCVN
#endif
#ifdef BACKUP_WDQS
#endif
#ifdef BACKUP_RDQS
#endif
#ifdef BACKUP_WDQ
#endif
#ifdef BACKUP_COMPS
#else
#endif
#ifdef BACKUP_WCMD
#else
#endif
#ifdef BACKUP_WCTL
#else
#endif
#ifdef FORCE_16BIT_DDRIO
#else
#endif
#ifdef HMC_TEST
#endif
#ifdef R2R_SHARING
#ifndef BACKUP_RCVN
#endif
#endif
#ifdef BACKUP_RCVN
#else
#endif
#ifndef BACKUP_RCVN
#endif
#ifdef R2R_SHARING
#endif
#ifdef BACKUP_RCVN
#else
#ifdef R2R_SHARING
#else
#endif
#endif
#ifndef BACKUP_RCVN
#endif
#ifdef R2R_SHARING
#ifndef BACKUP_WDQS
#endif
#endif
#ifdef BACKUP_WDQS
#else
#endif
#ifdef R2R_SHARING
#endif
#ifdef BACKUP_WDQS
#else
#ifdef R2R_SHARING
#endif
#endif
#ifdef BACKUP_RDQS
#else
#ifdef R2R_SHARING
#endif
#endif
#ifdef BACKUP_RDQS
#else
#ifdef R2R_SHARING
#endif
#ifdef RX_EYE_CHECK
#endif
#ifdef R2R_SHARING
#endif
#ifdef R2R_SHARING
#else
#endif
#endif
#ifdef BACKUP_WDQ
#else
#ifdef R2R_SHARING
#endif
#endif
#ifdef BACKUP_WDQ
#else
#ifdef R2R_SHARING
#endif
#ifdef R2R_SHARING
#endif
#ifdef R2R_SHARING
#else
#endif
#endif
