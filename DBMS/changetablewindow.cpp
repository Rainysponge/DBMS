#include "changetablewindow.h"
#include "ui_changetablewindow.h"

changeTableWindow::changeTableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeTableWindow)
{
    ui->setupUi(this);
}

changeTableWindow::~changeTableWindow()
{
    delete ui;
}
