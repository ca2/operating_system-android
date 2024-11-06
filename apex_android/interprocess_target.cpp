// From interprocess_communication.cpp by camilo on 2022-10-17 14:35 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "interprocess_target.h"


namespace apex_android
{


   interprocess_target::interprocess_target()
   {

      //m_preceiver    = nullptr;

   }


   interprocess_target::~interprocess_target()
   {

   }


   void interprocess_target::create(const ::string & strChannel)
   {
      /*
      m_key = ftok(".", 'c');

      if(m_key == 0)
      return false;

      if((m_iQueue = msgget(m_key, IPC_CREAT | IPC_EXCL | 0660 )) == -1)
      {
      return false;
      }
      */
      //m_strBaseChannel = strChannel;

      //return true;
   }


   void interprocess_target::destroy()
   {

      //int iRetry = 23;
      //while(m_bRunning && iRetry > 0)
      //{
      //   m_bRun = false;
      //   sleep(1_ms);
      //   iRetry--;
      //}

      //if(m_iQueue < 0)
      //   return true;
      ///*
      //if(msgctl( m_iQueue, IPC_RMID, 0) == -1)
      //{
      //return false;
      //}
      //*/
      //m_iQueue = -1;

      //return true;

   }

   
   //bool interprocess_target::start_receiving()
   //{

   //   //m_bRunning = true;

   //   //m_bRun = true;

   //   //m_pthread = get_app()->fork([&]()
   //   //{


   //   //   receive();


   //   //});

   //   return true;

   //}

   //void * rx::receive_proc(void * param)
   //{

   //   rx * pchannel = (rx *)param;

   //   return pchannel->receive();

   //}



   // void rx::receiver::on_ipc_receive(rx * prx,const char * pszMessage)
   // {
   // }

   // void rx::receiver::on_ipc_receive(rx * prx,int message,void * pdata,memsize len)
   // {
   // }

   // void rx::receiver::on_ipc_post(rx * prx,huge_integer a,huge_integer b)
   // {
   // }



   //void * interprocess_target::on_interprocess_receive(rx * prx,const char * pszMessage)
   //{

   //   if(m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_receive(prx,pszMessage);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}

   //void * interprocess_target::on_interprocess_receive(rx * prx,int message,void * pdata,memsize len)
   //{

   //   if(m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_receive(prx,message,pdata,len);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}



   //void * interprocess_target::on_interprocess_post(rx * prx,huge_integer a,huge_integer b)
   //{

   //   if(m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_post(prx,a,b);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}


   bool interprocess_target::on_idle()
   {

      return false;

   }


   bool interprocess_target::is_target_ok()
   {

      return true;

   }


} // namespace apex_android



