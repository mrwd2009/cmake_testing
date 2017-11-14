cmake_minimum_required(VERSION 3.8)
project(wolf)

set(CMAKE_CXX_STANDARD 17)

#version number
set(wolf_VERSION_MAJOR 1)
set(wolf_VERSION_MINOR 0)

set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/install")

set(SOURCE_FILES main.cpp)

configure_file(
        "${PROJECT_SOURCE_DIR}/wolf_config.h.in"
        "${PROJECT_BINARY_DIR}/wolf_config.h"
)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

include_directories("${PROJECT_BINARY_DIR}")
if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions1)
endif(USE_MYMATH)

add_executable(wolf ${SOURCE_FILES})
target_link_libraries(wolf ${EXTRA_LIBS})

install(TARGETS wolf DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/wolf_config.h" DESTINATION include)


include(CTest)

add_test(Test1 wolf 25)

add_test(Test2 wolf 25)
set_tests_properties(Test2 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")