#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <globle.h>
#include <QtDebug>

namespace Ui {
class userlogin;
}

class userlogin : public QWidget
{
    Q_OBJECT

public:
    explicit userlogin(QWidget *parent = 0);
    ~userlogin();

private slots:

    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

private:
    Ui::userlogin *ui;
};

#endif // USERLOGIN_H
