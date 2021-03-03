#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "test.h"
#include "move_pages_support.h"
#define TEST_PAGES 2
#define TEST_NODES 2
#define TOUCHED_PAGES 1
#define UNTOUCHED_PAGE (TEST_PAGES - 1)
typedef void (*sighandler_t) (int);

int main(int argc, char **argv)
{

	tst_parse_opts(argc, argv, NULL, NULL);

	setup();

#ifdef HAVE_NUMA_V2
	unsigned int i;
	int lc;
	unsigned int from_node;
	unsigned int to_node;
	int ret, exp_status;

	if ((tst_kvercmp(4, 3, 0)) >= 0)
		exp_status = -EFAULT;
	else
		exp_status = -ENOENT;

	ret = get_allowed_nodes(NH_MEMS, 2, &from_node, &to_node);
	if (ret < 0)
		tst_brkm(TBROK | TERRNO, cleanup, "get_allowed_nodes: %d", ret);

	/* check for looping state if -i option is given */
	for (lc = 0; TEST_LOOPING(lc); lc++) {
		void *pages[TEST_PAGES] = { 0 };
#else
#endif
