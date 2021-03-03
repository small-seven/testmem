#ifndef __CLEANUP_C__
#define __CLEANUP_C__
#ifndef CLEANUP
#define USING_DUMMY_CLEANUP 1
#define CLEANUP dummy_cleanup
#endif
#ifdef USING_DUMMY_CLEANUP
#endif
#endif
