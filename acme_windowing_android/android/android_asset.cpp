// Created by camilo on 2022-05-06 03:50 <3ThomasBorregaardSoerensen!!(ThomasLikesNumber5!!)
#include "framework.h"
#include "_internal.h"
#include "android_asset.h"


namespace android
{


    asset::asset()
    {

       m_passet = nullptr;

    }


    asset::~asset()
    {

       if(m_passet) {

          AAsset_close(m_passet);

       }

    }


    void asset::get_pointers(const char *&pstart, const char *&pend)
    {

       if(!m_passet)
       {

          throw ::exception(error_wrong_state);

       }

       pstart = (const char *) AAsset_getBuffer(m_passet);

       auto len = AAsset_getLength(m_passet);

       pend = pstart + len;

    }


} // namespace android





