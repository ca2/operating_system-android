#include "framework.h"
#include "directory_system.h"
#include "directory_context.h"
#include "directory_system.h"
#include "file_context.h"
#include "file_system.h"
//#include "file.h"

__FACTORY_EXPORT void acme_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_android_factory(::factory::factory * pfactory)
{


   acme_posix_factory(pfactory);


   //pfactory->add_factory_item < ::acme::android::node, ::platform::node >();
   pfactory->add_factory_item < ::acme_android::directory_system, ::directory_system >();
   //pfactory->add_factory_item < ::android::file_system, ::file_system >();
   //pfactory->add_factory_item < ::android::path_system, ::path_system >();

   //pfactory->add_factory_item < ::android::console, ::console::console >();
   //pfactory->add_factory_item < ::acme_android::file, ::file::file >();
   //pfactory->add_factory_item < ::android::stdio_file, ::file::file >();
   //pfactory->add_factory_item < ::android::stdio_file, ::file::text_file >();

   pfactory->add_factory_item < ::acme_android::directory_system, ::directory_system >();
   pfactory->add_factory_item < ::acme_android::file_system, ::file_system >();

   pfactory->add_factory_item < ::acme_android::directory_context, ::directory_context >();
   pfactory->add_factory_item < ::acme_android::file_context, ::file_context >();

}



