// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSorensen!!
#pragma once


#include "aura_android/_.h"


#if defined(_windowing_android_project)
#define CLASS_DECL_WINDOWING_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_WINDOWING_ANDROID  CLASS_DECL_IMPORT
#endif


namespace windowing_android
{


   class window;

   class windowing;

   class display;

   class monitor;

   class text_composition_client;


} // namespace aura



