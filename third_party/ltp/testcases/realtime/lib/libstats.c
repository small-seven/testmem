#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <math.h>
#include <libstats.h>
#include <librttest.h>
#include "../include/realtime_config.h"
#ifndef HAVE_EXP10
# define exp10(x) (exp((x) * log(10)))
#endif
int stats_container_free(stats_container_t * data)
{
	free(data->records);
	return 0;
}
int stats_quantiles_free(stats_quantiles_t * quantiles)
{
	free(quantiles->quantiles);
	return 0;
}
