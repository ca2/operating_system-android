#include "framework.h"
#include "interprocess_communication.h"


namespace apex_android
{


   interprocess_communication_base::interprocess_communication_base()
   {
      

   }


   interprocess_communication_base::~interprocess_communication_base()
   {


   }


   interprocess_communication_tx::interprocess_communication_tx()
   {


   }


   interprocess_communication_tx::~interprocess_communication_tx()
   {


   }


   void interprocess_communication_tx::open(const::string & pszChannel, ::launcher * plauncher)
   {

      //if(m_iQueue >= 0)
         //close();

      /*   m_key = ftok(".", 'c');

         if(m_key == 0)
         return false;

         if((m_iQueue = msgget(m_key, 0660)) == -1)
         {
         return false;
         }*/

         m_strBaseChannel = pszChannel;

      //return true;

   }


   void interprocess_communication_tx::close()
   {

      //if(m_iQueue < 0)
        // return true;

      //m_iQueue = -1;

      m_strBaseChannel = "";

      //return true;

   }


   void interprocess_communication_tx::send(const ::string & strMessage, const duration & durationTimeout)
   {

      //data_struct data;
      //data.mtype        = 20170101;
      //data.request      = 0;
      //data.size_i32         = ansi_length(pszMessage);
      //if(data.size_i32 > 512)
      //   return false;

      ///* The length is essentially the size_i32 of the structure minus sizeof(mtype) */
      //i32 length = sizeof(data_struct) - sizeof(long);

      //i32 result;
      /*
         if((result = msgsnd(m_iQueue, &data, length, 0)) == -1)
         {
         return false;
         }
         */



      //return true;

   }


   void interprocess_communication_tx::send(i32 message,void * pdata,i32 len, const duration & durationTimeout)
   {

      if (message == (i32)0x80000000)
      {

         throw ::exception(error_bad_argument);

      }


      if (!is_tx_ok())
      {
       
         throw ::exception(error_wrong_state);

      }


      m_psystem->open_link(m_strBaseChannel + "://" + message, "", "");

      //const char * pszMessage = (const char *)pdata;

      //::count c = len;

      //::count cSend;

      //data_struct data;
      //data.mtype        = 20170101;
      //data.request      = 0x80000000;
      //data.size_i32         = (i32)ansi_length(pszMessage);

      //::count cPos = 0;

      //while(c > 0)
      //{

      //   cSend = minimum(c,511);

      //   ::memcpy_dup(data.data,&pszMessage[cPos],minimum(c,511));

      //   c -= cSend;

      //   cPos += cSend;

      //   if(c > 0)
      //      data.size = 512;
      //   else
      //      data.size = (i32)cSend;

      //   /* The length is essentially the size_i32 of the structure minus sizeof(mtype) */
      //   i32 length = sizeof(data_struct) - sizeof(long);

      //   i32 result;
      //   /*
      //   if((result = msgsnd(m_iQueue, &data, length, 0)) == -1)
      //   {
      //   return false;
      //   }
      //   */
      //}

      //return true;

   }


   bool interprocess_communication_tx::is_tx_ok()
   {

      //return m_iQueue != -1;

      return true;

   }


   interprocess_communication_rx::interprocess_communication_rx()
   {

      m_preceiver    = nullptr;

   }


   interprocess_communication_rx::~interprocess_communication_rx()
   {

   }


   void interprocess_communication_rx::create(const ::string & strChannel)
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


   void interprocess_communication_rx::destroy()
   {

      //i32 iRetry = 23;
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

   
   //bool interprocess_communication_rx::start_receiving()
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

   // void rx::receiver::on_ipc_receive(rx * prx,i32 message,void * pdata,memsize len)
   // {
   // }

   // void rx::receiver::on_ipc_post(rx * prx,i64 a,i64 b)
   // {
   // }



   //void * interprocess_communication_rx::on_interprocess_receive(rx * prx,const char * pszMessage)
   //{

   //   if(m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_receive(prx,pszMessage);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}

   //void * interprocess_communication_rx::on_interprocess_receive(rx * prx,i32 message,void * pdata,memsize len)
   //{

   //   if(m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_receive(prx,message,pdata,len);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}




   //void * interprocess_communication_rx::on_interprocess_post(rx * prx,i64 a,i64 b)
   //{

   //   if(m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_post(prx,a,b);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}



   bool interprocess_communication_rx::on_idle()
   {

      return false;

   }


   bool interprocess_communication_rx::is_rx_ok()
   {

      return true;

   }




} // namespace apex_android



