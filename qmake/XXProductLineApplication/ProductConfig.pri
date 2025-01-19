
# Ensure CURRENT_PRODUCT is defined
!isEmpty(CURRENT_PRODUCT) {

    # Add configurations based on the CURRENT_PRODUCT value
    equals(CURRENT_PRODUCT, "Product_1") {

        CONFIG += UAsset1
        CONFIG += UAsset2

        DEFINES += Product_1

    } else: equals(CURRENT_PRODUCT, "Product_2") {

        CONFIG += UAsset2
        CONFIG += UAsset3

        DEFINES += Product_2

    } else: equals(CURRENT_PRODUCT, "Product_3") {

        CONFIG += UAsset2
        CONFIG += UAsset3
        CONFIG += UAsset4

        DEFINES += Product_3

    } else: equals(CURRENT_PRODUCT, "Product_4") {

        CONFIG += UAsset2
        CONFIG += UAsset4

        DEFINES += Product_4

    } else: equals(CURRENT_PRODUCT, "Product_5") {

        CONFIG += UAsset1
        CONFIG += UAsset3
        CONFIG += UAsset4

        DEFINES += Product_5

    } else {
        error("Unknown product specified: $$CURRENT_PRODUCT")
    }

} else {
    error("CURRENT_PRODUCT is not defined")
}

