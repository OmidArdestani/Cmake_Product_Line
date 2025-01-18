#include "uniqueasset3.h"

UniqueAsset3::UniqueAsset3() {}

QJsonObject UniqueAsset3::runFeature(QJsonObject params)
{

}


void UniqueAsset3::enableAsset(bool value)
{
}

APIFunctionMap UniqueAsset3::getAPIFunctionMap()
{
    APIFunctionMap apiFunctionMap;

    apiFunctionMap.insert("runFeature", BIND_API_FUNC(&UniqueAsset3::runFeature));


    return apiFunctionMap;
}
