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

bool createDatabaseWindow::limitJudge(int limitIndex)
{
    QString path = QCoreApplication::applicationDirPath();
    QString user_now_path = path + "/user_now.csv";
    QString user_path = path + "/user.csv";
    QFile user_nowFile(user_now_path);
    if(!user_nowFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "ERROR", "文件打开失败！");
        return false;
    }
    QByteArray user_now_ba = user_nowFile.readAll();
    qDebug() << user_now_ba;
    QString user_now = QString(user_now_ba);
    // QString user_now存储当前用户
    user_nowFile.close();

    bool user_exist = false;

    QFile user_file(user_path);
    if(!user_file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "ERROR", "文件打开失败！");
        return false;
    }

    QTextStream user_in(&user_file); // 新建文本流对象
    QStringList userlimitlist;//用于存储逐行数据
    QString userfileLine;//逐行读取数据

    while(!user_in.atEnd())
    {
        userfileLine=user_in.readLine();//逐行读取数据
        userlimitlist=userfileLine.split(",");//一行中的单元格以，区分

        qDebug() << userlimitlist.at(0);
        if(user_now == userlimitlist.at(0))
        {

            user_exist = true;
//            qDebug() << userlimitlist.at(3);
            if(userlimitlist.at(limitIndex) != "1")
            {
                QMessageBox::warning(this, "ERROR", user_now + "没有该权限！");
                return false;

            }
            break;
        }


    }
    if(!user_exist)
    {
        QMessageBox::warning(this, "ERROR", "用户不存在！");
        return false;
    }
    user_file.close();
    return true;
}



void createDatabaseWindow::on_pushButtonCreateDB_clicked()
{
    if(!limitJudge(4)){
        return;
    }
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
