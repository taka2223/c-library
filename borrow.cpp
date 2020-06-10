#include "borrow.h"
#include "ui_borrow.h"
#include<QMessageBox>

Borrow::Borrow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Borrow)
{
    ui->setupUi(this);
    opentTable();
}

Borrow::~Borrow()
{
    delete ui;
}
void Borrow::opentTable(){
    tabModel =new QSqlTableModel;//select the database
    tabModel->setTable("book");//select the book table
    tabModel->setSort(tabModel->fieldIndex("name"),Qt::AscendingOrder);//sort the data according to the name
    tabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//the changes on the model will not be saved unless submitAll()is called
    //set the horizontal header
    if(!(tabModel->select())){
        QMessageBox::information(this,"Error","open failed!");
    }
    tabModel->setHeaderData(tabModel->fieldIndex("name"),Qt::Horizontal,"Book Name");
    tabModel->setHeaderData(tabModel->fieldIndex("author_name"),Qt::Horizontal,"Author Name");
    tabModel->setHeaderData(tabModel->fieldIndex("number"),Qt::Horizontal,"Remained Number");
    tabModel->setHeaderData(tabModel->fieldIndex("ISBN"),Qt::Horizontal,"ISBN");
    tabModel->setHeaderData(tabModel->fieldIndex("type"),Qt::Horizontal,"Type of Book");
    ui->tableView->setEditTriggers(0);//0 maens can not be edited
    theSelcetion=new QItemSelectionModel(tabModel);//Constructs a selection model that operates on tabModel.

    ui->tableView->setModel(tabModel);//data model
    ui->tableView->setSelectionModel(theSelcetion);//selection model

   connect(theSelcetion,SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),this,SLOT(rowChange(QModelIndex,QModelIndex)));
}
void Borrow::rowChange(const QModelIndex &current, const QModelIndex &before){
    Q_UNUSED(before);
    ui->lab_book->setText("debug");
    QSqlRecord curRec=tabModel->record(current.row());
    QString test=curRec.value("name").toString();
    ui->lab_book->setText(curRec.value("name").toString());
    ui->lab_author->setText(curRec.value("author_name").toString());
    ui->lab_ISBN->setText(curRec.value("ISBN").toString());
}

void Borrow::on_Search_clicked()
{
    QString name=ui->led_search->text();
    QString input=QString("name LIKE '%%1%' OR author_name LIKE '%%2%'").arg(name).arg(name);//对书名或作者名的模糊搜索
    tabModel->setFilter(input);

}

void Borrow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    Q_UNUSED(previous);
       if(current->parent()!=NULL)
       {
           QString type=current->text(0);
           QString input=QString("type LIKE '%%1%' ").arg(type);
           tabModel->setFilter(input);
       }
}
