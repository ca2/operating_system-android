#include "framework.h"
#include "_internal.h"


extern thread_local JNIEnv* t_pjnienv1;


jni_object::jni_object()
{

   m_jobject = nullptr;

   m_jclass = nullptr;

}



jni_object::jni_object(jobject jobject)
{

   set_jni_object(jobject);

}


jni_object::~jni_object()
{

   t_pjnienv1->DeleteGlobalRef(m_jobject);

   t_pjnienv1->DeleteGlobalRef(m_jclass);

}


void jni_object::set_jni_object(jobject jobject)
{

   ::jclass jclass = t_pjnienv1->GetObjectClass(jobject);

   m_jclass = (::jclass) t_pjnienv1->NewGlobalRef(jclass);

   m_jobject = t_pjnienv1->NewGlobalRef(jobject);

}


jfieldID jni_object::field_str(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "Ljava/lang/String;");

}


jfieldID jni_object::field_b(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "Z");

}


jfieldID jni_object::field_uch(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "B");

}


jfieldID jni_object::field_ch(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "C");

}


jfieldID jni_object::field_sh(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "S");

}


jfieldID jni_object::field_i(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "I");

}


jfieldID jni_object::field_l(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "J");

}



jfieldID jni_object::field_f(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "F");

}


jfieldID jni_object::field_d(const_char_pointer  psz)
{

   return t_pjnienv1->GetFieldID(m_jclass, psz, "D");

}


void jni_object::set_str(const_char_pointer  pszField, const_char_pointer  psz)
{

   set_str(field_str(pszField), psz);

}


string jni_object::get_str(const_char_pointer  pszField)
{

   return get_str(field_str(pszField));

}


void jni_object::set_b(const_char_pointer  pszField, bool b)
{

   set_b(field_b(pszField), b);

}


bool jni_object::get_b(const_char_pointer  pszField)
{

   return get_b(field_b(pszField));

}



void jni_object::set_uch(const_char_pointer  pszField, unsigned char b)
{

   set_uch(field_uch(pszField), b);

}


unsigned char jni_object::get_uch(const_char_pointer  pszField)
{

   return get_uch(field_uch(pszField));

}



void jni_object::set_ch(const_char_pointer  pszField, char ch)
{

   set_ch(field_ch(pszField), ch);

}


char jni_object::get_ch(const_char_pointer  pszField)
{

   return get_ch(field_ch(pszField));

}



void jni_object::set_sh(const_char_pointer  pszField, short sh)
{

   set_sh(field_sh(pszField), sh);

}


short jni_object::get_sh(const_char_pointer  pszField)
{

   return get_sh(field_sh(pszField));

}



void jni_object::set_i(const_char_pointer  pszField, int i)
{

   set_i(field_i(pszField), i);

}



int jni_object::get_i(const_char_pointer  pszField)
{

   return get_i(field_i(pszField));

}



void jni_object::set_l(const_char_pointer  pszField, long long hi)
{

   set_l(field_l(pszField), hi);

}



long long jni_object::get_l(const_char_pointer  pszField)
{

   return get_l(field_l(pszField));

}


void jni_object::set_f(const_char_pointer  pszField, float f)
{

   set_f(field_f(pszField), f);

}


float jni_object::get_f(const_char_pointer  pszField)
{

   return get_f(field_f(pszField));

}


void jni_object::set_d(const_char_pointer  pszField, double d)
{

   set_d(field_d(pszField), d);

}


double jni_object::get_d(const_char_pointer  pszField)
{

   return get_d(field_d(pszField));

}


void jni_object::set_str(jfieldID jfieldid, const_char_pointer  psz)
{

   jstring jstring = t_pjnienv1->NewStringUTF(psz);

   if (!jstring)
   {

      return;

   }

   t_pjnienv1->SetObjectField(m_jobject, jfieldid, jstring);

   t_pjnienv1->DeleteLocalRef(jstring);

}


string jni_object::get_str(jfieldID jfieldid)
{

   jstring jstring = (::jstring) t_pjnienv1->GetObjectField(m_jobject, jfieldid);

   string str;
   
   if (jstring)
   {

      str = ::as_string(jstring);

      t_pjnienv1->DeleteLocalRef(jstring);

   }

   return str;

}


void jni_object::set_b(jfieldID fid, bool b)
{

   t_pjnienv1->SetBooleanField(m_jobject, fid, b);

}


bool jni_object::get_b(jfieldID fid)
{

   return t_pjnienv1->GetBooleanField(m_jobject, fid);

}


void jni_object::set_uch(jfieldID fid, unsigned char b)
{

   t_pjnienv1->SetByteField(m_jobject, fid, b);

}


unsigned char jni_object::get_uch(jfieldID fid)
{

   return t_pjnienv1->GetByteField(m_jobject, fid);

}


void jni_object::set_ch(jfieldID fid, char ch)
{

   t_pjnienv1->SetCharField(m_jobject, fid, ch);

}


char jni_object::get_ch(jfieldID fid)
{

   return t_pjnienv1->GetCharField(m_jobject, fid);

}


void jni_object::set_sh(jfieldID fid, short sh)
{

   t_pjnienv1->SetShortField(m_jobject, fid, sh);

}


short jni_object::get_sh(jfieldID fid)
{

   return t_pjnienv1->GetShortField(m_jobject, fid);

}


void jni_object::set_i(jfieldID fid, int i)
{

   t_pjnienv1->SetIntField(m_jobject, fid, i);

}


int jni_object::get_i(jfieldID fid)
{

   return t_pjnienv1->GetIntField(m_jobject, fid);

}



void jni_object::set_l(jfieldID fid, long long hi)
{

   t_pjnienv1->SetLongField(m_jobject, fid, hi);

}


long long jni_object::get_l(jfieldID fid)
{

   return t_pjnienv1->GetLongField(m_jobject, fid);

}


void jni_object::set_f(jfieldID fid, float f)
{

   t_pjnienv1->SetFloatField(m_jobject, fid, f);

}


float jni_object::get_f(jfieldID fid)
{

   return t_pjnienv1->GetFloatField(m_jobject, fid);

}



void jni_object::set_d(jfieldID fid, double d)
{

   t_pjnienv1->SetDoubleField(m_jobject, fid, d);

}


double jni_object::get_d(jfieldID fid)
{

   return t_pjnienv1->GetDoubleField(m_jobject, fid);

}




