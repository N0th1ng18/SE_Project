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

signals:

public slots:

private:
    QUdpSocket *gameSocket;
    QString userName;
    void setup();
    void connectGameServer(QString gameAddress, quint16 gamePort);
    void disconnectGameServer();
    void sendMessage(QByteArray message);
};

#endif // CLIENTGAMEPROTOCOL_H
