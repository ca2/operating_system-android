// From apex by camilo on 2022-04-30 04:23 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme_posix/file_system.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID file_system :
virtual public ::acme_posix::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void initialize(::particle * pparticle) override;



      //void update_module_path() override;


   };


} // namespace acme_android


