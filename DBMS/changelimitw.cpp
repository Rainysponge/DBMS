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
//             ui->comboBoxW->setLineEdit(tempbar[2]);

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
    bool flag = false;
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QString username = ui->lineEditUserName->text();

    // 读出界面中的权限
    QStringList limitUser;  // 0 1 2 3 4 5 6 7
    limitUser.append(ui->comboBoxW->currentText());
    limitUser.append(ui->comboBoxR->currentText());
    limitUser.append(ui->comboBoxC->currentText());
    limitUser.append(ui->comboBoxIn->currentText());
    limitUser.append(ui->comboBoxdel->currentText());
    limitUser.append(ui->comboBoxup->currentText());
    limitUser.append(ui->comboBoxS->currentText());
    limitUser.append(ui->comboBoxShow->currentText());


    QFile csvFile(userpath);
    csvFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream * out = new QTextStream(&csvFile);
    QStringList tempOption = out->readAll().split("\n");//每行以\n区分
    qDebug() << out->readAll();
    QString output = "";

    QString outputToFile = "";

    for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
    {
         QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分

         if (tempbar[0] == username)
         {
             flag = true;
             output = username + "权限为写:" + limitUser[0];
             output += "读:" + limitUser[1] + "创建:" + limitUser[2] + "插入:" + limitUser[3];
             output += "删除:" + limitUser[4] + "更新:" + limitUser[5] + "筛选:" + limitUser[6] + "查看:" + limitUser[7];

             //输出到文件的QString
             outputToFile += username + "," + tempbar[1]+ ",";
             outputToFile += "," + limitUser[0] + "," + limitUser[1] + "," + limitUser[2];
             outputToFile += "," + limitUser[3] + "," + limitUser[4] + "," + limitUser[5] + "," + limitUser[6] + "," + limitUser[7] + "\n";

         }else{

             // ToFile

             outputToFile += username + "," + tempbar[1]+ ",";
             outputToFile += "," + tempbar[2] + "," + tempbar[3] + "," + tempbar[4];
             outputToFile += "," + tempbar[5] + "," + tempbar[6] + "," + tempbar[7] + "," + tempbar[8] + "," + tempbar[9] + "\n";
         }



    }
    csvFile.close();//操作完成后记得关闭文件
    if(flag)
    {
        QFile fileW(userpath);
        fileW.open(QIODevice::WriteOnly);

        QByteArray bytes = outputToFile.toUtf8();
        fileW.write(bytes);  // 写入
        fileW.close();
        ui->textBrowser->setText(output);
        QMessageBox::warning(this, "Success", username + "权限修改完成！");
        return;
    }else
    {
        QMessageBox::warning(this, "ERROR", "该用户不存在！");
        return;
    }


}
