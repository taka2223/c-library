#ifndef FAILED_LOG_H
#define FAILED_LOG_H

#include <QDialog>
namespace Ui {
class failed_log;
}

class failed_log : public QDialog
{
    Q_OBJECT

public:
    explicit failed_log(QWidget *parent = nullptr);
    ~failed_log();

private:
    Ui::failed_log *ui;
};

#endif // FAILED_LOG_H
