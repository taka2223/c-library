#include "change_psw.h"
#include "ui_change_psw.h"
#include<QMessageBox>

Change_psw::Change_psw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Change_psw)
{
    ui->setupUi(this);
    ui->new_psw->setEchoMode(QLineEdit::Password);
    ui->confirm->setEchoMode(QLineEdit::Password);
}

Change_psw::~Change_psw()
{
    delete ui;
}

void Change_psw::on_pushButton_clicked()
{
    QString stu_ID=ui->stu_id->text();
    QString old_PSW=ui->old_psw->text();
    QString new_PSW=ui->new_psw->text();
    QString Confirm=ui->confirm->text();
    QSqlQuery* query=new QSqlQuery;
    QString str=QString("select * from user where identify= '%1' and password = '%2' ").arg(stu_ID).arg(old_PSW);
    if(query->exec(str))
    {
    if(new_PSW!=Confirm)
        QMessageBox::warning(this,"Error","The password input are not the same!");
    else {
        QString update=QString("update user set password = '%1' where identify ='%2' ").arg(new_PSW).arg(stu_ID);
        if(query->exec(update))
            QMessageBox::information(this,"success","Your password has changed");

    }
    }
    else QMessageBox::warning(this,"Error","Your ID and old password are not matched or the ID doesn't exist");


}
