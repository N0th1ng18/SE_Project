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
        CreateAccount,
        UserLogin,
        CreateGame,
        JoinGame,
        UserData
    };
    Q_OBJECT
public:
    ClientProtocol();
    QTcpSocket* connectMainServer(QObject *parent = nullptr);
    void disconnectMainServer();

public slots:
    bool connectToServer();
    void sendUserLogin(QString name, QString pass);
    void sendCreateAccount(QString name, QString pass);
    void sendJoinGame(int roomId);

private:
    QTcpSocket* socket = nullptr;

};

#endif // CLIENTPROTOCOL_H
