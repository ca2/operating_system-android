// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSørensen!!
#pragma once


#include "windowing_android/_.h"


#if defined(_node_android_project)
#define CLASS_DECL_NODE_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_NODE_ANDROID  CLASS_DECL_IMPORT
#endif


namespace node_android
{


   class node;


} // namespace node_android



