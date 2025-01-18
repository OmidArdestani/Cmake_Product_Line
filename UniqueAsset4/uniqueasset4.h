#pragma once

#include "UniqueAsset4_global.h"

#include <sharedassets.h>

class UNIQUEASSET4_EXPORT UniqueAsset4 : public IPLAsset
{
public:
    UniqueAsset4();

    // API Functions
private:
    QJsonObject runFeature(QJsonObject params);

    // IPLAsset interface
public:
    void enableAsset(bool value) override;
    APIFunctionMap getAPIFunctionMap() override;
};

