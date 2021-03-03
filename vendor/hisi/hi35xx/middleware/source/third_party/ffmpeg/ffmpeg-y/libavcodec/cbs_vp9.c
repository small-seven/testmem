#include "libavutil/avassert.h"
#include "cbs.h"
#include "cbs_internal.h"
#include "cbs_vp9.h"
#include "internal.h"
#define HEADER(name) do { \
#define CHECK(call) do { \
#define FUNC_NAME(rw, codec, name) cbs_ ## codec ## _ ## rw ## _ ## name
#define FUNC_VP9(rw, name) FUNC_NAME(rw, vp9, name)
#define FUNC(name) FUNC_VP9(READWRITE, name)
#define SUBSCRIPTS(subs, ...) (subs > 0 ? ((int[subs + 1]){ subs, __VA_ARGS__ }) : NULL)
#define f(width, name) \
#define s(width, name) \
#define fs(width, name, subs, ...) \
#define ss(width, name, subs, ...) \
#define READ
#define READWRITE read
#define RWContext GetBitContext
#define xf(width, name, var, subs, ...) do { \
#define xs(width, name, var, subs, ...) do { \
#define increment(name, min, max) do { \
#define fle(width, name, subs, ...) do { \
#define delta_q(name) do { \
#define prob(name, subs, ...) do { \
#define fixed(width, name, value) do { \
#define infer(name, value) do { \
#define byte_alignment(rw) (get_bits_count(rw) % 8)
#include "cbs_vp9_syntax_template.c"
#undef READ
#undef READWRITE
#undef RWContext
#undef xf
#undef xs
#undef increment
#undef fle
#undef delta_q
#undef prob
#undef fixed
#undef infer
#undef byte_alignment
#define WRITE
#define READWRITE write
#define RWContext PutBitContext
#define xf(width, name, var, subs, ...) do { \
#define xs(width, name, var, subs, ...) do { \
#define increment(name, min, max) do { \
#define fle(width, name, subs, ...) do { \
#define delta_q(name) do { \
#define prob(name, subs, ...) do { \
#define fixed(width, name, value) do { \
#define infer(name, value) do { \
#define byte_alignment(rw) (put_bits_count(rw) % 8)
#include "cbs_vp9_syntax_template.c"
#undef WRITE
#undef READWRITE
#undef RWContext
#undef xf
#undef xs
#undef increment
#undef fle
#undef delta_q
#undef prob
#undef fixed
#undef infer
#undef byte_alignment
