// Created by camilo on 2025-07~08 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "_internal.h"


jni_object::jni_object()
{

}


//jni_object::jni_object(jni_object_interface * pjniobjectinterface)
//{
//
//   initialize_jni_object(pjniobjectinterface);
//
//}


jni_object::~jni_object()
{

}


void jni_object::initialize_jni_object()
{

   ::jni_object_interface::initialize_jni_object();

   if(m_pjniobjectinterface)
   {

      if(!m_pjniobjectinterface->class_interface())
      {

         m_pjniobjectinterface->set_class_interface(class_interface());

      }

   }

}


void jni_object::initialize_jni_object(jni_object_interface * pjniobjectinterface)
{

   m_pjniobjectinterface = pjniobjectinterface;

   initialize_jni_object();

}





void * jni_object::p_jobject()
{

   return m_pjniobjectinterface->p_jobject();

}

::pointer < jni_object_interface > jni_object::call_args(::jni_method * pmethod, va_list args)
{

   return m_pjniobjectinterface->call_args(pmethod, args);

}


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




void jni_object::set_ba(jni_field * pfield, const ::block & block )
{

   return m_pjniobjectinterface->set_ba(pfield, block);

}


::memory jni_object::get_ba(jni_field * pfield)
{

   return m_pjniobjectinterface->get_ba(pfield);

}


