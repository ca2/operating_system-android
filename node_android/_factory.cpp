#include "framework.h"
#include "node.h"


__FACTORY_IMPORT void windowing_android_factory(::factory::factory* pfactory);


__FACTORY_EXPORT void node_android_factory(::factory::factory * pfactory)
{

   windowing_android_factory(pfactory);

   pfactory->add_factory_item < ::node_android::node, ::acme::node >();

}





