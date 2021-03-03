#define PIXOP2(OPNAME, OP)                                              \
#define op_avg(a, b) a = rnd_avg32(a, b)
#define op_put(a, b) a = b
#define put_no_rnd_pixels8_8_c put_pixels8_8_c
#undef op_avg
#undef op_put
