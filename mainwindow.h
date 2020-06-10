#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <failed_log.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Log_clicked();

    void on_register_2_clicked();

    void on_change_psw_clicked();

    void on_pswedit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
private:
    QDialog* log_failed;
};
#endif // MAINWINDOW_H
