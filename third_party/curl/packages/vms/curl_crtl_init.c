#include <stdio.h>
#include <string.h>
#include <descrip.h>
#include <lnmdef.h>
#include <stsdef.h>
#pragma member_alignment save
#pragma nomember_alignment longword
#pragma message save
#pragma message disable misalgndmem
#pragma message restore
#pragma member_alignment restore
#ifdef __VAX
#define ENABLE "ENABLE"
#define DISABLE "DISABLE"
#else
#define ENABLE TRUE
#define DISABLE 0
#endif
#ifdef __VAX
#else
#endif
#ifdef __VAX
#else
#endif
#pragma nostandard
#pragma extern_model save
#ifdef __VAX
#pragma extern_model strict_refdef "LIB$INITIALIZE" nowrt, long, nopic
#else
#pragma extern_model strict_refdef "LIB$INITIALIZE" nowrt, long
#    if __INITIAL_POINTER_SIZE
#        pragma __pointer_size __save
#        pragma __pointer_size 32
#    else
#        pragma __required_pointer_size __save
#        pragma __required_pointer_size 32
#    endif
#endif
#ifndef __VAX
#    if __INITIAL_POINTER_SIZE
#        pragma __pointer_size __restore
#    else
#        pragma __required_pointer_size __restore
#    endif
#endif
#ifdef __DECC
#pragma extern_model strict_refdef
#endif
#ifdef __DECC
#pragma extern_model restore
#pragma standard
#endif
