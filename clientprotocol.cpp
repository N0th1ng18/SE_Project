#include "clientprotocol.h"

ClientProtocol::ClientProtocol(QObject * parent, OpenGLWindow * gameView)
{
    //QByteArray data;
    //data = "Message";
    //tcpSocket->write(data);
    topLevel = parent;
    game = gameView;

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
    socket->connectToHost("192.168.1.2" , 5555);

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

bool ClientProtocol::sendUserLogin(QString username, QString password){

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
        qDebug() << "Received Message Back From UserLogin.";
        QStringList message = splitMessage(received);
        if(Msg(message[0].toInt()) != UserLogin){
            return false;
        }else{
            if(bool(message[1].toInt())){
                this->username = username;
                for(int j = message[2].toInt(); j < message.length(); j++){
                    qDebug() << message[j] << ' ';
                }
                qDebug() << endl;
            }else{
                return false;
            }
        }
    }
    return true;
}

bool ClientProtocol::sendCreateAccount(QString username, QString password){
    if(!isStringValid(username) || !isStringValid(password)){
        qDebug() << "Failed to send PlayerInfo: invalid string" << endl;
        return false;
    }

    QByteArray data;
    data.setNum(Msg::CreateAccount);
    data.append('|' + username + '|' + password + "||");
    socket->write(data);
    socket->flush();

    if(socket->waitForReadyRead()){
        QString received = socket->readAll();
        QStringList message = splitMessage(received);

        if(Msg(message[0].toInt()) != CreateAccount){
            return false;
        }else{
            return bool(message[1].toInt());
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
           QStringList message = splitMessage(received);
            qDebug() << message << endl;
           if (Msg(message[0].toInt()) != CreateGame){
                return false;
           }else{
               if(!bool(message[1].toInt())){
                    return false;
               }else{
                   //Create Game to connect to Server
                   if(game != nullptr)
                   {
                       qDebug() << "game!=nullptr";
                       //Delete Game Instance
                       game->~OpenGLWindow();
                   }
                   qDebug()<< "pre OpenGLWindow";
                   game = new OpenGLWindow(this->username, message[2], static_cast<quint16>(message[3].toInt()));
                   game->show();
                   qDebug() << "post OpenGLWindow";
               }
           }
       }
       return true;
}

bool ClientProtocol::sendJoinGame(int roomId){
    QByteArray data;
    data.setNum(Msg::JoinGame);
    data.append('|' + QString::number(roomId) + "||");
    socket->write(data);
    socket->flush();

    if(socket->waitForBytesWritten()){
        socket->flush();
        QString received = socket->readAll();
        QList<QString> messages = received.split("|", QString::SkipEmptyParts);


        if(socket->waitForReadyRead()){
            QString received = socket->readAll();
            QStringList message = splitMessage(received);

            if(Msg(message[0].toInt()) != JoinGame){
                if(message[1].toInt() == 0){
                    qDebug() << "Invalid room code" << endl;
                    return false;
                }else if(message[1].toInt() == 2){
                    qDebug() << "No server available" << endl;
                    return false;
                }else if(message[1].toInt() == 1){
                    qDebug() << message[2] << ' ' << message[3] << endl;

                }
            }
        }
    }
    return true;
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
        QList<QString> messages = received.split("|", QString::SkipEmptyParts);


        if(Msg(messages[0].toInt()) != Msg::GameList){
            return false;
        }else{
            int size = messages[1].toInt();
            for(int i = 0; i < size; i++){
                qDebug() << messages[i].toInt() << endl;
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

    return true;

}

QStringList ClientProtocol::splitMessage(QString message){
    //qDebug() << "SplitMessage: " << message;
    message = message.section("||",0,0,QString::SectionSkipEmpty);
    return message.split('|', QString::SkipEmptyParts);
}


