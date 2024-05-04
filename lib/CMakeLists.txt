cmake_minimum_required(VERSION 3.8.2)
cmake_policy(SET CMP0048 NEW)
project(K-Editor-lib VERSION 6.3.0 LANGUAGES C CXX)

###########################
# Dependencies
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)


set(RESOURCES_FILE
    resources/qcodeeditor_resources.qrc
)

set(INCLUDE_FILES
    #shortcuts
    public/QHighlightRule
    public/QHighlightBlockRule
    public/QCodeEditor
    public/QFramedTextAttribute
    public/QLanguage
    public/QLineNumberArea
    public/QStyleSyntaxHighlighter
    public/QSyntaxStyle
    public/QCXXHighlighter
    public/QGLSLHighlighter
    public/QXMLHighlighter
    public/QJSONHighlighter
    public/QLuaHighlighter
    public/QPythonHighlighter
    public/QGLSLCompleter
    public/QLuaCompleter
    public/QPythonCompleter

    #public
    public/QHighlightRule.hpp
    public/QHighlightBlockRule.hpp
    public/QCodeEditor.hpp
    public/QFramedTextAttribute.hpp
    public/QLanguage.hpp
    public/QLineNumberArea.hpp
    public/QStyleSyntaxHighlighter.hpp
    public/QSyntaxStyle.hpp

    #public
    #highliters
    public/highlighters/QCXXHighlighter.hpp
    public/highlighters/QGLSLHighlighter.hpp
    public/highlighters/QXMLHighlighter.hpp
    public/highlighters/QJSONHighlighter.hpp
    public/highlighters/QLuaHighlighter.hpp
    public/highlighters/QPythonHighlighter.hpp

    #public
    #completers
    public/completers/QGLSLCompleter.hpp
    public/completers/QLuaCompleter.hpp
    public/completers/QPythonCompleter.hpp
)

set(SOURCE_FILES
    #src
    src/QCodeEditor.cpp
    src/QLineNumberArea.cpp
    src/QSyntaxStyle.cpp
    src/QStyleSyntaxHighlighter.cpp
    src/QLanguage.cpp
    src/QFramedTextAttribute.cpp

    #src
    #highlighters
    src/highlighters/QCXXHighlighter.cpp
    src/highlighters/QGLSLHighlighter.cpp
    src/highlighters/QLuaHighlighter.cpp
    src/highlighters/QPythonHighlighter.cpp
    src/highlighters/QXMLHighlighter.cpp
    src/highlighters/QJSONHighlighter.cpp

    #src
    #completers
    src/completers/QGLSLCompleter.cpp
    src/completers/QLuaCompleter.cpp
    src/completers/QPythonCompleter.cpp
)

add_library(${PROJECT_NAME} STATIC
    ${RESOURCES_FILE}
    ${SOURCE_FILES}
    ${INCLUDE_FILES}
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:
      public
      public/highlighters
      public/completers
     >
    $<BUILD_INTERFACE:
      ${CMAKE_CURRENT_SOURCE_DIR}/public
      ${CMAKE_CURRENT_SOURCE_DIR}/public/highlighters
      ${CMAKE_CURRENT_SOURCE_DIR}/public/completers
     >
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/controllers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/models
)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(${PROJECT_NAME}
        PRIVATE
        -pedantic
        -Wall
        -Wextra
        -Weffc++
        -Woverloaded-virtual
        -Winit-self
        -Wunreachable-code
    )
endif(CMAKE_COMPILER_IS_GNUCXX)

target_link_libraries(${PROJECT_NAME}
    Qt::Core
    Qt::Widgets
    Qt::Gui
)

target_compile_features(${PROJECT_NAME}
    PUBLIC
    cxx_std_17
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    AUTOMOC ON # Create code for QObjects
    AUTORCC ON # Create code from resource files
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

###########################
# Include tests
add_subdirectory(tests)
