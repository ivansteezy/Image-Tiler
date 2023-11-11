cmake_minimum_required(VERSION 3.10)

project(image-tiler VERSION 1.0 LANGUAGES C)

find_package(ImageMagick COMPONENTS MagickWand REQUIRED)
include_directories(${ImageMagick_INCLUDE_DIRS})
link_directories(${ImageMagick_LIBRARY_DIRS})

file(GLOB_RECURSE TLM_SOURCES
  src/*.c)

file(GLOB_RECURSE TLM_HEADERS
  include/*.h)

add_executable(${PROJECT_NAME} ${TLM_SOURCES} ${TLM_HEADERS})

target_link_libraries(${PROJECT_NAME} ${ImageMagick_LIBRARIES})
