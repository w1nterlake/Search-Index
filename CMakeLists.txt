cmake_minimum_required(VERSION 3.30)

project(search_engine)

set(gtest_disable_pthreads on)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)




enable_testing()





FetchContent_Declare(
  googletest
  URL "https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip"
)
FetchContent_MakeAvailable(googletest)




set(S "${CMAKE_SOURCE_DIR}/include")

set(L "${CMAKE_SOURCE_DIR}/src")

add_subdirectory(src)
add_subdirectory(include/json/json-develop)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)






