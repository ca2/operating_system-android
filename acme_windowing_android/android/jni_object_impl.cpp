// Created by camilo on 2025-07~08 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "jni_object_impl.h"
#include "jni_local.h"


jni_object_impl::jni_object_impl()
{

   m_jobject = nullptr;

   //m_jclass = nullptr;

}



jni_object_impl::jni_object_impl(jobject jobject)
{

   set_jni_object(jobject);

}


jni_object_impl::~jni_object_impl()
{

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   pcontext->DeleteGlobalRef(m_jobject);

   //pcontext->DeleteGlobalRef(m_jclass);

}


::jni_class  *jni_object_impl:: class_interface()
{

   return m_pjniclass;

}


void * jni_class_impl::p_jclass()
{
   return (void*) m_jclass;
}

void jni_object_impl::set_jni_object(jobject jobject)
{

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;
//
//   ::jclass jclass = pcontext->GetObjectClass(jobject);
//
//   ::string strClassName = ::jni_get_class_name(jclass);
//
//   m_pjniclass = ::jni_get_class(strClassName);

//   if(!m_pjniclass)
//   {
//
//      m_pjniclass = class_interface();
//
//   }

   m_jobject = pcontext->NewGlobalRef(jobject);

}
void jni_object_impl::set_class_interface(::jni_class * pjniclass)
{

   m_pjniclass = pjniclass;

}

//jni_field * jni_object_impl::_field(const_char_pointer psz, const_char_pointer pszType)
//{
//
//   auto & pfield = m_mapField[psz];
//
//   if(pfield)
//   {
//
//      return pfield;
//
//   }
//
//   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
//
//   auto pcontext = pjnicontext->m_pjnicontext;
//
//   auto pfieldImpl = øallocate jni_field_impl();
//
//   pfieldImpl->m_jfieldid = pcontext->GetFieldID(m_jclass, psz, pszType);
//
//   pfield = pfieldImpl;
//
//   return pfield;
//
//}
//
//
//jni_field * jni_object_impl::field_str(const_char_pointer psz)
//{
//
//   return _field(psz, "Ljava/lang/String;");
//
//}
//
//
//jni_field * jni_object_impl::field_b(const_char_pointer psz)
//{
//
//   return _field(psz, "Z");
//
//}
//
//
//jni_field * jni_object_impl::field_uch(const_char_pointer psz)
//{
//
//   return _field(psz, "B");
//
//}
//
//
//jni_field * jni_object_impl::field_ch(const_char_pointer psz)
//{
//
//   return _field(psz, "C");
//
//}
//
//
//jni_field * jni_object_impl::field_sh(const_char_pointer psz)
//{
//
//   return _field(psz, "S");
//
//}
//
//
//jni_field * jni_object_impl::field_i(const_char_pointer psz)
//{
//
//   return _field(psz, "I");
//
//}
//
//
//jni_field * jni_object_impl::field_l(const_char_pointer psz)
//{
//
//   return _field(psz, "J");
//
//}
//
//
//
//jni_field * jni_object_impl::field_f(const_char_pointer psz)
//{
//
//   return _field(psz, "F");
//
//}
//
//
//jni_field * jni_object_impl::field_d(const_char_pointer psz)
//{
//
//   return _field(psz, "D");
//
//}
//
//
//
//jni_field * jni_object_impl::field_ba(const_char_pointer psz)
//{
//
//   return _field(psz, "[B");
//
//}


::pointer < ::jni_object_interface >  jni_object_impl::call_args(::jni_method * pmethod, va_list args)
{

   ::cast < jni_context_impl > pcontextimpl = ::jni_context::get();

   ::cast < jni_method_impl > pjnimethod = pmethod;

   if(pmethod->m_ejnicall == ::e_jni_call_void_method)
   {

      pcontextimpl->m_pjnicontext->CallVoidMethodV(m_jobject,
                                                   pjnimethod->m_jmethodid,
                                                   args);

      return {};

   }
   else
   {

      throw ::exception(error_failed, "bad ecall");

   }

}


