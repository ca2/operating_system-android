cmake_minimum_required(VERSION 3.17)
project(write_text_afont CXX)


list(APPEND library_source
        _.cpp
        _.h
        _factory.cpp
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



