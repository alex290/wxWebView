cmake_minimum_required(VERSION 3.20.0)
project(wxWeb VERSION 0.1.0)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

IF (WIN32)
  set(wxWidgets_ROOT_DIR "c:/wxwidgets/3.2.0")
  set(wxWidgets_LIB_DIR "c:/wxwidgets/3.2.0/lib/gcc_x64_dll")
ENDIF()

find_package(wxWidgets REQUIRED COMPONENTS net core base webview)
include(${wxWidgets_USE_FILE})


file(GLOB project
    src/*
)

add_executable(${PROJECT_NAME} ${project})

if(wxWidgets_FOUND)
    target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
    target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE_DIRS})
    message(STATUS "Found wxWidgets ${wxWidgets_VERSION_STRING}")
else()
    message(STATUS "wxWidgets Not Found")
endif()