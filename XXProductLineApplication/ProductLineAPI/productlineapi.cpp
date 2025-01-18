#include "productlineapi.h"

#include "../mainwindow.h"

ProductLineAPI::ProductLineAPI(MainWindow* parent)
    : QObject{parent}
    , webSocketsAPI(new WebSocketsAPI(this))
{}

QJsonObject ProductLineAPI::callFunction(QString functionName, QJsonObject params)
{
    qDebug() << Q_FUNC_INFO << functionName << params;

    return QJsonObject();
}

void ProductLineAPI::start()
{
    webSocketsAPI->startServer(1025);
}

void ProductLineAPI::stop()
{
    webSocketsAPI->stopServer();
}

QJsonObject ProductLineAPI::getInstance(QJsonObject)
{
    QJsonObject result{
        { "instanceId", QString::number(reinterpret_cast<quintptr>(productLineMainWindow)) },
        { "error", "" }
    };

    return result;
}
