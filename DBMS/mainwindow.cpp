#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect
    connect(ui->action_L, &QAction::triggered, this, &MainWindow::loginActionsSlot);
    connect(ui->action_R, &QAction::triggered, this, &MainWindow::regActionsSlot);
    connect(ui->action_C, &QAction::triggered, this, &MainWindow::createDatabaseActionsSlot);
    connect(ui->action_CreateTable, &QAction::triggered, this,
            &MainWindow::createTableActionsSlot);
    connect(ui->action_E, &QAction::triggered, this, &MainWindow::changeTableActionsSlot);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginActionsSlot()
{
//    printf("%s", "abbbb");
    loginWindow *loginw = new loginWindow();
    loginw->show();
}


void MainWindow::regActionsSlot()
{
    regWindow *regw = new regWindow();
    regw->show();
}


void MainWindow::createDatabaseActionsSlot()
{
    createDatabaseWindow *w = new createDatabaseWindow();
    w->show();
}


void MainWindow::createTableActionsSlot()
{
    createTable *w = new createTable();
    w->show();
}

void MainWindow::changeTableActionsSlot()
{
    changeTableWindow *w = new changeTableWindow();
    w->show();
}

