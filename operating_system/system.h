#pragma once


#undef INLINE


#ifdef __cplusplus
#define MOVE_SEMANTICS
#endif


#define PARALLELIZATION_PTHREAD


#ifdef _DEBUG
#ifndef DEBUG
#define DEBUG
#endif
#endif


void debug_break();


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


#include <string.h>

#include <strings.h>
#include <inttypes.h>
#include <errno.h>


#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>


#include <wchar.h>
#include <ctype.h>


#include <sys/resource.h>


#include <time.h>

int timespec_get(timespec * ts, int);



#undef user


#define user android_user


#ifdef __cplusplus


#include <typeinfo>
#include <initializer_list>


#endif


#include <pthread.h>


#undef user






#include <concepts>

typedef unsigned char BYTE;
typedef uint32_t UINT;


#define __cdecl
#define _stdcall
#define c_cdecl


// dbg alloc MS VC CRT
#define _NORMAL_BLOCK  1


// Ubuntu apt-get install libx11-dev
//#include <X11/Xlib.h>
//#include <X11/Xutil.h>


/* Types use for passing & returning polymorphic values */
//typedef uint_ptr                 WPARAM;
//typedef long_ptr                 LPARAM;
//typedef long_ptr                 LRESULT;
//typedef struct oswindow_data *   oswindow;

//#include <pthread.h>

typedef long pthread_t;

typedef pthread_t HTHREAD;


struct device_context;
struct gdi_object;




typedef struct device_context * HDC;

typedef struct gdi_object * HGDIOBJ;

union _XEvent;

typedef union _XEvent XEvent;

//typedef Font HFONT;


#define DECL_SPEC_ANY


#ifdef _DEBUG

#ifndef DEBUG

#define DEBUG

#endif // DEBUG

#endif // _DEBUG


#include "platform_cpu.h"


// #ifdef __cplusplus


// inline void debug_break() { throw 3; }


// #endif


// SIZE_T_MAX is used by the collection classes
#ifndef SIZE_T_MAX
#define SIZE_T_MAX  UINT_MAX
#endif


// CDECL and EXPORT are defined in case WINDOWS.H doesn't
#ifndef CDECL
#define CDECL
#endif

#ifndef EXPORT
#define EXPORT
#endif


// __CDECL is used for rare functions taking variable arguments
#ifndef __CDECL
#define __CDECL __cdecl
#endif

// __EXPORT is used for functions which need to be exported
#ifndef __EXPORT
#define __EXPORT EXPORT
#endif


#define MAX_DWORD_PTR ((dword_ptr)(-1))

#define true 1

#define false 0

typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef uint32_t    u_int;
typedef unsigned long   u_long;

#define DECL_C

#define _PRE_WIDEN(x) L##x
#define _WIDEN(x) _PRE_WIDEN(x)

#define NOTHROW throw()
#define THROWS // gnucc null throw statement means that the function can throw any exception



#define DWORD     uint32_t

#define BYTE      uint8_t

//#define _stricmp strcasecmp


#define __forceinline inline


#if defined(__LP64__) || defined(_LP64)

#define OS64BIT
#define OSBIT 64
#if !defined(__LP64__)
#define __LP64__
#endif

#if !defined(_LP64)
#define _LP64
#endif



#else


#define OS32BIT
#define OSBIT 32



#endif


#ifndef ANDROID
typedef uint8_t byte;
#endif


// for global data that should be in COMDATs (packaged data)
#ifndef __COMDAT
#define __COMDAT // __declspec(selectany)
#endif


#define NO_ANSIUNI_ONLY

#define MAX_DWORD_PTR ((dword_ptr)(-1))

#define TRUE 1

#define FALSE 0




typedef unsigned short  wd16char;
typedef wchar_t         wd32char;
typedef wd32char        widechar;

#define DECL_C


#define _PRE_WIDEN(x) L##x
#define _WIDEN(x) _PRE_WIDEN(x)

#define NOTHROW throw()
#define THROWS // gnucc null throw statement means that the function can throw any exception


#ifdef _DEBUG

#define RELEASENOTHROW

#else

#define RELEASENOTHROW throw()

#endif


//#define ::u32     ::u32
//
//#define byte      ::u328_t

//#define NULL 0

#define _strcmpi strcasecmp


#define __forceinline inline




//typedef ::u328_t byte;


typedef void * PVOID;


#define PURE = 0


#define __stdcall
#define _gmtime64 gmtime


#define stricmp strcasecmp
#define strnicmp strncasecmp


#define _stricmp  stricmp
#define _strnicmp  strnicmp





#define MOVE_SEMANTICS










#define wcsicmp wcscasecmp
#define wcsnicmp wcsncasecmp


#define _strlwr __ansilwr
#define _strupr __ansiupr



#undef index




#define WINBOOL int


#define INFINITE_TIMEOUT UINT_MAX

//#define offsetof(type, member)  __builtin_offsetof (type, member)




typedef wchar_t unichar;

using platform_char = char;



