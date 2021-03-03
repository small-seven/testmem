#include <common.h>
#include <fsl_ifc.h>
#ifdef CONFIG_TFABOOT
#if defined(CONFIG_SYS_CSPR0) && defined(CONFIG_SYS_CSOR0)
#ifdef CONFIG_SYS_CSPR0_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK0
#else
#endif
#ifdef CONFIG_SYS_CSOR0_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR0_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK0_FINAL
#else
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 2
#if defined(CONFIG_SYS_CSPR1) && defined(CONFIG_SYS_CSOR1)
#ifdef CONFIG_SYS_CSPR1_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK1
#else
#endif
#ifdef CONFIG_SYS_CSOR1_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR1_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK1_FINAL
#else
#endif
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 3
#if defined(CONFIG_SYS_CSPR2) && defined(CONFIG_SYS_CSOR2)
#ifdef CONFIG_SYS_CSPR2_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK2
#else
#endif
#ifdef CONFIG_SYS_CSOR2_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR2_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK2_FINAL
#else
#endif
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 4
#if defined(CONFIG_SYS_CSPR3) && defined(CONFIG_SYS_CSOR3)
#ifdef CONFIG_SYS_CSPR3_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK3
#else
#endif
#ifdef CONFIG_SYS_CSOR3_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR3_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK3_FINAL
#else
#endif
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 5
#if defined(CONFIG_SYS_CSPR4) && defined(CONFIG_SYS_CSOR4)
#ifdef CONFIG_SYS_CSPR4_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK4
#else
#endif
#ifdef CONFIG_SYS_CSOR4_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR4_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK4_FINAL
#else
#endif
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 6
#if defined(CONFIG_SYS_CSPR5) && defined(CONFIG_SYS_CSOR5)
#ifdef CONFIG_SYS_CSPR5_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK5
#else
#endif
#ifdef CONFIG_SYS_CSOR5_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR5_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK5_FINAL
#else
#endif
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 7
#if defined(CONFIG_SYS_CSPR6) && defined(CONFIG_SYS_CSOR6)
#ifdef CONFIG_SYS_CSPR6_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK6
#else
#endif
#ifdef CONFIG_SYS_CSOR6_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR6_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK6_FINAL
#else
#endif
#endif
#endif
#if CONFIG_SYS_FSL_IFC_BANK_COUNT >= 8
#if defined(CONFIG_SYS_CSPR7) && defined(CONFIG_SYS_CSOR7)
#ifdef CONFIG_SYS_CSPR7_EXT
#else
#endif
#ifdef CONFIG_SYS_AMASK7
#else
#endif
#ifdef CONFIG_SYS_CSOR7_EXT
#else
#endif
#ifdef CONFIG_SYS_CSPR7_FINAL
#else
#endif
#ifdef CONFIG_SYS_AMASK7_FINAL
#else
#endif
#endif
#endif
#endif
#ifdef CONFIG_TFABOOT
#else
#if defined(CONFIG_SYS_CSPR0) && defined(CONFIG_SYS_CSOR0)
#ifndef CONFIG_A003399_NOR_WORKAROUND
#ifdef CONFIG_SYS_CSPR0_EXT
#endif
#ifdef CONFIG_SYS_CSOR0_EXT
#endif
#endif
#endif
#ifdef CONFIG_SYS_CSPR1_EXT
#endif
#ifdef CONFIG_SYS_CSOR1_EXT
#endif
#if defined(CONFIG_SYS_CSPR1) && defined(CONFIG_SYS_CSOR1)
#endif
#ifdef CONFIG_SYS_CSPR2_EXT
#endif
#ifdef CONFIG_SYS_CSOR2_EXT
#endif
#if defined(CONFIG_SYS_CSPR2) && defined(CONFIG_SYS_CSOR2)
#endif
#ifdef CONFIG_SYS_CSPR3_EXT
#endif
#ifdef CONFIG_SYS_CSOR3_EXT
#endif
#if defined(CONFIG_SYS_CSPR3) && defined(CONFIG_SYS_CSOR3)
#endif
#ifdef CONFIG_SYS_CSPR4_EXT
#endif
#ifdef CONFIG_SYS_CSOR4_EXT
#endif
#if defined(CONFIG_SYS_CSPR4) && defined(CONFIG_SYS_CSOR4)
#endif
#ifdef CONFIG_SYS_CSPR5_EXT
#endif
#ifdef CONFIG_SYS_CSOR5_EXT
#endif
#if defined(CONFIG_SYS_CSPR5) && defined(CONFIG_SYS_CSOR5)
#endif
#ifdef CONFIG_SYS_CSPR6_EXT
#endif
#ifdef CONFIG_SYS_CSOR6_EXT
#endif
#if defined(CONFIG_SYS_CSPR6) && defined(CONFIG_SYS_CSOR6)
#endif
#ifdef CONFIG_SYS_CSPR7_EXT
#endif
#ifdef CONFIG_SYS_CSOR7_EXT
#endif
#if defined(CONFIG_SYS_CSPR7) && defined(CONFIG_SYS_CSOR7)
#endif
#ifdef CONFIG_SYS_CSPR0_FINAL
#endif
#ifdef CONFIG_SYS_AMASK0_FINAL
#endif
#ifdef CONFIG_SYS_CSPR1_FINAL
#endif
#ifdef CONFIG_SYS_AMASK1_FINAL
#endif
#ifdef CONFIG_SYS_CSPR2_FINAL
#endif
#ifdef CONFIG_SYS_AMASK2_FINAL
#endif
#ifdef CONFIG_SYS_CSPR3_FINAL
#endif
#ifdef CONFIG_SYS_AMASK3_FINAL
#endif
#endif
