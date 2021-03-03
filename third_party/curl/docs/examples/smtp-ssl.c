#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#define FROM    "<sender@example.org>"
#define TO      "<addressee@example.net>"
#define CC      "<info@example.org>"
#ifdef SKIP_PEER_VERIFICATION
#endif
#ifdef SKIP_HOSTNAME_VERIFICATION
#endif
