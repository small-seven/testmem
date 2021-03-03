#include <common.h>
#include <linux/bitops.h>
#include <linux/bitfield.h>
#include <malloc.h>
#include <clk-uclass.h>
#include <clk.h>
#include <dm.h>
#include <asm/arch/sys_proto.h>
#include <zynqmp_firmware.h>
#define MAX_PARENT			100
#define MAX_NODES			6
#define MAX_NAME_LEN			50
#define CLK_TYPE_SHIFT			2
#define PM_API_PAYLOAD_LEN		3
#define NA_PARENT			0xFFFFFFFF
#define DUMMY_PARENT			0xFFFFFFFE
#define CLK_TYPE_FIELD_LEN		4
#define CLK_TOPOLOGY_NODE_OFFSET	16
#define NODES_PER_RESP			3
#define CLK_TYPE_FIELD_MASK		0xF
#define CLK_FLAG_FIELD_MASK		GENMASK(21, 8)
#define CLK_TYPE_FLAG_FIELD_MASK	GENMASK(31, 24)
#define CLK_TYPE_FLAG2_FIELD_MASK	GENMASK(7, 4)
#define CLK_TYPE_FLAG_BITS		8
#define CLK_PARENTS_ID_LEN		16
#define CLK_PARENTS_ID_MASK		0xFFFF
#define END_OF_TOPOLOGY_NODE		1
#define END_OF_PARENTS			1
#define CLK_VALID_MASK			0x1
#define NODE_CLASS_SHIFT		26U
#define NODE_SUBCLASS_SHIFT		20U
#define NODE_TYPE_SHIFT			14U
#define NODE_INDEX_SHIFT		0U
#define CLK_GET_NAME_RESP_LEN		16
#define CLK_GET_TOPOLOGY_RESP_WORDS	3
#define CLK_GET_PARENTS_RESP_WORDS	3
#define CLK_GET_ATTR_RESP_WORDS		1
#define NODE_SUBCLASS_CLOCK_PLL	1
#define NODE_SUBCLASS_CLOCK_OUT	2
#define NODE_SUBCLASS_CLOCK_REF	3
#define NODE_CLASS_CLOCK	2
#define NODE_CLASS_MASK		0x3F
#define CLOCK_NODE_TYPE_MUX	1
#define CLOCK_NODE_TYPE_DIV	4
#define CLOCK_NODE_TYPE_GATE	6
#define PM_QUERY_DATA	35
