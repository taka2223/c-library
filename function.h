#ifndef FUNCTION_H
#define FUNCTION_H

#include <QWidget>

namespace Ui {
class Function;
}

class Function : public QWidget
{
    Q_OBJECT

public:
    explicit Function(QWidget *parent = nullptr);
    ~Function();

private slots:
    void on_Borrow_clicked();

private:
    Ui::Function *ui;
};

#endif // FUNCTION_H
