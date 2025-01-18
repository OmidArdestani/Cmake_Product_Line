#include "uniqueasset4.h"

UniqueAsset4::UniqueAsset4() {}

QJsonObject UniqueAsset4::runFeature(QJsonObject params)
{

}


void UniqueAsset4::enableAsset(bool value)
{
}

APIFunctionMap UniqueAsset4::getAPIFunctionMap()
{
    APIFunctionMap apiFunctionMap;

    apiFunctionMap.insert("runFeature", BIND_API_FUNC(&UniqueAsset4::runFeature));


    return apiFunctionMap;
}
