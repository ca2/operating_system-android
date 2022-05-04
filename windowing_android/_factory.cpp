#include "framework.h"
//#include "text_composition_client.h"




__FACTORY_EXPORT void windowing_android_factory(::factory::factory * pfactory)
{

   //pfactory->add_factory_item < ::windowing_android::buffer, ::graphics::graphics > ();

   //pfactory->add_factory_item < ::windowing_android::display, ::windowing::display > ();
   pfactory->add_factory_item < ::windowing_android::window, ::windowing::window > ();
   pfactory->add_factory_item < ::windowing_android::windowing, ::windowing::windowing > ();
   //pfactory->add_factory_item < ::windowing_android::text_composition_client, ::user::text_composition_client > ();

   //pfactory->add_factory_item < ::windowing_android::icon, ::windowing::icon > ();
   //pfactory->add_factory_item < ::windowing_android::cursor, ::windowing::cursor > ();
   //pfactory->add_factory_item < ::windowing_android::keyboard, ::windowing::keyboard > ();
   pfactory->add_factory_item < ::windowing_android::node, ::acme::node >();

}



