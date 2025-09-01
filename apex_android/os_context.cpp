#include "framework.h"
#include "os_context.h"
#include "acme/exception/interface_only.h"
#include "acme/platform/node.h"


#undef USERNAME_LENGTH // mysql one


namespace apex_android
{


   os_context::os_context()
   {
   }


   os_context::~os_context()
   {
   }


   void os_context::shutdown(bool bIfPowerOff)
   {
      /*      bool retval = true;
            HANDLE hToken;
            TOKEN_PRIVILEGES tokenprivileges;
            if (!OpenProcessToken(GetCurrentProcess(),
               TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
               return false;
            LookupPrivilegeValue(nullptr, SE_SHUTDOWN_NAME, &tokenprivileges.Privileges[0].Luid);
            tokenprivileges.PrivilegeCount = 1;
            tokenprivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            AdjustTokenPrivileges(hToken, false, &tokenprivileges, 0, (PTOKEN_PRIVILEGES) nullptr, 0);
            if (bIfPowerOff)
               retval = ExitWindowsEx(EWX_POWEROFF, 0) != false;
            else
               retval = ExitWindowsEx(EWX_SHUTDOWN, 0) != false;

            //reset the previlages
            tokenprivileges.Privileges[0].Attributes = 0;
            AdjustTokenPrivileges(hToken, false, &tokenprivileges, 0, (PTOKEN_PRIVILEGES) nullptr, 0);
            return retval;*/

      throw ::interface_only();
      //return false;

   }

   
   void os_context::reboot()
   {
      /*      HANDLE hToken;
            TOKEN_PRIVILEGES tokenprivileges;
            if (!OpenProcessToken(GetCurrentProcess(),
               TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
               return false;
            if(!LookupPrivilegeValue(nullptr, SE_SHUTDOWN_NAME, &tokenprivileges.Privileges[0].Luid))
            {
               TRACELASTERROR();
               return false;
            }
            tokenprivileges.PrivilegeCount = 1;
            tokenprivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(!AdjustTokenPrivileges(hToken, false, &tokenprivileges, 0, (PTOKEN_PRIVILEGES) nullptr, 0))
            {
               TRACELASTERROR();
               return false;
            }
            if (get_last_error() == ERROR_NOT_ALL_ASSIGNED)
            {
               return false;
            }
            if(!LookupPrivilegeValue(nullptr, SE_REMOTE_SHUTDOWN_NAME, &tokenprivileges.Privileges[0].Luid))
            {
               TRACELASTERROR();
               return false;
            }
            tokenprivileges.PrivilegeCount = 1;
            tokenprivileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(!AdjustTokenPrivileges(hToken, false, &tokenprivileges, 0, (PTOKEN_PRIVILEGES) nullptr, 0))
            {
               TRACELASTERROR();
               return false;
            }
            if (get_last_error() == ERROR_NOT_ALL_ASSIGNED)
            {
               return false;
            }


            if(!WTSShutdownSystem(WTS_CURRENT_SERVER_HANDLE, WTS_WSD_REBOOT))
            {
               TRACELASTERROR();
               return false;
            }
            /*if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE,
            SHTDN_REASON_MAJOR_SOFTWARE | SHTDN_REASON_MINOR_INSTALLATION))
            {
            unsigned int dwLastError = ::get_last_error();
            return false;
            }*/
      //reset the previlages
      /*    tokenprivileges.Privileges[0].Attributes = 0;
          AdjustTokenPrivileges(hToken, false, &tokenprivileges, 0, (PTOKEN_PRIVILEGES) nullptr, 0);
          return true;*/
      throw ::interface_only();
      //return false;

   }


