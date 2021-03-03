#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define  PROGRAM_NAME     "apinames"
#define  PROGRAM_VERSION  "0.3"
#define  LINEBUFF_SIZE  1024
typedef enum  OutputFormat_
{
  OUTPUT_LIST = 0,      /* output the list of names, one per line             */
  OUTPUT_WINDOWS_DEF,   /* output a Windows .DEF file for Visual C++ or Mingw */
  OUTPUT_BORLAND_DEF,   /* output a Windows .DEF file for Borland C++         */
  OUTPUT_WATCOM_LBC,    /* output a Watcom Linker Command File                */
  OUTPUT_NETWARE_IMP,   /* output a NetWare ImportFile                        */
  OUTPUT_GNU_VERMAP     /* output a version map for GNU or Solaris linker     */

} OutputFormat;
typedef struct  NameRec_
{
  char*         name;
  unsigned int  hash;

} NameRec, *Name;
typedef enum  State_
{
  STATE_START = 0,  /* waiting for FT_EXPORT keyword and return type */
  STATE_TYPE        /* type was read, waiting for function name      */

} State;
