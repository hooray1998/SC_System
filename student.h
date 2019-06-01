#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class student;
}

class student : public QWidget
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = 0);
    ~student();

private slots:

    void on_backButton_clicked();

private:
    Ui::student *ui;
};

#endif // STUDENTFORM_H
