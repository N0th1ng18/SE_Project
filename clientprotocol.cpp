#include "clientprotocol.h"

ClientProtocol::ClientProtocol()
{
    //QByteArray data;
    //data = "Message";
    //tcpSocket->write(data);

}

ClientProtocol::~ClientProtocol()
{
    delete socket;
}


QTcpSocket* ClientProtocol::connectMainServer(QObject *parent)
{
    qDebug() << "connectMainServer()";
    socket = new QTcpSocket(parent);
    socket->connectToHost("192.168.1.3", 5555);

    if (!socket->waitForConnected(3000))
    {
        qDebug("Not Connected!");
        return nullptr;
    }

    return socket;
}

void ClientProtocol::disconnectMainServer()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(1000))
    {
        qDebug("Disconnected!");
    }
}
