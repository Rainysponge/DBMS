#ifndef CHANGETABLEWINDOW_H
#define CHANGETABLEWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class changeTableWindow;
}

class changeTableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit changeTableWindow(QWidget *parent = nullptr);
    ~changeTableWindow();

private slots:
    void on_pushButtonSave_clicked();

    void on_pushButtonShowTable_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButtonDelTable_clicked();

private:
    Ui::changeTableWindow *ui;
};

#endif // CHANGETABLEWINDOW_H
