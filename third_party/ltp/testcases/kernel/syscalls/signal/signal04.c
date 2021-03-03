#include "test.h"
#include <errno.h>
#include <signal.h>
typedef void (*sighandler_t) (int);

sighandler_t Tret;

int main(int ac, char **av)
{
	int lc;
	int i;
	sighandler_t rval, first;

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

			/* First reset the signal to the default
			   action to clear out any pre-test
			   execution settings */
			signal(siglist[i], SIG_DFL);

			/* then set the handler to our own handler */
			if ((rval = signal(siglist[i], &sighandler)) == SIG_ERR) {
				tst_brkm(TBROK, cleanup, "initial signal call"
					 " failed");
			}
