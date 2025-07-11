   /* src/config.h.in.  Generated from configure.ac by autoheader.  */

//#include "operating_system/third_private_config.h"

/* Define if your architecture wants/needs/can use attribute_align_arg and
   alignment checks. It is for 32bit x86... */
#undef ABI_ALIGN_FUN

/* Define to use proper rounding. */
#undef ACCURATE_ROUNDING

/* Define if building universal (internal helper macro) */
#undef AC_APPLE_UNIVERSAL_BUILD

/* Define if .balign is present. */
#undef ASMALIGN_BALIGN

/* Define if .align just takes byte count. */
#undef ASMALIGN_BYTE

/* Define if .align takes 3 for alignment of 2^3=8 bytes instead of 8. */
#undef ASMALIGN_EXP

/* Define if __attribute__((aligned(16))) shall be used */
#undef CCALIGN

/* Define if debugging is enabled. */
#undef DEBUG

/* The default audio output module(s) to use */
#undef DEFAULT_OUTPUT_MODULE

/* Define if building with dynamcally linked libmpg123 */
#undef DYNAMIC_BUILD

/* Use EFBIG as substitude for EOVERFLOW, mingw.org may lack the latter */
#undef EOVERFLOW

/* Define if FIFO support is enabled. */
#undef FIFO

/* Define if frame index should be used. */
#undef FRAME_INDEX

/* Define if gapless is enabled. */
#undef GAPLESS

/* Define to 1 if you have the <alc.h> header file. */
#undef HAVE_ALC_H

/* Define to 1 if you have the <Alib.h> header file. */
#undef HAVE_ALIB_H

/* Define to 1 if you have the <AL/alc.h> header file. */
#undef HAVE_AL_ALC_H

/* Define to 1 if you have the <AL/al.h> header file. */
#undef HAVE_AL_AL_H

/* Define to 1 if you have the <al.h> header file. */
#undef HAVE_AL_H

/* Define to 1 if you have the <arpa/inet.h> header file. */
#undef HAVE_ARPA_INET_H

/* Define to 1 if you have the <asm/audioio.h> header file. */
#undef HAVE_ASM_AUDIOIO_H

/* Define to 1 if you have the `atoll' function. */
#undef HAVE_ATOLL

/* Define to 1 if you have the <audios.h> header file. */
#undef HAVE_AUDIOS_H

/* Define to 1 if you have the <AudioToolbox/AudioToolbox.h> header file. */
#undef HAVE_AUDIOTOOLBOX_AUDIOTOOLBOX_H

/* Define to 1 if you have the <AudioUnit/AudioUnit.h> header file. */
#undef HAVE_AUDIOUNIT_AUDIOUNIT_H

/* Define to 1 if you have the <CoreServices/CoreServices.h> header file. */
#undef HAVE_CORESERVICES_CORESERVICES_H

/* Define to 1 if you have the <CUlib.h> header file. */
#undef HAVE_CULIB_H

/* Define to 1 if you have the <dirent.h> header file. */
#undef HAVE_DIRENT_H

/* Define to 1 if you have the `dlclose' function. */
#undef HAVE_DLCLOSE

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Define to 1 if you have the `dlopen' function. */
#undef HAVE_DLOPEN

/* Define to 1 if you have the `dlsym' function. */
#undef HAVE_DLSYM

/* Define if getaddrinfo accepts the AI_ADDRCONFIG flag */
#undef HAVE_GAI_ADDRCONFIG

/* Define to 1 if you have the `getaddrinfo' function. */
#undef HAVE_GETADDRINFO

/* Define to 1 if you have the `getpagesize' function. */
#undef HAVE_GETPAGESIZE

/* Define to 1 if you have the `getuid' function. */
#undef HAVE_GETUID

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the <langinfo.h> header file. */
#undef HAVE_LANGINFO_H

/* Define to 1 if you have the `m' library (-lm). */
#undef HAVE_LIBM

/* Define to 1 if you have the `mx' library (-lmx). */
#undef HAVE_LIBMX

/* Define to 1 if you have the <limits.h> header file. */
#undef HAVE_LIMITS_H

/* Define to 1 if you have the <linux/soundcard.h> header file. */
#undef HAVE_LINUX_SOUNDCARD_H

/* Define to 1 if you have the <locale.h> header file. */
#undef HAVE_LOCALE_H

/* Define to 1 if you have the <machine/soundcard.h> header file. */
#undef HAVE_MACHINE_SOUNDCARD_H

/* Define to 1 if you have the <memory.h> header file. */
#undef HAVE_MEMORY_H

