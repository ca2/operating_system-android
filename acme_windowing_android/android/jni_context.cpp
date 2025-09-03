#include "framework.h"
#include "_internal.h"
#include "jni_local.h"
#include "jni_object_impl.h"


#include <string.h>
#include <stdlib.h>



thread_local ::pointer < jni_context_impl > t_pjnipcontextContext;


jni_context * jni_context::get()
{

   return t_pjnipcontextContext;

}

::particle_pointer g_pmutexOs;


::particle* osmutex()
{

   return g_pmutexOs;

}


int get_mem_free_available_kb()
{

   return ::platform::application_sink::get()->m_lMemFreeAvailableKb;

}


string as_string(const jstring & jstring)
{

   const_char_pointer nativeString = t_pjnipcontextContext->m_pjnicontext->GetStringUTFChars(jstring, 0);

   string str = nativeString;

   t_pjnipcontextContext->m_pjnicontext->ReleaseStringUTFChars(jstring, nativeString);

   return str;

}


void set_jni_context(JNIEnv* pcontext)
{

   if(!t_pjnipcontextContext)
   {

      t_pjnipcontextContext = øallocate jni_context_impl;

   }

   t_pjnipcontextContext->m_pjnicontext = pcontext;

}


//JNIEnv* get_jni_context()
//{
//
//   return t_pjnipcontextContext;
//
//}


::string __string(const jstring& jstring)
{

   auto pcontext = t_pjnipcontextContext;

   const ::wd16_character* utf16 = (::wd16_character*)pcontext->m_pjnicontext->GetStringChars(jstring, NULL);

   if (utf16 == NULL)
   {

      return "";

   }

   size_t length = (size_t)pcontext->m_pjnicontext->GetStringLength(jstring);

   wd16_string wstr(utf16, length);

   string str(wstr);

   pcontext->m_pjnicontext->ReleaseStringChars(jstring, (jchar*)utf16);

   return str;

}





// Cached ClassLoader and loadClass method
static jobject g_classLoader = NULL;
static jmethodID g_loadClass = NULL;

// Simple linked list of cached classes
typedef struct ClassEntry {
   char *name;         // dotted name: "platform.platform.message.Message"
   jclass clazz;       // global ref
   struct ClassEntry *next;
} ClassEntry;

static ClassEntry *g_classList = NULL;

void class_cache_init(JNIEnv *env, jobject loader) {
   if (g_classLoader != NULL) return; // already initialized

   g_classLoader = env->NewGlobalRef(loader);

   jclass classLoaderClass = env->FindClass("java/lang/ClassLoader");
   g_loadClass = env->GetMethodID(classLoaderClass,
                                     "loadClass",
                                     "(Ljava/lang/String;)Ljava/lang/Class;");
}

jclass class_cache_get(JNIEnv *env, const char *className) {
   // Look up in cache
   for (ClassEntry *e = g_classList; e; e = e->next) {
      if (strcmp(e->name, className) == 0) {
         return e->clazz;
      }
   }

   // Not cached → load it
   jstring strClassName = env->NewStringUTF(className);
   jclass localClass = (jclass)env->CallObjectMethod(g_classLoader, g_loadClass, strClassName);
   env->DeleteLocalRef(strClassName);

   if (!localClass) {
      return NULL; // failed
   }

   jclass globalClass = (jclass)env->NewGlobalRef(localClass);
   env->DeleteLocalRef(localClass);

   // Insert into cache
   ClassEntry *entry = (ClassEntry*)malloc(sizeof(ClassEntry));
   entry->name = strdup(className);
   entry->clazz = globalClass;
   entry->next = g_classList;
   g_classList = entry;

   return globalClass;
}

void class_cache_destroy(JNIEnv *env) {
   // Release cached classes
   ClassEntry *e = g_classList;
   while (e) {
      ClassEntry *next = e->next;
      if (e->clazz) {
         env->DeleteGlobalRef(e->clazz);
      }
      free(e->name);
      free(e);
      e = next;
   }
   g_classList = NULL;

   // Release ClassLoader
   if (g_classLoader) {
      env->DeleteGlobalRef(g_classLoader);
      g_classLoader = NULL;
   }
   g_loadClass = NULL;
}


extern "C"
JNIEXPORT void JNICALL
Java_platform_platform_platform_application_init_1class_1cache(JNIEnv *env, jclass clazz, jobject loader)
{

   class_cache_init(env, loader);

   // Preload Message class into cache
   jclass messageCls = class_cache_get(env, "platform.platform.message.message");

   if (!messageCls)
   {

      printf("Failed to load Message class\n");

   }

}


// Clean up when library unloads
extern "C"
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{

   JNIEnv* env = NULL;

   if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK)
   {

      return;

   }

   class_cache_destroy(env);

}



jstring _jni_get_class_name(JNIEnv *env, jclass cls)
{
// Get java.lang.Class class
jclass classClass = env->FindClass("java/lang/Class");

// Method ID for Class.getName()
jmethodID midGetName = env->GetMethodID(classClass, "getName", "()Ljava/lang/String;");

// Call getName() on the jclass
return (jstring)env->CallObjectMethod(cls, midGetName);
}

::string jni_get_class_name(jclass jclass)
{

   ::cast<jni_context_impl> pjnicontextimpl = ::jni_context::get();

   jni_local_string jnistringClassName(_jni_get_class_name(pjnicontextimpl->m_pjnicontext, jclass));

   ::string strClassName = jnistringClassName.as_string();
//   // Convert to C string
//   const char *pszClassName = pjnicontextimpl->m_pjnicontext->GetStringUTFChars( jnistringClassName, NULL);
////printf("Class name: %s\n", nameC);
//      strClassName = pszClassName;
//   pjnicontextimpl->m_pjnicontext->ReleaseStringUTFChars(jnistringClassName, pszClassName);
//   pjnicontextimpl->m_pjnicontext->DeleteLocalRef(jnistringClassName);

   return strClassName;

}