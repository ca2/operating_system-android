
message(STATUS "including operating_system/operating_system-android/_.cmake")

set(RELEASE_WITH_DEBUG FALSE)

if(${RELEASE_WITH_DEBUG})

if(CMAKE_BUILD_TYPE STREQUAL "Release")
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g")
   set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g")
endif()

endif()


if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Android")

   error("This file is designed to be used only for android systems...")

endif ()

#list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

message(STATUS "CMAKE_SYSTEM_NAME is ${CMAKE_SYSTEM_NAME}")

#FIND_PACKAGE(PkgConfig)

#include(FindPkgConfig)

#IF(PKG_CONFIG_FOUND)
# use pkg_check_modules()
#ENDIF(PKG_CONFIG_FOUND)
set(FREEBSD FALSE)
set(DEBIAN FALSE)
set(FEDORA FALSE)
set(UBUNTU FALSE)
set(MANJARO FALSE)
set(USE_PKGCONFIG TRUE)
set(CURL_NANO_HTTP TRUE)
set(HAS_WAYLAND TRUE)
set(HAS_X11 TRUE)
set(TOOL_RELEASE_NAME "linux")
set(MAIN_STORE_SLASHED_OPERATING_SYSTEM "linux")
set(OPERATING_SYSTEM_TOOL_FOLDER "tool-linux")


add_compile_definitions(TOOL_FOLDER_OPERATING_SYSTEM_NAME="${TOOL_RELEASE_NAME}")


#execute_process(COMMAND uname -m OUTPUT_VARIABLE __SYSTEM_ARCHITECTURE)
#string(STRIP ${__SYSTEM_ARCHITECTURE} __SYSTEM_ARCHITECTURE)
#message(STATUS "__SYSTEM_ARCHITECTURE is ${__SYSTEM_ARCHITECTURE}")


#execute_process(COMMAND lsb_release -is OUTPUT_VARIABLE __OPERATING_SYSTEM)
#string(STRIP ${__OPERATING_SYSTEM} __OPERATING_SYSTEM)
#string(TOLOWER ${__OPERATING_SYSTEM} __OPERATING_SYSTEM)
#message(STATUS "__OPERATING_SYSTEM is ${__OPERATING_SYSTEM}")


#set(APPLICATION_BUILD_HELPER_BINARY $ENV{HOME}/bin/application_build_helper)


if ("${CMAKE_BUILD_TYPE}" STREQUAL "")

   set(CMAKE_BUILD_TYPE Debug)

endif ()


#find_package(PkgConfig REQUIRED)

#if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#
#   message(STATUS "GNU Compiler")
#
#   string(APPEND CMAKE_CXX_FLAGS "-fPIC -fexceptions -fnon-call-exceptions -frtti")
#
#   #set(EXTRA_CXX_TARGET_COMPILER_OPTIONS "-ansi")
#
#else()
#
#   #set(EXTRA_CXX_TARGET_COMPILER_OPTIONS "")
#
#endif ()


set(DONT_USE_PKG_CONFIG NOT PKG_CONFIG_FOUND)



set(UNDERSCORE_OPERATING_SYSTEM $ENV{__SYSTEM_UNDERSCORE_OPERATING_SYSTEM})
set(SLASHED_OPERATING_SYSTEM $ENV{__SYSTEM_SLASHED_OPERATING_SYSTEM})
set(DISTRO $ENV{__SYSTEM_DISTRO})
set(DISTRO_RELEASE $ENV{__SYSTEM_DISTRO_RELEASE})


string(TOLOWER ${CMAKE_BUILD_TYPE} tolower_cmake_build_type)


message(STATUS "tolower_cmake_build_type = ${tolower_cmake_build_type}")


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
   set(CMAKE_CXX_EXTENSIONS OFF)
   add_compile_options(-fmax-errors=10)
endif()