/* Define to 1 if you have the `mkfifo' function. */
#undef HAVE_MKFIFO

/* Define to 1 if you have a working `mmap' system call. */
#undef HAVE_MMAP

/* Define to 1 if you have the <netdb.h> header file. */
#undef HAVE_NETDB_H

/* Define to 1 if you have the <netinet/in.h> header file. */
#undef HAVE_NETINET_IN_H

/* Define to 1 if you have the <netinet/tcp.h> header file. */
#undef HAVE_NETINET_TCP_H

/* Define to 1 if you have the `nl_langinfo' function. */
#undef HAVE_NL_LANGINFO

/* Define to 1 if you have the <OpenAL/alc.h> header file. */
#undef HAVE_OPENAL_ALC_H

/* Define to 1 if you have the <OpenAL/al.h> header file. */
#undef HAVE_OPENAL_AL_H

/* Define to 1 if you have the <os2me.h> header file. */
#undef HAVE_OS2ME_H

/* Define to 1 if you have the <os2.h> header file. */
#undef HAVE_OS2_H

/* Define to 1 if you have the `random' function. */
#undef HAVE_RANDOM

/* Define to 1 if you have the <sched.h> header file. */
#undef HAVE_SCHED_H

/* Define to 1 if you have the `sched_setscheduler' function. */
#undef HAVE_SCHED_SETSCHEDULER

/* Define to 1 if you have the `setlocale' function. */
#undef HAVE_SETLOCALE

/* Define to 1 if you have the `setpriority' function. */
#undef HAVE_SETPRIORITY

/* Define to 1 if you have the `setuid' function. */
#undef HAVE_SETUID

/* Define to 1 if you have the <signal.h> header file. */
#undef HAVE_SIGNAL_H

/* Define to 1 if you have the <sndio.h> header file. */
#undef HAVE_SNDIO_H

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdio.h> header file. */
#undef HAVE_STDIO_H

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#undef HAVE_STRING_H

/* Define to 1 if you have the <sun/audioio.h> header file. */
#undef HAVE_SUN_AUDIOIO_H

/* Define to 1 if you have the <sys/audioio.h> header file. */
#undef HAVE_SYS_AUDIOIO_H

/* Define to 1 if you have the <sys/audio.h> header file. */
#undef HAVE_SYS_AUDIO_H

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#undef HAVE_SYS_IOCTL_H

/* Define to 1 if you have the <sys/param.h> header file. */
#undef HAVE_SYS_PARAM_H

/* Define to 1 if you have the <sys/resource.h> header file. */
#undef HAVE_SYS_RESOURCE_H

/* Define to 1 if you have the <sys/select.h> header file. */
#undef HAVE_SYS_SELECT_H

/* Define to 1 if you have the <sys/signal.h> header file. */
#undef HAVE_SYS_SIGNAL_H

/* Define to 1 if you have the <sys/socket.h> header file. */
#undef HAVE_SYS_SOCKET_H

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#undef HAVE_SYS_SOUNDCARD_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/time.h> header file. */
#undef HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if you have the <sys/wait.h> header file. */
#undef HAVE_SYS_WAIT_H

/* Define this if you have the POSIX termios library */
#undef HAVE_TERMIOS

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the <windows.h> header file. */
#undef HAVE_WINDOWS_H

/* Define to 1 if you have the <ws2tcpip.h> header file. */
#undef HAVE_WS2TCPIP_H

/* Define to indicate that float storage follows IEEE754. */
#undef IEEE_FLOAT

/* size of the frame index seek table */
#undef INDEX_SIZE

/* Define if IPV6 support is enabled. */
#undef IPV6

/* Define this to the size of native offset type in bits, used for LFS alias
   functions. */
#undef LFS_ALIAS_BITS

/* Define to the extension used for runtime loadable modules, say, ".so". */
#undef LT_MODULE_EXT

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#undef LT_OBJDIR

/* Define to the shared library suffix, say, ".dylib". */
#undef LT_SHARED_EXT

/* Define to the shared archive member specification, say "(shr.o)". */
#undef LT_SHARED_LIB_MEMBER

/* Define if network support is enabled. */
#undef NETWORK

/* Define to disable 16 bit integer output. */
#undef NO_16BIT

/* Define to disable 32 bit and 24 bit integer output. */
#undef NO_32BIT

/* Define to disable 8 bit integer output. */
#undef NO_8BIT

/* Define to disable downsampled decoding. */
#undef NO_DOWNSAMPLE

/* Define to disable equalizer. */
#undef NO_EQUALIZER

/* Define to disable error messages in combination with a return value (the
   return is left intact). */
