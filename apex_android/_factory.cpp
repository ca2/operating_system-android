#include "framework.h"
#include "apex/operating_system.h"
//#include "apex/operating_system/android/_android.h"
//#include "file_os_watcher.h"
#include "apex/platform/launcher.h"
//#include "launcher.h"
#include "dir_system.h"
#include "dir_context.h"
#include "file_system.h"
#include "operating-system-posix/apex_posix/file_context.h"
#include "file_context.h"
//#include "process.h"
#include "os_context.h"
#include "apex/parallelization/service_handler.h"
//#include "service_handler.h"
//#include "crypto.h"
//#include "ip_enum.h"
//#include "interprocess_communication.h"
//#include "apex/operating_system/android/buffer.h"
//#include "apex/os/console.h"
//#include "console.h"
#include "apex/platform/node.h"
//#include "node.h"


__FACTORY_EXPORT void apex_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_android_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void apex_android_factory(::factory::factory * pfactory)
{


   apex_posix_factory(pfactory);

   acme_android_factory(pfactory);

   pfactory->add_factory_item < ::apex_android::dir_system, ::dir_system >();
   pfactory->add_factory_item < ::apex_android::file_system, ::file_system >();

   pfactory->add_factory_item < ::apex_android::dir_context, ::dir_context >();
   pfactory->add_factory_item < ::apex_android::file_context, ::file_context >();

   //create_factory < ::android::stdio_file, ::file::text_file >();
   //create_factory < ::android::file, ::file::file >();
   pfactory->add_factory_item < ::apex_android::os_context, ::os_context >();
   //pfactory->add_factory_item < ::android::pipe, ::process::pipe >();
   //pfactory->add_factory_item < ::android::process, ::process::process >();

   //create_factory < ::android::console, ::console::console >();
   //pfactory->add_factory_item < ::android::crypto, ::crypto::crypto >();
   //pfactory->add_factory_item < ::android::ip_enum, ::net::ip_enum >();


//   pfactory->add_factory_item < ::android::interprocess_communication_base, ::interprocess_communication::base >();
//   pfactory->add_factory_item < ::android::interprocess_communication_rx, ::interprocess_communication::rx >();
//   pfactory->add_factory_item < ::android::interprocess_communication_tx, ::interprocess_communication::tx >();
   //create_factory < ::android::interprocess_communication, ::interprocess_communication::interprocess_communication >();


   //create_factory < ::android::buffer, ::graphics::graphics >();
   //create_factory < ::android::interaction_impl, ::user::interaction_impl >();

   //pfactory->add_factory_item < ::file::os_watcher, ::file::watcher >();
   //pfactory->add_factory_item < ::file::os_watch, ::file::watch >();

   pfactory->add_factory_item < ::apex_android::file_context, ::file_context >();
   //pfactory->add_factory_item < ::android::service_handler, ::service_handler >();

   //pfactory->add_factory_item < ::apex::android::node, ::acme::node >();

   //create_factory < ::android::copydesk, ::user::cop
   // 
   // 
   // ydesk >();
   ////create_factory < ::android::shell, ::user::shell >();


}




