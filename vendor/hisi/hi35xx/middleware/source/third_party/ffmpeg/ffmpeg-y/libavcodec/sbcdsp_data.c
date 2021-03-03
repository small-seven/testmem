#include "sbcdsp_data.h"
#define F_PROTO(x) ((int32_t) (((x) * 2) * ((int32_t) 1 << 15) + 0.5))
#define F_COS(x)   ((int32_t) (((x)    ) * ((int32_t) 1 << 15) + 0.5))
#define C0 1.0932568993
#define C1 1.3056875580
#define C2 1.3056875580
#define C3 1.6772280856
#define F(x) F_PROTO(x)
#undef F
#define F(x) F_COS(x)
#undef F
#undef C0
#undef C1
#undef C2
#undef C3
#define C0 1.3056875580
#define C1 1.6772280856
#define C2 1.0932568993
#define C3 1.3056875580
#define F(x) F_PROTO(x)
#undef F
#define F(x) F_COS(x)
#undef F
#undef C0
#undef C1
#undef C2
#undef C3
#define C0 2.7906148894
#define C1 2.4270044280
#define C2 2.8015616024
#define C3 3.1710363741
#define C4 2.5377944043
#define C5 2.4270044280
#define C6 2.8015616024
#define C7 3.1710363741
#define F(x) F_PROTO(x)
#undef F
#define F(x) F_COS(x)
#undef F
#undef C0
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
#define C0 2.5377944043
#define C1 2.4270044280
#define C2 2.8015616024
#define C3 3.1710363741
#define C4 2.7906148894
#define C5 2.4270044280
#define C6 2.8015616024
#define C7 3.1710363741
#define F(x) F_PROTO(x)
#undef F
#define F(x) F_COS(x)
#undef F
#undef C0
#undef C1
#undef C2
#undef C3
#undef C4
#undef C5
#undef C6
#undef C7
