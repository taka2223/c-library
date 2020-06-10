#ifndef CHANGE_PSW_H
#define CHANGE_PSW_H

#include <QWidget>
#include<QtSql/QSqlQuery>

namespace Ui {
class Change_psw;
}

class Change_psw : public QWidget
{
    Q_OBJECT

public:
    explicit Change_psw(QWidget *parent = nullptr);
    ~Change_psw();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Change_psw *ui;
};

#endif // CHANGE_PSW_H
