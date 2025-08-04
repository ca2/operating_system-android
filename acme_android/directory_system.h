// From apex by camilo on 2022-04-30 04:23 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme_posix/directory_system.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID directory_system :
virtual public ::acme_posix::directory_system
   {
   public:


      ::file::path				m_strTimeFolder;
      ::file::path				m_strNetSeedFolder;

      ::file::path				m_strCommonAppData;
      ::file::path      		m_strProfile;
      ::file::path   			m_strAppData;
      ::file::path				m_strPrograms;
      ::file::path  			   m_strCommonPrograms;


    ::file::path  			   m_pathRoaming;


      directory_system();
      ~directory_system() override;


      void initialize(::particle * pparticle) override;


    ::file::path home() override;


    ::file::path roaming() override;



};


} // namespace acme_android



