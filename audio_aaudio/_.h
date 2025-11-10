#pragma once


#include "audio/audio/_.h"


#include <aaudio/AAudio.h>


#if defined(_audio_aaudio_project)
   #define CLASS_DECL_AUDIO_AAUDIO  CLASS_DECL_EXPORT
#else
   #define  CLASS_DECL_AUDIO_AAUDIO  CLASS_DECL_IMPORT
#endif

