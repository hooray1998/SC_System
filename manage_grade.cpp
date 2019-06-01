#include "manage_grade.h"
#include "ui_manage_grade.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include "manage.h"
manage_grade::manage_grade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manage_grade)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    headers<<"学号"<<"课程号"<<"成绩";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(100);
    on_seeAllButton_clicked();
}

manage_grade::~manage_grade()
{
    delete ui;
}

void manage_grade::on_insertButton_clicked()
{
    QString sno=ui->snoLineEdit->text();
    QString cno=ui->cnoLineEdit->text();
    QString grade=ui->gradeLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno,Cno from SC");
    bool T2=true;
    while(query.next())
    {
        QString s= query.value(0).toString();
        QString c= query.value(1).toString();
        if(s==sno&&c==cno)
        {
            QMessageBox::information(this ,tr("提示") , tr("该编号已存在不允许再次添加!"));
            T2=false;
        }
    }
    if(T2==true)
    {
        QString sql;
        sql = QString("insert into SC VALUES ('%1', '%2' , %3 )")
                .arg(sno).arg(cno).arg(grade);


        bool ok = query.exec(sql);
        if(ok)
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        else
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));

    }
    on_seeAllButton_clicked();

}

void manage_grade::on_updateButton_clicked()
{
    QString sno=ui->snoLineEdit->text();
    QString cno=ui->cnoLineEdit->text();
    QString grade=ui->gradeLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno,Cno from SC");
    bool T2=true;
    while(query.next())
    {
        QString s= query.value(0).toString();
        QString c= query.value(1).toString();
        if(s==sno&&c==cno)
        {
            QString sql;
            sql = QString("UPDATE SC set grade = %3 \
                           where Sno = '%1' and Cno='%2' ")
                    .arg(sno).arg(cno).arg(grade);


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
        QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));

    on_seeAllButton_clicked();
}

void manage_grade::on_deleteButton_clicked()
{
    QString sno=ui->snoLineEdit->text();
    QString cno=ui->cnoLineEdit->text();

    QSqlQuery query;
    query.exec("select Sno,Cno from SC");
    bool T2=true;
    while(query.next())
    {
        QString s= query.value(0).toString();
        QString c= query.value(1).toString();
        if(s==sno&&c==cno)
        {
            QString sql;
            sql = QString("DELETE FROM SC \
                           where Sno = '%1' and Cno='%2' ").arg(sno).arg(cno);

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
        QMessageBox::information(this ,tr("提示") , tr("改编号不存在无法删除"));

    on_seeAllButton_clicked();
}

void manage_grade::on_seeAllButton_clicked()
{

    QSqlQuery query;

    query.exec("select * from SC");
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row=0;
    QStringList rowdata;
    while(query.next())
    {
        rowdata.clear();
        QString id = query.value(0).toString();
        QString user = query.value(1).toString();
        QString pass = query.value(2).toString();
        rowdata<<id<<user<<pass;
        list_all_student.append(rowdata);

        for(int i  = 0 ; i <rowdata .size() ; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(i));
            ui->tableWidget->setItem(row , i , item);
        }

        row++;

    }

}

void manage_grade::on_backButton_clicked(){
    manage *dh;
    this->hide();
    dh=new manage ;
    dh->show();
}