   void os_context::terminate_processes_by_title(const ::scoped_string & scopedstrName)
   {
      
      throw ::interface_only();

      //return;

      /*      unsigned int dwPid;
            while(get_pid_by_title(pszName, dwPid))
            {
               HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                  PROCESS_VM_READ,
                  false, dwPid );
               TerminateProcess(hProcess, (unsigned int) -1);
               CloseHandle(hProcess);
               /*::EnumWindows((WNDENUMPROC)
               CKillProcessHelper::TerminateAppEnum,
               (LPARAM) dwId);
               // Wait on the handle. If it signals, great.

               //If it times out, then you kill it.

               if(WaitForSingleObject(hProcess, 5000)
               !=WAIT_OBJECT_0)
               bResult = TerminateProcess(hProcess,0);
               else
               bResult = true;
               CloseHandle(hProcess);
               return bResult == true;*/

      //  }
   }


   //::process_identifier_array os_context::module_path_processes_identifiers(const ::scoped_string & scopedstr)
   //{

   //   auto processesidentifiers = processes_identifiers();
   //   
   //   for(int i = 0; i < dwa.get_count(); i++)
   //   {
   //      if(get_process_path(dwa[i]).case_insensitive_order(strName) == 0)
   //      {
   //         dwPid = dwa[i];
   //         return true;
   //      }
   //   }
   //   return false;
   //}


   //bool os_context::title_pid(unsigned int & dwPid, const ::scoped_string & scopedstrName)
   //{
   //   ::unsigned_int_array dwa;
   //   get_all_processes(dwa);
   //   for(int i = 0; i < dwa.get_count(); i++)
   //   {
   //      if(get_process_path(dwa[i]).title().case_insensitive_order(strName) == 0)
   //      {
   //         dwPid = dwa[i];
   //         return true;
   //      }
   //   }
   //   return false;
   //}


   process_identifier os_context::current_process_identifier()
   {

      return ::getpid();

   }


   ::file::path os_context::process_identifier_module_path(process_identifier processidentifier)
   {
      /*
      string strName = ":<unknown>";
      // get a handle to the process.
      HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
         PROCESS_VM_READ,
         false, dwPid );

      // get the process name.

      if (nullptr != hProcess )
      {
         HMODULE hMod;
         unsigned int cbNeeded;

         if(EnumProcessModules( hProcess, &hMod, sizeof(hMod),
            &cbNeeded) )
         {
            strName = get_module_path(hMod);
         }
      }

      CloseHandle( hProcess );
      return strName;*/
      throw ::interface_only();
      return "";

   }

   
   process_identifier_array os_context::processes_identifiers()
   {

      return node()->processes_identifiers();

      /*
            dwa.set_size(0);
            unsigned int cbNeeded = 0;
            while(cbNeeded == natural(dwa.get_count()))
            {
               dwa.set_size(dwa.get_count() + 1024);
               if(!EnumProcesses(
                  dwa.get_data(),
                  (unsigned int) (dwa.get_count() * sizeof(unsigned int)),
                  &cbNeeded))
               {
                  return;
               }
               dwa.set_size(cbNeeded / sizeof(unsigned int));
            }*/
   }

   //string os_context::get_module_path(HMODULE hmodule)
   //{
   //   throw ::interface_only();
   //   return "";
   //   /*
   //   string strPath;
   //   unsigned int dwSize = 1;
   //   while(natural(strPath.get_length() + 1) == dwSize)
   //   {
   //      dwSize = ::GetModuleFileName(
   //         hmodule,
   //         strPath.get_buffer(dwSize + 1024),
   //         (dwSize + 1024));
   //      strPath.ReleaseBuffer();
   //   }
   //   return strPath;*/
   //}


   ::payload os_context::connection_settings_get_auto_detect()
   {
      //throw ::interface_only();
      return false;

      /*
            registry::Key key1;

            key1.OpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Connections", false);

            memory mem;

            key1.QueryValue("DefaultConnectionSettings", mem);

            bool bAutoDetect = (((LPBYTE) mem.get_data())[8] & 0x08) != 0;

            return bAutoDetect;
      */
   }



   ::payload os_context::connection_settings_get_auto_config_url()
   {

      //throw ::interface_only();
      return "";
      /*
            registry::Key key;

            key.OpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings", false);

            string strUrl;

            key.QueryValue("AutoConfigURL", strUrl);

            return strUrl;
      */
   }


