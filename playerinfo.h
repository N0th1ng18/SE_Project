#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QObject>
#include <QString>

class PlayerInfo : public QObject
{
    Q_OBJECT

public:
    explicit PlayerInfo(QObject *parent = nullptr);

    QString getUsername();
    void setUsername(QString newName);
    QString getPassword();
    void setPassword(QString newPass);

signals:
    void usernameEdited();
    void passwordEdited();

public slots:
   PlayerInfo* sendPlayeInfo();
   void receiveUsername(QString item);
   void receivePassword(QString item);


private:
   QString m_name;
   QString m_pass;

};

#endif // PLAYERINFO_H
