// Created by camilo on 2022-05-06 03:44 <3ThomasBorregaardSorensen!!
#pragma once


class asset;


class CLASS_DECL_ACME asset_manager :
   public jni_object
{
public:


   AAssetManager* m_pmanager;

   
   asset_manager(jobject jobjectAssetManager);
   ~asset_manager();


   ::pointer<asset>get_asset(const char * path);


};
