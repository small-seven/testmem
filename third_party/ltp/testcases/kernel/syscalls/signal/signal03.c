#include "test.h"
#include <errno.h>
#include <signal.h>
#ifdef SIGSTKFLT
#endif
#ifdef SIGUNUSED
#endif
typedef void (*sighandler_t) (int);

sighandler_t Tret;

int fail = 0;

int main(int ac, char **av)
{
	int lc;
	pid_t pid;
	int i, rval;

	tst_parse_opts(ac, av, NULL, NULL);

	setup();		/* global setup */

	/* The following loop checks looping state if -i option given */

	for (lc = 0; TEST_LOOPING(lc); lc++) {
		/* reset tst_count in case we are looping */
		tst_count = 0;

		/*
		 * loop through the list of signals and test each one
		 */
		for (i = 0; i < TST_TOTAL; i++) {

			errno = 0;
			Tret = signal(siglist[i], SIG_IGN);
			TEST_ERRNO = errno;

			if (Tret == SIG_ERR) {
				tst_brkm(TFAIL, cleanup, "%s call failed - "
					 "errno = %d : %s", TCID,
					 TEST_ERRNO, strerror(TEST_ERRNO));
			}
