#pragma once

#include "UniqueAsset3_global.h"

#include <sharedassets.h>

class UNIQUEASSET3_EXPORT UniqueAsset3 : public IPLAsset
{
public:
    UniqueAsset3();

    // API Functions
private:
    QJsonObject runFeature(QJsonObject params);

    // IPLAsset interface
public:
    void enableAsset(bool value) override;
    APIFunctionMap getAPIFunctionMap() override;
};

