#include <string.h>
#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#include <openssl/pem.h>
#include <openssl/engine.h>
#include <openssl/ts.h>
#define BASE_SECTION                    "tsa"
#define ENV_DEFAULT_TSA                 "default_tsa"
#define ENV_SERIAL                      "serial"
#define ENV_CRYPTO_DEVICE               "crypto_device"
#define ENV_SIGNER_CERT                 "signer_cert"
#define ENV_CERTS                       "certs"
#define ENV_SIGNER_KEY                  "signer_key"
#define ENV_SIGNER_DIGEST               "signer_digest"
#define ENV_DEFAULT_POLICY              "default_policy"
#define ENV_OTHER_POLICIES              "other_policies"
#define ENV_DIGESTS                     "digests"
#define ENV_ACCURACY                    "accuracy"
#define ENV_ORDERING                    "ordering"
#define ENV_TSA_NAME                    "tsa_name"
#define ENV_ESS_CERT_ID_CHAIN           "ess_cert_id_chain"
#define ENV_VALUE_SECS                  "secs"
#define ENV_VALUE_MILLISECS             "millisecs"
#define ENV_VALUE_MICROSECS             "microsecs"
#define ENV_CLOCK_PRECISION_DIGITS      "clock_precision_digits"
#define ENV_VALUE_YES                   "yes"
#define ENV_VALUE_NO                    "no"
#define ENV_ESS_CERT_ID_ALG             "ess_cert_id_alg"
#ifndef OPENSSL_NO_ENGINE
#endif
