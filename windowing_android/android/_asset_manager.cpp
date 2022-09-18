// Created by camilo on 2022-05-06 03:45 <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "_internal.h"
#include <android/asset_manager_jni.h>
#include "_asset_manager.h"
#include "_asset.h"


extern thread_local JNIEnv* t_pjnienv;


asset_manager::asset_manager(jobject jobjectAssetManager) :
   jni_object(jobjectAssetManager)
{


   m_pmanager = AAssetManager_fromJava(t_pjnienv, jobjectAssetManager);


}


asset_manager::~asset_manager()
{

   t_pjnienv->DeleteGlobalRef(m_jobject);

   t_pjnienv->DeleteGlobalRef(m_jclass);

}


#define AASSET_MANAGER_ACCESS_BUFFER 3


__pointer(asset) asset_manager::get_asset(const char* path)
{

   auto paasset = AAssetManager_open(m_pmanager, path, AASSET_MANAGER_ACCESS_BUFFER);

   auto passet = __new(asset(paasset));

   return passet;

}



