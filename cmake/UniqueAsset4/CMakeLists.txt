cmake_minimum_required(VERSION 3.16)
project(UniqueAsset4)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the library target
add_library(UniqueAsset4 SHARED
    uniqueasset4.cpp
)

# Include headers
target_include_directories(UniqueAsset4 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets
)

# Add the define for the library
target_compile_definitions(UniqueAsset4 PRIVATE UNIQUEASSET4_LIBRARY)

# Link against SharedAssets library
target_link_libraries(UniqueAsset4 PUBLIC SharedAssets)


# Ensure SharedAssets is built before UniqueAsset4
add_dependencies(UniqueAsset4 SharedAssets)
