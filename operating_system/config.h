#pragma once


#define _THREAD_SAFE


#define PARALLELIZATION_PTHREAD


#define BROAD_PRECOMPILED_HEADER 1


#define MUTEX_COND_TIMED



#include "inc.h"

#include "config_memdleak.h"


#include <features.h>

#if defined(_LP64)

#define AMD64

#else

#define _X86_

#endif


#define OPERATING_SYSTEM_NAMESPACE android

#define stricmp strcasecmp

#define WINAPI


#ifndef __INLINE
#define __INLINE inline /*__forceinline*/
#endif


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
#define __CDECL
#endif

// __EXPORT is used for functions which need to be exported
#ifndef __EXPORT
#define __EXPORT
#endif

#ifndef __STATIC
#define __STATIC extern
#define __STATIC_DATA extern 
// #define __STATIC_DATA extern  //__declspec(selectany)
#endif

// for data
#ifndef __DATA_EXPORT
#define __DATA_EXPORT
#endif
#ifndef __DATA_IMPORT
#define __DATA_IMPORT
#endif

// for classes
#ifndef __CLASS_EXPORT
#define __CLASS_EXPORT
#endif
#ifndef __CLASS_IMPORT
#define __CLASS_IMPORT
#endif

// for global APIs
#ifndef __API_EXPORT
#define __API_EXPORT
#endif
#ifndef __API_IMPORT
#define __API_IMPORT
#endif

#define __FACTORY_EXPORT extern "C"
#define __FACTORY_IMPORT extern "C"

// The following macros are used on data declarations/definitions
//  (they are redefined for extension DLLs and the shared MFC DLL)
#define __DATADEF
#ifndef __API
#define __API
#endif


//#define __ANDROID_API__ 19


#define _strdup strdup



#ifndef ANDROID
#define ANDROID 1
#ifndef __arm__
#define MD_SWAP
#endif
#endif


#ifndef EXPORT
#define EXPORT
#endif

#define BSD_STYLE_SOCKETS
#if !defined VARIADIC_TEMPLATE
#define VARIADIC_TEMPLATE
#endif


//#define HAVE_MYSQL
#define HAVE_OPENSSL

#ifdef HAVE_UNISTD_H
#undef HAVE_UNISTD_H
#endif

#define HAVE_UNISTD_H 1



#define OPERATING_SYSTEM_NAME   "android"





#ifdef CUBE
#define CLASS_DECL_EXPORT
#define CLASS_DECL_IMPORT
#else
#define CLASS_DECL_EXPORT 
#define CLASS_DECL_IMPORT 
#endif
#define CLASS_DECL_THREAD __thread


//#include "bit.h"


#define HAVE_UINT64_T 1



#ifdef __cplusplus

#define LOG_THIS_TAG (typeid(*this).name())
#define LOG_MEMBER_PREFIX __FUNCTION__

#define ALOG_FUNCTION __FUNCTION__
#define ALOG_FILE __FILE__
#define ALOG_LINE __LINE__

#endif


#define STR_NEWLINE "\n"







typedef int int_bool;


//#define index system_index
#define user system_user
#define lconv system_lconv
#define localeconv system_localeconv



#define static_inline inline


#define FONT_MONO "mono"
#define FONT_SANS "sans-serif"
#define FONT_SERIF "FreeSerif"
#define FONT_SANS_UI "sans-serif"
#define FONT_SERIF_UI "serif"
#define FONT_SANS_EX "Liberation Sans"
#define FONT_SERIF_EX "Liberation Serif"
#define FONT_SANS_FX "Ubuntu"
#define FONT_SERIF_FX "Bitstream Charter"




#define _strdup strdup






