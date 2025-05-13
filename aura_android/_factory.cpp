#include "framework.h"
//#include "aaa_interaction_impl.h"


__FACTORY_EXPORT void apex_android_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_android_factory(::factory::factory * pfactory)
{


   apex_android_factory( pfactory);


   aura_posix_factory( pfactory);


   pfactory->add_factory_item < ::aura_android::node, ::platform::node >();


}



