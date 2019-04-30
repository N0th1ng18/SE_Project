#include "clientgameprotocol.h"

ClientGameProtocol::ClientGameProtocol(QString userName, ClientState* clientState, QObject *parent) : QObject(parent)
{
    this->userName = userName;
    this->materials = nullptr;
    this->clientState = clientState;

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

    gameSocket->bind(QHostAddress::AnyIPv4, gamePort);

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
        qDebug() << "MESSAGE IN FROM GAME: " << tokens;


        //Reactive Server
        switch(tokens[0].toInt())
        {
        //case 0: //Drop Packet
        case server_connect:
        {
            qDebug() << "Connected Successfully To GameThread";
            break;
        }
        case server_disconnect:
        {
            //Go Back to QML
            break;
        }
        case server_lobby:
        {
            clientState->clear(); //Needs to remove players
            clientState->setState(tokens[0].toInt());
            clientState->setHasTurn(tokens[1].toInt());
            clientState->setMapID(tokens[2].toInt());
            clientState->setNumPlayers(tokens[3].toInt());

            for(int i=0; i < clientState->getNumPlayers(); i = i + 6)
            {
                //Add text for each player to gamestate -> then reset text
                Player* player = new Player(materials
                                            , 0
                                            , 0
                                            , tokens[i+4].toInt()
                                            , tokens[i+5].toUInt()
                                            , tokens[i+6].toInt()
                                            , new QVector3D(tokens[i+7].toFloat(), tokens[i+8].toFloat(), tokens[i+9].toFloat()));
                clientState->addPlayer(player);

                //Add buttons
                Button* b1 = new Button(materials, 0, 0, 10, 11, new QVector3D(1.0f, 0.0f, 0.0f));
                b1->setScale(new QVector3D(-0.6f, 0.6f, 0.6f));
                b1->setBounds(0.80f, 0.80f);
                clientState->addButton(b1);

            }
            qDebug() << "Lobby from server ------------------------------------------------------------------------------";
            break;
        }
        case server_game:
        {
            //update ClientState over time
            break;
        }
        case server_minigame:
        {
            //play mini game
            break;
        }

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

void ClientGameProtocol::setMaterials(Materials* materials)
{
    this->materials = materials;
}
