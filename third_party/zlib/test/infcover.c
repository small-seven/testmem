#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "zlib.h"
#define ZLIB_INTERNAL
#include "inftrees.h"
#include "inflate.h"
#define local static
local void mem_free(void *mem, void *ptr)
{
    struct mem_item *item, *next;
    struct mem_zone *zone = mem;

    /* if no zone, just do a free */
    if (zone == NULL) {
        free(ptr);
        return;
    }

    /* point next to the item that matches ptr, or NULL if not found -- remove
       the item from the linked list if found */
    next = zone->first;
    if (next) {
        if (next->ptr == ptr)
            zone->first = next->next;   /* first one is it, remove from list */
        else {
            do {                        /* search the linked list */
                item = next;
                next = item->next;
            } while (next != NULL && next->ptr != ptr);
            if (next) {                 /* if found, remove from linked list */
                item->next = next->next;
                zone->notlifo++;        /* not a LIFO free */
            }

        }
    }

    /* if found, update the statistics and free the item */
    if (next) {
        zone->total -= next->size;
        free(next);
    }

    /* if not found, update the rogue count */
    else
        zone->rogue++;

    /* in any case, do the requested free with the standard library function */
    free(ptr);
}
