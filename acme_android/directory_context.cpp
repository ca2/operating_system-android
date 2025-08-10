// From apex by camilo on 2022-04-30 04:22 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "directory_context.h"
#include "directory_system.h"
#include "file_system.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/parallelization/single_lock.h"
#include "acme/parallelization/task_flag.h"
#include "acme/platform/acme.h"
#include "acme/platform/system.h"


namespace acme_android
{


   directory_context::directory_context()
   {

   }


   directory_context::~directory_context()
   {

   }


   void directory_context::initialize(::particle * pparticle)
   {

      //auto estatus = 
      
      ::directory_context::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = 
      
      m_pdirectorysystem = system()->m_pdirectorysystem;

      //if (!estatus)
      //{

      //   return estatus;

      //}
      
      //estatus = 
      
      m_pfilesystem = system()->m_pfilesystem;

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   inline bool myspace(char ch)
   {
      return ch == ' ' ||
         ch == '\t' ||
         ch == '\r' ||
         ch == '\n';
   }


   ::file::listing_base & directory_context::root_ones(::file::listing_base & listing)
   {

      ::file::path path;

      path = "/";

      path.m_etype = ::file::e_type_existent_folder;

      listing.defer_add(path);

      listing.m_straTitle.add("File System");

      return listing;

   }


   //bool directory_context::enumerate(::file::listing_base & listing)
   //{

   //   if (::directory_context::ls( listing))
   //   {

   //      return listing;

   //   }


   //   if (listing.m_bRecursive)
   //   {

   //      index iStart = listing.get_count();

   //      {

   //         scoped_restore(listing.m_pathFinal);

   //         scoped_restore(listing.m_eextract);

   //         ::file::listing_base straDir;

   //         ls_dir(straDir, listing.m_pathFinal);

   //         for (int i = 0; i < straDir.get_count(); i++)
   //         {

   //            string strDir = straDir[i];

   //            if (strDir == listing.m_pathFinal)
   //               continue;

   //            if (listing.m_bDir)
   //            {

   //               listing.add(::file::path(strDir));

   //               ::file::path & path = listing.last();

   //               path.m_iSize = 0;

   //               path.m_iDir = 1;

   //            }

   //            listing.m_pathFinal = strDir;

   //            ls(listing);


   //         }

   //      }

   //      if (listing.m_bFile)
   //      {

   //         scoped_restore(listing.m_bRecursive);

   //         listing.m_bRecursive = false;

   //         ls_file(listing, listing.m_pathFinal);

   //      }

   //      for (::collection::index i = iStart; i < listing.get_size(); i++)
   //      {

   //         listing[i].m_iRelative = listing.m_pathFinal.get_length() + 1;

   //      }

   //   }
   //   else
   //   {


   //      ::file::path_array_base stra;

   //      ::dir::ls(stra, listing.m_pathFinal);

   //      for (int i = 0; i < stra.get_count(); i++)
   //      {

   //         ::file::path strPath = stra[i];

   //         if (!strPath.begins(listing.m_pathFinal))
   //            continue;

   //         bool bIsDir;

   //         bIsDir = ::directory_context::is(strPath);

   //         if (!bIsDir && !matches_wildcard_criteria(listing.m_straPattern, strPath.name()))
   //            continue;

   //         if ((bIsDir && !listing.m_bDir) || (!bIsDir && !listing.m_bFile))
   //            continue;

   //         listing.add(strPath);

   //         ::file::path & path = listing.last();

   //         path.m_iDir = bIsDir ? 1 : 0;

   //         if (bIsDir)
   //         {

   //            path.m_iSize = 0;

   //         }
   //         else
   //         {

   //            path.m_iSize = file_length_dup(strPath);

   //         }

   //      }

   //   }

   //   return listing;

   //}


   //bool directory_context::rls(const_char_pointer lpcsz, string_array_base * pstraPath, string_array_base * pstraTitle, string_array_base * pstraRelative, enum_extract eextract)
   //{

   //   if(::file::system_dir::rls(papp,lpcsz,pstraPath,pstraTitle,pstraRelative,eextract))
   //   {

   //      return true;

   //   }

   //   return rls_pattern(papp, lpcsz, "*.*", pstraPath, pstraTitle, pstraRelative, nullptr, nullptr, eextract);

   //}


   //bool directory_context::rls_pattern(const_char_pointer lpcsz, const_char_pointer pszPattern, string_array_base * pstraPath, string_array_base * pstraTitle, string_array_base * pstraRelative, bool_array * pbaIsDir, long_long_array_base * piaSize, enum_extract eextract)
   //{


   //   if(::file::system_dir::rls_pattern(papp,lpcsz,pszPattern,pstraPath,pstraTitle,pstraRelative,pbaIsDir,piaSize,eextract))
   //   {

   //      return true;

   //   }

   //   string_array_base straDir;

   //   ::directory_context::ls_dir(straDir, lpcsz);

   //   for(int i = 0; i < straDir.get_count(); i++)
   //   {

   //      string strDir = straDir[i];

   //      if(strDir == lpcsz)
   //         continue;

   //      index iStart = 0;

   //      if(pstraRelative != nullptr)
   //      {
   //         iStart = pstraRelative->get_size();
   //      }

   //      rls_pattern(papp, strDir, pszPattern, pstraPath, pstraTitle, pstraRelative, pbaIsDir, piaSize, eextract == e_extract_all ? e_extract_all : e_extract_none);

   //      if(pstraRelative != nullptr)
   //      {

   //         for(::collection::index i = iStart; i < pstraRelative->get_size(); i++)
   //         {

   //            pstraRelative->element_at(i) = get_context()->directory_context().path(file().name_(strDir), pstraRelative->element_at(i));

   //         }

   //      }

   //   }

   //   string strDir(lpcsz);

   //   if(!strDir.ends("/"))
   //   {

   //      strDir += "/";

   //   }

   //   string_array_base stra;

   //   ::directory_context::ls(stra, lpcsz);

   //   for(int i = 0; i < stra.get_count(); i++)
   //   {

   //      string strPath = stra[i];

   //      string strName = strPath;

   //      if(!strName.begins_eat(strDir))
   //         continue;

   //      if(!matches_wildcard_criteria(pszPattern, strName))
   //         continue;

   //      if(pstraPath != nullptr)
   //      {

   //         pstraPath->add(strPath);

   //      }

   //      if(pstraTitle != nullptr)
   //      {

   //         pstraTitle->add(strName);

   //      }

   //      if(pstraRelative != nullptr)
   //      {

   //         pstraRelative->add(strName);

   //      }

   //      bool bIsDir;

   //      if(pbaIsDir != nullptr || piaSize != nullptr)
   //      {

   //         bIsDir = ::directory_context::is(strPath);

   //      }

   //      if(pbaIsDir != nullptr)
   //      {

   //         pbaIsDir->add(bIsDir);

   //      }

   //      if(piaSize != nullptr)
   //      {

   //         if(bIsDir)
   //         {

   //            piaSize->add(0);

   //         }
   //         else
   //         {

   //            piaSize->add(file_length_dup(strPath));

   //         }

   //      }

   //   }

   //   return true;

   //}


   //bool directory_context::rls_dir(const_char_pointer lpcsz, string_array_base * pstraPath, string_array_base * pstraTitle, string_array_base * pstraRelative)
   //{

   //   if(::file::system_dir::rls_dir(papp,lpcsz,pstraPath,pstraTitle,pstraRelative))
   //   {

   //      return true;

   //   }

   //   string_array_base stra;

   //   ::directory_context::ls(stra, lpcsz);

   //   string strDir(lpcsz);

   //   if(!strDir.ends("/"))
   //   {

   //      strDir += "/";

   //   }


   //   for(int i = 0; i < stra.get_count(); i++)
   //   {

   //      string strPath = stra[i];

   //      string strName = strPath;

   //      if(!strName.begins_eat(strDir))
   //         continue;

   //      if(!get_context()->directory_context().is(strPath))
   //         continue;

   //      if(pstraPath != nullptr)
   //      {

   //         pstraPath->add((const_char_pointer )stra[i]);

   //      }

   //      if(pstraTitle != nullptr)
   //      {

   //         pstraTitle->add(strName);

   //      }

   //      if(pstraRelative != nullptr)
   //      {

   //         pstraRelative->add(strName);

   //      }

   //      index iStart = 0;

   //      if(pstraRelative != nullptr)
   //      {

   //         iStart = pstraRelative->get_size();

   //      }

   //      rls_dir(papp, strPath, pstraPath, pstraTitle, pstraRelative);

   //      if(pstraRelative != nullptr)
   //      {

   //         for(::collection::index i = iStart; i < pstraRelative->get_size(); i++)
   //         {

   //            pstraRelative->element_at(i) = get_context()->directory_context().path(strPath, pstraRelative->element_at(i));

   //         }

   //      }

   //   }

   //   return true;

   //}


   //bool directory_context::ls_dir(const_char_pointer lpcsz, string_array_base * pstraPath, string_array_base * pstraTitle)
   //{

   //   if(::file::system_dir::ls_dir(papp,lpcsz,pstraPath,pstraTitle))
   //   {

   //      return true;

   //   }

   //   string_array_base stra;

   //   ::directory_context::ls(stra, lpcsz);

   //   string strDir(lpcsz);

   //   if(!strDir.ends("/"))
   //   {

   //      strDir += "/";

   //   }


   //   for(int i = 0; i < stra.get_count(); i++)
   //   {

   //      string strPath = stra[i];

   //      string strName = strPath;

   //      if(!strName.begins_eat(strDir))
   //         continue;

   //      if(!get_context()->directory_context().is(strPath))
   //         continue;

   //      if(pstraPath != nullptr)
   //      {

   //         pstraPath->add((const_char_pointer )stra[i]);

   //      }

   //      if(pstraTitle != nullptr)
   //      {

   //         pstraTitle->add(strName);

   //      }

   //   }

   //   return true;

   //}


   //bool directory_context::ls_file(const_char_pointer lpcsz, string_array_base * pstraPath, string_array_base * pstraTitle)
   //{

   //   if(::file::system_dir::ls_file(papp,lpcsz,pstraPath,pstraTitle))
   //   {

   //      return true;

   //   }

   //   string_array_base stra;

   //   ::directory_context::ls(stra, lpcsz);

   //   string strDir(lpcsz);

   //   if(!strDir.ends("/"))
   //   {

   //      strDir += "/";

   //   }


   //   for(int i = 0; i < stra.get_count(); i++)
   //   {

   //      string strPath = stra[i];

   //      string strName = strPath;

   //      if(!strName.begins_eat(strDir))
   //         continue;

   //      if(get_context()->directory_context().is(strPath))
   //         continue;


   //      if(pstraPath != nullptr)
   //      {

   //         pstraPath->add((const_char_pointer )stra[i]);

   //      }

   //      if(pstraTitle != nullptr)
   //      {

   //         pstraTitle->add(strName);

   //      }

   //   }

   //   return true;

   //}


   //bool directory_context::ls(const_char_pointer lpcsz, string_array_base * pstraPath, string_array_base * pstraTitle, bool_array * pbaIsDir, long_long_array_base * piaSize)
   //{


   //   if(::file::system_dir::ls(papp,lpcsz,pstraPath,pstraTitle,pbaIsDir,piaSize))
   //   {

   //      return true;

   //   }


   //   string_array_base stra;

   //   ::directory_context::ls(stra, lpcsz);

   //   string strDir(lpcsz);

   //   if(!strDir.ends("/"))
   //   {

   //      strDir += "/";

   //   }


   //   for(int i = 0; i < stra.get_count(); i++)
   //   {

   //      string strPath = stra[i];

   //      string strName = strPath;

   //      if(!strName.begins_eat(strDir))
   //         continue;

   //      if(pstraPath != nullptr)
   //      {

   //         pstraPath->add((const_char_pointer )stra[i]);

   //      }

   //      if(pstraTitle != nullptr)
   //      {

   //         pstraTitle->add(strName);

   //      }


   //      bool bIsDir;

   //      if(pbaIsDir != nullptr || piaSize != nullptr)
   //      {

   //         bIsDir = get_context()->directory_context().is(strPath);

   //      }

   //      if(pbaIsDir != nullptr)
   //      {

   //         pbaIsDir->add(bIsDir);

   //      }

   //      if(piaSize != nullptr)
   //      {

   //         if(bIsDir)
   //         {

   //            piaSize->add(0);

   //         }
   //         else
   //         {

   //            piaSize->add(file_length_dup(strPath));

   //         }

   //      }


   //   }

   //   return true;

   //}


   //bool directory_context::is(const ::file::path & lpcszPath)
   //{

   //   if (::directory_context::is(lpcszPath))
   //   {

   //      return true;

   //   }

   //   string strPath(lpcszPath);

   //   if (strPath.get_length() >= MAX_PATH)
   //   {

   //      if (strPath.begins("\\\\"))
   //      {

   //         strPath = "\\\\?\\UNC" + strPath.substr(1);

   //      }
   //      else
   //      {

   //         strPath = "\\\\?\\" + strPath;

   //      }

   //   }

   //   bool bIsDir = ::dir::_is(strPath);

   //   return bIsDir;

   //}


   //bool directory_context::is(const ::scoped_string & scopedstrPath)
   //{

   //   if(::file::system_dir::is(strPath))
   //      return true;

   //   bool bIsDir;

   //   unsigned int dwLastError;

   //   if(m_isdirmap.lookup(strPath, bIsDir, dwLastError))
   //   {

   //      if(!bIsDir)
   //      {

   //         set_last_error(dwLastError);

   //      }

   //      return bIsDir;

   //   }


   //   wstring wstrPath;

   //   //character_count iLen = utf8_to_unicode_count(strPath);
   //   //wstrPath.alloc(iLen + 32);
   //   wstrPath = utf8_to_unicode(strPath);
   //   if(wstrPath.get_length() >= MAX_PATH)
   //   {
   //      if(wstrPath.begins(L"\\\\"))
   //      {
   //         ::str().begin(wstrPath, L"\\\\?\\UNC");
   //      }
   //      else
   //      {
   //         ::str().begin(wstrPath, L"\\\\?\\");
   //      }
   //   }

   //   bIsDir = ::directory_context::is(unicode_to_utf8(wstrPath));

   //   m_isdirmap.set(strPath, bIsDir, bIsDir ? 0 : ::get_last_error());

   //   return bIsDir;
   //}

   bool directory_context::name_is(const ::file::path & str)
   {
      //output_debug_string(str);
      character_count iLast = str.length() - 1;
      while (iLast >= 0)
      {
         if (str[iLast] != '\\' && str[iLast] != '/' && str[iLast] != ':')
            break;
         iLast--;
      }
      while (iLast >= 0)
      {
         if (str[iLast] == '\\' || str[iLast] == '/' || str[iLast] == ':')
            break;
         iLast--;
      }
      if (iLast >= 0)
      {
         while (iLast >= 0)
         {
            if (str[iLast] != '\\' && str[iLast] != '/' && str[iLast] != ':')
            {
               iLast++;
               break;

            }

            iLast--;

         }

      }
      else
      {

         return true; // assume empty string is root_ones directory

      }

      if (task_flag().is_set(e_task_flag_compress_is_dir) && iLast >= 3 && !case_insensitive_ansi_count_compare(&((const_char_pointer )str)[iLast - 3], ".zip", 4))
      {

         return true;

      }

      wstring wstrPath;

      wstrPath = str.left(iLast + 1);

      bool bIsDir = ::directory_context::is(wstrPath);

      return bIsDir;

   }


   ::file::path directory_context::time()
   {

      return m_pdirectorysystem->m_strTimeFolder;

   }


   ::file::path directory_context::stage()
   {

      return install() / "stage";

   }


   ::file::path directory_context::stageapp()
   {

      return stage() / "basis";

   }


   ::file::path directory_context::netseed()
   {

      return m_pdirectorysystem->m_strNetSeedFolder;

   }


   // stage in ccwarehouse spalib
   ::file::path directory_context::install()
   {

      single_lock synchronouslock(synchronization(), true);

      return m_pdirectorysystem->m_pathInstall;

   }


   //::file::path directory_context::module()
   //{

   // return ::apexacmesystem()->get_module_folder();

   //}


   //::file::path directory_context::ca2module()
   //{
   //
   // return ::apexacmesystem()->get_ca2_module_folder();
   //
   //}


   ::file::path directory_context::time_square()
   {

      return time() / "time";

   }


   ::file::path directory_context::time_log(const ::scoped_string & scopedstrId)
   {

      return appdata() / "log";

   }

   //bool directory_context::mk(const ::file::path & lpcsz)
   //{

   //   if (is(lpcsz))
   //      return true;

   //   ::file::path_array_base stra;

   //   lpcsz.ascendants_path(stra);

   //   for (int i = 0; i < stra.get_size(); i++)
   //   {

   //      if (!is(stra[i]))
   //      {

   //         if (!::dir::_mk(stra[i]))
   //         {

   //            auto estatus = ::get_last_status();

   //            if (estatus == error_already_exists)
   //            {

   //               string str;
   //               str = "\\\\?\\" + stra[i];
   //               str.trim_right("\\/");
   //               try
   //               {
   //                  file().del(str);
   //               }
   //               catch (...)
   //               {
   //               }
   //               str = stra[i];
   //               str.trim_right("\\/");
   //               try
   //               {
   //                  file().del(str);
   //               }
   //               catch (...)
   //               {
   //               }

   //               //if(::CreateDirectory(utf8_to_unicode("\\\\?\\" + stra[i]), nullptr))
   //               if (::directory_context::mk("\\\\?\\" + stra[i]))
   //               {

   //                  goto try1;

   //               }
   //               else
   //               {

   //                  estatus = ::get_last_status();

   //               }

   //            }

   //         }

   //      try1:

   //         if (!is(stra[i]))
   //         {

   //            return false;

   //         }

   //      }

   //   }

   //   return true;

   //}


   //bool directory_context::rm(const ::file::path & path, bool bRecursive)
   //{
   //   if (bRecursive)
   //   {

   //      ::file::listing_base straPath;

   //      straPath.m_pathFinal = path;

   //      ls(straPath);

   //      for (int i = 0; i < straPath.get_count(); i++)
   //      {

   //         if (is(straPath[i]))
   //         {

   //            rm(path / straPath[i].name(), true);

   //         }
   //         else
   //         {

   //            ::unlink(straPath[i]);

   //         }

   //      }

   //   }

   //   return ::rmdir(path) != false;

   //}


   void directory_context::init_system()
   {

      //auto estatus = 
      
      ::directory_context::init_system();
     
      //if (!estatus)
      //{

      //  return estatus;

      //}

      //xml::document doc;

      //doc.load(file().as_string(appdata() / "configuration\\directory.xml"));

      ::file::path pathInstall = system()->m_pathCacheDirectory;

      m_pdirectorysystem->m_pathInstall = pathInstall;

      //nodeos_set_home(         auto psystem = system();

//         auto pacmedirectory = psystem->m_pdirectorysystem;
//
//pacmedirectory->system() / "home");
//
//      //nodeos_set_temp(         auto psystem = system();
//
//         auto pacmedirectory = psystem->m_pdirectorysystem;
//
//pacmedirectory->system() / "temp");

      m_pdirectorysystem->m_strCommonAppData = pathInstall / "commonappdata";

      create(m_pdirectorysystem->m_strCommonAppData);

      if (!is(m_pdirectorysystem->m_strCommonAppData))
      {

         throw ::exception(error_failed);

      }

      ::file::path pathTimeFolder;

      ::file::path pathNetSeedFolder;

      //if (doc.get_name() == "directory_configuration")
      //{

      //   pathTimeFolder = doc.get_child_value("time");

      //   pathNetSeedFolder = doc.get_child_value("netseed");

      //}

      if (m_pdirectorysystem->m_strTimeFolder.is_empty())
      {

         pathTimeFolder = appdata() / "time";

      }

      if (m_pdirectorysystem->m_strNetSeedFolder.is_empty())
      {

         pathNetSeedFolder = install() / "net";

      }

      this->create(pathTimeFolder);

      if (!is(pathTimeFolder))
      {

         throw ::exception(error_failed);

      }

      ::file::path pathTimeFolderTime;

      pathTimeFolderTime = pathTimeFolder / "time";

      create(pathTimeFolderTime);

      if (!is(pathTimeFolderTime))
      {

         //return error_failed;

         throw ::exception(error_failed);


      }

      m_pdirectorysystem->m_strTimeFolder = pathTimeFolder;

      m_pdirectorysystem->m_strNetSeedFolder = pathNetSeedFolder;

      //return success;

   }


   void directory_context::init_context()
   {

      //auto estatus = 
      
      ::directory_context::init_context();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   //::file::path directory_context::trash_that_is_not_trash(const ::file::path & pathParam)
   //{

   //   if (pszParam == nullptr)
   //      return "";

   //   ::file::path psz(pszParam);

   //   if (psz[1] == ':')
   //   {
   //      string strDir = psz.folder();
   //      string str;
   //      str = strDir.left()(2);
   //      str += "\\trash_that_is_not_trash\\";
   //      string strFormat;
   //      ::earth::time time;
   //      time = ::earth::time::now();
   //      strFormat.formatf("%04d-%02d-%02d %02d-%02d-%02d\\", time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
   //      str += strFormat;
   //      if (strDir[2] == '\\')
   //      {
   //         str += strDir.substr(3);
   //      }
   //      else
   //      {
   //         str += strDir.substr(2);
   //      }
   //      return str;
   //   }

   //   return "";
   //}


//   ::file::path directory_context::appdata()
//   {
//
//      string str;
//
//      str =          auto psystem = system();
//
//         auto pacmedirectory = psystem->m_pdirectorysystem;
//
//pacmedirectory->system() / ".ca2/app/appdata";
//      
//      string strRelative;
//
//      strRelative = install();
//
//      return str / "ca2";
//
//   }


   ::file::path directory_context::commonappdata()
   {

      return m_pdirectorysystem->m_strCommonAppData;

   }


   //::file::path directory_context::usersystemappdata(const string & lpcszPrefix)
   //{

   //   

   //   return appdata() / lpcszPrefix;

   //}


   //::file::path directory_context::appdata()
   //{

   //   return userfolder() /  "appdata";

   //}


   //::file::path directory_context::userdata()
   //{

   //   return userfolder() / "data";

   //}


//   ::file::path directory_context::userfolder()
//   {
//
//      string str;
//      /*SHGetSpecialFolderPath(
//         nullptr,
//         str,
//         CSIDL_PROFILE,
//         false);*/
//
//      str = getenv("HOME");
//
//      ::file::path strRelative;
//      strRelative = install();
//      index iFind = strRelative.find(':');
//      if(iFind >= 0)
//      {
//         character_count iFind1 = strRelative.rear_find("\\", iFind);
//         character_count iFind2 = strRelative.rear_find("/", iFind);
//         character_count iStart = maximum(iFind1 + 1, iFind2 + 1);
//         strRelative = strRelative.left()(iFind - 1) + "_" + strRelative.substr(iStart, iFind - iStart) + strRelative.substr(iFind + 1);
//      }
//
//   ::file::path strUserFolderShift;
//
//      if(App(papp).has_property("user_folder_relative_path"))
//      {
//         strUserFolderShift = strRelative / App(papp).m_varTopicQuery["user_folder_relative_path"].get_string();
//      }
//      else
//      {
//         strUserFolderShift = strRelative;
//      }
//
//      return str / "ca2" / strUserFolderShift;
//
////      return path(path(str, "ca2"), lpcsz);
///*      if(&AppUser() == nullptr)
//      {
//         string str;
//         SHGetSpecialFolderPath(
//            nullptr,
//            str,
//            CSIDL_PROFILE,
//            false);
//         return path(path(str, "ca2\\_____default"), lpcsz);
//      }
//      else
//      {
//         return path(AppUser().m_strPath, lpcsz, lpcsz2);
//      }*/
//   }

   //::file::path directory_context::default_os_user_path_prefix()
   //{
   //   /*
   //   unichar buf[MAX_PATH];
   //   ULONG ulSize = sizeof(buf) / sizeof(unichar);
   //   if(!::GetUserNameExW(Namecanonical, buf, &ulSize))
   //   {
   //      if(!::GetUserNameW(buf, &ulSize))
   //      {
   //         memory_set(buf, 0, sizeof(buf));
   //      }
   //   }*/
   //   /*return unicode_to_utf8(buf);*/
   //   return ::getlogin();

   //}


   //::file::path directory_context::default_userappdata(const string & lpcszPrefix, const string & lpcszLogin)
   //{

   //   return default_userfolder(papp, lpcszPrefix, lpcszLogin) /  "appdata";

   //}


   //::file::path directory_context::default_userdata(const string & lpcszPrefix, const string & lpcszLogin)
   //{

   //   return default_userfolder(papp, lpcszPrefix, lpcszLogin) / "data";

   //}


   //::file::path directory_context::default_userfolder(::apex::application *  papp, const string & lpcszPrefix, const string & lpcszLogin)
   //{

   //   return userfolder();

   //}


   ::file::path directory_context::userquicklaunch()
   {

      return m_pdirectorysystem->m_pathInstall / ".ca2/app/Microsoft/Internet Explorer/Quick Launch";

   }


   ::file::path directory_context::bookmark()
   {

      return m_pdirectorysystem->m_pathInstall / "bookmark";

   }


   ::file::path directory_context::userprograms()
   {

      return m_pdirectorysystem->m_pathInstall / "userprograms";

   }


   ::file::path directory_context::commonprograms()
   {

      return m_pdirectorysystem->m_pathInstall / "commonprograms";

   }


   bool directory_context::is_inside_time(const ::file::path & path)
   {

      return is_inside(time(), path);

   }



   bool directory_context::is_inside(const ::file::path & pathFolder, const ::file::path & path)
   {

      return pathFolder.case_insensitive_begins(path);

   }


   //bool directory_context::has_subdir(const ::file::path & pathFolder)
   //{

   //   ::file::listing_base ls;

   //   ls_dir(ls, pszDir);

   //   return ls.get_size() > 0;

   //}


   ::file::path directory_context::commonappdata_root()
   {

      return m_pdirectorysystem->m_strCommonAppData;

   }


} // namespace acme_android




