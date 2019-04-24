#ifndef CLIENTPROTOCOL_H
#define CLIENTPROTOCOL_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>


class ClientProtocol
{

public:
    ClientProtocol();
    ~ClientProtocol();
    QTcpSocket* connectMainServer(QObject *parent = nullptr);
    void disconnectMainServer();

private:
    QTcpSocket* socket = nullptr;

};

#endif // CLIENTPROTOCOL_H
