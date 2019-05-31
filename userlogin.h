#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QWidget>

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

    void on_insertloginButton_clicked();
    void on_login_updatepushButton_clicked();
    void on_login_deleteButton_clicked();
    void on_insertloginqueryButton_clicked();

private:
    Ui::userlogin *ui;
};

#endif // USERLOGIN_H
