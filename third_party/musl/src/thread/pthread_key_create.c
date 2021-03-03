#include "pthread_impl.h"
int __pthread_key_create(pthread_key_t *k, void (*dtor)(void *))
{
	pthread_t self = __pthread_self();

	/* This can only happen in the main thread before
	 * pthread_create has been called. */
	if (!self->tsd) self->tsd = __pthread_tsd_main;

	/* Purely a sentinel value since null means slot is free. */
	if (!dtor) dtor = nodtor;

	__pthread_rwlock_wrlock(&key_lock);
	pthread_key_t j = next_key;
	do {
		if (!keys[j]) {
			keys[next_key = *k = j] = dtor;
			__pthread_rwlock_unlock(&key_lock);
			return 0;
		}
	} while ((j=(j+1)%PTHREAD_KEYS_MAX) != next_key);

	__pthread_rwlock_unlock(&key_lock);
	return EAGAIN;
}
