#ifndef STUINFORMANAGE_H
#define STUINFORMANAGE_H
#include <QWidget> 
namespace Ui {
class manage_student;
}

class manage_student : public QWidget
{
    Q_OBJECT

public:
    explicit manage_student(QWidget *parent = 0);
    ~manage_student();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();
private:
    Ui::manage_student *ui;
    QStringList headers;
};

#endif // STUINFORMANAGE_H
