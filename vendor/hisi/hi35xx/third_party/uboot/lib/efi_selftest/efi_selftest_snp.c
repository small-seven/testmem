#include <efi_selftest.h>
#define BOOTREQUEST 1
#define BOOTREPLY 2
# define HWT_ETHER 1
# define HWL_ETHER 6
#define DHCP_FLAGS_UNICAST	0x0000
#define DHCP_FLAGS_BROADCAST	0x0080
#define DHCP_MESSAGE_TYPE	0x35
#define DHCPDISCOVER		1
#define DHCPOFFER		2
#define DHCPREQUEST		3
#define DHCPDECLINE		4
#define DHCPACK			5
#define DHCPNAK			6
#define DHCPRELEASE		7
#ifdef CONFIG_SANDBOX
#endif
