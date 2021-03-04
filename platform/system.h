#pragma once


#undef INLINE


#ifdef __cplusplus
#define MOVE_SEMANTICS
#endif


#ifdef _DEBUG
#ifndef DEBUG
#define DEBUG
#endif
#endif




#define synchronization_object base_sync


#include "platform_android.h"



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
typedef struct oswindow_data *   oswindow;

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


#ifdef DEBUG

#define RELEASENOTHROW

#else

#define RELEASENOTHROW throw()

#endif


#define DWORD     uint32_t

#define BYTE      uint8_t

#define _stricmp strcasecmp


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

typedef void * PVOID;


#define _strcmpi strcasecmp


#define PURE = 0


#define __stdcall


#define strnicmp strncasecmp








#undef index
#undef user
#undef synchronization_object


// unichar should 16 bit wide - if wchar_t is 16 bit wide in the platform
// the wchar_t can be used instead of unsigned short or uint16_t
// unichar32 should 32 bit wide - if wchar_t is 32 bit wide in the platform
// the wchar_t can be used instead of unsigned int or uint32_t
// typedef unsigned short  unichar;
// typedef wchar_t         unichar32;



//#define int_bool int





