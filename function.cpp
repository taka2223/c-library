#include "function.h"
#include "ui_function.h"
#include "borrow.h"

Function::Function(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Function)
{
    ui->setupUi(this);
}

Function::~Function()
{
    delete ui;
}

void Function::on_Borrow_clicked()
{
    Borrow* borr=new Borrow;
    borr->show();
}
