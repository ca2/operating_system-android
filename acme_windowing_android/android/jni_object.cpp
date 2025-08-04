#include "framework.h"
#include "_internal.h"


jni_object::jni_object(jni_object_interface * pjniobjectinterface) :
m_pjniobjectinterface(pjniobjectinterface)
{


}


jni_object::~jni_object()
{

}



jni_field * jni_object::field_str(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_str(psz);

}


jni_field * jni_object::field_b(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_b(psz);

}


jni_field * jni_object::field_uch(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_uch(psz);

}


jni_field * jni_object::field_ch(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_ch(psz);

}


jni_field * jni_object::field_sh(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_sh(psz);

}


jni_field * jni_object::field_i(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_i(psz);

}


jni_field * jni_object::field_l(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_l(psz);

}



jni_field * jni_object::field_f(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_f(psz);

}


jni_field * jni_object::field_d(const_char_pointer psz)
{

   return m_pjniobjectinterface->field_d(psz);

}


//void jni_object::set_str(const_char_pointer pszField, const_char_pointer psz)
//{
//
//   set_str(field_str(pszField), psz);
//
//}
//
//
//string jni_object::get_str(const_char_pointer pszField)
//{
//
//   return get_str(field_str(pszField));
//
//}
//
//
//void jni_object::set_b(const_char_pointer pszField, bool b)
//{
//
//   set_b(field_b(pszField), b);
//
//}
//
//
//bool jni_object::get_b(const_char_pointer pszField)
//{
//
//   return get_b(field_b(pszField));
//
//}
//
//
//
//void jni_object::set_uch(const_char_pointer pszField, unsigned char b)
//{
//
//   set_uch(field_uch(pszField), b);
//
//}
//
//
//unsigned char jni_object::get_uch(const_char_pointer pszField)
//{
//
//   return get_uch(field_uch(pszField));
//
//}
//
//
//
//void jni_object::set_ch(const_char_pointer pszField, char ch)
//{
//
//   set_ch(field_ch(pszField), ch);
//
//}
//
//
//char jni_object::get_ch(const_char_pointer pszField)
//{
//
//   return get_ch(field_ch(pszField));
//
//}
//
//
//
//void jni_object::set_sh(const_char_pointer pszField, short sh)
//{
//
//   set_sh(field_sh(pszField), sh);
//
//}
//
//
//short jni_object::get_sh(const_char_pointer pszField)
//{
//
//   return get_sh(field_sh(pszField));
//
//}
//
//
//
//void jni_object::set_i(const_char_pointer pszField, int i)
//{
//
//   set_i(field_i(pszField), i);
//
//}
//
//
//
//int jni_object::get_i(const_char_pointer pszField)
//{
//
//   return get_i(field_i(pszField));
//
//}
//
//
//
//void jni_object::set_l(const_char_pointer pszField, long long hi)
//{
//
//   set_l(field_l(pszField), hi);
//
//}
//
//
//
//long long jni_object::get_l(const_char_pointer pszField)
//{
//
//   return get_l(field_l(pszField));
//
//}
//
//
//void jni_object::set_f(const_char_pointer pszField, float f)
//{
//
//   set_f(field_f(pszField), f);
//
//}
//
//
//float jni_object::get_f(const_char_pointer pszField)
//{
//
//   return get_f(field_f(pszField));
//
//}
//
//
//void jni_object::set_d(const_char_pointer pszField, double d)
//{
//
//   set_d(field_d(pszField), d);
//
//}
//
//
//double jni_object::get_d(const_char_pointer pszField)
//{
//
//   return get_d(field_d(pszField));
//
//}


void jni_object::set_str(jni_field * pfield, const_char_pointer psz)
{

   return m_pjniobjectinterface->set_str(pfield, psz);

}


string jni_object::get_str(jni_field * pfield)
{

   return m_pjniobjectinterface->get_str(pfield);

}


void jni_object::set_b(jni_field * pfield, bool b)
{

   return m_pjniobjectinterface->set_b(pfield, b);

}


bool jni_object::get_b(jni_field * pfield)
{

   return m_pjniobjectinterface->get_b(pfield);

}


void jni_object::set_uch(jni_field * pfield, unsigned char uch)
{

   return m_pjniobjectinterface->set_uch(pfield, uch);

}


unsigned char jni_object::get_uch(jni_field * pfield)
{

   return m_pjniobjectinterface->get_uch(pfield);

}


void jni_object::set_ch(jni_field * pfield, char ch)
{

   return m_pjniobjectinterface->set_ch(pfield, ch);

}


char jni_object::get_ch(jni_field * pfield)
{

   return m_pjniobjectinterface->get_ch(pfield);

}


void jni_object::set_sh(jni_field * pfield, short sh)
{

   return m_pjniobjectinterface->set_sh(pfield, sh);

}


short jni_object::get_sh(jni_field * pfield)
{

   return m_pjniobjectinterface->get_sh(pfield);

}


void jni_object::set_i(jni_field * pfield, int i)
{

   return m_pjniobjectinterface->set_i(pfield, i);

}


int jni_object::get_i(jni_field * pfield)
{

   return m_pjniobjectinterface->get_i(pfield);

}


void jni_object::set_l(jni_field * pfield, long long l)
{

   return m_pjniobjectinterface->set_l(pfield, l);

}


long long jni_object::get_l(jni_field * pfield)
{

   return m_pjniobjectinterface->get_l(pfield);

}


void jni_object::set_f(jni_field * pfield, float f)
{

   return m_pjniobjectinterface->set_f(pfield, f);

}


float jni_object::get_f(jni_field * pfield)
{

   return m_pjniobjectinterface->get_f(pfield);

}


void jni_object::set_d(jni_field * pfield, double d)
{

   return m_pjniobjectinterface->set_d(pfield, d);

}


double jni_object::get_d(jni_field * pfield)
{

   return m_pjniobjectinterface->get_d(pfield);

}




