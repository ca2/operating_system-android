// From interprocess_communication.cpp by camilo on 2022-10-17 14:35 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "interprocess_caller.h"
#include "acme/platform/system.h"


namespace apex_android
{


   interprocess_caller::interprocess_caller()
   {


   }


   interprocess_caller::~interprocess_caller()
   {


   }


   void interprocess_caller::open(const::string & pszChannel, ::launcher * plauncher)
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


   void interprocess_caller::close()
   {

      //if(m_iQueue < 0)
        // return true;

      //m_iQueue = -1;

      m_strBaseChannel = "";

      //return true;

   }


   void interprocess_caller::call(const ::string & strUri, const class time & timeTimeout)
   {

      //data_struct data;
      //data.mtype        = 20170101;
      //data.request      = 0;
      //data.size_i32         = ansi_length(pszMessage);
      //if(data.size_i32 > 512)
      //   return false;


      //acmesystem()->open_link(m_strBaseChannel + "://" + strUri, "", "");

      acmesystem()->open_link(strUri, "", "");


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


   //void interprocess_caller::send(i32 message,void * pdata,i32 len, const class time & timeTimeout)
   //{

   //   if (message == (i32)0x80000000)
   //   {

   //      throw ::exception(error_bad_argument);

   //   }


   //   if (!is_tx_ok())
   //   {
   //    
   //      throw ::exception(error_wrong_state);

   //   }


   //   acmesystem()->open_link(m_strBaseChannel + "://" + message, "", "");

   //   //const char * pszMessage = (const char *)pdata;

   //   //::count c = len;

   //   //::count cSend;

   //   //data_struct data;
   //   //data.mtype        = 20170101;
   //   //data.request      = 0x80000000;
   //   //data.size_i32         = (i32)ansi_length(pszMessage);

   //   //::count cPos = 0;

   //   //while(c > 0)
   //   //{

   //   //   cSend = minimum(c,511);

   //   //   ::memory_copy(data.data,&pszMessage[cPos],minimum(c,511));

   //   //   c -= cSend;

   //   //   cPos += cSend;

   //   //   if(c > 0)
   //   //      data.size = 512;
   //   //   else
   //   //      data.size = (i32)cSend;

   //   //   /* The length is essentially the size_i32 of the structure minus sizeof(mtype) */
   //   //   i32 length = sizeof(data_struct) - sizeof(long);

   //   //   i32 result;
   //   //   /*
   //   //   if((result = msgsnd(m_iQueue, &data, length, 0)) == -1)
   //   //   {
   //   //   return false;
   //   //   }
   //   //   */
   //   //}

   //   //return true;

   //}


   bool interprocess_caller::is_caller_ok()
   {

      //return m_iQueue != -1;

      return true;

   }



} // namespace apex_android



