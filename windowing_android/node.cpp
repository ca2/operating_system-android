// Created by camilo on 2022-05-04 00:00 <3ThomasBorregaardSorensen(ThomasLikesNumber5)
#include "framework.h"
#include "operating_system/_operating_system.h"


namespace windowing_android
{


   node::node()
   {


   }


   node::~node()
   {


   }


   void node::report_exception_to_user(::object* pobject, ::exception& exception, const ::string& strMoreDetails)
   {

      if (m_psystem->m_bIsReadyForUserInteraction)
      {

         ::aura_android::node::report_exception_to_user(pobject, exception, strMoreDetails);

      }
      else
      {

         operating_system_log_exception(pobject, exception, strMoreDetails);

      }

   }


} // namespace windowing_android



