#define pr_fmt(fmt) "PKEY: "fmt
#ifdef __UBOOT__
#include <linux/compat.h>
#else
#include <linux/module.h>
#include <linux/export.h>
#endif
#include <linux/kernel.h>
#ifndef __UBOOT__
#include <linux/slab.h>
#include <linux/seq_file.h>
#include <linux/scatterlist.h>
#include <keys/asymmetric-subtype.h>
#endif
#include <crypto/public_key.h>
#ifndef __UBOOT__
#include <crypto/akcipher.h>
#endif
#ifndef __UBOOT__
#endif
void public_key_free(struct public_key *key)
{
	if (key) {
		kfree(key->key);
		kfree(key->params);
		kfree(key);
	}
}
#ifdef __UBOOT__
void public_key_signature_free(struct public_key_signature *sig)
{
	int i;

	if (sig) {
		for (i = 0; i < ARRAY_SIZE(sig->auth_ids); i++)
			free(sig->auth_ids[i]);
		free(sig->s);
		free(sig->digest);
		free(sig);
	}
}
#else
static void public_key_destroy(void *payload0, void *payload3)
{
	public_key_free(payload0);
	public_key_signature_free(payload3);
}
#endif /* !__UBOOT__ */
