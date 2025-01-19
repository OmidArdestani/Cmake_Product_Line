#include "WebSocketsAPI.h"
#include <QDebug>

#include "productlineapi.h"

WebSocketsAPI::WebSocketsAPI(ProductLineAPI *parent)
    : QObject{parent}
    , productLineAPI(parent)
    , server(new QWebSocketServer("WebSockets API Server", QWebSocketServer::NonSecureMode, this))
{
}

WebSocketsAPI::~WebSocketsAPI()
{
    stopServer();
}

bool WebSocketsAPI::startServer(quint16 port)
{
    if (server->listen(QHostAddress::Any, port))
    {
        connect(server, &QWebSocketServer::newConnection, this, &WebSocketsAPI::onNewConnection, Qt::UniqueConnection);

        qDebug() << "WebSocket server started on port" << port;
        return true;
    }
    else
    {
        qWarning() << "Failed to start WebSocket server on port" << port;
        return false;
    }
}

void WebSocketsAPI::stopServer()
{
    foreach (QWebSocket *client, clients)
    {
        client->close();
    }
    server->close();

    qDebug() << "WebSocket server stopped.";
}

void WebSocketsAPI::onNewConnection()
{
    QWebSocket *client = server->nextPendingConnection();
    clients.append(client);

    connect(client, &QWebSocket::textMessageReceived, this, &WebSocketsAPI::onTextMessageReceived);
    connect(client, &QWebSocket::disconnected, this, &WebSocketsAPI::onClientDisconnected);

    qDebug() << "New client connected:" << client->peerAddress().toString();
}

void WebSocketsAPI::onTextMessageReceived(const QString &message)
{
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    if (client)
    {
        processRequest(client, message);
    }
}

void WebSocketsAPI::onClientDisconnected()
{
    QWebSocket *client = qobject_cast<QWebSocket *>(sender());
    if (client)
    {
        clients.removeAll(client);
        client->deleteLater();
        qDebug() << "Client disconnected.";
    }
}

void WebSocketsAPI::processRequest(QWebSocket *client, const QString &request)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(request.toUtf8());
    if (!jsonDoc.isObject())
    {
        sendResponse(client, QJsonObject{{"result", QJsonValue()}, {"error", "Invalid JSON format"}});
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QString instanceId = jsonObj.value("instanceId").toString();
    QString method     = jsonObj.value("method").toString();
    QJsonObject params = jsonObj.value("params").toObject();

    if (method.isEmpty() || instanceId.isEmpty())
    {
        sendResponse(client, QJsonObject{{"result", QJsonValue()}, {"error", "Method name is missing"}});
        return;
    }

    // Handle different methods
    QJsonObject result = productLineAPI->callFunction(instanceId.toULongLong(), method, params);
    sendResponse(client, result);
}

void WebSocketsAPI::sendResponse(QWebSocket *client, const QJsonObject &response)
{
    QJsonDocument responseDoc(response);
    client->sendTextMessage(responseDoc.toJson(QJsonDocument::Compact));
}