if (${tolower_cmake_build_type} STREQUAL "debug")

   message(STATUS "Debug Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "relwithdebinfo")

   message(STATUS "RelWithDebInfo Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "release")

   message(STATUS "Release Build!!")

   add_compile_definitions(NDEBUG)

   message(STATUS "NDEBUG compile definition set!!")

elseif (${tolower_cmake_build_type} STREQUAL "minsizerel")

   message(STATUS "MinSizeRel Build!!")

   add_compile_definitions(NDEBUG)

   message(STATUS "NDEBUG compile definition set!!")

else ()

   message(STATUS "\"${CMAKE_BUILD_TYPE}\" Build!!")

   add_compile_definitions(DEBUG)

   message(STATUS "DEBUG compile definition set!!")

endif ()


SET(CMAKE_SKIP_BUILD_RPATH FALSE)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


set(LINUX TRUE)
set(FREEBSD FALSE)
set(OPERATING_SYSTEM_NAME "linux")
set(OPERATING_SYSTEM_POSIX TRUE)
set(FILE_SYSTEM_INOTIFY TRUE)
set(POSIX_SPAWN TRUE)
set(WITH_X11 TRUE)
set(WITH_XCB TRUE)
set(USE_OPENSSL TRUE)
set(PTHREAD TRUE)
set(PLATFORM_NAME "linux")


if (${CMAKE_SYSTEM_NAME} STREQUAL "Android")

   set(ANDROID TRUE)

   add_compile_definitions(__ANDROID__)

   message(STATUS "ANDROID has been set TRUE")
   message(STATUS "__ANDROID__ compile definition has been set")

   set(MPG123_PKG_MODULE "libmpg123")

   set(HAS_SYSTEM_UNAC TRUE)

else ()

   set(MPG123_PKG_MODULE "mpg123")

endif ()


set(MIDI TRUE)
set(ALSA_MIDI TRUE)
set(INTERPROCESS_COMMUNICATION_SYSTEM_5 TRUE)


link_libraries(pthread)
include(FindPkgConfig)


if (EXISTS $ENV{HOME}/__config/xfce.txt)

   set(LINUX_XFCE TRUE)
   message(STATUS "Adding Xfce/X11 dependency.")

endif ()


set(copy_libraries_dependency "")


set(default_draw2d "draw2d_cairo")
set(default_imaging "imaging_freeimage")
set(default_write_text "write_text_pango")
set(default_audio "audio_alsa")
set(default_input "input_libinput")
set(default_music_midi "music_midi_alsa")
set(default_node "node_linux")
set(default_audio_mixer "audio_mixer_alsa")
set(default_gpu "gpu_opengl")
set(default_networking "networking_bsd")
set(default_acme "acme_linux")
set(default_apex "apex_linux")
set(default_nano_graphics "nano_graphics_cairo")


set(default_draw2d "draw2d_cairo")


list(APPEND acme_libraries
   acme
   acme_posix
   acme_android)


list(APPEND static_acme_libraries
   static_acme
   static_acme_posix
   static_acme_android)


list(APPEND apex_libraries
   ${acme_libraries}
   apex
   apex_posix
   apex_android
)

list(APPEND aura_libraries
   ${apex_libraries}
   aura
   aura_posix
   aura_linux
   node_android
)


set(default_node node_android)

set(default_windowing windowing_android)

set(default_operating_ambient operating_ambient_android)

set(default_nano_graphics nano_graphics_cairo)




list(APPEND acme_windowing_libraries
   nano_graphics_cairo
   acme_windowing_android
)


list(APPEND innate_ui_libraries
   ${acme_windowing_libraries}
   innate_ui_android
)


list(APPEND operating_ambient_libraries
   ${innate_ui_libraries}
   ${default_windowing_common}
   ${default_windowing}
   ${default_node}
   ${default_operating_ambient}
)


list(APPEND app_common_dependencies
   ${aura_libraries}
   ${operating_ambient_libraries}
)






set(LIBCXX_TARGETING_MSVC OFF)


add_compile_definitions(UNICODE)
add_compile_definitions(_UNICODE)

list(APPEND app_common_dependencies ${default_node})

#list(APPEND app_common_dependencies _console_application_build_helper)


#set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/time-${OPERATING_SYSTEM_NAME}/x64/basis)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/output)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)


link_directories(${LIBRARY_OUTPUT_PATH})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis)


include_directories(${WORKSPACE_FOLDER})
include_directories($ENV{HOME}/__config)
include_directories(${WORKSPACE_FOLDER}/source)
include_directories(${WORKSPACE_FOLDER}/source/app)
include_directories(${WORKSPACE_FOLDER}/source/app/include)
include_directories(${WORKSPACE_FOLDER}/source/include)
include_directories(${WORKSPACE_FOLDER}/port/_)
if (NOT ${HAS_SYSTEM_UNAC})
   include_directories(${WORKSPACE_FOLDER}/port/base/unac/include)
endif ()
include_directories(${WORKSPACE_FOLDER}/port/include)
include_directories(${WORKSPACE_FOLDER}/operating_system)
if (OPERATING_SYSTEM_POSIX)
   include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix)
   include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-posix/include)
endif ()
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include)
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/include/configuration_selection/${CMAKE_BUILD_TYPE})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${SLASHED_OPERATING_SYSTEM})
include_directories(${WORKSPACE_FOLDER}/operating_system/operating_system-${OPERATING_SYSTEM_NAME}/operating_system/${DISTRO})

set(INCLUDE_DRAW2D_CAIRO TRUE)
set(INCLUDE_IMAGING_FREEIMAGE TRUE)


set(STORE_FOLDER $ENV{HOME}/store/${SLASHED_OPERATING_SYSTEM})




