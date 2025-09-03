// Created by camilo on 2022-05-06 03:45 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "_internal.h"
#include <android/asset_manager_jni.h>
#include "android_asset_manager.h"
#include "android_asset.h"
#include "jni_object_impl.h"


namespace android
{


   asset_manager::asset_manager(jni_object_interface * pjniobjectinterfaceAssetManager)
   {

      initialize_jni_object(pjniobjectinterfaceAssetManager);

      ::cast < ::jni_object_impl > pjniobjectimplAssetManager = pjniobjectinterfaceAssetManager;

      ::cast < ::jni_context_impl > pcontext = ::jni_context::get();

      m_pmanager = AAssetManager_fromJava(pcontext->m_pjnicontext, pjniobjectimplAssetManager->m_jobject);

   }


   asset_manager::~asset_manager()
   {

   }


#define AASSET_MANAGER_ACCESS_BUFFER 3


   ::pointer<::acme::asset> asset_manager::get_asset(const_char_pointer path)
   {

      auto paasset = AAssetManager_open(m_pmanager, path, AASSET_MANAGER_ACCESS_BUFFER);

      auto passet = øallocate asset();

      passet->m_passet = paasset;

      return passet;

   }


} // namespace android



