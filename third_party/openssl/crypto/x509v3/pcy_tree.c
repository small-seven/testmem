#include "internal/cryptlib.h"
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "pcy_local.h"
#ifdef OPENSSL_POLICY_DEBUG
#endif
#define TREE_CALC_FAILURE 0
#define TREE_CALC_OK_NOFREE 1
#define TREE_CALC_OK_DOFREE 2
#ifdef OPENSSL_POLICY_DEBUG
#endif
static void exnode_free(X509_POLICY_NODE *node)
{
    if (node->data && (node->data->flags & POLICY_DATA_FLAG_EXTRA_NODE))
        OPENSSL_free(node);
}
void X509_policy_tree_free(X509_POLICY_TREE *tree)
{
    X509_POLICY_LEVEL *curr;
    int i;

    if (!tree)
        return;

    sk_X509_POLICY_NODE_free(tree->auth_policies);
    sk_X509_POLICY_NODE_pop_free(tree->user_policies, exnode_free);

    for (i = 0, curr = tree->levels; i < tree->nlevel; i++, curr++) {
        X509_free(curr->cert);
        sk_X509_POLICY_NODE_pop_free(curr->nodes, policy_node_free);
        policy_node_free(curr->anyPolicy);
    }

    sk_X509_POLICY_DATA_pop_free(tree->extra_data, policy_data_free);
    OPENSSL_free(tree->levels);
    OPENSSL_free(tree);

}
#ifdef OPENSSL_POLICY_DEBUG
#endif
