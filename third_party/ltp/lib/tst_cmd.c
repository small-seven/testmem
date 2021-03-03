#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include "test.h"
#include "tst_cmd.h"
#define OPEN_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define OPEN_FLAGS	(O_WRONLY | O_APPEND | O_CREAT)