   void os_context::local_machine_set_run(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet)
   {

//      throw ::interface_only();
      //return false;

      /*
            registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(pszKey, pszCommand);


            return true;
      */
   }


   void os_context::local_machine_set_run_once(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet)
   {


      throw ::interface_only();
      //return false;
      /*    registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(pszKey, pszCommand);
      */

      //return false;

   }


   void os_context::current_user_set_run(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet)
   {

      throw ::interface_only();
      //return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(pszKey, pszCommand);
      */

      //return false;

   }


   void os_context::current_user_set_run_once(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet)
   {

      throw ::interface_only();
      //return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(pszKey, pszCommand);

      */
      //return false;

   }


   void os_context::defer_register_ca2_plugin_for_mozilla()
   {
      //  throw ::interface_only();
      //return false;

      /*
            registry::Key keyPlugins;

            if(keyPlugins.OpenKey(HKEY_LOcaL_MACHINE, "SOFTWARE\\MozillaPlugins", true))
            {

               registry::Key keyPlugin;

               if(keyPlugin.OpenKey(keyPlugins, "@ca2.network/npca2", true))
               {

                  keyPlugin.SetValue("Description", "ca2 plugin for NPAPI");
                  keyPlugin.SetValue("Path", ::apexacmesystem()->m_strCa2Module("npca2.dll"));
                  keyPlugin.SetValue("ProductName", "ca2 plugin for NPAPI");
                  keyPlugin.SetValue("Vendor", "ca2 Desenvolvimento de Software Ltda.");
                  keyPlugin.SetValue("Version", get_app()->file_system()->as_string(m_papplication->dir().ca2("appdata/x86/ca2_build.txt")));

                  registry::Key keyApplicationca2;

                  if(keyApplicationca2.OpenKey(keyPlugin, "application/ca2", true))
                  {

                     keyApplicationca2.SetValue("Description", "ca2 Document");

                  }

               }

            }

            return true;
      */
   }

   
   void os_context::file_extension_get_open_with_list_keys(string_array_base & straKey, const ::scoped_string & scopedstrExtension)
   {

      throw ::interface_only();

      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += pszExtension;

            string strOpenWithKey;
            strOpenWithKey = strExt + "\\OpenWithList";

            registry::Key key;

            key.OpenKey(HKEY_CLASSES_ROOT, strOpenWithKey, false);

            key.EnumKey(straKey);

            return true;
      */
   }


   void os_context::file_extension_get_open_with_list_commands(string_array_base & straCommand, const ::scoped_string & scopedstrExtension)
   {

      string_array_base straKey;

      //if(!
      file_extension_get_open_with_list_keys(straKey, strExtension);
         //return false;


      //return true;

   }

   
   void os_context::file_association_set_default_icon(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass, const ::scoped_string & scopedstrIconPath)
   {

      throw ::interface_only();
      //return false;

      /*
            string strExtensionNamingClass(pszExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass, true);
            keyLink3.SetValue("DefaultIcon", pszIconPath);


            return false;
      */
   }


   void os_context::file_association_set_shell_open_command(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass, const ::scoped_string & scopedstrCommand, const ::scoped_string & scopedstrParam)
   {

      throw ::interface_only();

      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += pszExtension;

            string strExtensionNamingClass(pszExtensionNamingClass);

            registry::Key key(HKEY_CLASSES_ROOT, strExt, true);
            key.SetValue(nullptr, strExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass + "\\shell", true);
            keyLink3.SetValue(nullptr, "open");

            registry::Key keyLink2(keyLink3, "open", true);
            keyLink2.SetValue(nullptr, "&Abrir");

            registry::Key keyLink1(keyLink2, "command", true);

            string strFormat;
            strFormat.formatf("\"%s\" \"%%L\" %s", pszCommand, pszParam);
            keyLink1.SetValue(nullptr, strFormat);

            return true;
      */
   }

   
   void os_context::file_association_get_shell_open_command(const ::scoped_string & scopedstrExtension, string & strExtensionNamingClass, string & strCommand, string & strParam)
   {

      throw ::interface_only();
      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += pszExtension;

            registry::Key key(HKEY_CLASSES_ROOT, strExt, false);
            if(!key.QueryValue(nullptr, strExtensionNamingClass))
               return false;

            registry::Key keyLink(HKEY_CLASSES_ROOT, strExtensionNamingClass + "\\shell\\open\\command", false);

            string strFormat;
            if(keyLink.QueryValue(nullptr, strFormat))
            {

               const_char_pointer psz = strFormat;

               try
               {

                  strCommand = ::str().consume_quoted_value(psz);
                  ::str().consume_spaces(psz);
                  ::str().consume(psz, "\"%L\"");
                  strParam = psz;

               }
               catch(...)
               {
               }


            }

            return true;
      */
   }


