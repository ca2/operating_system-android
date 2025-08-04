#include "framework.h"
#include "_internal.h"


jni_object_interface::jni_object_interface()
{


}



jni_object_interface::~jni_object_interface()
{


}


jni_field * jni_object_interface::field_str(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_b(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_uch(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_ch(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_sh(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_i(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_l(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_f(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


jni_field * jni_object_interface::field_d(const_char_pointer psz)
{

   throw ::interface_only();

   return nullptr;

}


void jni_object_interface::set_str(const_char_pointer pszField, const_char_pointer psz)
{

   set_str(field_str(pszField), psz);

}


string jni_object_interface::get_str(const_char_pointer pszField)
{

   return get_str(field_str(pszField));

}


void jni_object_interface::set_b(const_char_pointer pszField, bool b)
{

   set_b(field_b(pszField), b);

}


bool jni_object_interface::get_b(const_char_pointer pszField)
{

   return get_b(field_b(pszField));

}



void jni_object_interface::set_uch(const_char_pointer pszField, unsigned char b)
{

   set_uch(field_uch(pszField), b);

}


unsigned char jni_object_interface::get_uch(const_char_pointer pszField)
{

   return get_uch(field_uch(pszField));

}



void jni_object_interface::set_ch(const_char_pointer pszField, char ch)
{

   set_ch(field_ch(pszField), ch);

}


char jni_object_interface::get_ch(const_char_pointer pszField)
{

   return get_ch(field_ch(pszField));

}



void jni_object_interface::set_sh(const_char_pointer pszField, short sh)
{

   set_sh(field_sh(pszField), sh);

}


short jni_object_interface::get_sh(const_char_pointer pszField)
{

   return get_sh(field_sh(pszField));

}



void jni_object_interface::set_i(const_char_pointer pszField, int i)
{

   set_i(field_i(pszField), i);

}



int jni_object_interface::get_i(const_char_pointer pszField)
{

   return get_i(field_i(pszField));

}



void jni_object_interface::set_l(const_char_pointer pszField, long long hi)
{

   set_l(field_l(pszField), hi);

}



long long jni_object_interface::get_l(const_char_pointer pszField)
{

   return get_l(field_l(pszField));

}


void jni_object_interface::set_f(const_char_pointer pszField, float f)
{

   set_f(field_f(pszField), f);

}


float jni_object_interface::get_f(const_char_pointer pszField)
{

   return get_f(field_f(pszField));

}


void jni_object_interface::set_d(const_char_pointer pszField, double d)
{

   set_d(field_d(pszField), d);

}


double jni_object_interface::get_d(const_char_pointer pszField)
{

   return get_d(field_d(pszField));

}


void jni_object_interface::set_str(jni_field * jfieldid, const_char_pointer psz)
{

   throw ::interface_only();

}


string jni_object_interface::get_str(jni_field * jfieldid)
{

   throw ::interface_only();

   return {};

}


void jni_object_interface::set_b(jni_field * fid, bool b)
{

   throw ::interface_only();

}



bool jni_object_interface::get_b(jni_field * fid)
{

   throw ::interface_only();

   return 0;

}



void jni_object_interface::set_uch(jni_field * fid, unsigned char b)
{

   throw ::interface_only();

}



unsigned char jni_object_interface::get_uch(jni_field * fid)
{

   throw ::interface_only();

   return 0;

}



void jni_object_interface::set_ch(jni_field * fid, char ch)
{

   throw ::interface_only();

}



char jni_object_interface::get_ch(jni_field * fid)
{

   throw ::interface_only();

   return 0;

}



void jni_object_interface::set_sh(jni_field * fid, short sh)
{

   throw ::interface_only();

}



short jni_object_interface::get_sh(jni_field * fid)
{

   throw ::interface_only();

   return 0;

}



void jni_object_interface::set_i(jni_field * fid, int i)
{

   throw ::interface_only();

}



int jni_object_interface::get_i(jni_field * fid)
{

   throw ::interface_only();

   return 0;

}




void jni_object_interface::set_l(jni_field * fid, long long hi)
{

   throw ::interface_only();

}



long long jni_object_interface::get_l(jni_field * fid)
{

   throw ::interface_only();

   return 0;

}



void jni_object_interface::set_f(jni_field * fid, float f)
{

   throw ::interface_only();

}



float jni_object_interface::get_f(jni_field * fid)
{

   throw ::interface_only();

   return 0.f;

}




void jni_object_interface::set_d(jni_field * fid, double d)
{

   throw ::interface_only();

}



double jni_object_interface::get_d(jni_field * fid)
{

   throw ::interface_only();

   return 0.;

}




