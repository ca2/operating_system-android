// Created by camilo on 2022-05-06 03:44 <3ThomasBorregaardSorensen!!
#pragma once


#include <android/asset_manager.h>
#include "acme/platform/asset_manager.h"
#include "jni_object.h"


namespace android
{

    class asset;


    class CLASS_DECL_ACME asset_manager

    :
    virtual public ::acme::asset_manager,
    public jni_object
{
    public:


    AAssetManager *m_pmanager;


    asset_manager();
    ~asset_manager() override;


    void set_AAssetManager(jobject
                                          jobjectAssetManager);


    ::pointer <::acme::asset> get_asset(const char *path) override;


};


} // namespace android



