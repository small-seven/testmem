#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <net/if.h>
#include "tst_test.h"
#define I2N_RNDCOUNT	10	/* random ints */
#define I2N_LOWCOUNT	10	/* sequential from 0 */
