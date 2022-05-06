// Created by camilo on 2022-05-06 03:50 <3ThomasBorregaardSørensen!!(ThomasLikesNumber5!!)
#include "framework.h"
#include "_operating_system.h"
#include "_asset.h"


asset::asset(AAsset * passet) :
   m_passet(passet)
{


}


asset::~asset()
{

   AAsset_close(m_passet);

}


void asset::get_pointers(const char*& pstart, const char* & pend)
{

   pstart = (const char *) AAsset_getBuffer(m_passet);

   auto len = AAsset_getLength(m_passet);

   pend = pstart + len;

}



