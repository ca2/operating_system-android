// Created by camilo on 2022-05-04 03:23 <3ThomasBorregaardSorensen
#pragma once


#include "aura_posix/node.h"
#include "apex_android/node.h"


namespace aura_android
{


   class CLASS_DECL_AURA_ANDROID node :
      virtual public ::aura_posix::node,
      virtual public ::apex_android::node
   {
   public:


      node();
      ~node() override;


   };


} // namespace aura_android



