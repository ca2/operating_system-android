//
//  host_interaction.cpp
//  aura
//
//  Copied from node/ios by Camilo Sasuke Tsumanuma on 20/06/05.
//  (with refactorization: ui_interaction -> host_interaction to
//  match OPERATING_SYSTEM_NAMESPACE::create_*host*_window() naming.)
//
#include "framework.h"
#include "android/driver.h"


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

      ::user::interaction::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &host_interaction::on_message_create);

   }


   void host_interaction::_001DrawThis(::draw2d::graphics_pointer & pgraphics)
   {

      //return ::user::interaction::_001DrawThis(pgraphics);
      
      //pgraphics->fill_rectangle(::rectangle_f64_dimension(10, 10, 100, 100), argb(255, 0, 0, 255));
      

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


   void host_interaction::post_redraw(bool bAscendants)
   {

      ::user::interaction::post_redraw(bAscendants);
      //::operating_system_driver::get()->m_bRedraw = true;

   }

   //bool host_interaction::is_this_visible()
   //{

   //   return true;

   //}

   void host_interaction::on_message_create(::message::message* pmessage)
   {

      pmessage->previous();

      __pointer(::windowing_android::windowing) pwindowing = windowing();

      auto pwindow = window();

      pwindowing->m_pwindowApplicationHost = pwindow;

   }

   //::user::interaction * create_host_window()
   //{
   //   
   //   return new host_interaction();
   //   
   //}


   void host_interaction::on_layout(::draw2d::graphics_pointer& pgraphics)
   {

      ::rectangle_i32 r;

      get_client_rect(r);

      if (r.is_empty())
      {

         return;

      }

      __pointer(::user::interaction) pinteraction;
      
      get_child(pinteraction);

      if (::is_null(pinteraction))
      {

         return;

      }

      pinteraction->place(r);

      pinteraction->set_need_layout();

      pinteraction->set_need_redraw();

      pinteraction->post_redraw();

   }


} // namespace windowing_android



