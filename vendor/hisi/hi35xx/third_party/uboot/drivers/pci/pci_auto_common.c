#include <common.h>
#include <dm.h>
#include <errno.h>
#include <pci.h>
int pciauto_region_allocate(struct pci_region *res, pci_size_t size,
	pci_addr_t *bar, bool supports_64bit)
{
	pci_addr_t addr;

	if (!res) {
		debug("No resource\n");
		goto error;
	}

	addr = ((res->bus_lower - 1) | (size - 1)) + 1;

	if (addr - res->bus_start + size > res->size) {
		debug("No room in resource, avail start=%llx / size=%llx, "
		      "need=%llx\n", (unsigned long long)res->bus_lower,
		      (unsigned long long)res->size, (unsigned long long)size);
		goto error;
	}

	if (upper_32_bits(addr) && !supports_64bit) {
		debug("Cannot assign 64-bit address to 32-bit-only resource\n");
		goto error;
	}

	res->bus_lower = addr + size;

	debug("address=0x%llx bus_lower=0x%llx\n", (unsigned long long)addr,
	      (unsigned long long)res->bus_lower);

	*bar = addr;
	return 0;

 error:
	*bar = (pci_addr_t)-1;
	return -1;
}