#undef NO_ERETURN

/* Define to disable error messages. */
#undef NO_ERRORMSG

/* Define to disable feeder and buffered readers. */
#undef NO_FEEDER

/* Define to disable ICY handling. */
#undef NO_ICY

/* Define to disable ID3v2 parsing. */
#undef NO_ID3V2

/* Define to disable layer I. */
#undef NO_LAYER1

/* Define to disable layer II. */
#undef NO_LAYER2

/* Define to disable layer III. */
#undef NO_LAYER3

/* Define to disable ntom resampling. */
#undef NO_NTOM

/* Define to disable real output. */
#undef NO_REAL

/* Define to disable string functions. */
#undef NO_STRING

/* Define for post-processed 32 bit formats. */
#undef NO_SYNTH32

/* Define to disable warning messages. */
#undef NO_WARNING

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Define if portaudio v18 API is wanted. */
#undef PORTAUDIO18

/* The size of `int32_t', as computed by sizeof. */
#undef SIZEOF_INT32_T

/* The size of `long', as computed by sizeof. */
#undef SIZEOF_LONG

/* The size of `off_t', as computed by sizeof. */
#undef SIZEOF_OFF_T

/* The size of `size_t', as computed by sizeof. */
#undef SIZEOF_SIZE_T

/* The size of `ssize_t', as computed by sizeof. */
#undef SIZEOF_SSIZE_T

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Define if modules are enabled */
#undef USE_MODULES

/* Define for ___new Huffman decoding scheme. */
#undef USE_NEW_HUFFTABLE

/* Define to use yasm for assemble AVX sources. */
#undef USE_YASM_FOR_AVX

/* Version number of package */
#undef VERSION

/* Define to use Win32 named pipes */
#undef WANT_WIN32_FIFO

/* Define to use Win32 sockets */
#undef WANT_WIN32_SOCKETS

/* Define to use Unicode for Windows */
#undef WANT_WIN32_UNICODE

/* WinXP and above for ipv6 */
#undef WINVER

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
#  undef WORDS_BIGENDIAN
# endif
#endif

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
#undef _FILE_OFFSET_BITS

/* Define for large files, on AIX-style hosts. */
#undef _LARGE_FILES

/* WinXP and above for ipv6 */
#undef _WIN32_WINNT

/* Define to empty if `const' does not conform to ANSI C. */
#undef const

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#undef inline
#endif

/* Define to `short' if <sys/types.h> does not define. */
#undef int16_t

/* Define to `int' if <sys/types.h> does not define. */
#undef int32_t

/* Define to `long long' if <sys/types.h> does not define. */
#undef int64_t

/* Define to the native offset type (long or actually off_t). */
#undef lfs_alias_t

/* Define to `long int' if <sys/types.h> does not define. */
#undef off_t

/* Define to `unsigned long' if <sys/types.h> does not define. */
#undef size_t

/* Define to `long' if <sys/types.h> does not define. */
#undef ssize_t

/* Define to `unsigned short' if <sys/types.h> does not define. */
#undef uint16_t

/* Define to `unsigned int' if <sys/types.h> does not define. */
#undef uint32_t

/* Define to `unsigned long' if <sys/types.h> does not define. */
#undef uintptr_t

#ifdef UNIVERSAL_WINDOWS
#define HAVE_STRING_H 1
#define HAVE_STRERROR 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_MEMORY_H 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STRDUP 1
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#elif defined(WINDOWS_DESKTOP)
#define HAVE_STRING_H 1
#define HAVE_STRERROR 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_MEMORY_H 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STRDUP 1
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#elif defined(__ANDROID__)
#define HAVE_STRING_H 1
#define HAVE_STRERROR 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_MEMORY_H 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STRDUP 1
#define HAVE_UNISTD_H 1
#elif defined(LINUX)
#define HAVE_STRING_H 1
#define HAVE_STRERROR 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_MEMORY_H 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STRDUP 1
#define HAVE_UNISTD_H 1
#elif defined(MACOS)
#define ASMALIGN_EXP
#define HAVE_STRING_H 1
#define HAVE_STRERROR 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_MEMORY_H 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STRDUP 1
#define HAVE_UNISTD_H 1
#elif defined(APPLE_IOS)
#define ASMALIGN_EXP
#define HAVE_STRING_H 1
#define HAVE_STRERROR 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_MEMORY_H 1
#define STDC_HEADERS 1
#define HAVE_STDLIB_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_WINDOWS_H 1
#define HAVE_STRDUP 1
#define HAVE_UNISTD_H 1
#endif


