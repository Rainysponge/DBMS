#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <stdio.h>
//#include <iostream>
//#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
#include <QMessageBox>
#include <QDir>
#include <QKeyEvent>
#include <QFileDialog>
#include <QRegExp>
#include <QTreeWidgetItem>
#include "loginwindow.h"
#include "regwindow.h"
#include "createdatabasewindow.h"
#include "createtable.h"
#include "changetablewindow.h"
#include "changelimitw.h"
#include "table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *k);
    void deleteSQL(QString username, QString sql);
    void useSQL(QString username, QString sql);
    void createSQL(QString username, QString sql);
    void selectData(QString sql);
    void insertData(QString sql);
    void updateData(QString sql);
    void grantLimit(QString sql);
    void revokeLimit(QString sql);
    bool check_insertData(QString table_name, QString database_used,QVector<QString> all_data_name,QVector<QString> all_insert_data);


private slots:
    void loginActionsSlot();
    void regActionsSlot();
    void createDatabaseActionsSlot();
    void createTableActionsSlot();
    void changeTableActionsSlot();
    void changeLimitActionsSlot();
    void changeTableInfoSlot();

    void on_pushButtonCommitQ_clicked();

    void on_pushButtonCMD_clicked();

private:
    Ui::MainWindow *ui;
    QTreeWidgetItem *item = nullptr;  //根节点(根节点下可以有多个子结点)
    QTreeWidgetItem *itemD = nullptr; //子节点(子点下可以有多个孙子结点)
    QTreeWidgetItem *itemW = nullptr; //子节点


    bool select_flag = false;
};

#endif // MAINWINDOW_H
