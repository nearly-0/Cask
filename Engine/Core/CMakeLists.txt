cmake_minimum_required(VERSION 3.30)

project(EngineCore LANGUAGES CXX)

# Gather platform-agnostic code
file(GLOB_RECURSE CORE_SRC CONFIGURE_DEPENDS src/*cpp include/*.h)

# Create EngineCore library
add_library(EngineCore ${CORE_SRC})

target_include_directories(EngineCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})