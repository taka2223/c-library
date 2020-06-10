#include "failed_log.h"
#include "ui_failed_log.h"

failed_log::failed_log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::failed_log)
{
    ui->setupUi(this);
}

failed_log::~failed_log()
{
    delete ui;
}
