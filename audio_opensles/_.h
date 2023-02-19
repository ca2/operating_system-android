#pragma once


#include "app-core/audio/_.h"
#include "apex/operating_system.h"
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>


#define DEBUG_SND TRACE


#if defined(_audio_opensles_project)
   #define CLASS_DECL_AUDIO_OPENSLES  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_AUDIO_OPENSLES  CLASS_DECL_IMPORT
#endif



