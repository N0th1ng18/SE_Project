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
    data = "Fuck You";
    QTcpSocket *tcpSocket = new QTcpSocket(parent);
    tcpSocket->connectToHost("192.168.1.109", 5555);
    tcpSocket->write(data);



}

void ClientProtocol::disconnectMainServer()
{
    qDebug() << "disconnectMainServer()";
}
