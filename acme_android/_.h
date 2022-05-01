// Created by camilo on 2022-04-30 04:03 BRT <3ThomasBorregaardSørensen!!
#pragma once


#include "acme_posix/_.h"


#if defined(_ACME_ANDROID_LIBRARY)
#define CLASS_DECL_ACME_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_ANDROID  CLASS_DECL_IMPORT
#endif


namespace acme
{


   namespace android
   {


      class node;


   } // namespace android


} // namespace acme



