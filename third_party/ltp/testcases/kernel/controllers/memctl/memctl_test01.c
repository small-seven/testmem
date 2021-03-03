#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libcontrollers.h"
#include "test.h"
typedef size_t record_t;
record_t **array_of_chunks;
record_t tmp;
int num_of_chunks, chunk_size, test_num, limit;

void cleanup();
void signal_handler_sigusr1(int signal);
void signal_handler_sigusr2(int signal);
int allocate_memory(void);

int main(void)
{
	int ret;
	char mygroup[FILENAME_MAX], mytaskfile[FILENAME_MAX];
	char *mygroup_p, *script_pid_p, *test_num_p, *chunk_size_p;
	char *num_chunks_p;
	struct sigaction newaction1, newaction2, oldaction1, oldaction2;

	/* Capture variables from the script environment */
	test_num_p = getenv("TEST_NUM");
	mygroup_p = getenv("MYGROUP");
	script_pid_p = getenv("SCRIPT_PID");
	chunk_size_p = getenv("CHUNK_SIZE");
	num_chunks_p = getenv("NUM_CHUNKS");

	if (test_num_p != NULL && mygroup_p != NULL && script_pid_p != NULL &&
	    chunk_size_p != NULL && num_chunks_p != NULL) {
		scriptpid = atoi(script_pid_p);
		test_num = atoi(test_num_p);
		chunk_size = atoi(chunk_size_p);
		num_of_chunks = atoi(num_chunks_p);
		sprintf(mygroup, "%s", mygroup_p);
	} else {
