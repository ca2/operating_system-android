// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSørensen!!
#pragma once


#include "apex_posix/_.h"
#include "acme_android/_.h"


#if defined(_APEX_ANDROID_LIBRARY)
#define CLASS_DECL_APEX_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APEX_ANDROID  CLASS_DECL_IMPORT
#endif


namespace apex
{


   namespace android
   {


      class node;


   } // namespace android


} // namespace apex



