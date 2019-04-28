#ifndef CLIENTPROTOCOL_H
#define CLIENTPROTOCOL_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QTcpSocket>
#include<QTcpServer>


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

    Q_OBJECT
public:
    ClientProtocol();
    QTcpSocket* connectMainServer(QObject *parent = nullptr);
    void disconnectMainServer();

public slots:
    bool connectToServer();
    bool sendUserLogin(QString username, QString password);
    bool sendCreateAccount(QString username, QString password);
    bool sendCreateGame();
    bool sendJoinGame(int roomId);
    bool sendGetGameList();


private:
    bool isStringValid(QString str);
    QStringList &splitMessage(QString message);
    QTcpSocket* socket = nullptr;

};

#endif // CLIENTPROTOCOL_H
