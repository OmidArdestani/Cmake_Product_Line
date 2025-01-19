# Define the project and specify C++ standard
cmake_minimum_required(VERSION 3.16)
project(XXProductLineApplication)

set(CMAKE_CXX_STANDARD 17)

# Add the necessary Qt5 components
find_package(Qt5 REQUIRED COMPONENTS Test)

# Add sources for the test executable
set(SOURCES
    main.cpp
    ../SharedAssets/SharedAssetsTest.cpp
    ../UniqueAsset1/UniqueAsset1Test.cpp
    ../UniqueAsset2/UniqueAsset2Test.cpp
    ../UniqueAsset3/UniqueAsset3Test.cpp
    ../UniqueAsset4/UniqueAsset4Test.cpp
)

# Define the include directories for dependencies
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets
    ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset1
    ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset2
    ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset3
    ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset4
)

# Define the libraries to link
set(LIBRARIES
    SharedAssets
    UniqueAsset1
    UniqueAsset2
    UniqueAsset3
    UniqueAsset4
)

# Conditionally set the link directories based on build type (Release or Debug)
if(WIN32)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        link_directories(
            ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets/release
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset1/release
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset2/release
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset3/release
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset4/release
        )
    else()
        link_directories(
            ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets/debug
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset1/debug
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset2/debug
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset3/debug
            ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset4/debug
        )
    endif()
endif()

# Create the test executable target
add_executable(XXProductLineTests ${SOURCES})

# Link Qt5 Test and other required libraries to the target
target_link_libraries(XXProductLineTests Qt5::Test ${LIBRARIES})

# Enable testing with CTest
enable_testing()

# Add the test
add_test(NAME XXProductLineTests COMMAND XXProductLineTests)
