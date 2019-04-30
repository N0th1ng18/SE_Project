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

    this->gameAddress = QHostAddress(gameAddress);
    this->gamePort = gamePort;

    gameSocket->bind(QHostAddress::AnyIPv4, gamePort, QUdpSocket::ShareAddress);
    gameSocket->joinMulticastGroup(this->gameAddress);

    //Send Connect message
    QList<QString> str;
    str.append("1");
    str.append(userName);
    sendMessage(str, this->gameAddress, this->gamePort);
}

void ClientGameProtocol::disconnectGameServer()
{
    QList<QString> str;
    str.append("2");
    sendMessage(str, this->gameAddress, this->gamePort);
    gameSocket->disconnectFromHost();
}


void ClientGameProtocol::checkMessages()
{
    while(gameSocket->hasPendingDatagrams())
    {
        QNetworkDatagram datagram = gameSocket->receiveDatagram();
        processMessage(datagram);
    }
}

void ClientGameProtocol::processMessage(QNetworkDatagram datagram)
{
    //Convert Datagram into QByteArray
    QByteArray data = datagram.data();
    //Convert QByteArray to QString
    QString str_Data = data;
    //Split message
    QList<QString> messages = str_Data.split("||", QString::SkipEmptyParts);

    //go through group of messages and process them
    for(int i=0; i < messages.size(); i++){

        QList<QString> tokens = messages[i].split("|", QString::SkipEmptyParts);
        qDebug() << tokens;


        //Reactive Server
        switch(tokens[0].toInt())
        {
        //case 0: //Drop Packet
        case server_connect:
            qDebug() << "Connected Successfully To GameThread";
            break;
        case server_disconnect:
            //Go Back to QML
            break;
        case server_lobby:
            //Render Lobby
            break;
        case server_game:
            //update ClientState over time
            break;
        case server_minigame:
            //play mini game
            break;

        }
    }
}

void ClientGameProtocol::sendMessage(QList<QString> tokens, QHostAddress address, quint16 port){
    QByteArray array;

    for(QString each: tokens)
    {
        array.append("|");
        array.append(each);
    }
    array.append("||");

    QNetworkDatagram datagram(array, address, port);
    gameSocket->writeDatagram(datagram);
    gameSocket->flush();
}
