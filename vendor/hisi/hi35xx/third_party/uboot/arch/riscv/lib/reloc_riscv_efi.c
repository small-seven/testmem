#include <efi.h>
#include <elf.h>
#if __riscv_xlen == 64
#define Elf_Dyn		Elf64_Dyn
#define Elf_Rela	Elf64_Rela
#define ELF_R_TYPE	ELF64_R_TYPE
#else
#define Elf_Dyn		Elf32_Dyn
#define Elf_Rela	Elf32_Rela
#define ELF_R_TYPE	ELF32_R_TYPE
#endif
