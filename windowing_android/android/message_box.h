// Created by camilo on 2022-05-08 18:26 <3ThomasBorregaardSorensen!!(All around what Thomas Likes 25!!)
#pragma once


//#include "aura/user/micro/message_box.h"
#include "acme/user/user/message_box.h"


namespace windowing_android
{


   class CLASS_DECL_AURA message_box :
virtual public ::acme::user::message_box
   {
   public:


      //string                  m_strMessage;
      //string                  m_strTitle;
      //e_message_box           m_emessagebox;
      //string                  m_strDetails;


      //void initialize_conversation(const ::string & strMessage, const ::string & strTitle, const ::e_message_box & emessagebox, const ::string & strDetails) override;
      //void do_conversation(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox, const ::string& strDetails) override;


      //::string get_conversation_message() override;
      //::string get_conversation_title() override;
      //::e_message_box get_conversation_flags() override;


//      void do_asynchronously() override;

        void on_realize(::message_box * pmessagebox) override;


        void add_button(const ::scoped_string & scopedstrText, enum_dialog_result edialogresult, char chLetter) override;


        void run() override;


   };


} // namespace windowing_android



