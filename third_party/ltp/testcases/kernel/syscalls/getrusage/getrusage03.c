#include <sys/types.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "safe_macros.h"
#define DELTA_MAX	10240
static void fork_malloc(void)
{
	tst_resm(TINFO, "Testcase #03: fork + malloc");

	SAFE_GETRUSAGE(cleanup, RUSAGE_SELF, &ru);
	tst_resm(TINFO, "initial.self = %ld", ru.ru_maxrss);

	switch (pid = fork()) {
	case -1:
		tst_brkm(TBROK | TERRNO, cleanup, "fork #3");
	case 0:
		maxrss_init = ru.ru_maxrss;
		tst_resm(TINFO, "child allocate +50MB");
		consume(50);
		SAFE_GETRUSAGE(cleanup, RUSAGE_SELF, &ru);
		tst_resm(TINFO, "child.self = %ld", ru.ru_maxrss);
		exit(is_in_delta(maxrss_init + 51200 - ru.ru_maxrss));
	default:
		break;
	}

	SAFE_WAITPID(cleanup, pid, &status, WUNTRACED | WCONTINUED);
	check_return(WEXITSTATUS(status), "initial.self + 50MB ~= child.self",
		     "initial.self + 50MB !~= child.self");
}
