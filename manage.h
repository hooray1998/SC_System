#ifndef MANGER_H
#define MANGER_H

#include <QWidget>

namespace Ui {
class manage;
}

class manage : public QWidget
{
    Q_OBJECT

public:
    explicit manage(QWidget *parent = 0);
    ~manage();

private slots:
    void on_pushButton_9_clicked();

    void on_manage_adminButton_clicked();

    void on_stu_inform_guanlipushButton_clicked();

    void on_manage_gradepushButton_clicked();

    void on_course_manageButton_clicked();


private:
    Ui::manage *ui;
};

#endif // MANGER_H
