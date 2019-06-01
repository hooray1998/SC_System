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
    void setID(QString Sno);

private slots:

    void on_backButton_clicked();
    void on_infoButton_clicked();
    void on_courseButton_clicked();
    void on_scoreButton_clicked();

private:
    Ui::student *ui;
    QString id;

    QStringList headers_info;
    QStringList headers_course;
    QStringList headers_grade;
};

#endif // STUDENTFORM_H
