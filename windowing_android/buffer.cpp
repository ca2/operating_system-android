#include "framework.h"
#include "_.h"
#include "buffer.h"
#include "acme_windowing_android/android/_internal.h"
#include "acme/parallelization/synchronous_lock.h"
#include "aura/graphics/image/image.h"
//#include <native_window.h>


#define LOG_TAG "buffer(native)"


namespace windowing_android
{


   buffer::buffer()
   {

      //m_cairoSource = nullptr;
      //m_cairosurfaceSource = nullptr;

   }


   buffer::~buffer()
   {
      
      destroy_buffer();

   }


   bool buffer::_on_begin_draw(::graphics::buffer_item *)
   {

      auto pitem = get_buffer_item();

      //auto sizeWindow = window_size();

      LOGI("on_begin_draw");

      auto pimage = pitem->m_pimage2;

      //if (pimage->size() != sizeWindow)
      {

         //         if(pimage->size().area() < sizeWindow.area())
         //         {
         //
         //            ::int_size sizeImage(1920, 1080);
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

         //auto sizeMonitor = ::int_size(1920, 1080);

      


         //pimage->create(sizeWindow);
         // 
         pimage->create(pitem->m_sizeBufferItemDraw);
         //if (!pimage->create(sizeWindow))
         //{

         //   return nullptr;

         //}

//         }
//
//         if(pimage->size().area() > sizeWindow.area())
//         {
//
//            pimage->map();
//
//            pimage->m_iScan = sizeWindow.width() * sizeof(::color32_t);
//
//            pimage->m_size = sizeWindow;
//
//         }
//
      }

      if (!pimage)
      {

         return false;

      }

      return pitem;

   }



   bool buffer::update_buffer(::graphics::buffer_item * pbufferitem)
   {

      //destroy_buffer();

      synchronous_lock synchronouslock(synchronization());

      int w;

      int h;


      //w = ANativeWindow_getWidth(m_pimpl->m_oswindow->m_engine.app->window);

      //h = ANativeWindow_getHeight(m_pimpl->m_oswindow->m_engine.app->window);

      //ANativeWindow_setBuffersGeometry(m_pimpl->m_oswindow->m_engine.app->window, w, h, WINDOW_FORMAT_RGBA_8888);

      ::graphics::double_buffer::update_buffer(pbufferitem);

      return true;

   }





   void buffer::destroy_buffer()
   {

      ::graphics::double_buffer::destroy_buffer();


   }


   void buffer::on_update_screen(::graphics::buffer_item * pbufferitem)
   {

      auto pdriver = ::acme::driver::get();

      LOGI("m_bRedraw = true");

      pdriver->m_bRedraw = true;

      //ANativeWindow_Buffer buffer;

      //ARect r;

      //rectangle.left() = 0;
      //rectangle.top() = 0;
      //rectangle.right() = pimage->width();
      //rectangle.bottom() = pimage->height();

      //zero(buffer);

      //ANativeWindow_lock(m_pimpl->m_oswindow->m_engine.app->window, &buffer, rectangle);

      ///**
      //* Unlock the window's drawing surface after previously locking it,
      //* posting the ___new buffer to the display.
      //*/


      //::copy_image32(pimage->width(), pimage->height(), (color32_t *)buffer.bits, pimage->width() * sizeof(color32_t), pimage->get_data(), pimage->scan_size());

      //ANativeWindow_unlockAndPost(m_pimpl->m_oswindow->m_engine.app->window);

      //return true;

   }


} // namespace windowing_android




