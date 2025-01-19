cmake_minimum_required(VERSION 3.16)
project(UniqueAsset1)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the library target as SHARED
add_library(UniqueAsset1 SHARED
    uniqueasset1.cpp
)

# Include headers
target_include_directories(UniqueAsset1 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets
)

# Add the define for the library
target_compile_definitions(UniqueAsset1 PRIVATE UNIQUEASSET1_LIBRARY)

# Link against SharedAssets library
target_link_libraries(UniqueAsset1 PUBLIC SharedAssets)

# Ensure SharedAssets is built before UniqueAsset1
add_dependencies(UniqueAsset1 SharedAssets)