   void os_context::native_modern_web_browser(const ::scoped_string & scopedstr)
   {

      throw ::interface_only();
      //return false;

   }


   void os_context::native_full_web_browser(const ::scoped_string & scopedstr)
   {

      throw ::interface_only();
      //return false;

      /*    registry reg;
            string str;
            string str2;
            string strCommand;
            registry::Key key;
            if(key.OpenKey(HKEY_CLASSES_ROOT, ".html", false))
            {
               if(reg.RegQueryValue(key.m_hkey, "", str))
               {
                  if(key.OpenKey(HKEY_CLASSES_ROOT, ".html\\shell\\opennew\\command", false))
                  {
                     string str;
                     if(reg.RegQueryValue(HKEY_CLASSES_ROOT, str, str2))
                     {
                        string strCommand(str2);
                        strCommand.replace("%1", lpcsz);
                        WinExec(strCommand,e_display_normal);
                     }
                  }
                  else
                  {
                     if(key.OpenKey(HKEY_CLASSES_ROOT, str, false))
                     {
                        str += "\\shell\\opennew\\command";
                        if(key.OpenKey(HKEY_CLASSES_ROOT, str, false))
                        {
                           if(reg.RegQueryValue(key.m_hkey, "", str2))
                           {
                              string strCommand(str2);
                              strCommand.replace("%1", lpcsz);
                              WinExec(strCommand,e_display_normal);
                           }
                        }
                     }
                  }
               }
            }

            return true;
      */

   }


   void os_context::enable_service()
   {

      //throw ::interface_only();
      //return error_failed;


   }


   void os_context::disable_service()
   {
//      throw ::interface_only();
      //return error_failed;

   }


   void os_context::start_service()
   {
      //throw ::interface_only();
      //return error_failed;

   }

   
   void os_context::stop_service()
   {

      throw ::interface_only();
      //return error_failed;

   }


   //void os_context::raise_exception( unsigned int dwExceptionCode, unsigned int dwExceptionFlags)
   //{

   //   throw ::interface_only();
   //   return;
   //   /*
   //         RaiseException( dwExceptionCode, dwExceptionFlags, 0, nullptr );
   //         */
   //}

   bool os_context::is_remote_session()
   {

//      throw ::interface_only();
      return false;
      /*
            return GetSystemMetrics(SM_REMOTESESSION) != false;
      */
   }


   //void os_context::post_to_all_threads(::user::enum_message eusermessage, ::wparam wparam, ::lparam lparam)
   //{

   //   throw ::interface_only();
   //   return;


   //}

//   void os_context::enum_draw2d_fonts(::write_text::font_enumeration_item_array& itema)
//   {
//
//      critical_section_lock synchronouslock(::apex::g_pcsFont);
//
//      ::pointer<::write_text::font_enumeration_item>pitem;
//
//      double dAndroid = 4.4;
//
//      string strSystemFonts = m_papplication->file().as_string("/system/etc/system_fonts.xml");
//
//            auto psystem = system();

      //auto pxml = psystem->xml();

