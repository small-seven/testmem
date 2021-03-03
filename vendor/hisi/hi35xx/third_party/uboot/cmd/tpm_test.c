#include <common.h>
#include <command.h>
#include <tpm-v1.h>
#include "tpm-user-utils.h"
#define TPM_CHECK(tpm_command) do { \
#define INDEX0			0xda70
#define INDEX1			0xda71
#define INDEX2			0xda72
#define INDEX3			0xda73
#define INDEX_INITIALISED	0xda80
#define PHYS_PRESENCE		4
#define PRESENCE		8
#define reboot() do { \
#define PERMPPGL (TPM_NV_PER_PPWRITE | TPM_NV_PER_GLOBALLOCK)
#define PERMPP TPM_NV_PER_PPWRITE
#define TTPM_CHECK(op, time_limit) do { \
#define TPM_MAX_NV_WRITES_NOOWNER 64
#define VOIDTEST(XFUNC) \
#define VOIDENT(XNAME) \
