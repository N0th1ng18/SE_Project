#ifndef QUERYHANDLER_H
#define QUERYHANDLER_H

#include <QObject>
#include <QtSql>

class QueryHandler : public QObject
{
    Q_OBJECT
public:
    explicit QueryHandler(QObject *parent = nullptr);

signals:
    void querySuccessful();
    void queryFailed();


public slots:

private:
    QSqlDatabase *m_DataBase;
};

#endif // QUERYHANDLER_H
