cmake_minimum_required(VERSION 3.21)
project(untitled4)

add_library(shared SHARED library.cpp C_dll.cpp) # compile "C_dll.cpp" and create a SHARED library called "shared"
set(CMAKE_CXX_STANDARD 14)
add_executable(main library.cpp C_dll.cpp)

include (GenerateExportHeader)
GENERATE_EXPORT_HEADER(shared           # generates the export header shared_EXPORTS.h automatically
        BASE_NAME shared
        EXPORT_MACRO_NAME shared_EXPORTS
        EXPORT_FILE_NAME shared_EXPORTS.h
        STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC)
target_link_libraries(main shared)      # link our previously created shared library "shared" to the exectable "main"
