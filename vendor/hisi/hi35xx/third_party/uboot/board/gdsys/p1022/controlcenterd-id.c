#ifdef CCDM_ID_DEBUG
#define DEBUG
#endif
#include <common.h>
#include <command.h>
#include <dm.h>
#include <env.h>
#include <malloc.h>
#include <fs.h>
#include <i2c.h>
#include <mmc.h>
#include <tpm-v1.h>
#include <u-boot/crc.h>
#include <u-boot/sha1.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <pca9698.h>
#undef CCDM_FIRST_STAGE
#undef CCDM_SECOND_STAGE
#undef CCDM_AUTO_FIRST_STAGE
#ifdef CONFIG_DEVELOP
#define CCDM_DEVELOP
#endif
#ifdef CONFIG_TRAILBLAZER
#define CCDM_FIRST_STAGE
#undef CCDM_SECOND_STAGE
#else
#undef CCDM_FIRST_STAGE
#define CCDM_SECOND_STAGE
#endif
#if defined(CCDM_DEVELOP) && defined(CCDM_SECOND_STAGE) && \
#define CCDM_AUTO_FIRST_STAGE
#endif
#define IS_PCR_HREG(spec) ((spec) & 0x20)
#define IS_FIX_HREG(spec) (((spec) & 0x38) == 0x08)
#define IS_VAR_HREG(spec) (((spec) & 0x38) == 0x10)
#define HREG_IDX(spec) ((spec) & (IS_PCR_HREG(spec) ? 0x1f : 0x7))
#ifdef CCDM_SECOND_STAGE
#else
#endif
#ifdef CCDM_SECOND_STAGE
#endif
#if defined(CCDM_FIRST_STAGE) || (defined CCDM_AUTO_FIRST_STAGE)
#endif
#ifdef CCDM_SECOND_STAGE
#endif
#if defined(CCDM_FIRST_STAGE) || (defined CCDM_AUTO_FIRST_STAGE)
#ifndef CCDM_SECOND_STAGE
#else
#endif
#endif
#ifdef CCDM_FIRST_STAGE
#ifndef CCDM_SECOND_STAGE
#endif
#endif
#ifdef CCDM_SECOND_STAGE
#ifdef CCDM_AUTO_FIRST_STAGE
#else
#endif
#endif
#ifdef CCDM_SECOND_STAGE
#else
#endif
#ifdef CCDM_DEVELOP
#endif
#ifdef CCDM_DEVELOP
#else
#endif
#ifdef CCDM_DEVELOP
#endif
#ifdef CCDM_FIRST_STAGE
#endif
#ifdef CCDM_SECOND_STAGE
#endif
