#include "clientprotocol.h"


ClientProtocol::ClientProtocol(){

}


void ClientProtocol::forwardMsg(){
    QByteArray data;
   // data.setNum(type);
    m_socket->write(data);
    m_socket->flush();
}

void ClientProtocol::sendUsername(QString name){
    QByteArray data;
    data.append(name + '\n');
    m_socket->write(data);
    m_socket->flush();
}


void ClientProtocol::sendPassword(QString pass){
    QByteArray data;
    data.append(pass + '\n');
    m_socket->write(data);
    m_socket->flush();
}

void ClientProtocol::sendPlayerInfo(QString name, QString pass){
    QByteArray data;
    data.setNum(USERLOGIN);
    data.append('|' + name + '|' + pass);
    m_socket->write(data);
    m_socket->flush();
}


bool ClientProtocol::connectToServer()
{
    qDebug() << "connectMainServer()";
    m_socket= new QTcpSocket();
    m_socket->connectToHost(QHostAddress::LocalHost, 1234);

    if(!m_socket->waitForConnected(5000)){
        qDebug() << "Failed to Connect to main server" << endl;
        return false;

    }
    else{

        qDebug() << "Connected to main server" << endl;
        return true;

    }

}


