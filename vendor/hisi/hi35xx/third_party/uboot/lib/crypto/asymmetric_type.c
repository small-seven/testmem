#ifndef __UBOOT__
#include <keys/asymmetric-subtype.h>
#include <keys/asymmetric-parser.h>
#endif
#include <crypto/public_key.h>
#ifdef __UBOOT__
#include <linux/compat.h>
#include <linux/ctype.h>
#include <linux/string.h>
#else
#include <linux/seq_file.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/ctype.h>
#endif
#ifdef __UBOOT__
#include <keys/asymmetric-type.h>
#else
#include <keys/system_keyring.h>
#include <keys/user-type.h>
#include "asymmetric_keys.h"
#endif
#ifndef __UBOOT__
#endif /* !__UBOOT__ */
#ifndef __UBOOT__
static void asymmetric_key_match_free(struct key_match_data *match_data)
{
	kfree(match_data->preparsed);
}
static void asymmetric_key_destroy(struct key *key)
{
	struct asymmetric_key_subtype *subtype = asymmetric_key_subtype(key);
	struct asymmetric_key_ids *kids = key->payload.data[asym_key_ids];
	void *data = key->payload.data[asym_crypto];
	void *auth = key->payload.data[asym_auth];

	key->payload.data[asym_crypto] = NULL;
	key->payload.data[asym_subtype] = NULL;
	key->payload.data[asym_key_ids] = NULL;
	key->payload.data[asym_auth] = NULL;

	if (subtype) {
		subtype->destroy(data, auth);
		module_put(subtype->owner);
	}

	asymmetric_key_free_kids(kids);
}
#endif /* !__UBOOT__ */