void * jni_object_impl::p_jobject()
{

   return m_jobject;

}

//jni_method * jni_object_impl::method(jni_method::enum_call ecall, const_char_pointer pszName,const_char_pointer pszSignature)
//{
//
//   ::string strKey;
//
//   strKey = pszName;
//
//   strKey += "::";
//
//   strKey += pszSignature;
//
//   auto & pmethod = m_mapMethod[strKey];
//
//   if(pmethod)
//   {
//
//      return pmethod;
//
//   }
//
//   auto pmethodNew = øcreate_new<jni_method_impl>();
//
//   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
//
//   auto pcontext = pjnicontext->m_pjnicontext;
//
//   jmethodID jmethodid = pcontext->GetMethodID(
//      m_jclass,
//      pszName,
//      pszSignature);
//
//   pmethodNew->m_jmethodid = jmethodid;
//
//   pmethodNew->m_ecall = ecall;
//
//   pmethod = pmethodNew;
//
//   return pmethod;
//
//}


void jni_object_impl::set_str(jni_field * pfield, const_char_pointer psz)
{

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   jni_local_string jnistring(psz);

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   pcontext->SetObjectField(m_jobject, pfieldImpl->m_jfieldid, jnistring.m_jstring);

}


string jni_object_impl::get_str(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   jni_local_string jnistring(pcontext->GetObjectField(m_jobject, pfieldImpl->m_jfieldid));

   auto str = jnistring.as_string();

   return str;

}


void jni_object_impl::set_b(jni_field * pfield, bool b)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   pcontext->SetBooleanField(m_jobject, pfieldImpl->m_jfieldid, b);

}


bool jni_object_impl::get_b(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   return pcontext->GetBooleanField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_uch(jni_field * pfield, unsigned char b)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   pcontext->SetByteField(m_jobject, pfieldImpl->m_jfieldid, b);

}


unsigned char jni_object_impl::get_uch(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   return pcontext->GetByteField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_ch(jni_field * pfield, char ch)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   pcontext->SetCharField(m_jobject, pfieldImpl->m_jfieldid, ch);

}


char jni_object_impl::get_ch(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   return pcontext->GetCharField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_sh(jni_field * pfield, short sh)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   pcontext->SetShortField(m_jobject, pfieldImpl->m_jfieldid, sh);

}


short jni_object_impl::get_sh(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   return pcontext->GetShortField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_i(jni_field * pfield, int i)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   pcontext->SetIntField(m_jobject, pfieldImpl->m_jfieldid, i);

}


int jni_object_impl::get_i(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   return pcontext->GetIntField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_l(jni_field * pfield, long long hi)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   pcontext->SetLongField(m_jobject, pfieldImpl->m_jfieldid, hi);

}


long long jni_object_impl::get_l(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   return pcontext->GetLongField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_f(jni_field * pfield, float f)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   pcontext->SetFloatField(m_jobject, pfieldImpl->m_jfieldid, f);

}


float jni_object_impl::get_f(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   return pcontext->GetFloatField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_d(jni_field * pfield, double d)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   pcontext->SetDoubleField(m_jobject, pfieldImpl->m_jfieldid, d);

}


double jni_object_impl::get_d(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   return pcontext->GetDoubleField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_ba(jni_field * pfield, const ::block & block)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   jni_local_byte_array ba(block);

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   pcontext->SetObjectField(m_jobject, pfieldImpl->m_jfieldid, ba.m_jobject);

}


::memory jni_object_impl::get_ba(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();
   
   auto pcontext = pjnicontext->m_pjnicontext;


   jni_local_byte_array jnibytea(pcontext->GetObjectField(m_jobject, pfieldImpl->m_jfieldid));

   auto memory = jnibytea.as_memory();

   return memory;

}


