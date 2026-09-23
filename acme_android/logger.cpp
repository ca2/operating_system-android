//
// Created by camilo on 2026-09-22 17:40 <3ThomasBorregaardSørensen!! Mummi!! bilbo!!
//
#include "platform.h"
#include "logger.h"
#include "acme/platform/acme.h"
#include "acme/platform/application.h"
#include "acme/platform/debug.h"
#include "acme/platform/system.h"
#include "acme/prototype/datetime/datetime.h"
#include <android/log.h>

CLASS_DECL_ACME ::i32 os_trace_level(enum_trace_level elevel);

//#ifdef WINDOWS
//#include <process.h>
//#elif defined(LINUX)
//#include <sys/types.h>
//#include <unistd.h>
//#elif defined(__BSD__) || defined(__APPLE__)
//#include <stdio.h>
//#endif
//
//#include <mutex>
//
//static bool g_bPrintfIfDebuggerIsNotAttached = false;
//
//static std::recursive_mutex g_simpleLogMutex;
//
//string get_status_message(const ::e_status & estatus);
//
//
//CLASS_DECL_ACME void __simple_tracea(enum_trace_level elevel, const_char_pointer pszFunction, const_char_pointer pszFile, ::i32 iLine, const ::scoped_string & scopedstr);
//CLASS_DECL_ACME void __simple_tracev(enum_trace_level elevel, const_char_pointer pszFunction, const_char_pointer pszFile, ::i32 iLine, const ::scoped_string & scopedstrFormat, va_list args);
//

//CLASS_DECL_ACME void FUNCTION_DEBUGBOX(const ::scoped_string & scopedstrMessage, const ::scoped_string & scopedstrTitle, const ::user::e_message_box & emessagebox, ::callback callback)
//{
//
//   ::auto pmessageboxpayload = __initialize_new ::message_box_payload(nullptr, pszMessage, pszTitle, iFlags, function);

//send(pmessageboxpayload);
//
//}


//CLASS_DECL_ACME void FUNCTION_DEBUGBOXW(const WCHAR * pszMessage, const WCHAR * pszTitle, ::i32 iFlags, const ::function_arg& function)
//{
//
//   ::os_message_box_w(nullptr, pszMessage, pszTitle, iFlags, function);
//
//}


namespace acme_android
{


   logger::logger()
   {

#if REFERENCING_DEBUGGING

      m_referencingdebugging.disable_referencing_debugging();

#endif

      increment_reference_count();

      m_bReallySimple = true;
      m_bWithTimePrefix = true;
      m_bDisplayRelativeTime = false;

      ::file::path pathTrace;

      auto pathHome = home_folder_path();

      pathTrace = pathHome / "trace_using_printf.txt";

//   if (file_exists(pathTrace))
//   {
//
//      g_bPrintfIfDebuggerIsNotAttached = true;
//
//   }

#ifdef _DEBUG

      //information() << "Starting Simple Alog";

#endif

   }


   logger::~logger()
   {

      //information() << "Ending Simple Alog";

   }


   void logger::on_initialize_particle()
   {

      ::simple_log::on_initialize_particle();

      defer_create_synchronization();

   }


   void logger::print(::trace_statement & tracestatement, bool bFlush)
   {

      _synchronous_lock synchronouslock(this->synchronization());

      if (!m_bLog) {

         return;

      }

      if (tracestatement.m_etracelevel > m_etracelevelMinimum) {

         return;

      }

      string str;

      auto sPrefix = tracestatement.prefix();

      if (sPrefix == "task") {

         auto sPrefix2 = tracestatement.prefix();

         sPrefix = sPrefix2;

      }

      auto s = tracestatement.as_string();

      if (m_bReallySimple) {

         if (sPrefix.begins_eat("\r")) {

            str += sPrefix + "> ";

            str += s;

         } else {

            str += s;

            str += "\n";

         }

      } else {

         str.formatf("%s %d %s\n", tracestatement.m_pszFunction, tracestatement.m_iLine, s.c_str());

      }

//   if(m_bWithTimePrefix)
//   {
//
//      ::string strTime;
//
//      class ::time timeNow;
//
//      timeNow.Now();
//
//      if(m_bDisplayRelativeTime)
//      {
//
//         auto Δtime = timeNow - ::acme::get()->m_timeStart;
//
//         ::earth::time_span earthtimepan(Δtime);
//
//         if(earthtimepan.days() <= 0)
//         {
//
//            strTime.formatf("%02d:%02d:%02d %03d ",
//                            earthtimepan.hours(),
//                            earthtimepan.minute(),
//                            earthtimepan.second(),
//                            Δtime.millisecond());
//
//         }
//         else
//         {
//
//            strTime.formatf("%3d %02d:%02d:%02d %03d ",
//                            earthtimepan.days(),
//                            earthtimepan.hour(),
//                            earthtimepan.minute(),
//                            earthtimepan.second(),
//                            Δtime.millisecond());
//
//         }
//
//      }
//      else
//      {
//
//         ::earth::time earthtime(timeNow);
//
//         strTime.formatf("%04d-%02d-%02d %02d:%02d:%02d %03d ",
//                         earthtime.year(),
//                         earthtime.month(),
//                         earthtime.day(),
//                         earthtime.hour(),
//                         earthtime.minute(),
//                         earthtime.second(),
//                         timeNow.millisecond());
//
//      }
//
//      if (str.begins_eat("\r"))
//      {
//
//
//         str = "\r"+strTime + str;
//
//      }
//      else
//      {
//
//         if (str.is_empty())
//         {
//
//            output_debug_string("WHAT?!?!(2)");
//
//         }
//         else if (str.begins("\n"))
//         {
//
//            output_debug_string("WHAT?!?!");
//
//         }
//
//         str = strTime + str;
//
//      }
//
//   }

      auto pplatform = ::platform::get();

      if ((pplatform && pplatform->is_console())) {

         if (tracestatement.m_pparticleLogging) {

            if (tracestatement.m_pparticleLogging->has_flag(e_flag_no_stdout)) {

               return;

            }

         }

         if (tracestatement.m_etracelevel <= e_trace_level_information) {

            fwrite(str.c_str(), 1, str.size(), stdout);

            if (bFlush) {

               fflush(stdout);

            }

         } else {

            fprintf(stderr, "%s", str.c_str());

            if (bFlush) {

               fflush(stderr);

            }

         }

      } else {

         auto iOsLevel = os_trace_level(tracestatement.m_etracelevel);

         __android_log_print(iOsLevel, tracestatement.prefix(), "%s", str.c_str());

      }

   }


} // namespace acme_android



