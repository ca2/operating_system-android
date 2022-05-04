#include "framework.h"
#include <sys/utsname.h>

//__FACTORY_IMPORT void windowing_android_factory(::factory::factory* pfactory);
__FACTORY_IMPORT void aura_android_factory(::factory::factory* pfactory);

__FACTORY_EXPORT void node_android_factory(::factory::factory * pfactory)
{

   aura_android_factory(pfactory);

   //auto edesktop = ::acme::linux::node::_get_edesktop();

   //if (edesktop & ::user::e_desktop_kde)
   //{

   //   auto & pfactoryKde = pfactory->m_psystem->factory("desktop_environment", "kde");

   //   if(!pfactoryKde)
   //   {

   //      throw resource_exception();

   //   }

   //   pfactoryKde->merge_to_global_factory();

   //}
   //else if ((edesktop & ::user::e_desktop_gnome) || (edesktop & ::user::e_desktop_lxde))
   //{

   //   auto & pfactoryGnome = pfactory->m_psystem->factory("desktop_environment", "gnome");

   //   if(!pfactoryGnome)
   //   {

   //      throw resource_exception();

   //   }

   //   pfactoryGnome->merge_to_global_factory();

   //}
   //else if (edesktop & ::user::e_desktop_xfce)
   //{

   //   auto & pfactoryXfce = pfactory->m_psystem->factory("desktop_environment", "xfce");

   //   if(!pfactoryXfce)
   //   {

   //      throw resource_exception();

   //   }

   //   pfactoryXfce->merge_to_global_factory();

   //}
   //else
   //{

   //   auto & pfactoryGnome = pfactory->m_psystem->factory("desktop_environment", "gnome");

   //   if (!pfactoryGnome)
   //   {

   //      auto & pfactoryKde = pfactory->m_psystem->factory("desktop_environment", "kde");

   //      if(!pfactoryKde)
   //      {

   //         throw resource_exception();

   //      }

   //      pfactoryKde->merge_to_global_factory();

   //   }
   //   else
   //   {

   //      pfactoryGnome->merge_to_global_factory();

   //   }

   //}
//
//#else
//
//      estatus = factory("aura", "windows");
//
//#endif


//      apexandroid_factory( pfactory);
//
//   aura_posix_factory( pfactory);
//
//   pfactory->add_factory_item < ::aura::linux::node, ::acme::node >();

}





