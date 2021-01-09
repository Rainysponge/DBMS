#ifndef CREATEDATABASEWINDOW_H
#define CREATEDATABASEWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class createDatabaseWindow;
}

class createDatabaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit createDatabaseWindow(QWidget *parent = nullptr);
    ~createDatabaseWindow();

private slots:
    void on_pushButtonCreateDB_clicked();

private:
    Ui::createDatabaseWindow *ui;
//    QString expression;   //记录
};

#endif // CREATEDATABASEWINDOW_H
