#include <linux/types.h>
#include <common.h>
#include <errno.h>
#include <exports.h>
#include <linux/string.h>
#include <image.h>
#include <asm/io.h>
#include <cpu_func.h>
#include <asm/setup.h>
#define SECURE		0x0
#define NON_SECURE	0x1
#define EP_EE_MASK      0x2
#define EP_EE_LITTLE    0x0
#define EP_EE_BIG       0x2
#define ep_get_ee(x) ((x) & EP_EE_MASK)
#define ep_set_ee(x, ee) ((x) = ((x) & ~EP_EE_MASK) | (ee))
#define DAIF_FIQ_BIT		(1 << 0)
#define DAIF_IRQ_BIT		(1 << 1)
#define DAIF_ABT_BIT		(1 << 2)
#define DAIF_DBG_BIT		(1 << 3)
#define SPSR_DAIF_SHIFT		6
#define SPSR_DAIF_MASK		0xf
#define SPSR_AIF_SHIFT          6
#define SPSR_AIF_MASK           0x7
#define SPSR_E_SHIFT            9
#define SPSR_E_MASK                     0x1
#define SPSR_E_LITTLE           0x0
#define SPSR_E_BIG                      0x1
#define SPSR_T_SHIFT            5
#define SPSR_T_MASK                     0x1
#define SPSR_T_ARM                      0x0
#define SPSR_T_THUMB            0x1
#define MODE_SP_SHIFT		0x0
#define MODE_SP_MASK		0x1
#define MODE_SP_EL0		0x0
#define MODE_SP_ELX		0x1
#define MODE_RW_SHIFT		0x4
#define MODE_RW_MASK		0x1
#define MODE_RW_64			0x0
#define MODE_RW_32			0x1
#define MODE_EL_SHIFT		0x2
#define MODE_EL_MASK		0x3
#define MODE_EL3		0x3
#define MODE_EL2		0x2
#define MODE_EL1		0x1
#define MODE_EL0		0x0
#define MODE32_SHIFT            0
#define MODE32_MASK             0xf
#define MODE32_USR              0x0
#define MODE32_FIQ              0x1
#define MODE32_IRQ              0x2
#define MODE32_SVC              0x3
#define MODE32_MON              0x6
#define MODE32_ABT              0x7
#define MODE32_HYP              0xa
#define MODE32_UND              0xb
#define MODE32_SYS              0xf
#define DISABLE_ALL_EXCEPTIONS \
#define PARAM_EP_SECURITY_MASK    0x1
#define get_security_state(x) ((x) & PARAM_EP_SECURITY_MASK)
#define set_security_state(x, security) \
#define spsr_64(el, sp, daif) \
#define spsr_mode32(mode, isa, endian, aif) \
#define	_UUID_NODE_LEN		6
typedef struct uuid uuid_t;

#define FIP_MAX_FILES			10

/* TODO: Update this number as required */
#define TOC_HEADER_SERIAL_NUMBER	0x12345678

#define FLAG_FILENAME			(1 << 0)

#define WAIT_A53MP_UP_NUM_OF_TIMES	10700

typedef struct entry_lookup_list {
	const char       *name;
	uuid_t           name_uuid;
	const char       *command_line_name;
	struct file_info *info;
	unsigned int     flags;
} entry_lookup_list_t;
typedef struct file_info {
	uuid_t 		name_uuid;
	const char      *filename;
	unsigned int 	size;
	void            *image_buffer;
	entry_lookup_list_t *entry;
} file_info_t;
#define TOC_HEADER_NAME	0xAA640001
#define UUID_TRUSTED_BOOT_FIRMWARE_BL2 \
#define UUID_SCP_FIRMWARE_BL30 \
#define UUID_EL3_RUNTIME_FIRMWARE_BL31 \
#define UUID_SECURE_PAYLOAD_BL32 \
#define UUID_NON_TRUSTED_FIRMWARE_BL33 \
typedef struct fip_toc_header {
	uint32_t	name;
	uint32_t	serial_number;
	uint64_t	flags;
} fip_toc_header_t;
typedef struct fip_toc_entry {
	uuid_t		uuid;
	uint64_t	offset_address;
	uint64_t	size;
	uint64_t	flags;
} fip_toc_entry_t;
typedef struct aapcs64_params {
	uint64_t arg0;
	uint64_t arg1;
	uint64_t arg2;
	uint64_t arg3;
	uint64_t arg4;
	uint64_t arg5;
	uint64_t arg6;
	uint64_t arg7;
} aapcs64_params_t;
typedef struct param_header {
	uint8_t type;		/* type of the structure */
	uint8_t version;    /* version of this structure */
	uint16_t size;      /* size of this structure in bytes */
	uint32_t attr;      /* attributes: unused bits SBZ */
} param_header_t;
typedef struct entry_point_info {
	param_header_t h;
	uint64_t pc;
	uint32_t spsr;
	aapcs64_params_t args;
} entry_point_info_t;
typedef struct atf_image_info {
	param_header_t h;
	uint64_t image_base;   /* physical address of base of image */
	uint32_t image_size;    /* bytes read from image file */
	uint32_t copied_size;	/* image size copied in blocks */
} atf_image_info_t;
typedef struct bl31_params {
	param_header_t h;
	uint64_t bl31_image_info;//atf_image_info_t *bl31_image_info;
	uint64_t bl32_ep_info;//entry_point_info_t *bl32_ep_info;
	uint64_t bl32_image_info;//atf_image_info_t *bl32_image_info;
	uint64_t bl33_ep_info;//entry_point_info_t *bl33_ep_info;
	uint64_t bl33_image_info;//atf_image_info_t *bl33_image_info;
} bl31_params_t;
#define BL33_LOAD_ADDR  (kernel_load_addr - 0x40)
#define FDT_LOAD_ADDR   (kernel_load_addr + 0x1F80000)
#define BL31_BASE       (kernel_load_addr + 0x2F80000)
#define BL31_SIZE	    0x200000
