#pragma once

#include "UniqueAsset1_global.h"

#include <sharedassets.h>

class UNIQUEASSET1_EXPORT UniqueAsset1 : public IPLAsset
{
public:
    UniqueAsset1();

    // API Functions
private:
    QJsonObject runFeature(QJsonObject params);

    // IPLAsset interface
public:
    void enableAsset(bool value) override;
    APIFunctionMap getAPIFunctionMap() override;
};

