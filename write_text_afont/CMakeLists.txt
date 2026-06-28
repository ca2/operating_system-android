cmake_minimum_required(VERSION 3.17)
project(write_text_afont CXX)


<<<<<<< HEAD

=======
>>>>>>> origin/main
list(APPEND library_source
        _.cpp
        _.h
        _factory.cpp
<<<<<<< HEAD
   font_enumeration.cpp
   font_enumeration.h
   fonts.cpp
   fonts.h

        framework.cpp
        framework.h
   write_text.cpp
   write_text.h
   write_text_win32_gdi.cpp
   write_text_win32_gdi.h
)




add_library(write_text_win32 SHARED ${library_source})

target_precompile_headers(write_text_win32 PRIVATE framework.h)

set_target_properties(write_text_win32 PROPERTIES LINKER_LANGUAGE CXX)

if (MSVC)
    target_compile_options(write_text_win32 PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(write_text_win32 PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(write_text_win32 PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/write_text_win32.lib")
    target_link_options(write_text_win32 PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/write_text_win32.def")
    target_link_libraries(write_text_win32 PRIVATE acme apex aqua aura Gdiplus)
elseif(LINUX)

    if(NOT DONT_USE_PKG_CONFIG)
        #pkg_check_modules(PKGCONFIG glib-2.0 gtk+-3.0 gdk-3.0 appindicator-0.1)
        pkg_check_modules(PKGCONFIG glib-2.0 freetype2 gtk+-3.0 gdk-3.0)
    endif()
    target_compile_options(write_text_win32 PRIVATE ${PKGCONFIG_CFLAGS})
    #target_compile_options(write_text_win32 PRIVATE -std=c++14)
    #target_link_options(write_text_win32 PRIVATE ${GTK_LDFLAGS})
    target_link_options(write_text_win32 PRIVATE -Wl,-rpath=\$ORIGIN)
    target_link_libraries(write_text_win32 PRIVATE z dl pthread ncurses X11 Xrender Xinerama Xft ${PKGCONFIG_LIBRARIES})
    target_link_options(write_text_win32 PRIVATE -Wl,-z,defs)
    message("PKGCONFIG_LIBRARIES is " ${PKGCONFIG_LIBRARIES})
endif()

target_link_directories(write_text_win32 PRIVATE ${LIBRARY_OUTPUT_PATH})
target_link_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/library/x64/basis)
target_link_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/storage-${OPERATING_SYSTEM_NAME}/third/library/x64/basis)


##target_include_directories(write_text_win32 PRIVATE $HOME_AAA_DIR/__aaa_config)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/app/_include)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../source/include)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_NAME})
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/operating_system-${OPERATING_SYSTEM_NAME}/_include)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/third-${OPERATING_SYSTEM_NAME}/include)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/third-${OPERATING_SYSTEM_NAME}/third/include)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../operating_system/third-${OPERATING_SYSTEM_NAME}/third/include/include)
target_include_directories(write_text_win32 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)



=======
        font_enumeration.cpp
        font_enumeration.h
        fonts.cpp
        fonts.h
        framework.cpp
        framework.h
        write_text.cpp
        write_text.h
)


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


list(APPEND library_references
        acme
        acme_posix
        acme_android
        apex
        apex_posix
        apex_android
        aqua
        aura
        aura_posix
        aura_android
)


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (${ANDROID})

    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)

    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} dl)
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references} dl)

    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)

endif ()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)
>>>>>>> origin/main
