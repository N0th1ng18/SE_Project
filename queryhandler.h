#ifndef QUERYHANDLER_H
#define QUERYHANDLER_H

#include <QObject>
#include <QtSql>
#include "playerinfo.h"

class QueryHandler : public QObject
{
    Q_OBJECT
public:
    explicit QueryHandler(QObject *parent = nullptr);

signals:
    void querySuccessful();
    void queryFailed();


public slots:
   bool queryUsername(QString name);
   bool queryPassword(QString pass);


private:
    QSqlDatabase *m_DataBase;
};

#endif // QUERYHANDLER_H
