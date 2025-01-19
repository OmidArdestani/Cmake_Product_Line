cmake_minimum_required(VERSION 3.16)
project(XXProductLineApplication)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 libraries
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets WebSockets Network)


message(STATUS "CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_DEFINITIONS: ${CMAKE_CXX_DEFINITIONS}")

# Set the current product
set(CURRENT_PRODUCT "Product_1")

# Handle the ProductLineAPI subdirectory
include(ProductLineAPI/ProductLineAPI.cmake)
include(ProductConfig.cmake)
include(ProductBuilder.cmake)

# Add the executable target
add_executable(XXProductLineApplication
    main.cpp
    mainwindow.cpp
    ${PRODUCT_LINE_API_SOURCES}
    ${PRODUCT_LINE_API_HEADERS}
    ${PRODUCT_BUILDER_HEADERS}
    ${PRODUCT_BUILDER_SOURCES}
)

# Apply the DEFINES to the target after it is defined
target_compile_definitions(XXProductLineApplication PRIVATE ${DEFINES})

# Link the required Qt6 libraries
target_link_libraries(XXProductLineApplication PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::WebSockets Qt6::Network)

# Include directories for headers
target_include_directories(XXProductLineApplication PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ProductLineAPI
)


# Optional installation rules
install(TARGETS XXProductLineApplication DESTINATION bin)
