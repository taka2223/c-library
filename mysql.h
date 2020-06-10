#ifndef MYSQL_H
#define MYSQL_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QDebug>

class Mysql
{
public:
    Mysql();
    void iniDB();
    void createTab();
    bool createUser(QString,QString,QString,int);
    bool logUser(QString account,QString password);
};

#endif // MYSQL_H
