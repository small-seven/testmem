#include "curl_setup.h"
#include <curl/curl.h>
#include "llist.h"
#include "curl_memory.h"
#include "memdebug.h"
Curl_llist_remove(struct curl_llist *list, struct curl_llist_element *e,
                  void *user)
{
  void *ptr;
  if(e == NULL || list->size == 0)
    return;

  if(e == list->head) {
    list->head = e->next;

    if(list->head == NULL)
      list->tail = NULL;
    else
      e->next->prev = NULL;
  }
  else {
    if(!e->prev)
      list->head = e->next;
    else
      e->prev->next = e->next;

    if(!e->next)
      list->tail = e->prev;
    else
      e->next->prev = e->prev;
  }

  ptr = e->ptr;

  e->ptr  = NULL;
  e->prev = NULL;
  e->next = NULL;

  --list->size;

  /* call the dtor() last for when it actually frees the 'e' memory itself */
  if(list->dtor)
    list->dtor(user, ptr);
}
Curl_llist_destroy(struct curl_llist *list, void *user)
{
  if(list) {
    while(list->size > 0)
      Curl_llist_remove(list, list->tail, user);
  }
}
