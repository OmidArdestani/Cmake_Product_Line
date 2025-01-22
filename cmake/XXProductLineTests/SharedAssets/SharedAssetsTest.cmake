
list(APPEND HEADERS SharedAssets/tst_sharedassets.h)
list(APPEND SOURCES SharedAssets/tst_sharedassets.cpp)

# Link SharedAssets library
if(MSVC)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../SharedAssets/release/ -lSharedAssets)
    else()
        list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../SharedAssets/debug/ -lSharedAssets)
    endif()
else()
    list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../SharedAssets/ -lSharedAssets)
endif()

list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../SharedAssets)
list(APPEND Dependencies SharedAssets)
