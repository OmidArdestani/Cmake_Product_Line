cmake_minimum_required(VERSION 3.16)
project(SharedAssets)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the library target
add_library(SharedAssets STATIC
    sharedassets.cpp
)

# Include headers
target_include_directories(SharedAssets PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Remove GUI module since it's excluded in the qmake file
find_package(Qt6 REQUIRED COMPONENTS Core) # Adjust to Qt5 if you're using it
target_link_libraries(SharedAssets PUBLIC Qt6::Core)

