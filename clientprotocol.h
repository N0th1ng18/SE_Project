#ifndef CLIENTPROTOCOL_H
#define CLIENTPROTOCOL_H

#include <QDebug>
#include <QObject>
#include <QTcpSocket>


class ClientProtocol : public QTcpSocket
{

public:
    ClientProtocol();
    ~ClientProtocol();
    static void connectMainServer(QObject *parent = nullptr);
    static void disconnectMainServer();

private:


};

#endif // CLIENTPROTOCOL_H
