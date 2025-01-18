#pragma once

#include "UniqueAsset2_global.h"

#include <sharedassets.h>

class UNIQUEASSET2_EXPORT UniqueAsset2 : public IPLAsset
{
public:
    UniqueAsset2();

    // API Functions
private:
    QJsonObject runFeature(QJsonObject params);

    // IPLAsset interface
public:
    void enableAsset(bool value) override;
    APIFunctionMap getAPIFunctionMap() override;
};

