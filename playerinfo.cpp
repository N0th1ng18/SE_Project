#include "playerinfo.h"

PlayerInfo::PlayerInfo(QObject *parent) : QObject(parent)
{

}

QString PlayerInfo::getUsername(){
       return m_name;
}

void PlayerInfo::setUsername(QString newName){
    m_name = newName;
}

QString PlayerInfo::getPassword(){
    return m_pass;
}

void PlayerInfo::setPassword(QString newPass){
    m_pass = newPass;
}

void PlayerInfo::receiveUsername(QString item){
    m_name = item;
}

void PlayerInfo::receivePassword(QString item){
    m_pass = item;
}

PlayerInfo* PlayerInfo::sendPlayeInfo(){
    return this;
}
