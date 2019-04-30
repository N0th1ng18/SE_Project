#ifndef CLIENTGAMEPROTOCOL_H
#define CLIENTGAMEPROTOCOL_H

#include <QObject>
#include <QUdpSocket>
#include <QNetworkDatagram>

class ClientGameProtocol : public QObject
{
    Q_OBJECT
public:
    explicit ClientGameProtocol(QString userName, QObject *parent = nullptr);
    ~ClientGameProtocol();

    void connectGameServer(QString gameAddress, quint16 gamePort);
    void disconnectGameServer();
    void checkMessages();
    void processMessage(QNetworkDatagram datagram);
    void sendMessage(QList<QString> tokens, QHostAddress address, quint16 port);

signals:

public slots:
    void setup();

private:
    QUdpSocket *gameSocket;
    QString userName;

    QHostAddress gameAddress;
    quint16 gamePort;

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
