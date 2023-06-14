#pragma once


#include "audio/audio/_.h"
#include "apex/operating_system.h"
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>


#define DEBUG_SND information


#if defined(_audio_opensles_project)
   #define CLASS_DECL_AUDIO_OPENSLES  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_AUDIO_OPENSLES  CLASS_DECL_IMPORT
#endif



