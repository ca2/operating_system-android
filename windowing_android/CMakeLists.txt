cmake_minimum_required(VERSION 3.16)
project(windowing_android CXX)


list(APPEND library_source
        android/application_state.cpp
        android/application_state.h
        android/platform_platform_enumerate.cpp
        android/platform_platform_impact.cpp
        android/platform_platform_InputConnection.cpp
        android/platform_platform_main_activity.cpp
        _.cpp
        _.h
        _windowing_android.h
        _factory.cpp
        #directory_system.cpp
        #directory_system.h
        buffer.cpp
        buffer.h
        display.cpp
        display.h
        #console.cpp
        #console.h
        #console_ncurses.cpp
        #   directory_context.cpp
        #   directory_context.h
        #   directory_system.cpp
        #   directory_system.h
        #   file.cpp
        #   file.h
        #   file_context.cpp
        #   file_context.h
        #   file_system.cpp
        #   file_system.h
        framework.cpp
        framework.h
        #integration_context.cpp
        #integration_context.h
        monitor.cpp
        monitor.h
        #        node.cpp
        #        node.h
        #   node_unistd.cpp
        #stdio_file.cpp
        #stdio_file.h
        text_composition_client.cpp
        text_composition_client.h
        window.cpp
        window.h
        windowing.cpp
        windowing.h
)


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


#set_source_files_properties(console_ncurses.cpp PROPERTIES SKIP_PRECOMPILE_HEADERS ON)


list(APPEND library_references
        acme
        acme_posix
        acme_android
        acme_windowing_android
        apex
        apex_posix
        apex_android
        aura
        aura_posix
        aura_android

)


list(APPEND static_library_references ${library_references})
list(TRANSFORM static_library_references PREPEND static_)


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)


    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/IMPLIB:${LIBRARY_OUTPUT_PATH}/acme_linux.lib")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/acme_linux.def")
    target_link_libraries(${PROJECT_NAME} PRIVATE acme apex aqua aura Gdiplus)


elseif (${ANDROID})


    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_options(static_${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    target_compile_definitions(static_${PROJECT_NAME} PRIVATE CUBE)

    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references} log android jnigraphics)
    target_link_libraries(static_${PROJECT_NAME} PRIVATE ${static_library_references})

    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
    target_link_options(static_${PROJECT_NAME} PRIVATE --whole-archive)


endif ()


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)



