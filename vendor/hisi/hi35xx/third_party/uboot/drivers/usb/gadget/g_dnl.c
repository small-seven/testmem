#include <common.h>
#include <malloc.h>
#include <mmc.h>
#include <part.h>
#include <usb.h>
#include <g_dnl.h>
#include <usb_mass_storage.h>
#include <dfu.h>
#include <thor.h>
#include <env_callback.h>
#include "gadget_chips.h"
#include "composite.c"
#define STRING_MANUFACTURER 25
#define STRING_PRODUCT 2
#define STRING_USBDOWN 2
#define STRING_SERIAL  3
#define MAX_STRING_SERIAL	256
#define CONFIGURATION_NUMBER 1
#define DRIVER_VERSION		"usb_dnl 2.0"
