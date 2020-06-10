#include "mysql.h"

Mysql::Mysql()
{

}
void Mysql::iniDB()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("zzx123456");
    db.setDatabaseName("info");
  if(!db.open()){
      qDebug()<<"Database connect failed!";
      EXIT_FAILURE;
  }
}
void Mysql::createTab(){
    QSqlQuery* query=new QSqlQuery;
    /*用户表*/
    query->exec("create table user(name VARCHAR(30) UNIQUE NOT NULL, password VARCHAR(30), type INT(1) UNIQUE NOT NULL, identify VARCHAR(30) PRIMARY KEY, book1 VARCHAR(30), book2 VARCHAR(30), book3 VARCHAR(30), book_number INT NOT NULL)");
    /*书籍表*/
    query->exec("create table book(name VARCHAR(30) UNIQUE NOT NULL, author_name VARCHAR(30), number INT(10), ISBN VARCHAR(30) PRIMARY KEY)");

}
bool Mysql::createUser(QString account, QString name, QString password, int type){
    QSqlQuery* query=new QSqlQuery;
    QString str=QString("insert into user(name,password,identify,book_number,type) value('%1','%2','%3',0,'%4');").arg(name).arg(password).arg(account).arg(type);
    bool ret=query->exec(str);
    return ret;
}
bool Mysql::logUser(QString account, QString password){
     QSqlQuery* query=new QSqlQuery;
     QString str=QString("select * from user where identify= '%1' and password = '%2' ").arg(account).arg(password);
     query->exec(str);
     query->last();
     int position=query->at()+1;
     if(position==0)
         return false;
     return true;
}
