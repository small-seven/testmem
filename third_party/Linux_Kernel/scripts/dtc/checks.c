#include "dtc.h"
#ifdef TRACE_CHECKS
#define TRACE(c, ...) \
#else
#define TRACE(c, fmt, ...)	do { } while (0)
#endif
typedef void (*tree_check_fn)(struct check *c, struct node *dt);
typedef void (*node_check_fn)(struct check *c, struct node *dt, struct node *node);
typedef void (*prop_check_fn)(struct check *c, struct node *dt,
			      struct node *node, struct property *prop);

struct check {
	const char *name;
	tree_check_fn tree_fn;
	node_check_fn node_fn;
	prop_check_fn prop_fn;
	void *data;
	bool warn, error;
	enum checkstatus status;
	bool inprogress;
	int num_prereqs;
	struct check **prereq;
};
#define CHECK_ENTRY(nm, tfn, nfn, pfn, d, w, e, ...)	       \
#define WARNING(nm, tfn, nfn, pfn, d, ...) \
#define ERROR(nm, tfn, nfn, pfn, d, ...) \
#define CHECK(nm, tfn, nfn, pfn, d, ...) \
#define TREE_WARNING(nm, d, ...) \
#define TREE_ERROR(nm, d, ...) \
#define TREE_CHECK(nm, d, ...) \
#define NODE_WARNING(nm, d, ...) \
#define NODE_ERROR(nm, d, ...) \
#define NODE_CHECK(nm, d, ...) \
#define PROP_WARNING(nm, d, ...) \
#define PROP_ERROR(nm, d, ...) \
#define PROP_CHECK(nm, d, ...) \
#ifdef __GNUC__
#endif
#define FAIL(c, ...) \
#define WARNING_IF_NOT_STRING(nm, propname) \
#define ERROR_IF_NOT_STRING(nm, propname) \
#define WARNING_IF_NOT_CELL(nm, propname) \
#define ERROR_IF_NOT_CELL(nm, propname) \
#define LOWERCASE	"abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS		"0123456789"
#define PROPNODECHARS	LOWERCASE UPPERCASE DIGITS ",._+*#?-"
#define DESCLABEL_FMT	"%s%s%s%s%s"
#define DESCLABEL_ARGS(node,prop,mark)		\
#define node_addr_cells(n) \
#define node_size_cells(n) \
