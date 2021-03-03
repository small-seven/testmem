#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/kobj.h>
#include <sys/malloc.h>
#include <sys/mutex.h>
#include <sys/systm.h>
#ifdef TEST
#include "usertest.h"
#endif
#ifdef KOBJ_STATS
#endif
#define	KOBJ_LOCK()		mtx_lock(&kobj_mtx)
#define	KOBJ_UNLOCK()		mtx_unlock(&kobj_mtx)
#define	KOBJ_ASSERT(what)	mtx_assert(&kobj_mtx, what);
kobj_class_free(kobj_class_t cls)
{
	void* ops = NULL;

	KOBJ_ASSERT(MA_NOTOWNED);
	KOBJ_LOCK();

	/*
	 * Protect against a race between kobj_create and
	 * kobj_delete.
	 */
	if (cls->refs == 0) {
		/*
		 * For now we don't do anything to unregister any methods
		 * which are no longer used.
		 */

		/*
		 * Free memory and clean up.
		 */
		ops = cls->ops;
		cls->ops = NULL;
	}

	KOBJ_UNLOCK();

	if (ops)
		bsd_free(ops, M_KOBJ);
}
kobj_create(kobj_class_t cls,
	    struct malloc_type *mtype,
	    int mflags)
{
	kobj_t obj;

	/*
	 * Allocate and initialise the new object.
	 */
	obj = bsd_malloc(cls->size, mtype, mflags | M_ZERO);
	if (!obj)
		return NULL;
	kobj_init(obj, cls);

	return obj;
}
