#include <net/pfe_eth/pfe_eth.h>
#include <net/pfe_eth/pfe/pfe_hw.h>
u32 pe_pmem_read(int id, u32 addr, u8 size)
{
	u32 offset = addr & 0x3;
	u32 mask = 0xffffffff >> ((4 - size) << 3);
	u32 val;

	addr = pe[id].pmem_base_addr | ((addr & ~0x3) & (pe[id].pmem_size - 1))
		| PE_MEM_ACCESS_READ | PE_MEM_ACCESS_IMEM |
		PE_MEM_ACCESS_BYTE_ENABLE(offset, size);

	writel(addr, pe[id].mem_access_addr);
	val = be32_to_cpu(readl(pe[id].mem_access_rdata));

	return (val >> (offset << 3)) & mask;
}
void pe_dmem_write(int id, u32 val, u32 addr, u8 size)
{
	u32 offset = addr & 0x3;

	addr = pe[id].dmem_base_addr | (addr & ~0x3) | PE_MEM_ACCESS_WRITE |
		PE_MEM_ACCESS_DMEM | PE_MEM_ACCESS_BYTE_ENABLE(offset, size);

	/* Indirect access interface is byte swapping data being written */
	writel(cpu_to_be32(val << (offset << 3)), pe[id].mem_access_wdata);
	writel(addr, pe[id].mem_access_addr);
}
u32 pe_dmem_read(int id, u32 addr, u8 size)
{
	u32 offset = addr & 0x3;
	u32 mask = 0xffffffff >> ((4 - size) << 3);
	u32 val;

	addr = pe[id].dmem_base_addr | (addr & ~0x3) | PE_MEM_ACCESS_READ |
		PE_MEM_ACCESS_DMEM | PE_MEM_ACCESS_BYTE_ENABLE(offset, size);

	writel(addr, pe[id].mem_access_addr);

	/* Indirect access interface is byte swapping data being read */
	val = be32_to_cpu(readl(pe[id].mem_access_rdata));

	return (val >> (offset << 3)) & mask;
}
static void class_pe_lmem_memset(u32 dst, int val, unsigned int len)
{
	u32 len32 = len >> 2;
	int i;

	val = val | (val << 8) | (val << 16) | (val << 24);

	for (i = 0; i < len32; i++, dst += 4)
		class_bus_write(val, dst, 4);

	if (len & 0x2) {
		class_bus_write(val, dst, 2);
		dst += 2;
	}

	if (len & 0x1) {
		class_bus_write(val, dst, 1);
		dst++;
	}
}
void pe_lmem_read(u32 *dst, u32 len, u32 offset)
{
	u32 len32 = len >> 2;
	int i = 0;

	for (i = 0; i < len32; dst++, i++, offset += 4)
		*dst = class_bus_read(PE_LMEM_BASE_ADDR + offset, 4);

	if (len & 0x03)
		*dst = class_bus_read(PE_LMEM_BASE_ADDR + offset, (len & 0x03));
}
void pe_lmem_write(u32 *src, u32 len, u32 offset)
{
	u32 len32 = len >> 2;
	int i = 0;

	for (i = 0; i < len32; src++, i++, offset += 4)
		class_bus_write(*src, PE_LMEM_BASE_ADDR + offset, 4);

	if (len & 0x03)
		class_bus_write(*src, PE_LMEM_BASE_ADDR + offset, (len &
					0x03));
}
