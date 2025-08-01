// Created by camilo on 2022-05-06 03:45 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "_internal.h"
#include <android/asset_manager_jni.h>
#include "android_asset_manager.h"
#include "android_asset.h"


namespace android
{


    //extern thread_local JNIEnv * t_pjnienv;


    asset_manager::asset_manager()
    {

         m_pmanager = nullptr;

    }


    asset_manager::~asset_manager()
    {

       get_jni_env()->DeleteGlobalRef(m_jobject);

       get_jni_env()->DeleteGlobalRef(m_jclass);

    }

    void asset_manager::set_AAssetManager(jobject
    jobjectAssetManager)
{

    set_jni_object(jobjectAssetManager);


    m_pmanager = AAssetManager_fromJava(get_jni_env(), jobjectAssetManager);


}


#define AASSET_MANAGER_ACCESS_BUFFER 3


    ::pointer<::acme::asset> asset_manager::get_asset(const_char_pointer  path)
    {

       auto paasset = AAssetManager_open(m_pmanager, path, AASSET_MANAGER_ACCESS_BUFFER);

       auto passet = __allocate asset();

       passet->m_passet = paasset;

       return passet;

    }


} // namespace android



