#ifndef STUINFORMANAGE_H
#define STUINFORMANAGE_H
#include <QWidget> 
namespace Ui {
class stuinformanage;
}

class stuinformanage : public QWidget
{
    Q_OBJECT

public:
    explicit stuinformanage(QWidget *parent = 0);
    ~stuinformanage();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();
private:
    Ui::stuinformanage *ui;
    QStringList headers;
};

#endif // STUINFORMANAGE_H
