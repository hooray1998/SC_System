#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class studentForm;
}

class studentForm : public QWidget
{
    Q_OBJECT

public:
    explicit studentForm(QWidget *parent = 0);
    ~studentForm();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::studentForm *ui;
};

#endif // STUDENTFORM_H
