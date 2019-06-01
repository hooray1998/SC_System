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
    ui->tableWidget->hide();
    headers_info<<"学号"<<"姓名"<<"性别"<<"年龄"<<"专业"<<"登录密码";
    headers_course<<"已选课程"<<"教师"<<"学分";
    headers_grade<<"课程"<<"成绩"<<"绩点";
}

student::~student()
{
    delete ui;
}

void student::setID(QString Sno){
    id = Sno;
}

void student::on_backButton_clicked()
{
    MainWindow *h;
    this->hide();
    h=new MainWindow  ;
    h->show();
}

void student::on_infoButton_clicked()
{
    ui->label->hide();
    ui->tableWidget->show();
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(6);
    //ui->tableWidget->setHorizontalHeaderLabels(headers_info);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setVerticalHeaderLabels(headers_info);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery query;
    QString sql = QString("select * from S where Sno = '%1'").arg(id);
    query.exec(sql);

    if(query.next())
    {
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(1,0,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(2,0,new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(3,0,new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(4,0,new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(5,0,new QTableWidgetItem(query.value(5).toString()));
    }
    else{
        qDebug()<<"未找到该生的信息";
    }



}

void student::on_courseButton_clicked()
{
    ui->label->hide();
    ui->tableWidget->clear();
    ui->tableWidget->show();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(headers_course);
    ui->tableWidget->horizontalHeader()->show();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery query;
    QString sql = QString("select name,teacher,credit from C,SC where C.Cno=SC.Cno and SC.Sno = '%1'").arg(id);
    query.exec(sql);

    int row=0;
    while(query.next())
    {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(query.value(2).toString()));

        row++;
    }
}

void student::on_scoreButton_clicked()
{
    ui->label->hide();
    ui->tableWidget->clear();
    ui->tableWidget->show();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(headers_grade);
    ui->tableWidget->horizontalHeader()->show();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery query;
    QString sql = QString("select name,grade from C,SC where C.Cno=SC.Cno and SC.Sno = '%1'").arg(id);
    query.exec(sql);

    int row=0;
    while(query.next())
    {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(query.value(1).toFloat()/10-5)));

        row++;
    }
}
