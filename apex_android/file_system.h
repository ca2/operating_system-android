// From apex by camilo on 2022-04-30 04:23 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/filesystem/filesystem/file_system.h"


namespace apex_android
{


   class CLASS_DECL_APEX file_system :
      virtual public ::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void initialize(::particle * pparticle) override;



      //void update_module_path() override;


   };


} // namespace apex_android


