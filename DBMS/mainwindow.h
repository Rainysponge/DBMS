#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <stdio.h>
#include <regex>
#include "loginwindow.h"
#include "regwindow.h"
#include "createdatabasewindow.h"
#include "createtable.h"
#include "changetablewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void loginActionsSlot();
    void regActionsSlot();
    void createDatabaseActionsSlot();
    void createTableActionsSlot();
    void changeTableActionsSlot();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
