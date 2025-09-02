//
//  host_interaction.cpp
//  aura
//
//  Copied from node/ios by Camilo Sasuke Thomas Borregaard Soerensen on 20/06/05.
//  (with refactorization: ui_interaction -> host_interaction to
//  match OPERATING_SYSTEM_NAMESPACE::create_*host*_window() naming.)
//
#include "framework.h"
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



   void host_interaction::_001DrawThis(::draw2d::graphics_pointer & pgraphics)
   {

      //return ::user::interaction::_001DrawThis(pgraphics);
      
      //pgraphics->fill_solid_rect_dim(10, 10, 100, 100, argb(255, 0, 0, 255));
      

   }


   void host_interaction::_001DrawChildren(::draw2d::graphics_pointer & pgraphics)
   {

//      pgraphics->fill_solid_rect_dim(10, 110, 100, 100, argb(255, 100, 155, 255));
//
//      pgraphics->fill_solid_rect_dim(10, 210, 100, 100, argb(255, 200, 225, 255));

      ::user::interaction::_001DrawChildren(pgraphics);
      

   }


   void host_interaction::_000OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::interaction::_000OnDraw(pgraphics);

   }


   void host_interaction::_001OnNcDraw(::draw2d::graphics_pointer & pgraphics)
   {

   }


   void host_interaction::_001OnDraw(::draw2d::graphics_pointer & pgraphics)
   {

      ::user::interaction::_001OnDraw(pgraphics);

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


