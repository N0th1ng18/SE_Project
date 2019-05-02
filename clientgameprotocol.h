#ifndef CLIENTGAMEPROTOCOL_H
#define CLIENTGAMEPROTOCOL_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include "clientstate.h"
#include "materials.h"
#include "player.h"

/*
 * Description: ClientGameProtocol communicates with the game thread
 *              through a udp socket. The Server State is converted
 *              to the client state.
 *
 * Author: Nick, Isaac
 *
 */

class ClientGameProtocol : public QObject
{
    Q_OBJECT
public:
    explicit ClientGameProtocol(QString userName, ClientState* clientState, QObject *parent = nullptr);
    ~ClientGameProtocol();

    void connectGameServer(QString gameAddress, quint16 gamePort);
    void disconnectGameServer();
    void checkMessages();
    void processMessage(QNetworkDatagram datagram);
    void sendMessage(QList<QString> tokens, QHostAddress address, quint16 port);
    void setMaterials(Materials* materials);

signals:

public slots:
    void setup();

private:
    QUdpSocket *gameSocket;
    QString userName;

    QHostAddress gameAddress;
    quint16 gamePort;

    ClientState* clientState;
    Materials* materials;

    enum clientMsg {
        client_connect = 1,
        client_disconnect,
        client_lobby,
        client_game,
        client_minigame
    };

    enum serverMsg {
        server_connect = 1,
        server_disconnect,
        server_lobby,
        server_game,
        server_minigame

    };

};

#endif // CLIENTGAMEPROTOCOL_H
