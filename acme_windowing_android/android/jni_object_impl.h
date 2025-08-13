#pragma once


#include "jni_object_interface.h"
#include "_internal.h"


class CLASS_DECL_ACME jni_field_impl :
   virtual public ::jni_field
{
public:

   jfieldID m_jfieldid;

};


class CLASS_DECL_ACME jni_object_impl :
   virtual public jni_object_interface
{
public:


   jobject     m_jobject;
   jclass      m_jclass;

   ::string_map_base < ::pointer < jni_field > > m_mapField;


   jni_object_impl();
   jni_object_impl(jobject jobject);
   ~jni_object_impl() override;


   void set_jni_object(jobject jobject);


   virtual jni_field * _field(const_char_pointer psz, const_char_pointer pszType);

   jni_field * field_str(const_char_pointer psz) override;
   jni_field * field_b(const_char_pointer psz) override;
   jni_field * field_uch(const_char_pointer psz) override;
   jni_field * field_ch(const_char_pointer psz) override;
   jni_field * field_sh(const_char_pointer psz) override;
   jni_field * field_i(const_char_pointer psz) override;
   jni_field * field_l(const_char_pointer psz) override;
   jni_field * field_f(const_char_pointer psz) override;
   jni_field * field_d(const_char_pointer psz) override;


   void set_str(jni_field * jfieldid, const_char_pointer psz) override;

   string get_str(jni_field * jfieldid) override;

   void set_b(jni_field * jfieldid, bool b) override;

   bool get_b(jni_field * jfieldid) override;

   void set_uch(jni_field * jfieldid, unsigned char b) override;

   unsigned char get_uch(jni_field * jfieldid) override;

   void set_ch(jni_field * jfieldid, char ch) override;

   char get_ch(jni_field * jfieldid) override;

   void set_sh(jni_field * jfieldid, short sh) override;

   short get_sh(jni_field * jfieldid) override;

   void set_i(jni_field * jfieldid, int i) override;

   int get_i(jni_field * jfieldid) override;

   void set_l(jni_field * jfieldid, long long hi) override;

   long long get_l(jni_field * jfieldid) override;

   void set_f(jni_field * jfieldid, float f) override;

   float get_f(jni_field * jfieldid) override;

   void set_d(jni_field * jfieldid, double d) override;

   double get_d(jni_field * jfieldid) override;

//   void set_str(const_char_pointer pszField, const_char_pointer psz) override;
//
//   string get_str(const_char_pointer pszField) override;
//
//   void set_b(const_char_pointer pszField, bool boolean) override;
//
//   bool get_b(const_char_pointer pszField) override;
//
//   void set_uch(const_char_pointer pszField, unsigned char b) override;
//
//   unsigned char get_uch(const_char_pointer pszField) override;
//
//   void set_ch(const_char_pointer pszField, char ch) override;
//
//   char get_ch(const_char_pointer pszField) override;
//
//   void set_sh(const_char_pointer pszField, short sh) override;
//
//   short get_sh(const_char_pointer pszField) override;
//
//   void set_i(const_char_pointer pszField, int i) override;
//
//   int get_i(const_char_pointer pszField) override;
//
//   void set_l(const_char_pointer pszField, long long hi) override;
//
//   long long get_l(const_char_pointer pszField) override;
//
//   void set_f(const_char_pointer pszField, float f) override;
//
//   float get_f(const_char_pointer pszField) override;
//
//   void set_d(const_char_pointer pszField, double f) override;
//
//   double get_d(const_char_pointer pszField) override;


};



inline ::pointer < ::jni_object_interface > __as_jni_object(jobject jobject)
{

   return __allocate jni_object_impl(jobject);

}


template < typename TYPE >
inline ::pointer < TYPE > __øjni(jobject jobject)
{

   auto pjniobjectinterface = __as_jni_object(jobject);

   return __allocate TYPE(pjniobjectinterface);

}