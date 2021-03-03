#include <common.h>
#include <dm.h>
#include <power/pmic.h>
#include <spmi/spmi.h>
#define PID_SHIFT 8
#define PID_MASK (0xFF << PID_SHIFT)
#define REG_MASK 0xFF
