cmake_minimum_required (VERSION 3.13)

project (debugError CXX)

cmake_policy(SET CMP0091 NEW)

find_package(azure-storage-blobs-cpp CONFIG REQUIRED)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_compile_options(
	$<$<CONFIG:>:/MT> #---------|
	$<$<CONFIG:Debug>:/MTd> #---|-- Statically link the runtime libraries
	$<$<CONFIG:Release>:/MT> #--|
)

add_executable(debugError debugError.cpp)

target_link_libraries(debugError PRIVATE Azure::azure-storage-blobs)
