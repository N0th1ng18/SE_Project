#ifndef CLIENTGAMEPROTOCOL_H
#define CLIENTGAMEPROTOCOL_H

#include <QObject>
#include <QUdpSocket>

class ClientGameProtocol : public QObject
{
    Q_OBJECT
public:
    explicit ClientGameProtocol(QString userName, QObject *parent = nullptr);
    ~ClientGameProtocol();

    void connectGameServer(QString gameAddress, quint16 gamePort);
    void disconnectGameServer();

signals:

public slots:
    void setup();

private:
    QUdpSocket *gameSocket;
    QString userName;

    void sendMessage(QByteArray message);
};

#endif // CLIENTGAMEPROTOCOL_H
