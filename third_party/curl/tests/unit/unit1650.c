#include "curlcheck.h"
#include "doh.h"
#ifndef CURL_DISABLE_DOH
#define DNS_PREAMBLE "\x00\x00\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00"
#define LABEL_TEST "\x04\x74\x65\x73\x74"
#define LABEL_HOST "\x04\x68\x6f\x73\x74"
#define LABEL_NAME "\x04\x6e\x61\x6d\x65"
#define DNSA_TYPE "\x01"
#define DNSAAAA_TYPE "\x1c"
#define DNSA_EPILOGUE "\x00\x00" DNSA_TYPE "\x00\x01"
#define DNSAAAA_EPILOGUE "\x00\x00" DNSAAAA_TYPE "\x00\x01"
#define DNS_Q1 DNS_PREAMBLE LABEL_TEST LABEL_HOST LABEL_NAME DNSA_EPILOGUE
#define DNS_Q2 DNS_PREAMBLE LABEL_TEST LABEL_HOST LABEL_NAME DNSAAAA_EPILOGUE
#define DNS_FOO_EXAMPLE_COM                                          \
#else /* CURL_DISABLE_DOH */
#endif
