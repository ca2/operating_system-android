//
//  ui_interaction.hpp
//  aura
//
//  Created by Camilo Sasuke Tsumanuma on 20/05/20.
//
#pragma once


namespace windowing_android
{


   class host_interaction :
      virtual public ::user::interaction
   {
   public:


      host_interaction();
      ~host_interaction() override;


      virtual void _001DrawThis(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001DrawChildren(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _000OnDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnNcDraw(::draw2d::graphics_pointer & pgraphics) override;
      virtual void _001OnDraw(::draw2d::graphics_pointer & pgraphics) override;



      void post_redraw(bool bAscendants = true) override;
      //virtual bool is_this_visible() override;


   };


} // namespace windowing_android




