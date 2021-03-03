#include <common.h>
#include <command.h>
#include <env.h>
#include <errno.h>
#include <env_flags.h>
#include <ethsw.h>
#define ETHSW_PORT_STATS_HELP "ethsw [port <port_no>] statistics " \
#define ETHSW_LEARN_HELP "ethsw [port <port_no>] learning " \
#define ETHSW_FDB_HELP "ethsw [port <port_no>] [vlan <vid>] fdb " \
#define ETHSW_PVID_HELP "ethsw [port <port_no>] " \
#define ETHSW_VLAN_HELP "ethsw [port <port_no>] vlan " \
#define ETHSW_PORT_UNTAG_HELP "ethsw [port <port_no>] untagged " \
#define ETHSW_EGR_VLAN_TAG_HELP "ethsw [port <port_no>] egress tag " \
#define ETHSW_VLAN_FDB_HELP "ethsw vlan fdb " \
#define ETHSW_PORT_INGR_FLTR_HELP "ethsw [port <port_no>] ingress filtering" \
#define ETHSW_PORT_AGGR_HELP "ethsw [port <port_no>] aggr" \
#define ETHSW_PORT_CONF_HELP "[port <port_no>] { enable | disable | show } " \
