#ifndef SCOREMANAGE_H
#define SCOREMANAGE_H

#include <QWidget>

namespace Ui {
class scoremanage;
}

class scoremanage : public QWidget
{
    Q_OBJECT

public:
    explicit scoremanage(QWidget *parent = 0);
    ~scoremanage();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

private:
    Ui::scoremanage *ui;
    QStringList headers;
};

#endif // SCOREMANAGE_H
