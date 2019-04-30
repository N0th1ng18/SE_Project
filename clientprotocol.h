#ifndef CLIENTPROTOCOL_H
#define CLIENTPROTOCOL_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include<QTcpServer>
#include "openglwindow.h"



class ClientProtocol: public QObject
{

    enum Msg
    {
        BlackMessage,
        CreateAccount,
        UserLogin,
        CreateGame,
        JoinGame,
        GameList
    };

    enum GameListProcess{
        OnLogin = 1,
        OnRequest
    };

    Q_OBJECT
public:
    explicit ClientProtocol();
    QTcpSocket* connectMainServer(QObject *parent = nullptr);
    void disconnectMainServer();

public slots:
    bool connectToServer();
    int sendUserLogin(QString username, QString password);
    bool sendCreateAccount(QString username, QString password);
    bool sendCreateGame();
    int sendJoinGame(QString roomId);
    bool sendGetGameList();
    QString loginDataProcess(int index);
    QString showRoomCode();
    bool isStringValid(QString str);

private:
    //bool isStringValid(QString str);
    QStringList splitMessage(QString message);
    QTcpSocket* socket;
    QStringList bufferList;
    QStringList userGames;

};

#endif // CLIENTPROTOCOL_H
