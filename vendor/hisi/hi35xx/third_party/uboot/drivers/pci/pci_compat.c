#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <pci.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include "pci_internal.h"
#define PCI_HOSE_OP(rw, name, size, type)				\
