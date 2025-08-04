// From apex by camilo on 2022-04-30 04:25 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme_posix/directory_context.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID directory_context :
virtual public ::acme_posix::directory_context
   {
   public:

      
      ::pointer<::acme_android::directory_system>      m_pdirectorysystem;
      ::pointer<::acme_android::file_system>     m_pfilesystem;


      directory_context();
      ~directory_context() override;


      virtual void initialize(::particle * pparticle) override;

      virtual void init_system() override;
      virtual void init_context() override;

      //virtual bool enumerate(::file::listing & listing) override;
      virtual ::file::listing & root_ones(::file::listing & listing) override;


      //virtual bool  is(const ::file::path & path, bool bRequired = false, bool bBypassCache = false);
      //virtual bool is(const ::file::path & path) override;
      virtual bool is_inside(const ::file::path & lpcszDir, const ::file::path & lpcszPath) override;
      virtual bool is_inside_time(const ::file::path & lpcsz) override;
      virtual bool name_is(const ::file::path & str) override;
      //virtual bool has_subdir(const ::file::path & lpcsz) override;

      //virtual void create(const ::file::path & lpcsz) override;
      //virtual void erase(const ::file::path & path, bool bRecursive = true) override;



      //virtual string warehouse();
      virtual ::file::path time() override;
      virtual ::file::path stage() override;
      virtual ::file::path stageapp() override;
      virtual ::file::path netseed() override;

      // stage in ccwarehouse spalib
      virtual ::file::path install() override;

      //virtual ::file::path module();
      //virtual ::file::path ca2module();
      virtual ::file::path time_square() override;
      virtual ::file::path time_log(const ::scoped_string & scopedstrId) override;


      //virtual ::file::path trash_that_is_not_trash(const ::file::path & path) override;

      //virtual ::file::path appdata() override;
      virtual ::file::path commonappdata() override;


      //virtual ::file::path usersystemappdata(const string & lpcszPrefix);
      //virtual ::file::path userappdata();
      //virtual ::file::path userdata();
      ////virtual ::file::path userfolder();
      //virtual ::file::path default_os_user_path_prefix();
      //virtual ::file::path default_userappdata(const string & lpcszPrefix, const string & lpcszLogin);
      //virtual ::file::path default_userdata(const string & lpcszPrefix, const string & lpcszLogin);
      //virtual ::file::path default_userfolder(const string & lpcszPrefix, const string & lpcszLogin);
      virtual ::file::path userquicklaunch() override;
      virtual ::file::path userprograms() override;
      virtual ::file::path bookmark() override;

      virtual ::file::path commonprograms() override;

      virtual ::file::path commonappdata_root() override;

//      virtual bool initialize();

   };


} // namespace acme_android



