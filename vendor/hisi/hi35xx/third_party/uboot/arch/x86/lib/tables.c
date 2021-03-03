#include <common.h>
#include <smbios.h>
#include <asm/sfi.h>
#include <asm/mpspec.h>
#include <asm/tables.h>
#include <asm/acpi_table.h>
#include <asm/coreboot_tables.h>
typedef ulong (*table_write)(ulong addr);

static table_write table_write_funcs[] = {
#ifdef CONFIG_GENERATE_PIRQ_TABLE
	write_pirq_routing_table,
#endif
#ifdef CONFIG_GENERATE_SFI_TABLE
	write_sfi_table,
#endif
#ifdef CONFIG_GENERATE_MP_TABLE
	write_mp_table,
#endif
#ifdef CONFIG_GENERATE_ACPI_TABLE
	write_acpi_tables,
#endif
#ifdef CONFIG_GENERATE_SMBIOS_TABLE
	write_smbios_table,
#endif
};
#ifdef CONFIG_SEABIOS
#endif
#ifdef CONFIG_SEABIOS
#endif
#ifdef CONFIG_SEABIOS
#endif
