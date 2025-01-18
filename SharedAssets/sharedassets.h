#pragma once

#include <QObject>
#include <functional>
#include <QJsonObject>


class IPLAsset{
public:
    virtual enableAsset(bool value) = 0;

    virtual QMap<QString, std::function<QJsonObject(QJsonObject)>> getAPIFunctionMap() = 0;
};


class SharedAssets
{
public:
    SharedAssets();
};

