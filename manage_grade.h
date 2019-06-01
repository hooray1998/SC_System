#ifndef SCOREMANAGE_H
#define SCOREMANAGE_H

#include <QWidget>

namespace Ui {
class manage_grade;
}

class manage_grade : public QWidget
{
    Q_OBJECT

public:
    explicit manage_grade(QWidget *parent = 0);
    ~manage_grade();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

private:
    Ui::manage_grade *ui;
    QStringList headers;
};

#endif // SCOREMANAGE_H
