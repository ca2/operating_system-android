// From apex by camilo on 2022-04-30 04:23 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/filesystem/filesystem/file_context.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID file_context :
      virtual public ::file_context
   {
   public:



      ::pointer<dir_system>      m_pdirsystem;
      ::pointer<file_system>     m_pfilesystem;


      file_context();
      ~file_context() override;


      void initialize(::particle * pparticle) override;


      //void update_module_path() override;


   };


} // namespace acme_android



