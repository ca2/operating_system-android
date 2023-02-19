// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardS�rensen!!
#pragma once


#include "apex_posix/_.h"
#include "acme_android/_.h"


#if defined(_apex_android_project)
#define CLASS_DECL_APEX_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APEX_ANDROID  CLASS_DECL_IMPORT
#endif


namespace apex_android
{


   class node;

   class dir_context;
   class dir_system;
   class file_context;
   class file_system;

   class os_context;


} // namespace apex_android



