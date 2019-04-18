#ifndef CLIENTPROTOCOL_H
#define CLIENTPROTOCOL_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>


class ClientProtocol : public QObject
{
    Q_OBJECT

public:

    ClientProtocol();

signals:
    void beginServer();


public slots:
    void forwardMsg();
    void sendUsername(QString name);
    void sendPassword(QString pass);
    void sendPlayerInfo(QString name, QString pass);
    bool connectToServer();

private:
    enum MSG_TYPE{USERLOGIN,
                 };
    QTcpSocket * m_socket;
};

#endif // CLIENTPROTOCOL_H
