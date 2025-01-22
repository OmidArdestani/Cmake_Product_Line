
list(APPEND HEADERS UniqueAsset2/tst_uniqueasset2.h)
list(APPEND SOURCES UniqueAsset2/tst_uniqueasset2.cpp)

if(MSVC)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/release/ -lUniqueAsset2)
        list(APPEND ASSETS_LIB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/release/libUniqueAsset2.dll)
    else()
        list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/debug/ -lUniqueAsset2)
        list(APPEND ASSETS_LIB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/debug/libUniqueAsset2.dll)
    endif()
else()
    list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/ -lUniqueAsset2)
    list(APPEND ASSETS_LIB_PATH ${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/libUniqueAsset2.dll)
endif()

list(APPEND DEFINES -DUAsset2)
list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset2)
list(APPEND Dependencies UniqueAsset2)

