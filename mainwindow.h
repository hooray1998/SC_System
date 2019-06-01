#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QRadioButton>
#include "student.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include<manage.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();
    void on_remitButton_clicked();

signals:
    void sendData(QString);
private:
    Ui::MainWindow *ui;
    student *f;
    manage *m;
};

#endif // MAINWINDOW_H
