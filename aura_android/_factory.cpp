#include "framework.h"


__FACTORY_EXPORT void apex_android_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_android_factory(::factory::factory * pfactory)
{


   apex_android_factory( pfactory);


   aura_posix_factory( pfactory);


   pfactory->add_factory_item < ::aura_android::interaction_impl, ::user::interaction_impl >();


}



