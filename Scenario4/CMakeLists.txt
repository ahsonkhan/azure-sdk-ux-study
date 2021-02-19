cmake_minimum_required (VERSION 3.13)

project (longRunning CXX)

cmake_policy(SET CMP0091 NEW)

find_package(azure-storage-blobs-cpp CONFIG REQUIRED)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_compile_options(
	$<$<CONFIG:>:/MT> #---------|
	$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
	$<$<CONFIG:Release>:/MT> #--|
)

add_executable(longRunning longRunning.cpp)

target_link_libraries(longRunning PRIVATE Azure::azure-storage-blobs)
