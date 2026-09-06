//
//  host_interaction.cpp
//  aura
//
//  Copied from node/ios by Camilo Sasuke Thomas Borregaard Soerensen on 20/06/05.
//  (with refactorization: ui_interaction -> host_interaction to
//  match OPERATING_SYSTEM_NAMESPACE::create_*host*_window() naming.)
//
#include "platform.h"
#include "host_interaction.h"




namespace android
{

   namespace acme
   {

      namespace windowing
      {


   host_interaction::host_interaction()
   {

      

   }


   host_interaction::~host_interaction()
   {


   }

//
//   void host_interaction::_001DrawThis(::draw2d::graphics_pointer & pdraw2dgraphics)
//   {
//
//      //return ::user::interaction::_001DrawThis(pdraw2dgraphics);
//
//      //pdraw2dgraphics->fill_solid_rect_dim(10, 10, 100, 100, argb(255, 0, 0, 255));
//
//
//   }
//
//
//   void host_interaction::_001DrawChildren(::draw2d::graphics_pointer & pdraw2dgraphics)
//   {
//
////      pdraw2dgraphics->fill_solid_rect_dim(10, 110, 100, 100, argb(255, 100, 155, 255));
////
////      pdraw2dgraphics->fill_solid_rect_dim(10, 210, 100, 100, argb(255, 200, 225, 255));
//
//      ::user::interaction::_001DrawChildren(pdraw2dgraphics);
//
//
//   }
//
//
//   void host_interaction::_000OnDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
//   {
//
//      ::user::interaction::_000OnDraw(pdraw2dgraphics);
////
////   }
////
////
////   void host_interaction::_001OnNcDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
////   {
////
////   }
////
////
////   void host_interaction::_001OnDraw(::draw2d::graphics_pointer & pdraw2dgraphics)
////   {
////
////      ::user::interaction::_001OnDraw(pdraw2dgraphics);
////
////   }
//

//   bool host_interaction::is_this_visible()
//   {
//
//      return true;
//
//   }


//   ::user::interaction * create_host_window()
//   {
//
//      return memory_new host_interaction();
//
//   }



      } // namespace windowing


   } // namespace acme


} // namespace android





