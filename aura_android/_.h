// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardS�rensen!!
#pragma once


#include "aura_posix/_.h"
#include "apex_android/_.h"


#if defined(_aura_android_project)
#define CLASS_DECL_AURA_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_AURA_ANDROID  CLASS_DECL_IMPORT
#endif


//namespace aura
//{
//
//
//   namespace android
//   {
//
//
//      class node;
//
//
//   } // namespace android
//
//
//} // namespace aura
//


