#include "mainwindow.h"
#include<QFile>
#include <QApplication>
#include<QtSql/QSqlDatabase>
#include<mysql.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Mysql sql;
    sql.iniDB();
    w.show();
    return a.exec();
}
