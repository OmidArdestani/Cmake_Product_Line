cmake_minimum_required(VERSION 3.16)
project(UniqueAsset3)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the library target
add_library(UniqueAsset3 SHARED
    uniqueasset3.cpp
)

# Include headers
target_include_directories(UniqueAsset3 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets
)

# Add the define for the library
target_compile_definitions(UniqueAsset3 PRIVATE UNIQUEASSET3_LIBRARY)

# Link against SharedAssets library
target_link_libraries(UniqueAsset3 PUBLIC SharedAssets)


# Ensure SharedAssets is built before UniqueAsset3
add_dependencies(UniqueAsset3 SharedAssets)
