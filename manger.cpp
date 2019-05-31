#include "manger.h"
#include "ui_manger.h"
#include"globle.h"
#include"mainwindow.h"
#include "userlogin.h"
#include "stuinformanage.h"
#include "scoremanage.h"
#include "coursemanage.h"

manger::manger(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manger)
{
    ui->setupUi(this);
    QLabel *lab= ui->label_useradmin;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_qj);



}

manger::~manger()
{
    delete ui;
}

void manger::on_pushButton_9_clicked()
{
    MainWindow *dh;
    this->hide();
    dh=new MainWindow  ;

    dh->show();
}

void manger::on_userloginButton_clicked()
{
    this->hide();
    userlogin *ti=new userlogin;
    ti->show();
}

void manger::on_stu_inform_guanlipushButton_clicked()
{
    this->hide();
    stuinformanage *ij=new stuinformanage;
    ij->show();
}



void manger::on_scoremanagepushButton_clicked()
{
    this->hide();
    scoremanage *pk=new scoremanage;
    pk->show();

}

void manger::on_course_manageButton_clicked()
{
    this->hide();
	coursemanage *ew=new coursemanage;
	ew->show();
}

