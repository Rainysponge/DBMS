#include "regwindow.h"
#include "ui_regwindow.h"

regWindow::regWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regWindow)
{
    ui->setupUi(this);
}

regWindow::~regWindow()
{
    delete ui;
}

void regWindow::on_commitButton_clicked()
{
    QString username = ui->lineEditUserName->text();
    QString password = ui->lineEditPass->text();
    QString password_again = ui->lineEditPassAgain->text();

    if(password != password_again)
    {
        QMessageBox::warning(this, "ERROR", "两次密码不一致");
        return;
    }

    if(password.length()<4)
    {
        QMessageBox::warning(this, "ERROR", "密码太短！");
        return;
    }
    if(username.length()<4)
    {
        QMessageBox::warning(this, "ERROR", "用户名太短！");
        return;
    }
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
//    qDebug() << userpath;
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
                if(username == tempbar[0])
                {
                    QMessageBox::warning(this, "ERROR", "用户名已经存在！");
                    return;
                }

            }
        }
        userListFile.close();


        // 写入权限
        userListFile.open(QIODevice::WriteOnly|QIODevice::Text| QIODevice::Append);
        // 初始默认可读不可写
        QString lineInfo = "";
        lineInfo += username + ',' + password + ',' + "0,1,0,0,0,0,1,1";
        lineInfo += "\n";
        QTextStream in(&userListFile);
        in<<lineInfo;

        userListFile.close();
        QMessageBox::warning(this, "Success", "用户名已经成功创建，快去登录吧！");
        this->close();
    }



}

void regWindow::on_cancelButton_clicked()
{
    this->close();
}
