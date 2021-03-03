#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#define FROM_ADDR    "<sender@example.org>"
#define TO_ADDR      "<addressee@example.net>"
#define CC_ADDR      "<info@example.org>"
#define FROM_MAIL "Sender Person " FROM_ADDR
#define TO_MAIL   "A Receiver " TO_ADDR
#define CC_MAIL   "John CC Smith " CC_ADDR
