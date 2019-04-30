#include "clientprotocol.h"

ClientProtocol::ClientProtocol()
{
    socket = nullptr;
    bufferList.clear();
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

int ClientProtocol::sendUserLogin(QString username, QString password){

    if(!isStringValid(username) || !isStringValid(password)){
        qDebug() << "Failed to send PlayerInfo: invalid string" << endl;
        return false;
    }

    QByteArray data;
    data.setNum(Msg::UserLogin);
    data.append('|' + username + '|' + password + "||");
    socket->write(data);
    socket->flush();

    if(socket->waitForReadyRead()){
        QString received = socket->readAll();
        bufferList.clear();
        bufferList = splitMessage(received);

        if(Msg(bufferList[0].toInt()) != UserLogin){
            qDebug()<< "User Login does not exist" << endl;
            return false;
        }else{
            if(bool(bufferList[1].toInt())){
                userGames = bufferList.mid(2);
                return userGames[0].toInt();
            }
            else {
                return false;
            }
        }
    }
    return 0;
}

bool ClientProtocol::sendCreateAccount(QString username, QString password){
    if(!isStringValid(username) || !isStringValid(password)){
        qDebug() << "Failed to send PlayerInfo: invalid string" << endl;
        return false;
    }

    QByteArray data;
    data.setNum(CreateAccount);
    data.append('|' + username + '|' + password + "||");
    socket->write(data);
    socket->flush();

    if(socket->waitForReadyRead()){
        QString received = socket->readAll();
        bufferList.clear();
         bufferList = splitMessage(received);
        if(Msg(bufferList[0].toInt()) != CreateAccount){
            return false;
        }else{
            return bool(bufferList[1].toInt());
        }
    }
    return true;
}

bool ClientProtocol::sendCreateGame(){
       QByteArray data;
       data.setNum(Msg::CreateGame);
       data.append("||");
       socket->write(data);
       socket->flush();

       if(socket->waitForReadyRead()){
           QString received = socket->readAll();
           bufferList.clear();
           bufferList = splitMessage(received);

           if (Msg(bufferList[0].toInt()) != CreateGame){
                return false;
           }else{
               if(!bool(bufferList[1].toInt())){
                    return false;
               }else{
                    qDebug() << bufferList[2] << ' ' << bufferList[3] <<' ' <<  bufferList[4] << endl;
               }
           }
       }
       return true;
}

int ClientProtocol::sendJoinGame(QString roomId){
    QByteArray data;
    data.setNum(Msg::JoinGame);
    data.append('|' + roomId + "||");
    socket->write(data);
    socket->flush();

    if(socket->waitForReadyRead()){
        QString received = socket->readAll();
        bufferList.clear();
        bufferList = splitMessage(received);
        if(Msg(bufferList[0].toInt()) != JoinGame)
            return false;
        else
            return  bufferList[1].toInt();
     }
    return false;
}

bool ClientProtocol::sendGetGameList(){
    QByteArray data;
    data.setNum(Msg::GameList);// Send username
    data.append("||");
    socket->write(data);
    socket->flush();

    if(socket->waitForBytesWritten()){
        socket->flush();
        QString received = socket->readAll();
        bufferList.clear();
        bufferList = received.split("|", QString::SkipEmptyParts);


        if(Msg(bufferList[0].toInt()) != GameList){
            return false;
        }else{
            int size = bufferList[1].toInt();
            for(int i = 0; i < size; i++){
                qDebug() << bufferList[i].toInt() << endl;
            }
        }
    }
    return true;
}

bool ClientProtocol::isStringValid(QString str){
    if(str.contains('|'))
        return false;
    if(str.contains('*'))
        return false;
    if(str.contains('.'))
        return false;
    if(str.contains('-'))
        return false;
    if(str == "")
        return false;

    return true;

}

QStringList ClientProtocol::splitMessage(QString message){
    message = message.section("||",0,0,QString::SectionSkipEmpty);
    return message.split('|', QString::SkipEmptyParts);
}

QString ClientProtocol::loginDataProcess(int index){
    return userGames[index+1];
}

QString ClientProtocol::showRoomCode(){
    return bufferList[4];
}
