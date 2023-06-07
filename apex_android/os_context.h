#pragma once


#include "apex/platform/os_context.h"


namespace apex_android
{


   class CLASS_DECL_APEX os_context :
      public ::os_context
   {
   public:


      os_context();
      ~os_context() override;


      void reboot() override;
      void shutdown(bool bPowerOff) override;

      void terminate_processes_by_title(const ::string & strName) override;
      //process_identifier_array module_path_processes_identifiers(const ::scoped_string & scopedstr) override;
      //process_identifier_array title_processes_identifiers(const ::scoped_string & scopedstr) override;
      process_identifier current_process_identifier() override;
      process_identifier_array processes_identifiers() override;
      ::file::path process_identifier_module_path(process_identifier processidentifier) override;

      virtual ::payload connection_settings_get_auto_detect() override;
      virtual ::payload connection_settings_get_auto_config_url() override;


      void local_machine_set_run(const ::string & strKey, const ::string & strCommand, const ::string& strArguments, bool bSet) override;
      void local_machine_set_run_once(const ::string & strKey, const ::string & strCommand, const ::string& strArguments, bool bSet) override;
      void current_user_set_run(const ::string & strKey, const ::string & strCommand, const ::string& strArguments, bool bSet) override;
      void current_user_set_run_once(const ::string & strKey, const ::string & strCommand, const ::string& strArguments, bool bSet) override;
      void defer_register_ca2_plugin_for_mozilla() override;

      void file_extension_get_open_with_list_keys(string_array & straKey, const ::string & strExtension) override;
      void file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & strExtension) override;

      void file_association_set_default_icon(const ::string & strExtension, const ::string & strExtensionNamingClass, const ::string & strIconPath) override;
      void file_association_set_shell_open_command(const ::string & strExtension, const ::string & strExtensionNamingClass, const ::string & strCommand, const ::string & strParam) override;
      void file_association_get_shell_open_command(const ::string & strExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;


      void native_full_web_browser(const ::string & str) override;
      void native_modern_web_browser(const ::string & str) override;

      void enable_service() override;
      void disable_service() override;

      void start_service() override;
      void stop_service() override;


      bool is_remote_session() override;


   };


} // namespace apex_android




