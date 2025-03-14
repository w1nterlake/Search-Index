cmake_minimum_required(VERSION 3.30)

project(search_engine)



add_executable(search_engine 
main.cpp 
ConverterJSON.cpp 
InvertedIndex.cpp 
SearchServer.cpp
${S}/ConverterJSON.h
${S}/SearchServer.h
${S}/header.h
${S}/threadpool.h
${S}/InvertedIndex.h

)
#${CMAKE_SOURCE_DIR}/Test/test.h

add_executable(unit_tests ${CMAKE_SOURCE_DIR}/Test/test.cpp ${CMAKE_SOURCE_DIR}/Test/test.h InvertedIndex.cpp
        ${CMAKE_SOURCE_DIR}/Test/test_Search.h SearchServer.cpp)

target_include_directories(search_engine PUBLIC ${S})
target_include_directories(search_engine PUBLIC ${CMAKE_SOURCE_DIR}/Test)
target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
find_package(Threads REQUIRED)
# target_link_libraries(search_engine PRIVATE Threads::Threads)
target_link_libraries(search_engine PRIVATE gtest_main)
# Если MinGW действительно поддерживает -pthread
target_compile_options(search_engine PRIVATE -pthread)
target_link_libraries(search_engine PRIVATE -pthread)

target_include_directories(unit_tests PUBLIC ${S})
target_include_directories(unit_tests PUBLIC ${CMAKE_SOURCE_DIR}/Test)
target_link_libraries(unit_tests PRIVATE nlohmann_json::nlohmann_json)
# target_link_libraries(search_engine PRIVATE Threads::Threads)
target_link_libraries(unit_tests PRIVATE gtest_main)
# Если MinGW действительно поддерживает -pthread
target_compile_options(unit_tests PRIVATE -pthread)
target_link_libraries(unit_tests PRIVATE -pthread)

include(GoogleTest)
gtest_discover_tests(search_engine)

gtest_discover_tests(unit_tests)