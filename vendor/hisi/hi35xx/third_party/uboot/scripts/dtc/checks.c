#include "dtc.h"
#ifdef TRACE_CHECKS
#define TRACE(c, ...) \
#else
#define TRACE(c, fmt, ...)	do { } while (0)
#endif
typedef void (*check_fn)(struct check *c, struct dt_info *dti, struct node *node);

struct check {
	const char *name;
	check_fn fn;
	void *data;
	bool warn, error;
	enum checkstatus status;
	bool inprogress;
	int num_prereqs;
	struct check **prereq;
};
#define CHECK_ENTRY(nm_, fn_, d_, w_, e_, ...)	       \
#define WARNING(nm_, fn_, d_, ...) \
#define ERROR(nm_, fn_, d_, ...) \
#define CHECK(nm_, fn_, d_, ...) \
#define FAIL(c, dti, node, ...)						\
#define FAIL_PROP(c, dti, node, prop, ...)				\
#define WARNING_IF_NOT_STRING(nm, propname) \
#define ERROR_IF_NOT_STRING(nm, propname) \
#define WARNING_IF_NOT_STRING_LIST(nm, propname) \
#define ERROR_IF_NOT_STRING_LIST(nm, propname) \
#define WARNING_IF_NOT_CELL(nm, propname) \
#define ERROR_IF_NOT_CELL(nm, propname) \
#define LOWERCASE	"abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS		"0123456789"
#define PROPNODECHARS	LOWERCASE UPPERCASE DIGITS ",._+*#?-"
#define PROPNODECHARSSTRICT	LOWERCASE UPPERCASE DIGITS ",-"
#define DESCLABEL_FMT	"%s%s%s%s%s"
#define DESCLABEL_ARGS(node,prop,mark)		\
#define node_addr_cells(n) \
#define node_size_cells(n) \
#define WARNING_PROPERTY_PHANDLE_CELLS(nm, propname, cells_name, ...) \
