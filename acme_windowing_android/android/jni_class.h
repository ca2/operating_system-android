//
// Created by camilo on 2025-09-02 16:57 <3ThomasBorregaardSorensen!!
//
#pragma once

class jni_field;
class jni_method;
class jni_object;
class jni_object_interface;
enum enum_jni_call : int;


#define JNI_JX_CLASS_DATA(type, name) \
::pointer < jni_field > m_pfield##name;\
jni_field * jni_field_##name()         \
{                                      \
    if(!m_pfield##name)                \
    {                                  \
      m_pfield##name =field_##type("m_" # type # name); \
    }                                  \
   return m_pfield##name;              \
}



// ejnicall ex.: ::e_jni_call_void_method,
#define JNI_JX_CLASS_FUNC(name, ejnicall, sig) \
::pointer < ::jni_method > m_pmethod_##name; \
jni_method * jni_method_##name()         \
{                                      \
    if(!m_pmethod_##name)                \
    {                                  \
      m_pmethod_##name =this->method( \
   ejnicall, \
   ""#name, \
   sig); \
    }                                  \
   return m_pmethod_##name;              \
}



#define JNI_JX_OBJECT_DATA(type, name) \
template < typename T > \
inline void set##name(T && t) { set_##type(this_class()->jni_field_##name(), t); } \
inline auto get##name() { return get_##type(this_class()->jni_field_##name()); }

#define JNI_JX_OBJECT_FUNC(name, ejnicallUNUSED, sigUNUSED) \
inline ::pointer< ::jni_object > name(::jni_context * pcontext, ...) \
{                                                           \
         va_list args; \
va_start(args, pcontext); \
auto p = this->call_args(this_class()->jni_method_##name(),  args); \
va_end(args);                                               \
         return p;                                                   \
}


#define IMPL_JNI_CLASS(JNI_CLASS) \
   JNI_CLASS(JNI_JX_CLASS_DATA, JNI_JX_CLASS_FUNC);


#define IMPL_JNI_OBJECT(JNI_CLASS, jniclass, javaclassname) \
   inline static jniclass##_class * s_pjniclassimpl2 = nullptr;               \
   inline static jniclass##_class * s_class() {                         \
   if(!s_pjniclassimpl2)                                    \
   {                                                        \
      s_pjniclassimpl2 = jni_get_class<jniclass##_class>(javaclassname);\
   }\
   return s_pjniclassimpl2;                                  \
                                                            \
   }                                                        \
                                                            \
jniclass(::jni_object_interface * pjniobjectinterface)      \
{                                                           \
   initialize_jni_object(pjniobjectinterface);              \
}                                                            \
::jni_class * class_interface() override {return this_class();}                                    \
   inline jniclass##_class * this_class() {  return s_class(); }                       \
   JNI_CLASS(JNI_JX_OBJECT_DATA, JNI_JX_OBJECT_FUNC);

#define BEGIN_JNI_CLASS(JNI_CLASS, jniclass) \
class jniclass##_class :  \
   virtual public jni_class  \
{ \
public:                                      \
  \
   IMPL_JNI_CLASS(JNI_CLASS)


#define END_JNI_CLASS() };


class jni_class :
virtual public ::particle
{
public:


   ::pointer < jni_class > m_pjniclassImpl;
   ::string_map_base < ::pointer < jni_field > > m_mapField;
   ::string_map_base < ::pointer < jni_method > > m_mapMethod;


   jni_class();
   ~jni_class() override;


   virtual void * p_jclass();

   ::pointer < jni_object_interface >new_jni_object(
      jni_method * pmethodConstructor,
      ...);

   virtual ::pointer < jni_object_interface >new_jni_object_args(
      jni_method * pmethodConstructor,
      va_list args);

   virtual jni_field * _field(const_char_pointer psz, const_char_pointer pszType);

   virtual jni_field * field_str(const_char_pointer psz);
   virtual jni_field * field_b(const_char_pointer psz);
   virtual jni_field * field_uch(const_char_pointer psz);
   virtual jni_field * field_ch(const_char_pointer psz);
   virtual jni_field * field_sh(const_char_pointer psz);
   virtual jni_field * field_i(const_char_pointer psz);
   virtual jni_field * field_l(const_char_pointer psz);
   virtual jni_field * field_f(const_char_pointer psz);
   virtual jni_field * field_d(const_char_pointer psz);

   virtual jni_field * field_ba(const_char_pointer psz);

   virtual jni_method * method(enum_jni_call ecall, const_char_pointer pszName, const_char_pointer pszSignature);

};


void jni_get_class_impl(jni_class * pjniclassInterface, const_char_pointer pszClassName);


template < typename JNICLASSINTERFACE >
inline JNICLASSINTERFACE * jni_get_class(const_char_pointer pszClassName)
{

   auto pjniclassinterface = øallocate JNICLASSINTERFACE();

   jni_get_class_impl(pjniclassinterface, pszClassName);

   return pjniclassinterface;

}



