// From apex by camilo on 2022-04-30 04:23 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme/filesystem/filesystem/dir_system.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID dir_system :
      virtual public ::dir_system
   {
   public:


      ::file::path				m_strTimeFolder;
      ::file::path				m_strNetSeedFolder;

      ::file::path				m_strCommonAppData;
      ::file::path      		m_strProfile;
      ::file::path   			m_strAppData;
      ::file::path				m_strPrograms;
      ::file::path  			   m_strCommonPrograms;


      dir_system();
      ~dir_system() override;


      void initialize(::particle * pparticle) override;



   };


} // namespace acme_android



