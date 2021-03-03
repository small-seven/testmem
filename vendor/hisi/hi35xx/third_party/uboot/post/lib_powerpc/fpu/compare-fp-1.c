#include <common.h>
#include <post.h>
#if CONFIG_POST & CONFIG_SYS_POST_FPU
#define TEST(c) if ((c) != ok) failed++
#define ORD(a, b) (!__builtin_isunordered ((a), (b)))
#define UNORD(a, b) (__builtin_isunordered ((a), (b)))
#define UNEQ(a, b) (__builtin_isunordered ((a), (b)) || ((a) == (b)))
#define UNLT(a, b) (__builtin_isunordered ((a), (b)) || ((a) < (b)))
#define UNLE(a, b) (__builtin_isunordered ((a), (b)) || ((a) <= (b)))
#define UNGT(a, b) (__builtin_isunordered ((a), (b)) || ((a) > (b)))
#define UNGE(a, b) (__builtin_isunordered ((a), (b)) || ((a) >= (b)))
#define LTGT(a, b) (__builtin_islessgreater ((a), (b)))
#endif /* CONFIG_POST & CONFIG_SYS_POST_FPU */
