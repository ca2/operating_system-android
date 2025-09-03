// Created by camilo on 2025-07~08 <3ThomasBorregaardSorensen!!
#pragma once

class jni_context;
class jni_class;


enum enum_jni_call : int {
   e_jni_call_none,
   e_jni_call__init__,
   e_jni_call_void_method,
};

class CLASS_DECL_ACME jni_field :
   virtual public ::particle
{
public:

};

class CLASS_DECL_ACME jni_method :
   virtual public ::particle
{
public:



   enum_jni_call m_ejnicall = e_jni_call_none;

};

class jni_object;
class CLASS_DECL_ACME jni_object_interface :
   virtual public ::particle
{
public:


   jni_object_interface();
   ~jni_object_interface();

   virtual ::jni_class  * class_interface();
   virtual void set_class_interface(::jni_class * pjniclass);

   virtual void initialize_jni_object();
   virtual void initialize_jni_object(jni_object_interface * pjniobjectinterface);

   ::pointer < ::jni_object_interface > call(::jni_method * pmethod, ...);
   virtual ::pointer < ::jni_object_interface > call_args(::jni_method * pmethod, va_list args);

   virtual void * p_jobject();

   virtual void set_str(jni_field * jfieldid, const_char_pointer psz);

   virtual string get_str(jni_field * jfieldid);

   virtual void set_b(jni_field * jfieldid, bool b);

   virtual bool get_b(jni_field * jfieldid);

   virtual void set_uch(jni_field * jfieldid, unsigned char b);

   virtual unsigned char get_uch(jni_field * jfieldid);

   virtual void set_ch(jni_field * jfieldid, char ch);

   virtual char get_ch(jni_field * jfieldid);

   virtual void set_sh(jni_field * jfieldid, short sh);

   virtual short get_sh(jni_field * jfieldid);

   virtual void set_i(jni_field * jfieldid, int i);

   virtual int get_i(jni_field * jfieldid);

   virtual void set_l(jni_field * jfieldid, long long hi);

   virtual long long get_l(jni_field * jfieldid);

   virtual void set_f(jni_field * jfieldid, float f);

   virtual float get_f(jni_field * jfieldid);

   virtual void set_d(jni_field * jfieldid, double d);

   virtual double get_d(jni_field * jfieldid);

   virtual void set_ba(jni_field * jfieldid, const ::block & block);

   virtual memory get_ba(jni_field * jfieldid);

   virtual void set_str(const_char_pointer pszField, const_char_pointer psz);

   virtual string get_str(const_char_pointer pszField);

   virtual void set_b(const_char_pointer pszField, bool boolean);

   virtual bool get_b(const_char_pointer pszField);

   virtual void set_uch(const_char_pointer pszField, unsigned char b);

   virtual unsigned char get_uch(const_char_pointer pszField);

   virtual void set_ch(const_char_pointer pszField, char ch);

   virtual char get_ch(const_char_pointer pszField);

   virtual void set_sh(const_char_pointer pszField, short sh);

   virtual short get_sh(const_char_pointer pszField);

   virtual void set_i(const_char_pointer pszField, int i);

   virtual int get_i(const_char_pointer pszField);

   virtual void set_l(const_char_pointer pszField, long long hi);

   virtual long long get_l(const_char_pointer pszField);

   virtual void set_f(const_char_pointer pszField, float f);

   virtual float get_f(const_char_pointer pszField);

   virtual void set_d(const_char_pointer pszField, double f);

   virtual double get_d(const_char_pointer pszField);

   virtual void set_ba(const_char_pointer pszField, const ::block & block);

   virtual memory get_ba(const_char_pointer pszField);

};


