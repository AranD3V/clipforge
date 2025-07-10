cmake_minimum_required(VERSION 3.14)
project(ClipForge)

set(CMAKE_CXX_STANDARD 17)

# Optional: Enable MSVC warnings
if (MSVC)
    add_compile_options(/W4 /permissive-)
endif()

# Source files
add_executable(MediaTool
    src/main.cpp
    src/cli_parser.h
    src/processor.h
)

# Include CLI parser
target_include_directories(ClipForge PRIVATE include)
