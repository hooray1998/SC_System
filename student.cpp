#include "student.h"
#include "ui_student.h"
#include "mainwindow.h"
#include "globle.h"
#include  <QtDebug>
student::student(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);


}

student::~student()
{
    delete ui;
}

void student::on_backButton_clicked()
{
    MainWindow *h;
    this->hide();
    h=new MainWindow  ;
    h->show();
}
