#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QObject>
#include <QString>

class PlayerInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY usernameEdited)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY passwordEdited)
public:
    explicit PlayerInfo(QObject *parent = nullptr);

    QString getUsername();
    void setUsername(QString newName);
    QString getPassword();
    void setPassword(QString newPass);

signals:
    void sendUsername(QString item);
    void sendPassword(QString item);
    void usernameEdited();
    void passwordEdited();
   // void sendPlayerInfo(PlayerInfo* item);

public slots:
   void receiveUsername(QString item);
   void receivePassword(QString item);
   //void receivePlayerInfo(PlayerInfo* item);

private:
   QString m_name;
   QString m_pass;

};

#endif // PLAYERINFO_H
