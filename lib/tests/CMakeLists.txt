cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(K-Editor-test VERSION 6.6.0 LANGUAGES C CXX)

# Dependencies
find_package(Qt6 COMPONENTS Test REQUIRED)

add_executable(${PROJECT_NAME}
    # Tests
    src/TestFirst.hpp
    src/TestFirst.cpp

    src/TestSecond.hpp
    src/TestSecond.cpp

    # Necessary test runner classes
    src/TestRunner.hpp
    src/TestRunner.cpp
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    Qt6::Test
    K-Editor-lib
)

target_compile_features(${PROJECT_NAME}
  PRIVATE
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
