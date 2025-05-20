cmake_minimum_required(VERSION 3.30)
project(Cask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Global include directories (optional)
include_directories(${CMAKE_SOURCE_DIR}/External)

# Add subdirectories
add_subdirectory(Engine/Core)
add_subdirectory(Engine/Platform)

# Add External subdirectories
add_subdirectory(External/EASTL)
#target_include_directories(Cask PRIVATE
#        External/EASTL/include
#)

add_executable(Cask
        Cask.h
        EntryPoint.h
        CaskContainer.h)

target_link_libraries(Cask
        PRIVATE
        EngineCore
        EnginePlatform
        EASTL
)
