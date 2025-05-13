// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSorensen!!
#pragma once


#include "aura_android/_.h"


#if defined(_operating_ambient_android_project)
#define CLASS_DECL_OPERATING_AMBIENT_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_OPERATING_AMBIENT_ANDROID  CLASS_DECL_IMPORT
#endif


namespace operating_ambient_android
{


    class node;


} // namespace operating_ambient_android



