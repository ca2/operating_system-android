#include "framework.h"
#include "interprocess_base.h"
#include "interprocess_caller.h"
#include "interprocess_target.h"
#include "os_context.h"
#include "apex/platform/launcher.h"
//#include "operating_system-posix/apex_posix/file_context.h"
#include "apex/parallelization/service_handler.h"
#include "apex/platform/node.h"


//#include "acme/_operating_system.h"


__FACTORY_EXPORT void apex_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_android_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void apex_android_factory(::factory::factory * pfactory)
{


   apex_posix_factory(pfactory);

   acme_android_factory(pfactory);


   //create_factory < ::android::stdio_file, ::file::text_file >();
   //create_factory < ::android::file, ::file::file >();
   pfactory->add_factory_item < ::apex_android::os_context, ::os_context >();
   //pfactory->add_factory_item < ::android::pipe, ::process::pipe >();
   //pfactory->add_factory_item < ::android::process, ::process::process >();

   //create_factory < ::android::console, ::console::console >();
   //pfactory->add_factory_item < ::android::crypto, ::crypto::crypto >();
   //pfactory->add_factory_item < ::android::ip_enum, ::net::ip_enum >();


   pfactory->add_factory_item < ::apex_android::interprocess_base, ::interprocess::base >();
   pfactory->add_factory_item < ::apex_android::interprocess_caller, ::interprocess::caller >();
   pfactory->add_factory_item < ::apex_android::interprocess_target, ::interprocess::target >();
   //create_factory < ::android::inteprocess_channel, ::inteprocess_channel::inteprocess_channel >();


   //create_factory < ::android::buffer, ::graphics::graphics >();
   //create_factory < ::android::interaction_impl, ::windowing::window >();

   //pfactory->add_factory_item < ::file::os_watcher, ::file::watcher >();
   //pfactory->add_factory_item < ::file::os_watch, ::file::watch >();

   //pfactory->add_factory_item < ::apex_android::file_context, ::file_context >();
   //pfactory->add_factory_item < ::android::service_handler, ::service_handler >();

   //pfactory->add_factory_item < ::apex::android::node, ::acme::node >();

   //create_factory < ::android::copydesk, ::user::cop
   // 
   // 
   // ydesk >();
   ////create_factory < ::android::shell, ::user::shell >();


}




