cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(ush C)

set(BUILD_SHARED_LIBS OFF)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(ush_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(ush_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(ush_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

set(ush_HDR ${ush_INC_DIR}/ush.h)
file(GLOB_RECURSE ush_HDRS ${ush_HDRS} ${ush_INC_DIR}/ush/*.h)
file(GLOB_RECURSE ush_SRCS ${ush_SRCS} ${ush_SRC_DIR}/*.c)
file(GLOB_RECURSE ush_SRCS ${ush_SRCS} ${ush_SRC_DIR}/*.h)

add_executable(ush ${ush_HDR} ${ush_HDRS} ${ush_SRCS})
set_property(TARGET ush PROPERTY C_STANDARD 90)
target_include_directories(ush PUBLIC ${ush_INC_DIR})
target_link_libraries(ush PUBLIC debug ft debug rl debug ps)

target_compile_definitions(ush
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
  target_compile_options(ush
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(ush
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()
