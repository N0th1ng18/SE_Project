#include "clientprotocol.h"
#include <QTcpServer>

ClientProtocol::ClientProtocol()
{

}

ClientProtocol::~ClientProtocol()
{

}


void ClientProtocol::connectMainServer(QObject *parent)
{
    qDebug() << "connectMainServer()";
    QByteArray data;
    data = "Hello World";
    QTcpSocket *tcpSocket = new QTcpSocket(parent);
    tcpSocket->connectToHost(QHostAddress::LocalHost, 1234);

    if(!tcpSocket->waitForConnected(5000)){
        qDebug() << "Failed to Connect to main server" << endl;
    }
    else{

        tcpSocket->write(data);
        tcpSocket->flush();
    }

}

void ClientProtocol::disconnectMainServer()
{
    /*
     * Socket->disconnectFromHost();
     * if socket->state() == Qabstractsocket::unnconnectedstate ||
     *  socket->waitfordisconnect(1000)){
     *      qDebug() << "Disconnected";
     * }

    */
    qDebug() << "disconnectMainServer()";
}
