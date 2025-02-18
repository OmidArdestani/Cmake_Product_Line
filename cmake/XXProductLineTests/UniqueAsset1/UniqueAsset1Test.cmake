
list(APPEND HEADERS UniqueAsset1/tst_uniqueasset1.h)
list(APPEND SOURCES UniqueAsset1/tst_uniqueasset1.cpp)

if(MSVC)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/release/ -lUniqueAsset1)
        list(APPEND ASSETS_LIB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/release/libUniqueAsset1.dll)
    else()
        list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/debug/ -lUniqueAsset1)
        list(APPEND ASSETS_LIB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/debug/libUniqueAsset1.dll)
    endif()
else()
    list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/ -lUniqueAsset1)
    list(APPEND ASSETS_LIB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/libUniqueAsset1.dll)
endif()

list(APPEND DEFINES -DUAsset1)
list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset1)
list(APPEND Dependencies UniqueAsset1)
