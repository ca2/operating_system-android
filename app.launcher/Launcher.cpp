/*
* Copyright (C) 2010 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

//
// pch.h
// Header for standard system include files.
// 
// Used by the build system to generate the precompiled header. Note that no 
// pch.cpp is needed and the pch.h is automatically included in all cpp files
// that are part of the project
//

#include "core/core/core/_.h"
#include "aura/aura/os/android/node_data_exchange.h"
#include "aura/user/user/interaction.h"
#include "aura/aura/app_core.h"
#include "_defer.h"
//#include "core/user/core_user.h"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "AndroidProject1.NativeActivity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "AndroidProject1.NativeActivity", __VA_ARGS__))

//extern "C"
//void lib_ANativeActivity_onCreate(ANativeActivity* activity, void* savedState, size_t savedStateSize);


/**
* Our saved state data.
*/
struct saved_state {
	float angle;
	int32_t x;
	int32_t y;
};


/**
* Initialize an EGL context for the current display.
*/
static int engine_init_display(oswindow window) {
	// initialize OpenGL ES and EGL


	return 0;
}

/**
* Just the current frame in the display.
*/
static void engine_draw_frame(oswindow window) {
	//if (window->m_engine.display == NULL) {
	//	// No display.
	//	return;
	//}

	oswindow_interaction(window)->_001UpdateWindow();

	// Just fill the screen with a color.
	//glClearColor(((float)window->m_engine.m_pstate->x) / window->m_engine.width, window->m_engine.m_pstate->angle,
	//	((float)window->m_engine.m_pstate->y) / window->m_engine.height, 1);
	//glClear(GL_COLOR_BUFFER_BIT);

	//eglSwapBuffers(window->m_engine.display, window->m_engine.surface);
}

/**
* Tear down the EGL context currently associated with the display.
*/
static void engine_term_display(oswindow window) {
	//if (window->m_engine.display != EGL_NO_DISPLAY) {
	//	eglMakeCurrent(window->m_engine.display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	//	if (window->m_engine.context != EGL_NO_CONTEXT) {
	//		eglDestroyContext(window->m_engine.display, window->m_engine.context);
	//	}
	//	if (window->m_engine.surface != EGL_NO_SURFACE) {
	//		eglDestroySurface(window->m_engine.display, window->m_engine.surface);
	//	}
	//	eglTerminate(window->m_engine.display);
	//}
	//window->m_engine.animating = 0;
	//window->m_engine.display = EGL_NO_DISPLAY;
	//window->m_engine.context = EGL_NO_CONTEXT;
	//window->m_engine.surface = EGL_NO_SURFACE;
}

/**
* Process the next input happening.
*/
//static int32_t engine_handle_input(struct android_app* app, AInputEvent* happening) {
//	oswindow window = (oswindow)app->userData;
//	if (AInputEvent_getType(happening) == AINPUT_EVENT_TYPE_MOTION) {
//		window->m_engine.m_pstate->x = AMotionEvent_getX(happening, 0);
//		window->m_engine.m_pstate->y = AMotionEvent_getY(happening, 0);
//		return 1;
//	}
//	return 0;
//}

/**
* Process the next main command.
*/
//static void engine_handle_cmd(struct android_app* app, int32_t cmd) {
//	oswindow window = (oswindow)app->userData;
//	switch (cmd) {
//	case APP_CMD_SAVE_STATE:
//		// The system has asked us to save our current state.  Do so.
//		window->m_engine.app->savedState = malloc(sizeof(struct saved_state));
//		*((struct saved_state*)window->m_engine.app->savedState) = *window->m_engine.m_pstate;
//		window->m_engine.app->savedStateSize = sizeof(struct saved_state);
//		break;
//	case APP_CMD_INIT_WINDOW:
//		// The window is being shown, get it ready.
//		if (window->m_engine.app->window != NULL) {
//			engine_init_display(window);
//			engine_draw_frame(window);
//		}
//		break;
//	case APP_CMD_TERM_WINDOW:
//		// The window is being hidden or closed, clean it up.
//		engine_term_display(window);
//		break;
//	case APP_CMD_GAINED_FOCUS:
//		// When our app gains focus, we start monitoring the accelerometer.
//		if (window->m_engine.accelerometerSensor != NULL) {
//			ASensorEventQueue_enableSensor(window->m_engine.sensorEventQueue,
//				window->m_engine.accelerometerSensor);
//			// We'd like to get 60 happenings per second (in us).
//			ASensorEventQueue_setEventRate(window->m_engine.sensorEventQueue,
//				window->m_engine.accelerometerSensor, (1000L / 60) * 1000);
//		}
//		break;
//	case APP_CMD_LOST_FOCUS:
//		// When our app loses focus, we stop monitoring the accelerometer.
//		// This is to avoid consuming battery while not being used.
//		if (window->m_engine.accelerometerSensor != NULL) {
//			ASensorEventQueue_disableSensor(window->m_engine.sensorEventQueue,
//				window->m_engine.accelerometerSensor);
//		}
//		// Also stop animating.
//		window->m_engine.animating = 0;
//		engine_draw_frame(window);
//		break;
//	}
//}
//
//
//extern unichar * g_pwszCommandLine;

