// Created by camilo on 2022-05-08 18:27 <3ThomasBorregaardSørensen!!(All around what Thomas Likes 25!!)
#include "framework.h"
#include "message_box.h"


namespace windowing_android
{


   void message_box::do_message_box(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox, const ::string& strDetails)
   {

      auto pdriver = ::operating_system_driver::get();

      m_strMessage = strMessage;

      m_strTitle = strTitle;

      m_emessagebox = emessagebox;

      pdriver->add_message_box_sequence(m_psequence);

   }


   ::string message_box::get_message_box_message()
   {

      return m_strMessage;

   }


   ::string message_box::get_message_box_title()
   {

      return m_strTitle;
      
   }


   ::e_message_box message_box::get_message_box_flags()
   {

      return m_emessagebox;

   }


   __pointer(::conversation) node::create_new_message_box_conversation()
   {

      return __new(class message_box());

   }



} // namespace windowing_android



