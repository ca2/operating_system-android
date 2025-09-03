//
// Created by camilo on 2025-09-02 18:05 <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include "jni_class.h"
#include "jni_object_impl.h"
#include "_internal.h"


jni_class::jni_class()
{


}


jni_class::~jni_class()
{


}


::pointer < jni_object_interface >jni_class::new_jni_object(
   jni_method * pmethodConstructor,
   ...)
{

   va_list args;

   va_start(args, pmethodConstructor);

   auto p = new_jni_object_args(pmethodConstructor, args);

   va_end(args);

   return p;

}


::pointer < jni_object_interface >jni_class::new_jni_object_args(
   jni_method * pmethodConstructor,
   va_list args)
{

   ::cast < jni_context_impl > pcontext = ::jni_context::get();
   ::cast < jni_method_impl > pmethodimpl = pmethodConstructor;

   auto jclass = (::jclass) p_jclass();
   auto jmethod =pmethodimpl->m_jmethodid;

   auto jobject = pcontext->m_pjnicontext->NewObjectV(
      jclass,
      jmethod,
      args);

   auto pjniobject = øjni_object(jobject);

   return ::transfer(pjniobject);

}


void * jni_class::p_jclass()
{

   return m_pjniclassImpl->p_jclass();

}


jni_field * jni_class::_field(const_char_pointer psz, const_char_pointer pszType)
{

   auto & pfield = m_mapField[psz];

   if(pfield)
   {

      return pfield;

   }

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   auto pfieldImpl = øallocate jni_field_impl();

   ::cast < ::jni_class_impl > pimpl = m_pjniclassImpl;

   pfieldImpl->m_jfieldid = pcontext->GetFieldID(pimpl->m_jclass, psz, pszType);

   pfield = pfieldImpl;

   return pfield;

}


jni_field * jni_class::field_str(const_char_pointer psz)
{

   return _field(psz, "Ljava/lang/String;");

}


jni_field * jni_class::field_b(const_char_pointer psz)
{

   return _field(psz, "Z");

}


jni_field * jni_class::field_uch(const_char_pointer psz)
{

   return _field(psz, "B");

}


jni_field * jni_class::field_ch(const_char_pointer psz)
{

   return _field(psz, "C");

}


jni_field * jni_class::field_sh(const_char_pointer psz)
{

   return _field(psz, "S");

}


jni_field * jni_class::field_i(const_char_pointer psz)
{

   return _field(psz, "I");

}


jni_field * jni_class::field_l(const_char_pointer psz)
{

   return _field(psz, "J");

}



jni_field * jni_class::field_f(const_char_pointer psz)
{

   return _field(psz, "F");

}


jni_field * jni_class::field_d(const_char_pointer psz)
{

   return _field(psz, "D");

}



jni_field * jni_class::field_ba(const_char_pointer psz)
{

   return _field(psz, "[B");

}

//jni_method * jni_class::method(::enum_jni_call ejnicall, const_char_pointer pszName, const_char_pointer pszSignature)
//{
//
//   return m_pjniobjectinterface->method(ecall, pszName, pszSignature);
//
//}


jni_method * jni_class::method(enum_jni_call ejnicall, const_char_pointer pszName,const_char_pointer pszSignature)
{

   ::string strKey;

   strKey = pszName;

   strKey += "::";

   strKey += pszSignature;

   auto & pmethod = m_mapMethod[strKey];

   if(pmethod)
   {

      return pmethod;

   }

   auto pmethodNew = øcreate_new<jni_method_impl>();

   ::cast < ::jni_context_impl > pjnicontext = ::jni_context::get();

   auto pcontext = pjnicontext->m_pjnicontext;

   ::cast < ::jni_class_impl > pimpl = m_pjniclassImpl;

   const_char_pointer pszName2;

   if(ejnicall == e_jni_call__init__)
   {

      pszName2 = "<init>";

   }
   else
   {

      pszName2 = pszName;


   }

   jmethodID jmethodid = pcontext->GetMethodID(
      pimpl->m_jclass,
      pszName2,
      pszSignature);

   pmethodNew->m_jmethodid = jmethodid;

   pmethodNew->m_ejnicall = ejnicall;

   pmethod = pmethodNew;

   return pmethod;

}

CLASS_DECL_ACME_WINDOWING_ANDROID void jni_get_class_impl(jni_class * pjniclassInterface, const_char_pointer pszClassName)
{

   ::cast < ::android::acme::application_sink > papplicationsink = ::platform::application_sink::get();

   papplicationsink->get_jni_class_impl(pjniclassInterface, pszClassName);

}



