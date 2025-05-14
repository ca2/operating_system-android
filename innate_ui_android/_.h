// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSorensen!!
#pragma once


#include "aura_android/_.h"


#if defined(_innate_ui_project)
#define CLASS_DECL_INNATE_UI_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_INNATE_UI_ANDROID  CLASS_DECL_IMPORT
#endif


namespace innate_ui_android
{

   class window;

   class windowing;

   class display;

   class monitor;

   class text_composition_client;


} // namespace innate_ui_android



