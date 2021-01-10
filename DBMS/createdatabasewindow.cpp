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
            QMessageBox::warning(this, "Warning", "Exist or inputError!");
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




void createDatabaseWindow::on_pushButtonChoose_clicked()
{
    QString dir = ui->lineEditDBName->text();
    QString path = QCoreApplication::applicationDirPath();
    QString pathForFold = path + '/' + dir;
    QString DBused = path + "/database_use.csv";
    QDir *folder = new QDir;
    if (dir.isEmpty()){
        QMessageBox::warning(this, "ERROR", "输入错误");
        this->close();
    }
    bool exist = folder->exists(pathForFold);
    if(exist){
        QFile file(DBused);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        qDebug() << ba;
        QString database_used = QString(ba);
        qDebug() << ba;

        /*qDebug() << database_used;*/  // 读出先前使用的数据库
        file.close();


        // 如果当前数据库就是要转换的数据库
        if(database_used == dir || database_used.isEmpty())
        {
            QMessageBox::warning(this, "提示", "当前数据库为<database:"+dir+">!");
            qDebug() << "database_used == dir";
        }else{
            QFile fileW(DBused);
            fileW.open(QIODevice::WriteOnly);

            QByteArray bytes = dir.toUtf8();
            fileW.write(bytes);  // 写入后面要使用的数据库
            fileW.close();

            QMessageBox::warning(this, "提示",
                                 "已经从数据库为<database:"+database_used+">转换为<database:"+dir+">!");
            qDebug() << "database_used.isNotEmpty()";
        }





    }else{
        QMessageBox::warning(this, "Warning", "不存在<database:"+dir+">!");
    }
    this->close();


}
