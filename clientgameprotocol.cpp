#include "clientgameprotocol.h"

ClientGameProtocol::ClientGameProtocol(QString userName, QObject *parent) : QObject(parent)
{
    this->userName = userName;
}

ClientGameProtocol::~ClientGameProtocol()
{

}

void ClientGameProtocol::setup()
{
    gameSocket = new QUdpSocket();
}

void ClientGameProtocol::connectGameServer(QString gameAddress, quint16 gamePort)
{

    //CLient connects to ready Game Server and sends its username to reserve a player seat

    gameSocket->connectToHost(gameAddress, gamePort);
    QByteArray message;
    message.append(userName + "|1||");
    sendMessage(message);

}

void ClientGameProtocol::disconnectGameServer()
{
    QByteArray message;
    message.append(userName + "|0||");
    sendMessage(message);
    gameSocket->disconnectFromHost();
}

void ClientGameProtocol::sendMessage(QByteArray message)
{
    gameSocket->write(message);
    while(!gameSocket->waitForBytesWritten(5000))
    {
        gameSocket->write(message);
    }
}
