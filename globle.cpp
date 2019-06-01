#ifndef GLOBLE_CPP
#define GLOBLE_CPP
#include "globle.h"
int num01;
QString str = "test";
QString username_qj = "";
QString password_qj = "";
QVariantList list_all_student;
QString sqluser="root";
QString sqlpass="123456";
QVariantList list_all_dormstudent;

QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

// Open the Database
bool openDatabase()
{
    db.setHostName("localhost");
    db.setDatabaseName("SC_pro");
    db.setUserName("root");
    db.setPassword("123456");
    db.setPort(3306);

    if (!db.open())
        return false;

    return true;
}

// Close Database
void closeDatabase()
{
    db.close();
}

#endif // VARIATE_H
