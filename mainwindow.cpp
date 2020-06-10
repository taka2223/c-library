#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "mysql.h"
#include "register.h"
#include"function.h"
#include"change_psw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Log_clicked()
{
QString account=ui->accedit->text();
QString password=ui->pswedit->text();
Mysql sql;
if(sql.logUser(account,password)){
    Function* func=new Function;
    func->show();
    this->hide();
}
else QMessageBox::warning(this,"Error","The account or password is wrong!");
}

void MainWindow::on_register_2_clicked()
{
  Register* regist=new Register();
  regist->show();
}

void MainWindow::on_change_psw_clicked()
{
    Change_psw* change=new Change_psw;
    change->show();
}

void MainWindow::on_pswedit_textChanged(const QString &arg1)
{
    ui->pswedit->setEchoMode(QLineEdit::Password);
}
