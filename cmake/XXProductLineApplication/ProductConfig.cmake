# Ensure CURRENT_PRODUCT is defined
if(DEFINED CURRENT_PRODUCT)

    # Add configurations based on the CURRENT_PRODUCT value
    if(CURRENT_PRODUCT STREQUAL "Product_1")
        set(CONFIG UAsset1 UAsset2)

        add_definitions(-DProduct_1)

    elseif(CURRENT_PRODUCT STREQUAL "Product_2")
        set(CONFIG UAsset2 UAsset3)

        add_definitions(-DProduct_2)

    elseif(CURRENT_PRODUCT STREQUAL "Product_3")
        set(CONFIG UAsset2 UAsset3 UAsset4)

        add_definitions(-DProduct_3)

    elseif(CURRENT_PRODUCT STREQUAL "Product_4")
        set(CONFIG UAsset2 UAsset4)

        add_definitions(-DProduct_4)

    elseif(CURRENT_PRODUCT STREQUAL "Product_5")
        set(CONFIG UAsset1 UAsset3 UAsset4)

        add_definitions(-DProduct_5)

    else()
        message(FATAL_ERROR "Unknown product specified: ${CURRENT_PRODUCT}")
    endif()

else()
    message(FATAL_ERROR "CURRENT_PRODUCT is not defined")
endif()
