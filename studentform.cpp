#include "studentform.h"
#include "ui_studentform.h"
#include "mainwindow.h"
#include "globle.h"
#include  <QtDebug>
studentForm::studentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::studentForm)
{
    ui->setupUi(this);


}

studentForm::~studentForm()
{
    delete ui;
}



void studentForm::on_pushButton_clicked()
{
    MainWindow *h;
    this->hide();
    h=new MainWindow  ;

    h->show();
}

void studentForm::on_pushButton_3_clicked()
{

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    db = QSqlDatabase::database("qt_sql_default_connection");
    else
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("studentmanager");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if (!db.open())
    qDebug() << "Failed to connect to root mysql admin";
     else qDebug() << "open";


    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF8'");
    query.exec("select id,name,sex,age,major,banji,address,phonenumber,beizhu from student");

    while(query.next())
               {
                   QStringList q;
                   q.clear();
                  QString id = query.value(0).toString();
                   QString user = query.value(1).toString();
                   QString pass = query.value(2).toString();
                   QString sex =query.value(3).toString();
                   QString age=query.value(4).toString();
                   QString major=query.value(5).toString();
                   QString banji=query.value(6).toString();
                   QString address=query.value(7).toString();
                     QString phonenumber=query.value(8).toString();
                      QString beizhu=query.value(9).toString();
                      q<<id<<user<<pass<<sex<<age<<major<<banji<<address<<phonenumber<<beizhu;
                      list_all_student.append(q);




              }


      for(int i=0;i<list_all_student.size();i++){
          qDebug()<<list_all_student[i];

      }


}
