cmake_minimum_required(VERSION 3.14)
project(BCD_library)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -g -m32 -O3)


set(SOURCES src/main.cpp
            src/BCD.h
            src/BCD.cpp
            src/BCD_add.cpp
            src/BCD_sub.cpp
            src/BCD_mul.cpp
            )

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include lib)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
add_library(${PROJECT_NAME}_lib ${SOURCES})


###Google Test
enable_testing()

include_directories(tests)
include_directories(src)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
FetchContent_MakeAvailable(googletest)

FetchContent_GetProperties(googletest)

include_directories(${googletest_SOURCE_DIR})
include_directories(${googletest_BINARY_DIR})

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

set(SOURCES_TST test/main.cpp
                test/BCD_add_tst.cpp
                test/BCD_sub_tst.cpp
                test/BCD_mul_tst.cpp
                )

add_executable(${PROJECT_NAME}_tst ${SOURCES_TST})

target_include_directories(${PROJECT_NAME}_tst PRIVATE include ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_tst PRIVATE include lib)
target_link_libraries(${PROJECT_NAME}_tst gtest_main)
target_link_libraries(${PROJECT_NAME}_tst ${PROJECT_NAME}_lib)

add_test(NAME ${PROJECT_NAME}_tst COMMAND ${PROJECT_NAME}_tst)

##Performance testing
set(SOURCES_PERF perf_test/main.cpp
                 )
add_executable(${PROJECT_NAME}_perf ${SOURCES_PERF})
target_include_directories(${PROJECT_NAME}_perf PRIVATE include ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}_perf PRIVATE include lib)
target_link_libraries(${PROJECT_NAME}_perf ${PROJECT_NAME}_lib)
