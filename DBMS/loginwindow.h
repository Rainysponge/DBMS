#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonLogin_clicked();

private:
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H
