#include "framework.h"
#include "acme_directory.h"
#include "dir_context.h"
#include "dir_system.h"
#include "file_context.h"
#include "file_system.h"
//#include "file.h"

__FACTORY_EXPORT void acme_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_android_factory(::factory::factory * pfactory)
{


   acme_posix_factory(pfactory);


   //pfactory->add_factory_item < ::acme::android::node, ::acme::node >();
   pfactory->add_factory_item < ::acme_android::acme_directory, ::acme_directory >();
   //pfactory->add_factory_item < ::android::acme_file, ::acme_file >();
   //pfactory->add_factory_item < ::android::acme_path, ::acme_path >();

   //pfactory->add_factory_item < ::android::console, ::console::console >();
   //pfactory->add_factory_item < ::acme_android::file, ::file::file >();
   //pfactory->add_factory_item < ::android::stdio_file, ::file::file >();
   //pfactory->add_factory_item < ::android::stdio_file, ::file::text_file >();

   pfactory->add_factory_item < ::acme_android::dir_system, ::dir_system >();
   pfactory->add_factory_item < ::acme_android::file_system, ::file_system >();

   pfactory->add_factory_item < ::acme_android::dir_context, ::dir_context >();
   pfactory->add_factory_item < ::acme_android::file_context, ::file_context >();

}



