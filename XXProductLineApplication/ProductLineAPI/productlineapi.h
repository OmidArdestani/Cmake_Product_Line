#pragma once

#include "WebSocketsAPI.h"

#include <QObject>
#include <sharedassets.h>

class MainWindow;

class ProductLineAPI : public QObject
{
    Q_OBJECT
public:
    explicit ProductLineAPI(MainWindow* parent);

    QJsonObject callFunction(QString functionName, QJsonObject params);

    void start();
    void stop();

private:
    QJsonObject getInstance(QJsonObject);

private:
    MainWindow* productLineMainWindow {nullptr};
    WebSocketsAPI* webSocketsAPI;

    QMap<quint64, IPLAsset*> instanceMap;
};

