#include "app_verify.h"
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "app_centraldirectory.h"
#include "app_common.h"
#include "app_file.h"
#include "app_provision.h"
#include "app_verify_hap.h"
#include "mbedtls/base64.h"
#include "mbedtls/md.h"
#include "mbedtls/pk.h"
#include "mbedtls/x509_crt.h"
#include "mbedtls_pkcs7.h"
#include "securec.h"
static void FreeAppSignPublicKey(AppSignPk *pk)
{
    if (pk->pk != NULL) {
        APPV_FREE(pk->pk);
    }
    return;
}
static int CheckReleaseAppSign(const CertInfo *binSignCert, const ProfileProf *pf)
{
    /* if distribution type is app_gallery, return error */
    if (strcmp(pf->appDistType, "app_gallery") == 0) {
        LOG_ERROR("app release, distribution type is app_gallery, return error");
        return V_ERR;
    }

    if (strlen((char *)pf->bundleInfo.releaseCert) == 0) {
        LOG_ERROR("release app, release Cert null");
        return V_ERR;
    }
    int ret = LoadCertAndCmpDest(pf->bundleInfo.releaseCert, binSignCert);
    if (ret == V_OK) {
        LOG_INFO("dev cert consistent");
        return V_OK;
    }
    LOG_ERROR("app sign cert not consistent with profile cert");
    return V_ERR;
}
void FreeCertInfo(CertInfo *certInfo)
{
    if (certInfo == NULL) {
        return;
    }
    if (certInfo->issuer != NULL) {
        APPV_FREE(certInfo->issuer);
        certInfo->issuerLen = 0;
    }

    if (certInfo->subject != NULL) {
        APPV_FREE(certInfo->subject);
        certInfo->subjectLen = 0;
    }

    if (certInfo->pkBuf != NULL) {
        APPV_FREE(certInfo->pkBuf);
        certInfo->pkLen = 0;
    }
    return;
}
void APPVERI_FreeVerifyRst(VerifyResult *verifyRst)
{
    if (verifyRst == NULL) {
        return;
    }
    LOG_INFO("free verify rst data");
    ProfFreeData(&verifyRst->profile);
    return;
}