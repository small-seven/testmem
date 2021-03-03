#if defined(TEMPLATE_8bit)
#    define RENAME(N)   N ## _8bit
#    define TYPE        int16_t
#    undef  TEMPLATE_8bit
#elif defined(TEMPLATE_10bit)
#    define RENAME(N)   N ## _10bit
#    define TYPE        int32_t
#    undef  TEMPLATE_10bit
#elif defined(TEMPLATE_12bit)
#    define RENAME(N)   N ## _12bit
#    define TYPE        int32_t
#    undef  TEMPLATE_12bit
#endif
#undef RENAME
#undef TYPE
