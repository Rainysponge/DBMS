#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_pushButtonCancel_clicked()
{
    this->close();
}

void loginWindow::on_pushButtonLogin_clicked()
{
    bool flag = false;
    QString userNow = "";  // 用于存放当前用户
    QString username = ui->lineEditUserName->text();
    QString password = ui->lineEditPassWord->text();

    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QFile * userFile = new QFile;
    if(userFile->exists(userpath))
    {
        qDebug()<<QObject::tr("文件存在");

        QFile userListFile(userpath);
        if(!userListFile.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            qDebug()<<"OPEN FILE FAILED";
        }
        else
        {
            QTextStream * out = new QTextStream(&userListFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分
            qDebug() << out->readAll();




            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
                qDebug() << tempbar[0];
                if(username == tempbar[0] && password == tempbar[1])
                {
                    flag = true;
                    userNow = tempbar[0];
                }

            }
        }
        userListFile.close();


        if(flag)
        {
            QFile fileW(userlogining);
            fileW.open(QIODevice::WriteOnly);

            QByteArray bytes = userNow.toUtf8();
            fileW.write(bytes);
            fileW.close();
            QMessageBox::warning(this, "Success", "登陆成功！");
            this->close();
        }
        else {
            QMessageBox::warning(this, "ERROR", "输入有误！");
            return;
        }
    }





}
