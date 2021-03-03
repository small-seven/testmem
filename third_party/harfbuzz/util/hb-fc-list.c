#define HAVE_GETOPT_LONG 1 /* XXX */
#include "hb-fc.h"
#include <fontconfig/fontconfig.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#else
#ifdef linux
#define HAVE_GETOPT_LONG 1
#endif
#define HAVE_GETOPT 1
#endif
#ifndef HAVE_GETOPT
#define HAVE_GETOPT 0
#endif
#ifndef HAVE_GETOPT_LONG
#define HAVE_GETOPT_LONG 0
#endif
#if HAVE_GETOPT_LONG
#undef  _GNU_SOURCE
#define _GNU_SOURCE
#include <getopt.h>
#else
#if HAVE_GETOPT
#endif
#endif
#if HAVE_GETOPT_LONG
#else
#endif
#if HAVE_GETOPT_LONG
#else
#endif
#if HAVE_GETOPT_LONG || HAVE_GETOPT
#if HAVE_GETOPT_LONG
#else
#endif
#else
#endif
