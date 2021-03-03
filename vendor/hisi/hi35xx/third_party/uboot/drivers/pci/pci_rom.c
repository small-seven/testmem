#include <common.h>
#include <bios_emul.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <pci.h>
#include <pci_rom.h>
#include <vbe.h>
#include <video.h>
#include <video_fb.h>
#include <linux/screen_info.h>
#ifdef CONFIG_X86
#include <acpi_s3.h>
#endif
#if defined(CONFIG_X86) && defined(CONFIG_HAVE_ACPI_RESUME)
#endif
#ifdef CONFIG_VGA_BIOS_ADDR
#else
#endif
#ifndef CONFIG_VGA_BIOS_ADDR
#endif
#ifdef PCI_VGA_RAM_IMAGE_START
#else
#endif
#if defined(CONFIG_FRAMEBUFFER_SET_VESA_MODE) && \
#endif
#ifdef CONFIG_X86
#else
#endif
#ifdef CONFIG_BIOSEMU
#else
#endif
#ifdef CONFIG_BIOSEMU
#endif
#if defined(CONFIG_X86) && (CONFIG_IS_ENABLED(X86_32BIT_INIT) || CONFIG_TPL)
#endif
#ifdef CONFIG_DM_VIDEO
#endif
