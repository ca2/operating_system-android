// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSørensen!!
#pragma once


#include "aura_android/_.h"


#if defined(_WINDOWING_ANDROID_LIBRARY)
#define CLASS_DECL_WINDOWING_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_WINDOWING_ANDROID  CLASS_DECL_IMPORT
#endif


namespace windowing_android
{


      class window;

      class windowing;


   //} // namespace android


} // namespace aura



