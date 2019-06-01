#include "userlogin.h"
#include "ui_userlogin.h"
#include "manger.h"
#include "globle.h"
userlogin::userlogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userlogin)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    headers<<"ID"<<"姓名"<<"密码";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(100);
    on_seeAllButton_clicked();
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::on_insertButton_clicked()
{
    QString id=ui->idLineEdit->text();
    QString username=ui->nameLineEdit->text();
    QString password=ui->passwardLineEdit->text();

    QSqlQuery query;
    query.exec("select id from Admin");
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
        sql = QString("insert into Admin (id,username,password)"
                      " VALUES ('%1', '%2' , '%3' )")
                .arg(id).arg(username).arg(password);


        bool ok = query.exec(sql);
        if(ok)
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        else
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));

    }
    on_seeAllButton_clicked();

}

void userlogin::on_updateButton_clicked()
{
    QString id=ui->idLineEdit->text();
    QString username=ui->nameLineEdit->text();
    QString password=ui->passwardLineEdit->text();

    QSqlQuery query;
    query.exec("select id from Admin");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();
        if(id.compare(id1)==0)
        {
            QString sql;
            sql = QString("UPDATE Admin "
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
        QMessageBox::information(this ,tr("提示") , tr("该编号不存在，无法更改"));

    on_seeAllButton_clicked();
}

void userlogin::on_deleteButton_clicked()
{
    QString id=ui->idLineEdit->text();
    QString username=ui->nameLineEdit->text();
    QString password=ui->passwardLineEdit->text();

    QSqlQuery query;
    query.exec("select id from Admin");
    bool T2=true;
    while(query.next())
    {
        QString id1= query.value(0).toString();

        if(id.compare(id1)==0)
        {
            QString sql;
            sql = QString("DELETE FROM Admin "
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
        QMessageBox::information(this ,tr("提示") , tr("改编号不存在无法删除"));

    on_seeAllButton_clicked();
}

void userlogin::on_seeAllButton_clicked()
{

    QSqlQuery query;

    query.exec("select id,username,password from Admin");
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    int row=0;
    while(query.next())
    {
        for(int i  = 0 ; i <3; i++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(query.value(i).toString());
            ui->tableWidget->setItem(row, i, item);
        }
        row++;
    }

}

void userlogin::on_backButton_clicked(){
    manger *dh;
    this->hide();
    dh=new manger ;
    dh->show();
}
