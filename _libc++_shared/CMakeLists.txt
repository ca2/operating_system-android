cmake_minimum_required(VERSION 3.10.2)
project("lib_cpp_shared_loader")

# A minimal dummy library so CMake has something to compile
add_library(${PROJECT_NAME} SHARED dummy.cpp)

# (Optional) If you want to explicitly ensure it links, though the gradle argument handles it:
# find_library(log-lib log)
# target_link_libraries(dummy-lib ${log-lib})
