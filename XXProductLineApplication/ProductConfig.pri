
# Ensure CURRENT_PRODUCT is defined
!isEmpty(CURRENT_PRODUCT) {

    # Add configurations based on the CURRENT_PRODUCT value
    equals(CURRENT_PRODUCT, "Product_1") {
        CONFIG += UAsset1
        CONFIG += UAsset2
    } else: equals(CURRENT_PRODUCT, "Product_2") {
        CONFIG += UAsset2
        CONFIG += UAsset3
    } else: equals(CURRENT_PRODUCT, "Product_3") {
        CONFIG += UAsset2
        CONFIG += UAsset3
        CONFIG += UAsset4
    } else: equals(CURRENT_PRODUCT, "Product_4") {
        CONFIG += UAsset2
        CONFIG += UAsset4
    } else: equals(CURRENT_PRODUCT, "Product_5") {
        CONFIG += UAsset1
        CONFIG += UAsset3
        CONFIG += UAsset4
    } else {
        error("Unknown product specified: $$CURRENT_PRODUCT")
    }

} else {
    error("CURRENT_PRODUCT is not defined")
}

