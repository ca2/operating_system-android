// Created by camilo on 2022-05-08 18:26 <3ThomasBorregaardS�rensen!!(All around what Thomas Likes 25!!)
#pragma once


//#include "aura/user/micro/message_box.h"


namespace windowing_android
{


   class CLASS_DECL_AURA message_box :
      virtual public ::conversation
   {
   public:


      string                  m_strMessage;
      string                  m_strTitle;
      e_message_box           m_emessagebox;


      
      void do_message_box(const ::string& strMessage, const ::string& strTitle, const ::e_message_box& emessagebox) override;

      ::string get_message_box_message() override;
      ::string get_message_box_title() override;
      ::e_message_box get_message_box_flags() override;

   };


} // namespace windowing_android


