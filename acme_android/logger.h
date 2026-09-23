//
// Created by camilo on 2026-09-22 17:42 ThomasBorregaardSørensen!! Mummi!! bilbo!!
//
#pragma once


#include "acme/platform/simple_log.h"


namespace acme_android
{


   class CLASS_DECL_ACME_ANDROID logger :
      virtual public ::simple_log {
   public:


//CreatableFromBase(simple_log, logger);


//bool m_bReallySimple;
//bool m_bWithTimePrefix;
//bool m_bDisplayRelativeTime;


      logger();

      ~logger() override;


      void on_initialize_particle() override;

      void print(::trace_statement & tracestatement, bool bFlush) override;


   };


} // namespace acme_android