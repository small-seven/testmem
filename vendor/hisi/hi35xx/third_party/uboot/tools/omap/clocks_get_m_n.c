#include <stdlib.h>
#include <stdio.h>
typedef unsigned int u32;
#define MAX_N	127

/*
 * get_m_n_optimized() - Finds optimal DPLL multiplier(M) and divider(N)
 * values based on the reference frequency, required output frequency,
 * maximum tolerance for output frequency etc.
 *
 * target_freq_khz - output frequency required in KHz
 * ref_freq_khz - reference(input) frequency in KHz
 * m - pointer to computed M value
 * n - pointer to computed N value
 * tolerance_khz - tolerance for the output frequency. When the algorithm
 * succeeds in finding vialble M and N values the corresponding output
 * frequency will be in the range:
 *	[target_freq_khz - tolerance_khz, target_freq_khz]
 *
 * Formula:
 *	Fdpll = (2 * M * Fref) / (N + 1)
 *
 * Considerations for lock-time:
 *	- Smaller the N, better lock-time, especially lock-time will be
 *	- For acceptable lock-times:
 *		Fref / (M + 1) >= 1 MHz
 *
 * Considerations for power:
 *	- The difference in power for different N values giving the same
 *	  output is negligible. So, we optimize for lock-time
 *
 * Hard-constraints:
 *	- N can not be greater than 127(7 bit field for representing N)
 *
 * Usage:
 *	$ gcc clocks_get_m_n.c
 *	$ ./a.out
 */
int get_m_n_optimized(u32 target_freq_khz, u32 ref_freq_khz, u32 *M, u32 *N)
{
	u32 freq = target_freq_khz;
	u32 m_optimal, n_optimal, freq_optimal = 0, freq_old;
	u32 m, n;
	n = 1;
	while (1) {
		m = target_freq_khz / ref_freq_khz / 2 * n;
		freq_old = 0;
		while (1) {
			freq = ref_freq_khz * 2 * m / n;
			if (freq > target_freq_khz) {
				freq = freq_old;
				m--;
				break;
			}
