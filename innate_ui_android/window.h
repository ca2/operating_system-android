// Created by camilo on 2024-09-12 22:34 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/innate_ui/window.h"


namespace innate_ui_android
{


   class innate_ui;


   class CLASS_DECL_INNATE_UI_ANDROID window :
      virtual public ::innate_ui::window
   {
   public:


      //QWidget * m_pqwidget;


      window();
      ~window() override;

//
//      void set_text(const ::scoped_string & scopedstr) override;
//
//      virtual void _create();
//      virtual void _create_child(window * pwindow);
//
//      void create() override;
//      void create_child(::innate_ui::window * pwindow) override;
//      void destroy_window() override;
//      void center() override;
//
//      void show() override;
//      void hide() override;
//
//      void set_position(const ::int_point & point) override;
//      void set_size(const ::int_size & size) override;
//      void adjust_for_client_size(const ::int_size & size) override;
//
//      ::innate_ui_kde6::innate_ui * innate_ui();
//
//
//      void defer_show_system_menu(::user::mouse * pmouse) override;
//

   };


} // namespace innate_ui_android



