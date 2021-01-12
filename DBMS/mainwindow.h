#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <stdio.h>
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <string>
//#include <vector>
//#include <io.h>
//#include <sstream>
//#include <regex>
//#include <fstream>
//#include <typeinfo>
//#include <direct.h>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include "loginwindow.h"
#include "regwindow.h"
#include "createdatabasewindow.h"
#include "createtable.h"
#include "changetablewindow.h"
#include "changelimitw.h"

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
    void changeLimitActionsSlot();

    void on_pushButtonCommitQ_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
