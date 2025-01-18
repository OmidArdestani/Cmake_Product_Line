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

public:
    void exceptionFunction();

    // IPLAsset interface
public:
    void enableAsset(bool value) override{ enable = value;}
    bool isEnable() const{return enable;}
    APIFunctionMap getAPIFunctionMap() override;

private:
    bool enable{false};
};

