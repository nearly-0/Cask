cmake_minimum_required(VERSION 3.30)

project(EnginePlatform LANGUAGES CXX)

# Locate SDL3 via VCPKG
find_package(SDL3 CONFIG REQUIRED)

# Gather platform-agnostic code
file(GLOB_RECURSE PLATFORM_SRC CONFIGURE_DEPENDS
        src/*.cpp
        include/*.h)

# Create EnginePlatform library
add_library(EnginePlatform ${PLATFORM_SRC})
target_include_directories(EnginePlatform PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link SDL3
target_link_libraries(EnginePlatform PUBLIC SDL3::SDL3)

# Optional: Include platform-specific subdirectories
#if(WIN32)
#    add_subdirectory(Windows)
#    target_link_libraries(EnginePlatform PRIVATE EnginePlatformWindows)
#endif()

