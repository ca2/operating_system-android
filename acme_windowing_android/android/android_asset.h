// Created by camilo on 2022-05-06 03:49 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/platform/asset.h"


namespace android
{

    class asset :
      virtual public ::acme::asset
    {
    public:


        AAsset *m_passet;


        asset();
        ~asset() override;


        void get_pointers(const char *&pstart, const char *&pend) override;


    };


} // namespace android





