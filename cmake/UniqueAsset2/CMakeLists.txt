cmake_minimum_required(VERSION 3.16)
project(UniqueAsset2)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the library target
add_library(UniqueAsset2 SHARED
    uniqueasset2.cpp
)

# Include headers
target_include_directories(UniqueAsset2 PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets
)

# Add the define for the library
target_compile_definitions(UniqueAsset2 PRIVATE UNIQUEASSET2_LIBRARY)

# Link against SharedAssets library
target_link_libraries(UniqueAsset2 PUBLIC SharedAssets)


# Ensure SharedAssets is built before UniqueAsset2
add_dependencies(UniqueAsset2 SharedAssets)
