#include "uniqueasset1.h"

UniqueAsset1::UniqueAsset1() {}

QJsonObject UniqueAsset1::runFeature(QJsonObject params)
{
    return QJsonObject{
        {"dateTime", QDateTime::currentDateTime().toString()},
        {"error", ""},
        {"loopback", params}
    };
}


void UniqueAsset1::enableAsset(bool value)
{
}

APIFunctionMap UniqueAsset1::getAPIFunctionMap()
{
    APIFunctionMap apiFunctionMap;

    apiFunctionMap.insert("runFeature", BIND_API_FUNC(&UniqueAsset1::runFeature));


    return apiFunctionMap;
}
