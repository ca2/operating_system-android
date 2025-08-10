// created from windowing::display by camilo 2022-05-06 18:48 <3ThomasBorregaardSoerensen!!
// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen
// recreated by Camilo 2021-01-28 22:20
#include "framework.h"
#include "display.h"
//#include "_windowing.h"
//#include "acme/prototype/geometry2d/_.h"
//#include "acme/prototype/geometry2d/_enhanced.h"
//#include "acme/prototype/geometry2d/_impl.h"


namespace windowing_android
{


   display::display()
   {

//      m_pDisplay = nullptr;
//
//      m_pDisplay2 = nullptr;
//
//#ifdef LINUX
//      _m_pX11Display = nullptr;
//#endif
//
//      m_bSystemSynchronizedScreen = true;
//      m_iMainMonitor = 0;
//      m_iMainWorkspace = 0;
//
//      defer_create_synchronization();

   }


   display::~display()
   {


   }




//   void display::initialize_display(::windowing::windowing* pwindowing)
//   {
//
//      //auto estatus =
//
//      initialize(pwindowing);
//
//      //if (!estatus)
//      //{
//
//      //   return estatus;
//
//      //}
//
//      auto psystem = system();
//
//      if (psystem != nullptr)
//      {
//
//         m_bSystemSynchronizedScreen = psystem->m_bSystemSynchronizedScreen;
//
//      }
//
//      m_pwindowing = pwindowing;
//
//      //return ::success;
//
//   }
//
//
//   iptr display::get_os_data() const
//   {
//
//      return -1;
//
//   }
//
//
//   window* display::default_root_window()
//   {
//
//      return nullptr;
//
//   }
//
//
//
//   float display::get_dpi()
//   {
//
//      return 96.0;
//
//   }
//
//
//   void display::open()
//   {
//
//      //return ::success;
//
//   }
//
//
//   bool display::set_main_workspace(::collection::index iWorkspace)
//   {
//
//      if (iWorkspace == -1)
//      {
//
//         m_iMainWorkspace = -1;
//
//         return true;
//
//      }
//      else if (iWorkspace < 0 || iWorkspace >= get_workspace_count())
//      {
//
//         return false;
//
//      }
//      else
//      {
//
//         m_iMainWorkspace = iWorkspace;
//
//         return true;
//
//      }
//
//   }
//
//
//
//
//   void display::enum_display_monitors()
//   {
//      //
//      //#ifdef WINDOWS_DESKTOP
//      //
//      //      m_monitorinfoa.erase_all();
//      //
//      //      ::EnumDisplayMonitors(nullptr, nullptr, &display::monitor_enum_proc, (lparam)(dynamic_cast <::aura::session *> (this)));
//      //
//      //#elif defined(LINUX)
//      //
//      //      ::enum_display_monitors(this);
//      //
//      //#endif
//
//   }
//
//
//   ::collection::index display::get_main_monitor(::int_rectangle* prectangle)
//   {
//
//      index iMainMonitor = 0;
//
//      if (prectangle != nullptr)
//      {
//
//         if (!get_monitor_rectangle(iMainMonitor, prectangle))
//         {
//
//            return -1;
//
//         }
//
//      }
//
//      return iMainMonitor;
//
//   }
//
//
//   ::int_size display::get_main_monitor_size()
//   {
//
//      ::int_rectangle rectangle;
//
//      get_main_monitor(rectangle);
//
//      return rectangle.size();
//
//   }
//
//
//   ::int_size display::get_monitor_union_size()
//   {
//
//      ::int_size size;
//
//      size.cx = 0;
//
//      size.cy = 0;
//
//      for (auto& pmonitor : m_monitora)
//      {
//
//         if (size.cx < pmonitor->m_rectangle.width())
//         {
//
//            size.cx = pmonitor->m_rectangle.width();
//
//         }
//
//
//         if (size.cy < pmonitor->m_rectangle.height())
//         {
//
//            size.cy = pmonitor->m_rectangle.height();
//
//         }
//
//      }
//
//      return size;
//
//   }
//
//
//   ::collection::count display::get_monitor_count()
//   {
//
//      return 1;
//
//   }
//
//
//   bool display::get_monitor_rectangle(::collection::index iMonitor, ::int_rectangle* prectangle)
//   {
//
//      if (iMonitor < 0 || iMonitor >= get_monitor_count())
//      {
//
//         return false;
//
//      }
//
//      auto& pmonitor = m_monitora.element_at_grow(iMonitor);
//
//      if (!pmonitor)
//      {
//
//         __construct(pmonitor);
//
//         pmonitor->m_iIndex = iMonitor;
//
//         pmonitor->m_pdisplay = this;
//
//      }
//
//      //auto bOk = 
//
//      pmonitor->get_monitor_rectangle(prectangle);
//
//      //return bOk;
//
//      return true;
//
//   }
//
//
//   ::collection::count display::get_desk_monitor_count()
//   {
//
//      return get_monitor_count();
//
//   }
//
//
//   bool display::get_desk_monitor_rect(::collection::index iMonitor, ::int_rectangle* prectangle)
//   {
//
//      return get_monitor_rectangle(iMonitor, prectangle);
//
//   }
//
//
//
//   index display::get_main_workspace(::int_rectangle* prectangle)
//   {
//
//      if (!get_workspace_rectangle(0, prectangle))
//      {
//
//         return -1;
//
//      }
//
//      return 0;
//
//   }
//
//
//   ::collection::count display::get_workspace_count()
//   {
//
//      return get_monitor_count();
//
//   }
//
//
//   bool display::get_workspace_rectangle(::collection::index iWorkspace, ::int_rectangle* prectangle)
//   {
//
//      if (iWorkspace < 0 || iWorkspace >= get_workspace_count())
//      {
//
//         return false;
//
//      }
//
//      auto& pmonitor = m_monitora.element_at_grow(iWorkspace);
//
//      if (!pmonitor)
//      {
//
//         __construct(pmonitor);
//
//         if (!pmonitor)
//         {
//
//            return false;
//
//         }
//
//         pmonitor->m_iIndex = iWorkspace;
//
//         pmonitor->m_pdisplay = this;
//
//      }
//
//      //auto bOk = 
//
//      pmonitor->get_workspace_rectangle(prectangle);
//
//      //return bOk;
//
//      return true;
//
//   }
//
//
//   ::collection::count display::get_desk_workspace_count()
//   {
//
//      return get_workspace_count();
//
//   }
//
//
//   bool display::get_desk_workspace_rect(::collection::index iWorkspace, ::int_rectangle* prectangle)
//
//   {
//
//      return get_workspace_rectangle(iWorkspace, prectangle);
//
//
//   }
//
//
//   bool display::set_main_monitor(::collection::index iMonitor)
//   {
//
//      if (iMonitor == -1)
//      {
//
//         m_iMainMonitor = -1;
//
//         return true;
//
//      }
//      else if (iMonitor < 0 || iMonitor >= get_monitor_count())
//      {
//
//         return false;
//
//      }
//      else
//      {
//
//         m_iMainMonitor = iMonitor;
//
//         return true;
//
//      }
//
//   }
//
//
//   bool display::workspace_to_monitor(::int_rectangle* prectangle, ::collection::index iMonitor, ::collection::index iWorkspace)
//   {
//
//      ::int_rectangle rectangle(*prectangle);
//
//      ::int_rectangle rectangleWorkspace;
//
//      if (!get_workspace_rectangle(iWorkspace, rectangleWorkspace))
//      {
//
//         return false;
//
//      }
//
//      rectangle -= rectangleWorkspace.top_left();
//
//      ::int_rectangle rectangleMonitor;
//
//      if (!get_monitor_rectangle(iMonitor, rectangleMonitor))
//      {
//
//         return false;
//
//      }
//
//      rectangle += rectangleMonitor.top_left();
//
//      *prectangle = rectangle;
//
//
//      return true;
//
//   }
//
//
//   bool display::workspace_to_monitor(::int_rectangle* prectangle)
//   {
//
//      index iWorkspace = get_best_workspace(nullptr, int_rectangle(prectangle));
//
//      return workspace_to_monitor(prectangle, iWorkspace, iWorkspace);
//
//   }
//
//
//   bool display::monitor_to_workspace(::int_rectangle* prectangle)
//   {
//
//      index iMonitor = get_best_monitor(nullptr, int_rectangle(prectangle));
//
//      return monitor_to_workspace(prectangle, iMonitor, iMonitor);
//
//   }
//
//
//   bool display::monitor_to_workspace(::int_rectangle* prectangle, ::collection::index iWorkspace, ::collection::index iMonitor)
//   {
//
//      ::int_rectangle rectangle(prectangle);
//
//      ::int_rectangle rectangleMonitor;
//
//      if (!get_monitor_rectangle(iMonitor, rectangleMonitor))
//      {
//
//         return false;
//
//      }
//
//      rectangle -= rectangleMonitor.top_left();
//
//      ::int_rectangle rectangleWorkspace;
//
//      if (!get_workspace_rectangle(iWorkspace, rectangleWorkspace))
//      {
//
//         return false;
//
//      }
//
//      rectangle += rectangleWorkspace.top_left();
//
//      *prectangle = rectangle;
//
//      return true;
//
//   }
//
//
//   monitor* display::get_monitor(::collection::index iMonitor)
//   {
//
//      synchronous_lock synchronouslock(synchronization());
//
//      if (iMonitor < 0 || iMonitor >= m_monitora.get_count())
//      {
//
//         return nullptr;
//
//      }
//
//      return m_monitora[iMonitor];
//
//   }
//
//
//   void display::get_monitor(::int_rectangle_array& rectaMonitor, ::int_rectangle_array& rectaIntersect, const int_rectangle& rectangleParam)
//   {
//
//      for (::collection::index iMonitor = 0; iMonitor < get_monitor_count(); iMonitor++)
//      {
//
//         ::int_rectangle rectangleIntersect;
//
//         ::int_rectangle rectangleMonitor;
//
//         if (get_monitor_rectangle(iMonitor, rectangleMonitor))
//         {
//
//            if (rectangleIntersect.top_left_null_intersect(&rectangleParam, rectangleMonitor))
//            {
//
//               if (rectangleIntersect.area() >= 0)
//               {
//
//                  rectaMonitor.add(rectangleMonitor);
//
//                  rectaIntersect.add(rectangleIntersect);
//
//               }
//
//            }
//
//         }
//
//      }
//
//   }
//
//
//
//
//
//#define ZONEING_COMPARE ::comparison
//
//   long long g_i_get_best_zoneing = 0;
//
//   index display::_get_best_zoneing(edisplay* pedisplay, ::int_rectangle* prectangle, const ::int_rectangle& rectangleRequest, bool bPreserveSize)
//   {
//
//      ::int_rectangle rectangle(rectangleRequest);
//
//      ::int_rectangle rectangleWorkspace;
//
//      index iBestWorkspace = get_best_workspace(&rectangleWorkspace, rectangle);
//
//      ::e_display edisplay;
//
//      ::e_display edisplayPrevious = *pedisplay;
//
//      auto psystem = system();
//
//      double dMargin = psystem->m_dDpi;
//
//      if (ZONEING_COMPARE::is_equal(rectangle.top(), rectangleWorkspace.top(), dMargin, !(edisplayPrevious & e_display_top)))
//      {
//
//         edisplay |= e_display_top;
//
//         if (bPreserveSize)
//         {
//
//            rectangle.move_top_to(rectangleWorkspace.top());
//
//         }
//         else
//         {
//
//            rectangle.top() = rectangleWorkspace.top();
//
//         }
//
//      }
//      else if (ZONEING_COMPARE::is_equal(rectangle.bottom(), rectangleWorkspace.bottom(), dMargin, !(edisplayPrevious & e_display_bottom)))
//      {
//
//         edisplay |= e_display_bottom;
//
//         if (bPreserveSize)
//         {
//
//            rectangle.move_bottom_to(rectangleWorkspace.bottom());
//
//         }
//         else
//         {
//
//            rectangle.bottom() = rectangleWorkspace.bottom();
//
//         }
//
//      }
//
//      if (ZONEING_COMPARE::is_equal(rectangleRequest.left(), rectangleWorkspace.left(), dMargin, !(edisplayPrevious & e_display_left)))
//      {
//
//         edisplay |= e_display_left;
//
//         if (bPreserveSize)
//         {
//
//            rectangle.move_left_to(rectangleWorkspace.left());
//
//         }
//         else
//         {
//
//            rectangle.left() = rectangleWorkspace.left();
//
//         }
//
//      }
//      else if (ZONEING_COMPARE::is_equal(rectangleRequest.right(), rectangleWorkspace.right(), dMargin, !(edisplayPrevious & e_display_right)))
//      {
//
//         edisplay |= e_display_right;
//
//         if (bPreserveSize)
//         {
//
//            rectangle.move_right_to(rectangleWorkspace.right());
//
//         }
//         else
//         {
//
//            rectangle.right() = rectangleWorkspace.right();
//
//         }
//
//      }
//
//      if (!(edisplay & e_display_top || edisplay & e_display_bottom)
//         && is_different(edisplay & e_display_left, edisplay & e_display_right))
//      {
//
//         if (ZONEING_COMPARE::is_centered(rectangleWorkspace.top(), rectangle.top(), rectangle.bottom(), rectangleWorkspace.bottom()))
//         {
//
//            edisplay |= e_display_bottom;
//
//            edisplay |= e_display_top;
//
//            rectangle.bottom() = rectangleWorkspace.bottom();
//
//            rectangle.top() = rectangleWorkspace.top();
//
//         }
//
//      }
//
//      if (!(edisplay & e_display_left || edisplay & e_display_right)
//         && is_different(edisplay & e_display_top, edisplay & e_display_bottom))
//      {
//
//         if (ZONEING_COMPARE::is_centered(rectangleWorkspace.left(), rectangle.left(), rectangle.right(), rectangleWorkspace.right()))
//         {
//
//            edisplay |= e_display_left;
//
//            edisplay |= e_display_right;
//
//            rectangle.left() = rectangleWorkspace.left();
//
//            rectangle.right() = rectangleWorkspace.right();
//
//         }
//
//      }
//
//      bool bLeftXorRight = is_different(edisplay & e_display_left, edisplay & e_display_right);
//
//      bool bTopXorBottom = is_different(edisplay & e_display_top, edisplay & e_display_bottom);
//
//      bool bTopAndBottom = edisplay & e_display_top && edisplay & e_display_bottom;
//
//      bool bLeftAndRight = edisplay & e_display_left && edisplay & e_display_right;
//
//      if (bLeftXorRight && bTopXorBottom)
//      {
//
//      }
//      else if (bTopAndBottom && bLeftAndRight)
//      {
//
//         edisplay = e_display_zoomed;
//
//      }
//      else
//      {
//
//         if (bLeftXorRight && !bTopAndBottom)
//         {
//
//            edisplay = e_display_none;
//
//         }
//
//         if (bTopXorBottom && !bLeftAndRight)
//         {
//
//            edisplay = e_display_none;
//
//         }
//
//         if (bTopAndBottom)
//         {
//
//            edisplay -= e_display_top;
//
//            edisplay -= e_display_bottom;
//
//         }
//
//         if (bLeftAndRight)
//         {
//
//            edisplay -= e_display_left;
//
//            edisplay -= e_display_right;
//
//         }
//
//      }
//
//      if (edisplay == e_display_none)
//      {
//
//         edisplay = e_display_normal;
//
//      }
//
//      if (is_docking_appearance(edisplay))
//      {
//
//         *prectangle = rectangle;
//
//      }
//      else if (edisplay == e_display_zoomed)
//      {
//
//         *prectangle = rectangleWorkspace;
//
//      }
//      else
//      {
//
//         *prectangle = rectangleRequest;
//
//      }
//
//      if (pedisplay)
//      {
//
//         *pedisplay = edisplay;
//
//      }
//
//      //if (g_i_get_best_zoneing % 10 == 0)
//      //{
//
//      //   string strE("e");
//      //   if (edisplay & e_display_left)
//      //      strE += "L";
//      //   if (edisplay & e_display_top)
//      //      strE += "T";
//      //   if (edisplay & e_display_right)
//      //      strE += "R";
//      //   if (edisplay & e_display_bottom)
//      //      strE += "B";
//
//      //   string strP("p");
//      //   if (edisplayPrevious & e_display_left)
//      //      strP += "L";
//      //   if (edisplayPrevious & e_display_top)
//      //      strP += "T";
//      //   if (edisplayPrevious & e_display_right)
//      //      strP += "R";
//      //   if (edisplayPrevious & e_display_bottom)
//      //      strP += "B";
//
//      //   ::output_debug_string(
//      //      "w" + __string(rectangleWorkspace.left()) + ","
//      //      + __string(rectangleWorkspace.top()) + ","
//      //      + __string(rectangleWorkspace.right()) + ","
//      //      + __string(rectangleWorkspace.bottom()) + " " +
//      //      "r" + __string(prectangle->left()) + ","
//      //      + __string(prectangle->top()) + ","
//      //      + __string(prectangle->right()) + ","
//      //      + __string(prectangle->bottom()) + " " +
//      //      strE + " " + strP + "\n");
//
//      //}
//
//
//      //g_i_get_best_zoneing++;
//
//      //   rectangleWorkspace.left(),
//      //   rectangleWorkspace.top(),
//      //   rectangleWorkspace.right(),
//      //   rectangleWorkspace.bottom(),
//      //   (edisplay & e_display_left)?'L':' ',
//      //   (edisplay & e_display_top) ? 'T':' ',
//      //   (edisplay & e_display_right) ? 'R':' ',
//      //   (edisplay & e_display_bottom) ? 'B':' ',
//      //   (edisplayPrevious & e_display_left) ? 'L':' ',
//      //   (edisplayPrevious & e_display_top) ? 'T':' ',
//      //   (edisplayPrevious & e_display_right) ? 'R':' ',
//      //   (edisplayPrevious & e_display_bottom) ? 'B':' ');
//
//      return iBestWorkspace;
//
//   }
//
//
//   index display::get_best_monitor(::int_rectangle* prectangle, const int_rectangle& rectangleParam, const ::user::activation & useractivation)
//   {
//
//      index iMatchingMonitor = -1;
//
//      long long iBestArea = -1;
//
//      ::int_rectangle rectangleMatch;
//
//      ::int_rectangle rectangle(rectangleParam);
//
//      if (useractivation & ::user::e_activation_under_mouse_cursor || rectangle.is_null())
//      {
//
//         ::int_point pointCursor = m_pwindowing->get_cursor_position();
//
//         rectangle.set(pointCursor - ::int_size(5, 5), ::int_size(10, 10));
//
//      }
//
//      for (::collection::index iMonitor = 0; iMonitor < get_monitor_count(); iMonitor++)
//      {
//
//         ::int_rectangle rectangleIntersect;
//
//         ::int_rectangle rectangleMonitor;
//
//         if (get_monitor_rectangle(iMonitor, rectangleMonitor))
//         {
//
//            if (rectangleIntersect.top_left_null_intersect(rectangle, rectangleMonitor))
//            {
//
//               if (rectangleIntersect.area() > iBestArea)
//               {
//
//                  iMatchingMonitor = iMonitor;
//
//                  iBestArea = rectangleIntersect.area();
//
//                  rectangleMatch = rectangleMonitor;
//
//               }
//
//            }
//            else if (rectangleMonitor.contains(rectangle))
//            {
//
//               iMatchingMonitor = iMonitor;
//
//               rectangleMatch = rectangleMonitor;
//
//            }
//
//         }
//
//      }
//
//      if (iMatchingMonitor >= 0)
//      {
//
//         if (prectangle != nullptr)
//         {
//
//            *prectangle = rectangleMatch;
//
//         }
//
//         return iMatchingMonitor;
//
//      }
//
//      iMatchingMonitor = get_main_monitor(prectangle);
//
//      return iMatchingMonitor;
//
//   }
//
//
//   index display::get_best_workspace(::int_rectangle* prectangle, const int_rectangle& rectangleParam, const ::user::activation & useractivation)
//   {
//
//      index iMatchingWorkspace = -1;
//
//      long long iBestArea = -1;
//
//      ::int_rectangle rectangleMatch;
//
//      ::int_rectangle rectangle(rectangleParam);
//
//      if (useractivation & ::user::e_activation_under_mouse_cursor || rectangle.is_null())
//      {
//
//         ::int_point pointCursor = m_pwindowing->get_cursor_position();
//
//         rectangle.set(pointCursor - ::int_size(5, 5), ::int_size(10, 10));
//
//      }
//
//      for (::collection::index iWorkspace = 0; iWorkspace < get_workspace_count(); iWorkspace++)
//      {
//
//         ::int_rectangle rectangleIntersect;
//
//         ::int_rectangle rectangleMonitor;
//
//         if (get_workspace_rectangle(iWorkspace, rectangleMonitor))
//         {
//
//            if (rectangleIntersect.top_left_null_intersect(rectangle, rectangleMonitor))
//            {
//
//               if (rectangleIntersect.area() > iBestArea)
//               {
//
//                  iMatchingWorkspace = iWorkspace;
//
//                  iBestArea = rectangleIntersect.area();
//
//                  rectangleMatch = rectangleMonitor;
//
//               }
//
//            }
//            else if (rectangleMonitor.contains(rectangle))
//            {
//
//               iMatchingWorkspace = iWorkspace;
//
//               rectangleMatch = rectangleMonitor;
//
//            }
//
//         }
//
//      }
//
//      if (iMatchingWorkspace >= 0)
//      {
//
//         if (prectangle != nullptr)
//         {
//
//            *prectangle = rectangleMatch;
//
//         }
//
//         return iMatchingWorkspace;
//
//      }
//
//      iMatchingWorkspace = get_main_workspace(prectangle);
//
//      return iMatchingWorkspace;
//
//   }
//
//
//   index display::get_good_iconify(::int_rectangle* prectangle, const int_rectangle& rectangleParam)
//   {
//
//      ::int_rectangle rectangleMonitor;
//
//      index iMatchingMonitor = get_best_monitor(rectangleMonitor, rectangleParam);
//
//      prectangle->left() = rectangleMonitor.left();
//
//      prectangle->top() = rectangleMonitor.top();
//
//      prectangle->right() = rectangleMonitor.left();
//
//      prectangle->bottom() = rectangleMonitor.top();
//
//      return iMatchingMonitor;
//
//   }
//
//
//   index display::initial_frame_position(::int_rectangle* prectangle, const int_rectangle& rectangleParam, bool bMove, ::user::interaction* pinteraction)
//   {
//
//      ::int_rectangle rectangleRestore(rectangleParam);
//
//      ::int_rectangle rectangleMonitor;
//
//      index iMatchingMonitor = get_best_monitor(rectangleMonitor, rectangleParam);
//
//      ::int_size sizeMin;
//
//      if (pinteraction != nullptr)
//      {
//
//         sizeMin = pinteraction->get_window_minimum_size();
//
//      }
//      else
//      {
//
//         sizeMin = m_pwindowing->get_window_minimum_size();
//
//      }
//
//      ::int_rectangle rectangleIntersect;
//
//      if (bMove)
//      {
//
//         ::int_rectangle_array rectaMonitor;
//
//         ::int_rectangle_array rectaIntersect;
//
//         get_monitor(rectaMonitor, rectaIntersect, rectangleParam);
//
//         rectaIntersect.get_box(rectangleIntersect);
//
//      }
//      else
//      {
//
//         rectangleIntersect.intersect(rectangleMonitor, &rectangleParam);
//
//      }
//
//      auto sizeMax = rectangleMonitor.size() * 0.9;
//
//      if (rectangleIntersect.width() < sizeMin.cx || rectangleIntersect.height() < sizeMin.cy
//         || rectangleIntersect.width() > sizeMax.cx || rectangleIntersect.height() > sizeMax.cy)
//      {
//
//         if (rectangleMonitor.width() / 7 + maximum(sizeMin.cx, rectangleMonitor.width() * 2 / 5) > rectangleMonitor.width()
//            || rectangleMonitor.height() / 7 + maximum(sizeMin.cy, rectangleMonitor.height() * 2 / 5) > rectangleMonitor.width())
//         {
//
//            rectangleRestore = rectangleMonitor;
//
//         }
//         else
//         {
//
//            rectangleRestore.left() = rectangleMonitor.left() + rectangleMonitor.width() / 7;
//
//            rectangleRestore.top() = rectangleMonitor.top() + rectangleMonitor.height() / 7;
//
//            rectangleRestore.right() = rectangleRestore.left() + maximum(sizeMin.cx, rectangleMonitor.width() * 2 / 5);
//
//            rectangleRestore.bottom() = rectangleRestore.top() + maximum(sizeMin.cy, rectangleMonitor.height() * 2 / 5);
//
//            if (rectangleRestore.right() > rectangleMonitor.right() - rectangleMonitor.width() / 7)
//            {
//
//               rectangleRestore.offset(rectangleMonitor.right() - rectangleMonitor.width() / 7 - rectangleRestore.right(), 0);
//
//            }
//
//            if (rectangleRestore.bottom() > rectangleMonitor.bottom() - rectangleMonitor.height() / 7)
//            {
//
//               rectangleRestore.offset(0, rectangleMonitor.bottom() - rectangleMonitor.height() / 7 - rectangleRestore.bottom());
//
//            }
//
//         }
//
//         *prectangle = rectangleRestore;
//
//         return iMatchingMonitor;
//
//      }
//      else
//      {
//
//         if (!bMove)
//         {
//
//            *prectangle = rectangleIntersect;
//
//         }
//
//         return -1;
//
//      }
//
//   }
//
//
//   index display::get_good_restore(::int_rectangle* prectangle, const int_rectangle& rectangleHintParam, ::user::interaction* pinteraction, ::e_display edisplay)
//   {
//
//      ::int_rectangle rectangleHint(rectangleHintParam);
//
//      ::int_rectangle rectangleWorkspace;
//
//      ::int_size sizeMin;
//
//      ::int_size sizeBroad;
//
//      ::int_size sizeCompact;
//
//      ::int_size sizeNormal;
//
//      index iMatchingWorkspace;
//
//      if (pinteraction != nullptr)
//      {
//
//         auto iMonitor = pinteraction->get_preferred_restore(prectangle);
//
//         if (iMonitor >= 0)
//         {
//
//            return iMonitor;
//
//         }
//
//         sizeMin = pinteraction->get_window_minimum_size();
//
//         iMatchingWorkspace = pinteraction->calculate_broad_and_compact_restore(rectangleWorkspace, sizeMin, rectangleHint);
//
//         sizeBroad = pinteraction->m_sizeRestoreBroad;
//
//         sizeCompact = pinteraction->m_sizeRestoreCompact;
//
//         sizeNormal = pinteraction->layout().normal().m_size;
//
//         if (sizeNormal.is_empty())
//         {
//
//            sizeNormal = sizeMin.maximum(rectangleWorkspace.size() * 3 / 5);
//
//         }
//
//      }
//      else
//      {
//
//         sizeMin = m_pwindowing->get_window_minimum_size();
//
//         iMatchingWorkspace = get_best_workspace(&rectangleWorkspace, rectangleHint);
//
//         sizeBroad = sizeMin.maximum(rectangleWorkspace.size() * 4 / 5);
//
//         sizeCompact = sizeMin.maximum(rectangleWorkspace.size() * 2 / 5);
//
//         sizeNormal = sizeMin.maximum(rectangleWorkspace.size() * 3 / 5);
//
//      }
//
//      ::int_size sizeRestore;
//
//      if (edisplay == e_display_broad)
//      {
//
//         sizeRestore = sizeBroad;
//
//      }
//      else if (edisplay == e_display_compact)
//      {
//
//         sizeRestore = sizeCompact;
//
//      }
//      else
//      {
//
//         sizeRestore = sizeNormal;
//
//      }
//
//      ::int_rectangle rectangleRestore;
//
//      rectangleRestore.move_to(rectangleHint.top_left());
//
//      rectangleRestore.set_size(sizeRestore);
//
//      ::int_rectangle rectangleWorkspaceBitSmaller(rectangleWorkspace);
//
//      rectangleWorkspaceBitSmaller.deflate(5);
//
//      if (!rectangleWorkspaceBitSmaller.contains(rectangleRestore))
//      {
//
//         rectangleRestore.move_to(rectangleWorkspace.origin() + rectangleWorkspace.size() / 10);
//
//      }
//
//      *prectangle = rectangleRestore;
//
//      return iMatchingWorkspace;
//
//   }
//
//
//   index display::get_good_move(::int_rectangle* prectangle, const int_rectangle& rectangleParam, ::user::interaction* pinteraction)
//   {
//
//      index iMatchingMonitor = initial_frame_position(prectangle, rectangleParam, true, pinteraction);
//
//      if (__memcmp(prectangle, &rectangleParam, sizeof(const int_rectangle&)))
//      {
//
//         return iMatchingMonitor;
//
//      }
//      else
//      {
//
//         return -1;
//
//      }
//
//   }
//
//
//
//
//
//
//   index display::get_ui_workspace(::user::interaction* pinteraction)
//   {
//
//      if (m_bSystemSynchronizedScreen)
//      {
//
//         return get_ui_workspace(pinteraction);
//
//      }
//      else
//      {
//
//         ::int_rectangle rectangle;
//
//         rectangle = pinteraction->screen_rect();
//
//         return get_best_workspace(nullptr, rectangle);
//
//      }
//
//   }
//
//   string_array_base display::get_wallpaper()
//   {
//
//      
//
//      ::collection::count iMonitorCount = get_monitor_count();
//
//      string_array_base stra;
//
//      for (::collection::index iScreen = 0; iScreen < iMonitorCount; iScreen++)
//      {
//
//         stra.add(get_wallpaper(iScreen));
//
//      }
//
//      bool bAllEqual = true;
//
//      for (::collection::index iScreen = 1; iScreen < iMonitorCount; iScreen++)
//      {
//
//         if (stra[iScreen] != stra[iScreen - 1])
//         {
//
//            bAllEqual = false;
//
//         }
//
//      }
//
//      if (bAllEqual && stra.get_count() >= 2)
//      {
//
//         stra.set_size(1);
//
//      }
//
//      return stra;
//
//   }
//
//
//   void display::set_wallpaper(const string_array_base& straWallpaper)
//   {
//
//      if (straWallpaper.is_empty())
//      {
//
//         return;
//
//      }
//
//      
//
//      ::collection::count iMonitorCount = get_monitor_count();
//
//#ifdef LINUX
//
//      if (iMonitorCount > 0)
//      {
//
//         set_wallpaper(0, straWallpaper[0]);
//
//      }
//
//#else
//
//      for (::collection::index iScreen = 0; iScreen < iMonitorCount; iScreen++)
//      {
//
//         string strWallpaper = iScreen % straWallpaper;
//
//         set_wallpaper(iScreen, strWallpaper);
//
//      }
//
//#endif
//
//   }
//
//
//   string display::get_wallpaper(::collection::index iScreen)
//   {
//
//      return impl_get_wallpaper(iScreen);
//
//   }
//
//
//   string display::impl_get_wallpaper(::collection::index)
//   {
//
//      return "";
//
//   }
//
//   string display::os_get_user_theme()
//   {
//
//      return impl_get_os_desktop_theme();
//
//   }
//
//   string display::impl_get_os_desktop_theme()
//   {
//
//      return "";
//
//   }
//
//
//   bool display::set_os_desktop_theme(string strTheme)
//   {
//
//      return impl_set_os_desktop_theme(strTheme);
//
//   }
//
//
//   bool display::impl_set_os_desktop_theme(string strTheme)
//   {
//
//      return false;
//
//   }
//
//
//   // todo color:// gradient:// if the operating system doesn't have this, create the file, please.
//   bool display::impl_set_wallpaper(::collection::index, string strWallpaper)
//   {
//
//      //return "";
//      return false;
//
//   }
//
//   bool display::set_wallpaper(::collection::index iScreen, string strWallpaper)
//   {
//
//      //return "";
//      return impl_set_wallpaper(iScreen, strWallpaper);
//
//   }
//
//
//   void display::enable_wallpaper_change_notification()
//   {
//
//
//   }


} // namespace windowing_display




