// Created by camilo on 2022-05-04 07:20 <3ThomasBorregaardSorensen!!
#pragma once


#include <jni.h>
#include <android/asset_manager.h>
#include <android/log.h>


#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


#include "object.h"


#include "bind.h"
#include "driver.h"


CLASS_DECL_WINDOWING_ANDROID void operating_system_log_exception(::object* pobject, ::exception& exception, const ::string& strMoreDetails);


#include <android/log.h>
#include <android/bitmap.h>
#include <jni.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>
#include <android/log.h>
#include <android/bitmap.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


::string __string(const jstring& jstring);

//#include "_os_object.h"
//#include "_os_local.h"
//#include "_os_remote.h"


void android_on_text(e_os_text etext, const wchar_t* pwch, size_t len);


//#define  LOG_TAG    "apex : os : _os_binding"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


void android_apex_main();

void android_fill_plasma(AndroidBitmapInfo* info, color32_t* pixels, double  t);

void android_mouse(unsigned int message, float x, float y);

void android_key(unsigned int message, int keyCode, int iUni);

void android_on_size(float xDummy, float yDummy, float cx, float cy);

extern int g_iScreenW;

extern int g_iScreenH;

extern const char* g_pszCommandLine;

extern const char* g_pszCacheDir;

class asset_manager;

//extern ::pointer<operating_system_bind>g_pandroidcontext;

//extern ::pointer<operating_system_driver>g_pandroiddriver;

CLASS_DECL_APEX string get_string(jstring jstring);


CLASS_DECL_APEX void set_jni_context(JNIEnv* penv);
CLASS_DECL_APEX JNIEnv* get_jni_env();

CLASS_DECL_APEX void android_exchange();



