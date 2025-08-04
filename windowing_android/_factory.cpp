#include "framework.h"
#include "buffer.h"
#include "monitor.h"
#include "display.h"
#include "window.h"
#include "windowing.h"
#include "text_composition_client.h"
//#include "node.h"
#include "aura/windowing/desktop_environment.h"
#include "host_interaction.h"


__FACTORY_IMPORT void aura_android_factory(::factory::factory* pfactory);


__FACTORY_EXPORT void windowing_android_factory(::factory::factory * pfactory)
{


   aura_android_factory(pfactory);

   pfactory->add_factory_item < ::windowing_android::buffer, ::graphics::graphics > ();

   pfactory->add_factory_item < ::windowing_android::monitor, ::windowing::monitor >();

   pfactory->add_factory_item < ::windowing_android::display, ::windowing::display > ();
   pfactory->add_factory_item < ::windowing_android::window, ::acme::windowing::window > ();
   pfactory->add_factory_item < ::windowing_android::windowing, ::acme::windowing::windowing > ();
   pfactory->add_factory_item < ::windowing_android::text_composition_client, ::user::text_composition_client > ();
   pfactory->add_factory_item < ::windowing_android::host_interaction, ::acme::sandbox_windowing::host_interaction >();

   //pfactory->add_factory_item < ::windowing_android::icon, ::windowing::icon > ();
   //pfactory->add_factory_item < ::windowing_android::cursor, ::windowing::cursor > ();
   //pfactory->add_factory_item < ::windowing_android::keyboard, ::windowing::keyboard > ();
   //pfactory->add_factory_item < ::windowing_android::node, ::platform::node >();

   pfactory->add_factory_item < ::windowing::desktop_environment >();

}