/**
* This is the main entry int_point of a native application that is using
* android_native_app_glue.  It runs in its own thread, with its own
* happening loop for receiving input happenings and doing other things.
*/
//void native_activity_android_start(struct android_app* state) {
extern "C"
void native_activity_android_start(node_data_exchange * pinitdata)
{

	if (!defer_core_init())
	{

		return;

	}

	::core::system * psystem = ___new ::core::system();

	int32_t nReturnCode = 0;

	auto pmaindata = øallocate aura_main_data(pinitdata->m_pszCommandLine);

   if (pinitdata != NULL)
   {

		pmaindata->m_strCommandLine = pinitdata->m_pszCommandLine;

   }
   else
	{

		// pinitmaindata->m_vssCommandLine     = argv[0];
		pmaindata->m_strCommandLine = "app : app=app-core/hellomultiverse";

	}

	pmaindata->m_edisplay = display_default;

	psystem->m_pappcore->m_pmaindata = pmaindata;

	bool bOk = true;

	try
	{

		if (psystem->begin_synch())
		{

			bOk = true;

		}

	}
	catch (...)
	{

	}

   psystem->get_session()->m_puserinteractionHost = ___new ::user::interaction();

   ::user::native_window_initialize initialize;

   initialize.m_rectangle.left() = 0;
   initialize.m_rectangle.top() = 0;
   initialize.m_rectangle.right() = pinitdata->m_iScreenWidth;
   initialize.m_rectangle.bottom() = pinitdata->m_iScreenHeight;

	::user::system_struct createstruct;

	psystem->get_session()->m_puserinteractionHost->create_window_ex(createstruct);

   //::oswindow_data * pwindow = ___new oswindow_data;

   //oswindow window = pwindow;

   //psystem->m_possystemwindow->m_oswindow = pwindow;

	try
	{

		if (!bOk)
		{

			if (psystem->m_estatus == 0)
			{

				psystem->m_estatus = error_failed;

			}

			return;

		}


	}
	catch (...)
	{

		psystem->m_estatus = error_failed;

		return;

	}




	//engine & engine = pwindow->m_engine;

	//engine.m_pstate = ___new saved_state;

	//memset(&engine, 0, sizeof(engine));
	//state->userData = &engine;
	//state->onAppCmd = engine_handle_cmd;
	//state->onInputEvent = engine_handle_input;
	//engine.app = state;

	//// Prepare to monitor accelerometer
	//engine.sensorManager = ASensorManager_getInstance();
	//engine.accelerometerSensor = ASensorManager_getDefaultSensor(engine.sensorManager,
	//	ASENSOR_TYPE_ACCELEROMETER);
	//engine.sensorEventQueue = ASensorManager_createEventQueue(engine.sensorManager,
	//	state->looper, LOOPER_ID_USER, NULL, NULL);

	//if (state->savedState != NULL) {
	//	// We are starting with a previous saved state; restore from it.
	//	*engine.m_pstate = *(struct saved_state*)state->savedState;
	//}

	//engine.animating = 1;

	//psystem->main();

	// loop waiting for stuff to do.

	//while (1) {
	//	// Read all pending happenings.
	//	int ident;
	//	int happenings;
	//	struct android_poll_source* source;

	//	// If not animating, we will block forever waiting for happenings.
	//	// If animating, we loop until all happenings are read, then continue
	//	// to draw the next frame of animation.
	//	while ((ident = ALooper_pollAll(engine.animating ? 0 : -1, NULL, &happenings,
	//		(void**)&source)) >= 0) {

	//		// Process this happening.
	//		if (source != NULL) {
	//			source->process(state, source);
	//		}

	//		// If a sensor has data, process it now.
	//		if (ident == LOOPER_ID_USER) {
	//			if (engine.accelerometerSensor != NULL) {
	//				ASensorEvent happening;
	//				while (ASensorEventQueue_getEvents(engine.sensorEventQueue,
	//					&happening, 1) > 0) {
	//					LOGI("accelerometer: x=%f y=%f z=%f",
	//						happening.acceleration.x, happening.acceleration.y,
	//						happening.acceleration.z);
	//				}
	//			}
	//		}

	//		// Check if we are exiting.
	//		if (state->destroyRequested != 0) {
	//			engine_term_display(window);
	//			return;
	//		}
	//	}

	//	if (engine.animating) {
	//		// Done with happenings; draw next animation frame.
	//		engine.state.angle += .01f;
	//		if (engine.state.angle > 1) {
	//			engine.state.angle = 0;
	//		}

	//		// Drawing is throttled to the screen update rate, so there
	//		// is no need to do timing here.
	//		engine_draw_frame(window);
	//	}
	//}

	//defer_core_term();

}


//class native_activity_static_init
//{
//public:
//
//	native_activity_static_init()
//	{
//		g_android_main = native_activity_android_start;
//	}
//	~native_activity_static_init()
//	{
//	}
//
//} g_native_activity_static_init;



//void ANativeActivity_onCreate(ANativeActivity* activity,
//	void* savedState, size_t savedStateSize)
//{
//	//lib_ANativeActivity_onCreate(activity, savedState, savedStateSize);
//
//}
