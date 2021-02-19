cmake_minimum_required (VERSION 3.13)

project (uploadFile CXX)

cmake_policy(SET CMP0091 NEW)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_compile_options(
	$<$<CONFIG:>:/MT> #---------|
	$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
	$<$<CONFIG:Release>:/MT> #--|
)

add_executable(uploadFile uploadFile.cpp)
