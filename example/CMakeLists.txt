cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(K-Editor-example VERSION 6.6.0 LANGUAGES C CXX)


find_package(Qt6 COMPONENTS Core Gui Qml Quick QuickControls2 Widgets REQUIRED)

# Only used to make qml files accessible in VS
file(GLOB_RECURSE QML_SRC "*.qml")
source_group("Qml Files" FILES ${QML_SRC})

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/MainWindow.cpp
    include/MainWindow.hpp
    resources/demo_resources.qrc
    ${QML_SRC}
)

target_include_directories(${PROJECT_NAME}
   PUBLIC
    include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
      Qt6::Core
      Qt6::Gui
      Qt6::Qml
      Qt6::Quick
      Qt6::QuickControls2
      Qt6::Widgets
    K-Editor-lib
)

target_compile_features(${PROJECT_NAME}
  PUBLIC
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
