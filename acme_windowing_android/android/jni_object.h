#pragma once


class CLASS_DECL_ACME jni_object
{
public:


   jobject     m_jobject;
   jclass      m_jclass;


   jni_object();
   jni_object(jobject jobject);
   ~jni_object();


   void set_jni_object(jobject jobject);


   jfieldID field_str(const_char_pointer  psz);
   jfieldID field_b(const_char_pointer  psz);
   jfieldID field_uch(const_char_pointer  psz);
   jfieldID field_ch(const_char_pointer  psz);
   jfieldID field_sh(const_char_pointer  psz);
   jfieldID field_i(const_char_pointer  psz);
   jfieldID field_l(const_char_pointer  psz);
   jfieldID field_f(const_char_pointer  psz);
   jfieldID field_d(const_char_pointer  psz);


   void set_str(jfieldID jfieldid, const_char_pointer  psz);

   string get_str(jfieldID jfieldid);

   void set_b(jfieldID jfieldid, bool b);

   bool get_b(jfieldID jfieldid);

   void set_uch(jfieldID jfieldid, unsigned char b);

   unsigned char get_uch(jfieldID jfieldid);

   void set_ch(jfieldID jfieldid, char ch);

   char get_ch(jfieldID jfieldid);

   void set_sh(jfieldID jfieldid, short sh);

   short get_sh(jfieldID jfieldid);

   void set_i(jfieldID jfieldid, int i);

   int get_i(jfieldID jfieldid);

   void set_l(jfieldID jfieldid, long long hi);

   long long get_l(jfieldID jfieldid);

   void set_f(jfieldID jfieldid, float f);

   float get_f(jfieldID jfieldid);

   void set_d(jfieldID jfieldid, double d);

   double get_d(jfieldID jfieldid);

   void set_str(const_char_pointer  pszField, const_char_pointer  psz);

   string get_str(const_char_pointer  pszField);

   void set_b(const_char_pointer  pszField, bool boolean);

   bool get_b(const_char_pointer  pszField);

   void set_uch(const_char_pointer  pszField, unsigned char b);

   unsigned char get_uch(const_char_pointer  pszField);

   void set_ch(const_char_pointer  pszField, char ch);

   char get_ch(const_char_pointer  pszField);

   void set_sh(const_char_pointer  pszField, short sh);

   short get_sh(const_char_pointer  pszField);

   void set_i(const_char_pointer  pszField, int i);

   int get_i(const_char_pointer  pszField);

   void set_l(const_char_pointer  pszField, long long hi);

   long long get_l(const_char_pointer  pszField);

   void set_f(const_char_pointer  pszField, float f);

   float get_f(const_char_pointer  pszField);

   void set_d(const_char_pointer  pszField, double f);

   double get_d(const_char_pointer  pszField);


};


#define JX(type, name) \
jfieldID m_fid##name = field_##type("m_" # type # name); \
template < typename T > \
inline void set##name(T && t) { set_##type(m_fid##name, t); } \
inline auto get##name() { return get_##type(m_fid##name); }

