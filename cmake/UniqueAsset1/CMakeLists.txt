cmake_minimum_required(VERSION 3.16)
project(UniqueAsset1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# Find Qt6/5 libraries
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets WebSockets Network)

# Define the library target as SHARED
add_library(UniqueAsset1 SHARED
    uniqueasset1.cpp
)

# Include headers
target_include_directories(UniqueAsset1 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets
)


# Link against SharedAssets library
target_link_libraries(UniqueAsset1 PUBLIC SharedAssets Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::WebSockets Qt${QT_VERSION_MAJOR}::Network)

# Ensure SharedAssets is built before UniqueAsset1
add_dependencies(UniqueAsset1 SharedAssets)

# Add the define for the library
target_compile_definitions(UniqueAsset1 PRIVATE UNIQUEASSET1_LIBRARY)

