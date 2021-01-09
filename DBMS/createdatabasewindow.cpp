#include "createdatabasewindow.h"
#include "ui_createdatabasewindow.h"

createDatabaseWindow::createDatabaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createDatabaseWindow)
{
    ui->setupUi(this);
}

createDatabaseWindow::~createDatabaseWindow()
{
    delete ui;
}

void createDatabaseWindow::on_pushButtonCreateDB_clicked()
{
    QString dir = ui->lineEditDBName->text();
    QString path = QCoreApplication::applicationDirPath();
    QString pathForFold = path + '/' + dir;

    QDir *folder = new QDir;

    bool exist = folder->exists(pathForFold);
    if(dir.isEmpty() || exist){
            QMessageBox::warning(this, "Warning", "Exist");
    }else{
        bool ok = folder->mkdir(pathForFold);
        if(ok){
            QMessageBox::warning(this, tr("CreateDB"), tr("Create DB success!"));
            this->close();
        }
        else{
            QMessageBox::warning(this, tr("CreateDB"), tr("Create DB fail"));
            this->close();
        }
    }
}
