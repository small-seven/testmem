#include <string.h>
#include <openssl/pem.h>         /* PEM_def_callback() */
#include "internal/thread_once.h"
#include "ui_local.h"
#ifndef BUFSIZ
#define BUFSIZ 256
#endif
