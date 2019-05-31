#include "userlogin.h"
#include "ui_userlogin.h"
#include "insertlogin.h"
#include "manger.h"
#include "deletelogin.h"
#include "updatelogin.h"
userlogin::userlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userlogin)
{
    ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_insertloginButton_clicked()
{
    QString id=ui->inster_IdlineEdit->text();
    QString username=ui->insert_namelineEdit_->text();
    QString password=ui->insert_passwordlineEdit->text();

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
    query.exec("select id from admin");
    bool T2=true;
    while(query.next())
    {
       QString id1= query.value(0).toString();


       if(id.compare(id1)==0)
       {

        QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
          T2=false;
       }
     }
    if(T2==true)
    {
         QString sql;
         sql = QString("insert into admin (id,username,password)"
                  " VALUES ('%1', '%2' , '%3' )")
            .arg(id).arg(username).arg(password);


        bool ok = query.exec(sql);
       if(ok)
       {

        QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
      }
      else
      {
        QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
      }
   }

}

void userlogin::on_login_updatepushButton_clicked()
{
    QString id=ui->login_update_IDlineEdit->text();
    QString username=ui->login_updatenamelineEdit->text();
    QString password=ui->update_loginpasswordlineEdit->text();

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
        query.exec("select id from admin");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("UPDATE admin "
                                     "set username = '%0',password = '%1'"
                                     " where id = '%2' ")
                               .arg(username).arg(password).arg(id);


                       QSqlQuery query;
                       bool ok = query.exec(sql);
                       if(ok)
                       {

                           QMessageBox::information(this ,tr("提示") , tr("更改成功!"));
                           T2=false;
                       }
                       else
                       {
                           QMessageBox::information(this ,tr("提示") , tr("更改失败!"));
                           T2=false;
                       }

                   }
                 }
    if(T2==true)
    {

       QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));


    }
}

void userlogin::on_login_deleteButton_clicked()
{
    QString id=ui->login_IDlineEdit->text();
    QString username=ui->login_deletename_lineEdit->text();
    QString password=ui->dele_login_passwordlineEdit->text();

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
        query.exec("select id from admin");
    bool T2=true;
    while(query.next())
               {
                   QString id1= query.value(0).toString();


                   if(id.compare(id1)==0)
                  {
                       QString sql;
                       sql = QString("DELETE FROM admin "
                                     " where id = '%1' ").arg(id);

                       QSqlQuery query;
                       bool ok = query.exec(sql);
                       if(ok)
                       {

                           QMessageBox::information(this ,tr("提示") , tr("删除成功!"));
                           T2=false;
                       }
                       else
                       {
                           QMessageBox::information(this ,tr("提示") , tr("删除失败!"));
                           T2=false;
                       }

                   }
                 }
    if(T2==true)
    {

       QMessageBox::information(this ,tr("提示") , tr("改编号不存在无法删除"));


    }
}

void userlogin::on_insertloginqueryButton_clicked()
{
    QString id=ui->inster_IdlineEdit->text();


    if(id.compare("")==0)
    QMessageBox::information(this, "警告", "请输入编号");

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


   query.exec("select username,password from admin where id='"+id+"'");

    if(query.next())
    {
       qDebug()<<"第一条数据为"<<query.value(0).toString();
        ui->insert_namelineEdit_->setText(query.value(0).toString());
        ui->insert_passwordlineEdit->setText(query.value(1).toString());


    }
    else
    {
           if(id.compare("")==0)
               return;

           else  QMessageBox::information(this, "警告", "不存在你所要查找的编号");
     }
}
