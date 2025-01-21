# Define headers and sources
set(PRODUCT_BUILDER_HEADERS)
set(PRODUCT_BUILDER_SOURCES)

# Check for Product-specific configurations by verifying the macro definition
if(CURRENT_PRODUCT STREQUAL "Product_1")
    list(APPEND PRODUCT_BUILDER_HEADERS ProductBuilder/Product1Builder.h)
    list(APPEND PRODUCT_BUILDER_SOURCES ProductBuilder/Product1Builder.cpp)
endif()

if(CURRENT_PRODUCT STREQUAL "Product_2")
    list(APPEND PRODUCT_BUILDER_HEADERS ProductBuilder/Product2Builder.h)
    list(APPEND PRODUCT_BUILDER_SOURCES ProductBuilder/Product2Builder.cpp)
endif()

if(CURRENT_PRODUCT STREQUAL "Product_3")
    list(APPEND PRODUCT_BUILDER_HEADERS ProductBuilder/Product3Builder.h)
    list(APPEND PRODUCT_BUILDER_SOURCES ProductBuilder/Product3Builder.cpp)
endif()

if(CURRENT_PRODUCT STREQUAL "Product_4")
    list(APPEND PRODUCT_BUILDER_HEADERS ProductBuilder/Product4Builder.h)
    list(APPEND PRODUCT_BUILDER_SOURCES ProductBuilder/Product4Builder.cpp)
endif()

if(CURRENT_PRODUCT STREQUAL "Product_5")
    list(APPEND PRODUCT_BUILDER_HEADERS ProductBuilder/Product5Builder.h)
    list(APPEND PRODUCT_BUILDER_SOURCES ProductBuilder/Product5Builder.cpp)
endif()

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

# Include SharedAssets and UniqueAsset libraries based on configuration
foreach(ASSET IN LISTS CONFIG)
    if(${ASSET} MATCHES "UAsset1")
        if(MSVC)
            if(CMAKE_BUILD_TYPE STREQUAL "Release")
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/release/ -lUniqueAsset1)
            else()
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/debug/ -lUniqueAsset1)
            endif()
        else()
            list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset1/ -lUniqueAsset1)
        endif()

        list(APPEND DEFINES -DUAsset1)
        list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset1)
        list(APPEND Dependencies UniqueAsset1)
    elseif(${ASSET} MATCHES "UAsset2")
        if(MSVC)
            if(CMAKE_BUILD_TYPE STREQUAL "Release")
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/release/ -lUniqueAsset2)
            else()
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/debug/ -lUniqueAsset2)
            endif()
        else()
            list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset2/ -lUniqueAsset2)
        endif()

        list(APPEND DEFINES -DUAsset2)
        list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset2)
        list(APPEND Dependencies UniqueAsset2)
    elseif(${ASSET} MATCHES "UAsset3")
        if(MSVC)
            if(CMAKE_BUILD_TYPE STREQUAL "Release")
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset3/release/ -lUniqueAsset3)
            else()
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset3/debug/ -lUniqueAsset3)
            endif()
        else()
            list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset3/ -lUniqueAsset3)
        endif()

        list(APPEND DEFINES -DUAsset3)
        list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset3)
        list(APPEND Dependencies UniqueAsset3)
    elseif(${ASSET} MATCHES "UAsset4")
        if(MSVC)
            if(CMAKE_BUILD_TYPE STREQUAL "Release")
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset4/release/ -lUniqueAsset4)
            else()
                list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset4/debug/ -lUniqueAsset4)
            endif()
        else()
            list(APPEND LIBS -L${CMAKE_CURRENT_BINARY_DIR}/../UniqueAsset4/ -lUniqueAsset4)
        endif()

        list(APPEND DEFINES -DUAsset4)
        list(APPEND ASSETS_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../UniqueAsset4)
        list(APPEND Dependencies UniqueAsset4)
    endif()
endforeach()

