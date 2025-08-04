#include "framework.h"
#include "jni_object_impl.h"


extern thread_local JNIEnv* t_pjnienv1;


jni_object_impl::jni_object_impl()
{

   m_jobject = nullptr;

   m_jclass = nullptr;

}



jni_object_impl::jni_object_impl(jobject jobject)
{

   set_jni_object(jobject);

}


jni_object_impl::~jni_object_impl()
{

   t_pjnienv1->DeleteGlobalRef(m_jobject);

   t_pjnienv1->DeleteGlobalRef(m_jclass);

}


void jni_object_impl::set_jni_object(jobject jobject)
{

   ::jclass jclass = t_pjnienv1->GetObjectClass(jobject);

   m_jclass = (::jclass) t_pjnienv1->NewGlobalRef(jclass);

   m_jobject = t_pjnienv1->NewGlobalRef(jobject);

}


jni_field * jni_object_impl::_field(const_char_pointer psz, const_char_pointer pszType)
{

   auto & pfield = m_mapField[psz];

   if(pfield)
   {

      return pfield;

   }

   auto pfieldImpl = __allocate jni_field_impl();

   pfieldImpl->m_jfieldid = t_pjnienv1->GetFieldID(m_jclass, psz, pszType);

   pfield = pfieldImpl;

   return pfield;

}


jni_field * jni_object_impl::field_str(const_char_pointer psz)
{

   return _field(psz, "Ljava/lang/String;");

}


jni_field * jni_object_impl::field_b(const_char_pointer psz)
{

   return _field(psz, "Z");

}


jni_field * jni_object_impl::field_uch(const_char_pointer psz)
{

   return _field(psz, "B");

}


jni_field * jni_object_impl::field_ch(const_char_pointer psz)
{

   return _field(psz, "C");

}


jni_field * jni_object_impl::field_sh(const_char_pointer psz)
{

   return _field(psz, "S");

}


jni_field * jni_object_impl::field_i(const_char_pointer psz)
{

   return _field(psz, "I");

}


jni_field * jni_object_impl::field_l(const_char_pointer psz)
{

   return _field(psz, "J");

}



jni_field * jni_object_impl::field_f(const_char_pointer psz)
{

   return _field(psz, "F");

}


jni_field * jni_object_impl::field_d(const_char_pointer psz)
{

   return _field(psz, "D");

}


//void jni_object_impl::set_str(const_char_pointer pszField, const_char_pointer psz)
//{
//
//   set_str(field_str(pszField), psz);
//
//}
//
//
//string jni_object_impl::get_str(const_char_pointer pszField)
//{
//
//   return get_str(field_str(pszField));
//
//}
//
//
//void jni_object_impl::set_b(const_char_pointer pszField, bool b)
//{
//
//   set_b(field_b(pszField), b);
//
//}
//
//
//bool jni_object_impl::get_b(const_char_pointer pszField)
//{
//
//   return get_b(field_b(pszField));
//
//}
//
//
//
//void jni_object_impl::set_uch(const_char_pointer pszField, unsigned char b)
//{
//
//   set_uch(field_uch(pszField), b);
//
//}
//
//
//unsigned char jni_object_impl::get_uch(const_char_pointer pszField)
//{
//
//   return get_uch(field_uch(pszField));
//
//}
//
//
//
//void jni_object_impl::set_ch(const_char_pointer pszField, char ch)
//{
//
//   set_ch(field_ch(pszField), ch);
//
//}
//
//
//char jni_object_impl::get_ch(const_char_pointer pszField)
//{
//
//   return get_ch(field_ch(pszField));
//
//}
//
//
//
//void jni_object_impl::set_sh(const_char_pointer pszField, short sh)
//{
//
//   set_sh(field_sh(pszField), sh);
//
//}
//
//
//short jni_object_impl::get_sh(const_char_pointer pszField)
//{
//
//   return get_sh(field_sh(pszField));
//
//}
//
//
//
//void jni_object_impl::set_i(const_char_pointer pszField, int i)
//{
//
//   set_i(field_i(pszField), i);
//
//}
//
//
//
//int jni_object_impl::get_i(const_char_pointer pszField)
//{
//
//   return get_i(field_i(pszField));
//
//}
//
//
//
//void jni_object_impl::set_l(const_char_pointer pszField, long long hi)
//{
//
//   set_l(field_l(pszField), hi);
//
//}
//
//
//
//long long jni_object_impl::get_l(const_char_pointer pszField)
//{
//
//   return get_l(field_l(pszField));
//
//}
//
//
//void jni_object_impl::set_f(const_char_pointer pszField, float f)
//{
//
//   set_f(field_f(pszField), f);
//
//}
//
//
//float jni_object_impl::get_f(const_char_pointer pszField)
//{
//
//   return get_f(field_f(pszField));
//
//}
//
//
//void jni_object_impl::set_d(const_char_pointer pszField, double d)
//{
//
//   set_d(field_d(pszField), d);
//
//}
//
//
//double jni_object_impl::get_d(const_char_pointer pszField)
//{
//
//   return get_d(field_d(pszField));
//
//}
//

void jni_object_impl::set_str(jni_field * pfield, const_char_pointer psz)
{

   jstring jstring = t_pjnienv1->NewStringUTF(psz);

   if (!jstring)
   {

      return;

   }
   
   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetObjectField(m_jobject, pfieldImpl->m_jfieldid, jstring);

   t_pjnienv1->DeleteLocalRef(jstring);

}


string jni_object_impl::get_str(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   jstring jstring = (::jstring) t_pjnienv1->GetObjectField(m_jobject, pfieldImpl->m_jfieldid);

   string str;
   
   if (jstring)
   {

      str = ::as_string(jstring);

      t_pjnienv1->DeleteLocalRef(jstring);

   }

   return str;

}


void jni_object_impl::set_b(jni_field * pfield, bool b)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetBooleanField(m_jobject, pfieldImpl->m_jfieldid, b);

}


bool jni_object_impl::get_b(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetBooleanField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_uch(jni_field * pfield, unsigned char b)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetByteField(m_jobject, pfieldImpl->m_jfieldid, b);

}


unsigned char jni_object_impl::get_uch(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetByteField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_ch(jni_field * pfield, char ch)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetCharField(m_jobject, pfieldImpl->m_jfieldid, ch);

}


char jni_object_impl::get_ch(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetCharField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_sh(jni_field * pfield, short sh)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetShortField(m_jobject, pfieldImpl->m_jfieldid, sh);

}


short jni_object_impl::get_sh(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetShortField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_i(jni_field * pfield, int i)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetIntField(m_jobject, pfieldImpl->m_jfieldid, i);

}


int jni_object_impl::get_i(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetIntField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_l(jni_field * pfield, long long hi)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetLongField(m_jobject, pfieldImpl->m_jfieldid, hi);

}


long long jni_object_impl::get_l(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetLongField(m_jobject, pfieldImpl->m_jfieldid);

}


void jni_object_impl::set_f(jni_field * pfield, float f)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetFloatField(m_jobject, pfieldImpl->m_jfieldid, f);

}


float jni_object_impl::get_f(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetFloatField(m_jobject, pfieldImpl->m_jfieldid);

}



void jni_object_impl::set_d(jni_field * pfield, double d)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   t_pjnienv1->SetDoubleField(m_jobject, pfieldImpl->m_jfieldid, d);

}


double jni_object_impl::get_d(jni_field * pfield)
{

   ::cast < ::jni_field_impl > pfieldImpl = pfield;

   return t_pjnienv1->GetDoubleField(m_jobject, pfieldImpl->m_jfieldid);

}




