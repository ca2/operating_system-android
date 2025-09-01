// Created by camilo on 2022-04-30 04:05 BRT <3ThomasBorregaardSorensen!!
#pragma once


#include "acme_android/_.h"


#if defined(_acme_windowing_android_project)
#define CLASS_DECL_ACME_WINDOWING_ANDROID  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_WINDOWING_ANDROID  CLASS_DECL_IMPORT
#endif


namespace android
{

    namespace acme
    {


        namespace windowing
        {


            class window;

            class windowing;

            class display;

            //class monitor;

            //class text_composition_client;

        } // namespace windowing


    } // namespace acme


} // namespace aura


class jni_message_sink;

