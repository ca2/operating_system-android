#include "platform.h"
#include "_.h"
#include "graphics.h"
#include "acme_windowing_android/android/_internal.h"
#include "acme/parallelization/synchronous_lock.h"
#include "aura/graphics/graphics/buffer_item.h"
#include "aura/graphics/image/image.h"
#include "aura/windowing/window.h"
#include <typeinfo>
//#include <native_window.h>


#define LOG_TAG "windowing_android::graphics"


namespace windowing_android
{


   graphics::graphics()
   {

      //m_cairoSource = nullptr;
      //m_cairosurfaceSource = nullptr;

   }


   graphics::~graphics()
   {
      
      destroy_buffer();

   }


   bool graphics::_on_begin(::graphics::buffer_item * pitem)
   {

      //auto sizeWindow = window_size();

      LOGI("on_begin_draw item=%p", pitem);

      if (!pitem)
      {

         return false;

      }

      // Set up the window render target before acquiring graphics for this
      // frame. The descriptor below only describes the image graphics.
      if (!::graphics::double_buffer_graphics::_on_begin(pitem))
      {

         return false;

      }

      ::image::image_pointer pimage;

      //if (pimage->size() != sizeWindow)
      {

         //         if(pimage->size().area() < sizeWindow.area())
         //         {
         //
         //            ::i32_size sizeImage(1920, 1080);
         //
         //            if(sizeWindow.area() > sizeImage.area())
         //            {
         //
         //               sizeImage = sizeWindow;
         //
         //            }
         //
         //

         //         if(sizeWindow.cx == 1)
         //         {
         //
         //            printf("cx=1");
         //
         //         }
         //         else
         //         {
         //            printf("cx!=1");
         //
         //         }

         //auto sizeMonitor = ::i32_size(1920, 1080);

      


         try
         {

            pimage = pitem->m_pimageBufferItem;

            LOGI("image pointer=%p", pimage.m_p);

            if (!pimage)
            {

               return false;

            }

            LOGI("image before create type=%s graphics=(%d,%d)",
               typeid(*pimage.m_p).name(),
               pitem->m_sizeBufferItem.cx,
               pitem->m_sizeBufferItem.cy);

            pimage->update_as_render_target(pitem->m_sizeBufferItem,
                                            m_pwindow->user_interaction());

            auto ppixmapImage = pimage->map();

            LOGI("image after create type=%s size=(%d,%d) scan=%d raw=%p data=%p",
                  typeid(*pimage.m_p).name(),
                  ppixmapImage->width(),
                  ppixmapImage->height(),
                  ppixmapImage->scan_size(),
                  ppixmapImage->m_pimage32Raw,
                  ppixmapImage->m_pimage32);

         }
         catch (const ::exception & exception)
         {

            LOGI("image create exception: %s", exception.get_message().c_str());

            throw;

         }
         catch (...)
         {

            LOGI("image create unknown exception");

            throw;

         }

//         auto pdraw2dgraphics = pdraw2dgraphicsImage;

  //       if (pdraw2dgraphics)
         {

    //        pdraw2dgraphics->resize(pitem->m_sizeBufferItem);

         }
         //if (!pimage->create_as_descriptor(sizeWindow))
         //{

         //   return nullptr;

         //}

//         }
//
//         if(pimage->size().area() > sizeWindow.area())
//         {
//
//            pimage->map_base();
//
//            pimage->m_iScan = sizeWindow.width() * sizeof(::color32_t);
//
//            pimage->m_size = sizeWindow;
//
//         }
//
      }

//      if (!pimage)
      {

  //       return false;

      }

    //  return pitem;

      return true;

   }



   bool graphics::update_buffer(::graphics::buffer_item * pbufferitem)
   {

      //destroy_buffer();

      synchronous_lock synchronouslock(synchronization());

      int w;

      int h;


      //w = ANativeWindow_getWidth(m_pimpl->m_pacmewindowingwindow->m_engine.app->window);

      //h = ANativeWindow_getHeight(m_pimpl->m_pacmewindowingwindow->m_engine.app->window);

      //ANativeWindow_setBuffersGeometry(m_pimpl->m_pacmewindowingwindow->m_engine.app->window, w, h, WINDOW_FORMAT_RGBA_8888);

      ::graphics::double_buffer_graphics::update_buffer(pbufferitem);

      return true;

   }





   void graphics::destroy_buffer()
   {

      ::graphics::double_buffer_graphics::destroy_buffer();


   }


   void graphics::on_update_screen(::graphics::buffer_item * pbufferitem)
   {

      auto pdriver = ::platform::application_sink::get();

      LOGI("m_bRedraw = true");

      pdriver->m_bRedraw = true;


//      auto pbind = ::jni_bind::get();
//
//      if(!pbind->getApplicationReady())
//      {
//
//         pbind->setApplicationReady(true);
//
//      }



      //ANativeWindow_Buffer graphics;

      //ARect r;

      //rectangle.left = 0;
      //rectangle.top = 0;
      //rectangle.right = pimage->width();
      //rectangle.bottom = pimage->height();

      //zero(graphics);

      //ANativeWindow_lock(m_pimpl->m_pacmewindowingwindow->m_engine.app->window, &graphics, rectangle);

      ///**
      //* Unlock the window's drawing surface after previously locking it,
      //* posting the ___new graphics to the display.
      //*/


      //::copy_image32(pimage->width(), pimage->height(), (color32_t *)graphics.bits, pimage->width() * sizeof(color32_t), pimage->get_data(), pimage->scan_size());

      //ANativeWindow_unlockAndPost(m_pimpl->m_pacmewindowingwindow->m_engine.app->window);

      //return true;

   }


} // namespace windowing_android




