#include <sys/ioctl.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <stddef.h>
#include <string.h>
#include "syscall.h"
#define alignof(t) offsetof(struct { char c; t x; }, x)
#define W 1
#define R 2
#define WR 3
#define NINTH(a,b,c,d,e,f,g,h,i,...) i
#define COUNT(...) NINTH(__VA_ARGS__,8,7,6,5,4,3,2,1,0)
#define OFFS(...) COUNT(__VA_ARGS__), { __VA_ARGS__ }
#define new_misaligned(n) struct { int i; time_t t; char c[(n)-4]; }
