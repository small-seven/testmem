#include <stdlib.h>
#include <string.h>
#include <los_printf_pri.h>
#include "implementation/usb_btree.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#ifdef USB_BINARY_TREE_DEBUG
#define	BT_DEBUG(x...) dprintf(x)
#else
#define	BT_DEBUG(x...) do{}while(0)
#endif
usbd_create_bt_node(struct node_info *info)
{
	struct usbd_bt_node *node = (usbd_bt_node *)malloc(sizeof(usbd_bt_node));
	if (node == NULL) {
		PRINT_ERR("Binary tree node alloc failed!\n");
		return (NULL);
	}

	(void)memset_s(&node->info, sizeof(node->info), 0, sizeof(node->info));
	node->info.port_no = info->port_no;
	node->info.nameunit = info->nameunit;
	node->lbt_node = NULL;
	node->rbt_node = NULL;

	BT_DEBUG("[create node] %p %s %d\n", node, node->info.nameunit, node->info.port_no);
	return (node);
}
usbd_free_bt_node(usbd_bt_node *node)
{
	BT_DEBUG("[free node] %p %s %d\n", node, node->info.nameunit, node->info.port_no);

	node->info.nameunit = NULL;
	node->info.port_no = 0;
	node->lbt_node = NULL;
	node->rbt_node = NULL;

	free(node);
}
usbd_release_bt_node(usbd_bt_node *node)
{
	if (node == NULL)
		return;

	usbd_release_bt_node(node->lbt_node);
	usbd_release_bt_node(node->rbt_node);

	if (node->info.nameunit != NULL)
		usbd_free_bt_node(node);
}
usbd_remove_bt_node(usbd_bt_tree tree, struct node_info *p_info, struct node_info *rm_info)
{
	usbd_bt_node *rm_node;

	if ((tree == NULL) || (p_info == NULL) || (rm_info == NULL))
		return (-1);

	rm_node = usbd_pre_order_bt_node(tree, rm_info);
	if (rm_node == NULL) {
		BT_DEBUG("Find err, remove fail!\n");
		return (-1);
	}

	usbd_release_bt_node(rm_node);

	/* release parent left node */
	rm_node = usbd_pre_order_bt_node(tree, p_info);
	if (rm_node == NULL) {
		PRINT_ERR("Parent find err, remove fail!\n");
		return (-1);
	}
	rm_node->lbt_node = NULL;

	return (0);
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */