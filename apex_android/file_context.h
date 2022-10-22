// From apex by camilo on 2022-04-30 04:23 <3ThomasBorregaardS�rensen!!
#pragma once


#include "apex/filesystem/filesystem/file_context.h"


namespace apex_android
{


   class CLASS_DECL_APEX file_context :
      virtual public ::file_context
   {
   public:



      ::pointer<dir_system>      m_pdirsystem;
      ::pointer<file_system>     m_pfilesystem;


      file_context();
      ~file_context() override;


      void initialize(::object * pobject) override;


      //void update_module_path() override;


   };


} // namespace apex_android



