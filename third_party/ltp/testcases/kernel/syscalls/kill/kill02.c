#include <sys/param.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include "test.h"
#define CHAR_SET_FAILED	"0"	/*Set up failing status transferred through the pipe.   */
#define CHAR_SET_PASSED	"1"	/*Set up passing status transferred through the pipe.   */
#define SIG_CAUGHT	"2"	/*Indicates that the signal SIGUSR1 was caught.         */
#define SIG_RECEIVED	1	/*Integer value that indicates that the signal SIGUSR1  */
#define SIG_NOT_RECD	0	/*Integer value that indicates that the signal SIGUSR1  */
#define INT_SET_FAILED	0	/*Set up failing status transferred through the pipe.   */
#define INT_SET_PASSED	1	/*Set up passing status transferred through the pipe.   */
#define SLEEP_TIME	10	/*Amount of time the children get to catch the signal   */
#define TRUE	 	40	/*Child exits with this if execution was as     */
#define FALSE	 	50	/*Child exits with this if it timed out waiting for the         */
#define TIMEOUT		60	/*Amount of time given in alarm calls.                  */
#define CHILD_EXIT(VAR) ((VAR >> 8) & 0377)	/*Exit value from the child.               */
#define CHILD_SIG(VAR) (VAR & 0377)	/*Signal value from the termination of child.       */
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#else
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#endif
