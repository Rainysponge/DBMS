#include "changelimitw.h"
#include "ui_changelimitw.h"

changeLimitW::changeLimitW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeLimitW)
{
    ui->setupUi(this);
}

changeLimitW::~changeLimitW()
{
    delete ui;
}

void changeLimitW::on_pushButtonShow_clicked()
{
    bool flag = false;
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QString username = ui->lineEditUserName->text();



    QFile csvFile(userpath);
    csvFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream * out = new QTextStream(&csvFile);
    QStringList tempOption = out->readAll().split("\n");//每行以\n区分
    qDebug() << out->readAll();
    QString output = "";



    for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
    {
         QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
//         qDebug() << tempbar[0];
         if (tempbar[0] == username)
         {
             flag = true;
             output = username + "权限为写:" + tempbar[2];
             output += "读:" + tempbar[3] + "创建:" + tempbar[4] + "插入:" + tempbar[5];
             output += "删除:" + tempbar[6] + "更新:" + tempbar[7] + "筛选:" + tempbar[8] + "查看:" + tempbar[9];

         }


    }
    csvFile.close();//操作完成后记得关闭文件
    if(flag)
    {
        ui->textBrowser->setText(output);
    }else {
        QMessageBox::warning(this, "ERROR", "该用户不存在！");
        return;
    }

}

void changeLimitW::on_pushButtonSummit_clicked()
{
    int i = 0;
    i++;
}
