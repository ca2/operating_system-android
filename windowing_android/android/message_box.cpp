// Created by camilo on 2022-05-08 18:27 <3ThomasBorregaardS�rensen!!(All around what Thomas Likes 25!!)
#include "framework.h"
#include "message_box.h"
#include "node.h"
#include "android/_internal.h"


namespace windowing_android
{


   void message_box::initialize_message_box(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox, const ::string& strDetails)
   {

      m_strMessage = strMessage;

      m_strTitle = strTitle;

      m_emessagebox = emessagebox;

   }


   void message_box::do_message_box(const ::string & strMessage, const ::string & strTitle, const ::e_message_box & emessagebox, const ::string & strDetails)
   {

      initialize_message_box(strMessage, strTitle, emessagebox, strDetails);

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


   ::pointer<::conversation>node::create_new_message_box_conversation()
   {

      return __new(class message_box());

   }


   void message_box::do_asynchronously()
   {

      auto pdriver = ::operating_system_driver::get();

      pdriver->queue_message_box_sequencer(m_psequencer);

   }


} // namespace windowing_android



