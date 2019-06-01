#ifndef COURSEMANAGE_H
#define COURSEMANAGE_H

#include <QWidget>

namespace Ui {
class coursemanage;
}

class coursemanage : public QWidget
{
    Q_OBJECT

public:
    explicit coursemanage(QWidget *parent = 0);
    ~coursemanage();

private slots:
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_updateButton_clicked();
    void on_seeAllButton_clicked();
    void on_backButton_clicked();

private:
    Ui::coursemanage *ui;
    QStringList headers;
};

#endif // COURSEMANAGE_H
