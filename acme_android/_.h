// Created by camilo on 2022-04-30 04:03 BRT <3ThomasBorregaardSorensen!!
#pragma once


#include "acme_posix/_.h"


#if defined(_acme_android_project)
#define CLASS_DECL_ACME_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_ANDROID  CLASS_DECL_IMPORT
#endif


namespace acme_android
{


   class node;


   class dir_context;
   class dir_system;
   class file_context;
   class file_system;


} // namespace acme



