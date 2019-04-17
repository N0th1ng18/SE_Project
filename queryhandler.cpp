#include "queryhandler.h"

QueryHandler::QueryHandler(QObject *parent) : QObject(parent)
{

}

bool QueryHandler::queryUsername(QString name){
    return false;
}

bool QueryHandler::queryPassword(QString pass){
    return false;
}
