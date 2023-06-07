#pragma once





#define __cdecl
#define _stdcall

#define _NORMAL_BLOCK  1


// Ubuntu apt-get install libx11-dev
// CentOS yum install libX11-devel
// openSUSE zypper install libx11-devel
//#include <X11/Xlib.h>
//#include <X11/Xutil.h>
namespace windowing
{

   class window;

} // namespace windowing


typedef uptr                     WPARAM;
typedef iptr                     LPARAM;
typedef iptr                     LRESULT;
typedef ::windowing::window *    oswindow;

//#include <pthread.h>

typedef pthread_t pthread;

typedef pthread HTHREAD;

//#ifdef __cplusplus
//struct pthread
//{
//
//   pthread_t m_thread;
//
//   pthread(){}
//   pthread(const pthread & p){operator=(p);}
//   pthread(const pthread_t & p){operator=(p);}
//
//   inline operator pthread_t &() { return m_thread; }
//   inline operator void *() { return (void *) (int_ptr) m_thread; }
//
//   inline operator pthread_t() const { return m_thread; }
//   inline operator void *() const { return (void *) (int_ptr) m_thread; }
//
//   pthread & operator =(const pthread & p) {m_thread = p.m_thread; return *this;}
//   pthread & operator =(const pthread_t & p) {m_thread = p; return *this;}
//
//   bool operator ==(const pthread_t & p) const {return m_thread == p;}
//   bool operator ==(const pthread & p) const {return operator==(p.m_thread);}
//   bool operator !=(const pthread_t & p) const {return !operator == (p);}
//   bool operator !=(const pthread & p) const {return operator != (p.m_thread);}
//
//};
//typedef pthread_t HTHREAD;
//
//#else
//struct pthread
//{
//   pthread_t m_thread;
//};
//#endif
//typedef struct pthread HTHREAD;

//typedef XID                      Window;

struct device_context;
struct gdi_object;




typedef struct device_context * HDC;

typedef struct gdi_object * HGDIOBJ;


void debug_break();



typedef unsigned short        wd16_character;
typedef wchar_t               wd32_character;
typedef ::wd32_character      wide_character;

#define DECL_C


#define _PRE_WIDEN(x) L##x
#define _WIDEN(x) _PRE_WIDEN(x)

#define NOTHROW throw()
#define THROWS // gnucc null throw statement means that the function can throw any exception


#ifdef _DEBUG

#else

#define RELEASENOTHROW throw()

#endif



#define _strcmpi strcasecmp


#define __forceinline inline


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

