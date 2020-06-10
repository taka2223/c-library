#ifndef BORROW_H
#define BORROW_H

#include <QWidget>
#include<QDataWidgetMapper>
#include<QtSql/QSqlDatabase>
#include<QtSql>
#include<QtSql/QSqlQuery>
#include <QTreeWidgetItem>
namespace Ui {
class Borrow;
}

class Borrow : public QWidget
{
    Q_OBJECT

public:
    explicit Borrow(QWidget *parent = nullptr);
    ~Borrow();
    void opentTable();


private:
    Ui::Borrow *ui;
    QItemSelectionModel *theSelcetion;// selcetion model
    QSqlTableModel *tabModel;//data model
private slots:
    void rowChange(const QModelIndex &current, const QModelIndex &before);


    void on_Search_clicked();
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);
};

#endif // BORROW_H
