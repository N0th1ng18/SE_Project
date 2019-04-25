#include "clientprotocol.h"

ClientProtocol::ClientProtocol()
{
    //QByteArray data;
    //data = "Message";
    //tcpSocket->write(data);

}


QTcpSocket* ClientProtocol::connectMainServer(QObject *parent)
{
    qDebug() << "connectMainServer()";
    socket = new QTcpSocket(parent);
    socket->connectToHost("192.168.1.2", 5555);

    if (!socket->waitForConnected(3000))
    {
        qDebug("Not Connected!");
        return nullptr;
    }

    return socket;
}

void ClientProtocol::disconnectMainServer()
{
    socket->disconnectFromHost();
    if (socket->state() == QAbstractSocket::UnconnectedState || socket->waitForDisconnected(1000))
    {
        qDebug("Disconnected!");
    }
}

bool ClientProtocol::connectToServer(){
    qDebug() << "connectMainServer()";
    socket = new QTcpSocket(nullptr);
    socket->connectToHost(QHostAddress::LocalHost , 1234);

    if (!socket->waitForConnected(3000))
    {
        qDebug("Not Connected!");
        return false;
    }
    else{
        qDebug()<< "Connected to host" << endl;
        return true;
    }

}

void ClientProtocol::sendUserLogin(QString name, QString pass){
    QByteArray data;
    QString s;
    s = QString::number(Msg::UserLogin);
    s.append('|' + name + '|' + pass + "||");
    data.append(s);
    socket->write(data);

    qDebug() << "Sending UserLogin" << endl;
}

void ClientProtocol::sendCreateAccount(QString name, QString pass){

    QByteArray data;
    QString s;
    s = QString::number(Msg::CreateGame);
    s.append('|' + name + '|' + pass + "||");
    data.append(s);
    socket->write(data);
    socket->flush();
    qDebug() << "Sending CreateAccount" << endl;
}

void ClientProtocol::sendJoinGame(int roomId){
    QByteArray data;
    QString s;

    s = QString::number(Msg::JoinGame);
    data.setNum(roomId);
    s.append('|' + data);

    socket->write(data);

}
