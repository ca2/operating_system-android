#include "framework.h"
#include "button.h"
#include "dialog.h"
#include "icon.h"
#include "innate_ui.h"
#include "still.h"
#include "window.h"
//#include "text_composition_client.h"
//#include "node.h"
//#include "aura/windowing/desktop_environment.h"


//__FACTORY_IMPORT void aura_android_factory(::factory::factory* pfactory);
//

__FACTORY_EXPORT void innate_ui_android_factory(::factory::factory * pfactory)
{

   //aura_android_factory(pfactory);

   pfactory->add_factory_item < ::innate_ui_android::button, ::innate_ui::button > ();
   pfactory->add_factory_item < ::innate_ui_android::dialog, ::innate_ui::dialog >();
   pfactory->add_factory_item < ::innate_ui_android::icon, ::innate_ui::icon > ();
   pfactory->add_factory_item < ::innate_ui_android::still, ::innate_ui::still > ();
   pfactory->add_factory_item < ::innate_ui_android::window, ::innate_ui::window > ();

   pfactory->add_factory_item < ::innate_ui_android::innate_ui, ::innate_ui::window > ();

   //pfactory->add_factory_item < ::windowing_android::icon, ::windowing::icon > ();
   //pfactory->add_factory_item < ::windowing_android::cursor, ::windowing::cursor > ();
   //pfactory->add_factory_item < ::windowing_android::keyboard, ::windowing::keyboard > ();
   //pfactory->add_factory_item < ::windowing_android::node, ::platform::node >();

//   pfactory->add_factory_item < ::windowing::desktop_environment >();

}



