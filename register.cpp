#include "register.h"
#include "ui_register.h"
#include "mysql.h"
#include"QMessageBox"
Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
    ui->Confirm->setEchoMode(QLineEdit::Password);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    Mysql* sql=new Mysql;
    QString account=ui->account->text();
    QString name=ui->Name->text();
    QString password=ui->Password->text();
    QString confirm=ui->Confirm->text();
if(account==""||name==""||password==""||confirm==""){
    QMessageBox::information(this,"Error","The information can not be null");
}else if(password!=confirm){
    QMessageBox::information(this,"Error","The passwords you entered are not the same");
}
bool isReg;
if(ui->Admin->isChecked())
   isReg=sql->createUser(account,name,password,1);
else
   isReg=sql->createUser(account,name,password,0);
  if(isReg)
  {
      QMessageBox::information(this,"Success","Register success!");
      this->close();
  }else
  {
      QMessageBox::information(this,"Fail","The user has been registered");
      this->close();
  }

}
