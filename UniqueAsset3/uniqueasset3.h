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

