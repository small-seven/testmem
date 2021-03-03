#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lkc.h"
#define DEBUG_EXPR	0
void expr_free(struct expr *e)
{
	if (!e)
		return;

	switch (e->type) {
	case E_SYMBOL:
		break;
	case E_NOT:
		expr_free(e->left.expr);
		return;
	case E_EQUAL:
	case E_GEQ:
	case E_GTH:
	case E_LEQ:
	case E_LTH:
	case E_UNEQUAL:
		break;
	case E_OR:
	case E_AND:
		expr_free(e->left.expr);
		expr_free(e->right.expr);
		break;
	default:
		printf("how to free type %d?\n", e->type);
		break;
	}
	free(e);
}
#define e1 (*ep1)
#define e2 (*ep2)
#undef e1
#undef e2
#define e1 (*ep1)
#define e2 (*ep2)
#undef e1
#undef e2
