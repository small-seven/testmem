#include <string.h>
#include "internal/cryptlib.h"
#include <openssl/e_os2.h>
#include <openssl/buffer.h>
#include <openssl/ui.h>
#include <openssl/err.h>
#include "ui_local.h"
void UI_free(UI *ui)
{
    if (ui == NULL)
        return;
    if ((ui->flags & UI_FLAG_DUPL_DATA) != 0) {
        ui->meth->ui_destroy_data(ui, ui->user_data);
    }
    sk_UI_STRING_pop_free(ui->strings, free_string);
    CRYPTO_free_ex_data(CRYPTO_EX_INDEX_UI, ui, &ui->ex_data);
    CRYPTO_THREAD_lock_free(ui->lock);
    OPENSSL_free(ui);
}
#if 0
#endif
