#include "los_hwi.h"
#include "vfs_config.h"
#include "stdint.h"
#include "poll.h"
#include "assert.h"
#include "errno.h"
#include "debug.h"
#include "fs/fs.h"
#include "inode/inode.h"
#include "stdlib.h"
#include "stdio.h"
#include "console.h"
#include "unistd.h"
#include "linux/wait.h"
#ifdef LOSCFG_NET_LWIP_SACK
#include "lwip/sockets.h"
#endif
#ifndef CONFIG_DISABLE_POLL
#ifndef MSEC_PER_SEC
#define MSEC_PER_SEC        1000L
#endif
#ifndef NSEC_PER_MSEC
#define NSEC_PER_MSEC    1000000L
#endif
#define N_POLL_ITEMS 5
#define poll_semgive(sem) sem_post(sem)
typedef wait_queue_head_t * poll_wait_queue;

typedef struct tag_poll_wait_node
{
  LOS_DL_LIST queue_node;
  pollevent_t key;
  struct tag_poll_wait_entry *entry;
  poll_wait_queue wait_queue;
} poll_wait_node;
typedef struct tag_poll_wait_entry_table
{
  struct tag_poll_wait_entry_table *next;
  UINT32 index;
  poll_wait_node items[N_POLL_ITEMS];
} poll_wait_entry_table;
typedef struct tag_poll_wait_entry
{
  bool add_queue_flag;
  sem_t sem;
  UINT32 inline_index;
  poll_wait_node inline_items[N_POLL_ITEMS];
  poll_wait_entry_table *table;
} poll_wait_entry;
static int destroy_poll_wait(poll_wait_head wait)
{
  unsigned int i;
  unsigned long int_save;
  poll_wait_node *wait_node = NULL;
  poll_wait_entry_table *curr_table = NULL;

  for (i = 0; i < wait->inline_index; ++i)
    {
      wait_node = &wait->inline_items[i];
      spin_lock_irqsave(&wait_node->wait_queue->lock, int_save);
      LOS_ListDelete(&wait_node->queue_node);
      spin_unlock_irqrestore(&wait_node->wait_queue->lock, int_save);
    }

  while (wait->table)
    {
      curr_table = wait->table;
      wait->table = curr_table->next;

      for (i = 0; i < curr_table->index; ++i)
        {
          wait_node = &curr_table->items[i];
          spin_lock_irqsave(&wait_node->wait_queue->lock, int_save);
          LOS_ListDelete(&wait_node->queue_node);
          spin_unlock_irqrestore(&wait_node->wait_queue->lock, int_save);
        }
      free(curr_table);
    }

  if (sem_destroy(&wait->sem) < 0)
    {
      PRINT_ERR("[%s] sem_destroy failed\n", __FUNCTION__);
      return -1;
    }

  return 0;
}
#if defined(LOSCFG_NET_LWIP_SACK)
#endif
#endif /* CONFIG_DISABLE_POLL */
