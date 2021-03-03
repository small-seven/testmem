#include "libavutil/float_dsp.h"
#include "libavutil/thread.h"
#include "libavutil/mem.h"
#include "internal.h"
#include "get_bits.h"
#include "put_bits.h"
#include "dolby_e.h"
#include "fft.h"
static void bit_allocate(int nb_exponent, int nb_code, int fr_code,
                         int *exp, int *bap,
                         int fg_spc, int fg_ofs, int msk_mod, int snr_ofs)
{
    int msk_val[MAX_BIAS_EXP];
    int psd_val[MAX_BIAS_EXP];
    int fast_leak  = 0;
    int slow_leak  = 0;
    int dc_code    = dc_code_tab[fr_code - 1];
    int ht_code    = ht_code_tab[fr_code - 1];
    int fast_gain  = fast_gain_tab[fg_ofs];
    int slow_decay = slow_decay_tab[dc_code][msk_mod];
    int misc_decay = misc_decay_tab[nb_code][dc_code][msk_mod];
    const uint16_t *slow_gain      = slow_gain_tab[nb_code][msk_mod];
    const uint16_t *fast_decay     = fast_decay_tab[nb_code][dc_code][msk_mod];
    const uint16_t *fast_gain_adj  = fast_gain_adj_tab[nb_code][dc_code];
    const uint16_t *hearing_thresh = hearing_thresh_tab[nb_code][ht_code];
    int i;

    for (i = 0; i < nb_exponent; i++)
        psd_val[i] = (48 - exp[i]) * 64;

    fast_gain_adj += band_ofs_tab[nb_code][fg_spc];
    for (i = 0; i < nb_exponent; i++) {
        fast_leak = log_add(fast_leak  - fast_decay[i],
                            psd_val[i] - fast_gain + fast_gain_adj[i]);
        slow_leak = log_add(slow_leak  - slow_decay,
                            psd_val[i] - slow_gain[i]);
        msk_val[i] = FFMAX(fast_leak, slow_leak);
    }

    fast_leak = 0;
    for (i = nb_exponent - 1; i > band_low_tab[nb_code]; i--) {
        fast_leak = log_add(fast_leak - misc_decay, psd_val[i] - fast_gain);
        msk_val[i] = FFMAX(msk_val[i], fast_leak);
    }

    for (i = 0; i < nb_exponent; i++)
        msk_val[i] = FFMAX(msk_val[i], hearing_thresh[i]);

    if (!nb_code)
        calc_lowcomp(msk_val);

    for (i = 0; i < nb_exponent; i++) {
        int v = 16 * (snr_ofs - 64) + psd_val[i] - msk_val[i] >> 5;
        bap[i] = bap_tab[av_clip_uintp2(v, 6)];
    }
}
