//
//  host_interaction.cpp
//  aura
//
//  Copied from node/ios by Camilo Sasuke Thomas Borregaard Soerensen on 20/06/05.
//  (with refactorization: ui_interaction -> host_interaction to
//  match OPERATING_SYSTEM_NAMESPACE::create_*host*_window() naming.)
//
#include "platform.h"
#include "display.h"
#include "host_interaction.h"
#include "windowing.h"
#include "acme_windowing_android/android/jni_bind.h"
#include "aura/windowing/monitor.h"


namespace windowing_android
{


   host_interaction::host_interaction()
   {

      

   }


   host_interaction::~host_interaction()
   {


   }


   void host_interaction::install_message_routing(::channel* pchannel)
   {

      ::sandbox_windowing::host_interaction::install_message_routing(pchannel);

      USER_MESSAGE_LINK(::user::e_message_create, pchannel, this, &host_interaction::on_message_create);

   }


   void host_interaction::on_message_create(::message::message* pmessage)
   {

      display(e_display_normal);

      pmessage->previous();

   }



   void host_interaction::_001DrawThis(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      //return ::user::interaction::_001DrawThis(pdraw2dgraphics);
      
      //pdraw2dgraphics->fill_solid_rect_dim(10, 10, 100, 100, argb(255, 0, 0, 255));
      

   }


   void host_interaction::_001DrawChildren(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      static int s_iTraceCount = 0;
      auto pchild = first_child();
      const bool bChildHidden = pchild && !pchild->is_this_visible();
      // Include later startup frames without flooding Logcat during a stall.
      const int iTrace = s_iTraceCount++;
      if (iTrace < 12 || ((!pchild || bChildHidden) && iTrace % 120 == 0))
      {
         information() << "Android host child draw: child=" << (::iptr)pchild
            << " visible=" << (pchild ? pchild->is_this_visible() : false)
            << " window=" << (pchild ? pchild->is_window() : false);
         if (pchild)
         {
            synchronous_lock lock(pchild->synchronization());
            information() << "Android host child layout: sketch=" << (int)pchild->const_layout().sketch().display()
               << " lading=" << (int)pchild->const_layout().lading().display()
               << " layout=" << (int)pchild->const_layout().layout().display()
               << " design=" << (int)pchild->const_layout().design().display()
               << " window=" << (int)pchild->const_layout().window().display()
               << " created=" << !!(pchild->m_ewindowflag & ::e_window_flag_window_created)
               << " not_visible=" << !!(pchild->m_ewindowflag & ::e_window_flag_not_visible)
               << " graphics_locked=" << (bool)pchild->m_bLockGraphicalUpdate
               << " layout_locked=" << (bool)pchild->m_bLockSketchToDesign
               << " sketch_size=" << pchild->const_layout().sketch().size().cx << "x" << pchild->const_layout().sketch().size().cy
               << " design_size=" << pchild->const_layout().design().size().cx << "x" << pchild->const_layout().design().size().cy;
         }
      }

//      pdraw2dgraphics->fill_solid_rect_dim(10, 110, 100, 100, argb(255, 100, 155, 255));
//
//      pdraw2dgraphics->fill_solid_rect_dim(10, 210, 100, 100, argb(255, 200, 225, 255));

      ::user::interaction::_001DrawChildren(pdraw2dgraphics);
      

   }


   void host_interaction::_000OnDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      ::user::interaction::_000OnDraw(pdraw2dgraphics);

   }


   void host_interaction::_001OnNcDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

   }


   void host_interaction::_001OnDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
   {

      ::user::interaction::_001OnDraw(pdraw2dgraphics);

   }


//   bool host_interaction::is_this_visible()
//   {
//
//      return true;
//
//   }

//
//   ::user::interaction * create_host_window()
//   {
//
//      return memory_new host_interaction();
//
//   }


} // namespace windowing_android