      //auto pdoc = pxml->create_document();
//
//      ::pointer<ttf_util>putil;
//
//      ::e_status estatus = øconstruct_new(putil);
//
//      if (pdoc->load(strSystemFonts))
//      {
//
//         ::collection::index iFamilyPos = 0;
//
//         while (auto pfamily = pdoc->root()->get_child("family", iFamilyPos))
//         {
//
//            if (iFamilyPos < 0)
//            {
//
//               break;
//
//            }
//
//            iFamilyPos++;
//
//            if (pfamily->get_name() == "family")
//            {
//
//               ::collection::index iNamesetPos = 0;
//
//               auto pnameset = pfamily->get_child("nameset", iNamesetPos);
//
//               ::collection::index iFilesetPos = 0;
//
//               auto pfileset = pfamily->get_child("fileset", iFilesetPos);
//
//               if (pnameset && pfileset)
//               {
//
//                  if (pnameset->get_children_count() >= 1 && pfileset->get_children_count() >= 1)
//                  {
//
//                     ::collection::index iNamePos = 0;
//
//                     auto pfirstname = pnameset->get_child("name", iNamePos);
//
//                     ::collection::index iFilePos = 0;
//
//                     auto pfirstfile = pfileset->get_child("file", iFilePos);
//
//                     if (pfirstname && pfirstfile)
//                     {
//
//                        string strName = pfirstname->get_value();
//
//                        string strFile = pfirstfile->get_value();
//
//                        ::file::path path = "/system/fonts";
//
//                        path /= strFile;
//
//                        pitem = øallocate ::write_text::font_enumeration_item();
//
//                        if (::file_system()->exists(path))
//                        {
//
//                           pitem->m_strFile = path;
//
//                        }
//                        else
//                        {
//
//                           pitem->m_strFile = strFile;
//
//                        }
//
//                        pitem->m_strName = strName;
//
//                        itema.add(pitem);
//
//                        ::apex::g_pmapFontFaceName->set_at(strName, pitem->m_strFile);
//
//                     }
//
//                  }
//
//               }
//
//            }
//
//         }
//
//      }
//
//      if (dAndroid >= 8.0)
//      {
//
//         ::file::path_array_base patha;
//
//         ::dir::ls(patha, "/system/fonts");
//
//         if(estatus.succeeded())
//         {
//
//            for (auto& path : patha)
//            {
//
//               pitem = øallocate ::write_text::font_enumeration_item();
//
//               pitem->m_strFile = path;
//
//               string strName = putil->GetFontNameFromFile(path);
//
//               if (strName.is_empty())
//               {
//
//                  strName = path.title();
//
//               }
//
//               pitem->m_strName = strName;
//
//               itema.add(pitem);
//
//               ::apex::g_pmapFontFaceName->set_at(strName, path);
//
//            }
//
//         }
//
//      }
//
//      if (itema.isEmpty())
//      {
//
//
//#ifdef pnode->font_name(e_font_mono)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_mono);
//
//         pitem->m_strName = pnode->font_name(e_font_mono);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef pnode->font_name(e_font_sans)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_sans);
//
//         pitem->m_strName = pnode->font_name(e_font_sans);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef pnode->font_name(e_font_serif)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_serif);
//
//         pitem->m_strName = pnode->font_name(e_font_serif);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef pnode->font_name(e_font_sans_ex)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_sans_ex);
//
//         pitem->m_strName = pnode->font_name(e_font_sans_ex);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef pnode->font_name(e_font_serif_ex)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_serif_ex);
//
//         pitem->m_strName = pnode->font_name(e_font_serif_ex);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef pnode->font_name(e_font_sans_fx)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_sans_fx);
//
//         pitem->m_strName = pnode->font_name(e_font_sans_fx);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef pnode->font_name(e_font_serif_fx)
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = pnode->font_name(e_font_serif_fx);
//
//         pitem->m_strName = pnode->font_name(e_font_serif_fx);
//
//         itema.add(pitem);
//
//#endif
//
//
//#ifdef FONT_SANS_FX2
//
//         pitem = øallocate ::write_text::font_enumeration_item();
//
//         pitem->m_strFile = FONT_SANS_FX2;
//
//         pitem->m_strName = FONT_SANS_FX2;
//
//         itema.add(pitem);
//
//#endif
//
//
//      }
//
//   }


} // namespace apex_android



