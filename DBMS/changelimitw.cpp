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
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QFile fileW(userlogining);
    fileW.open(QIODevice::ReadOnly);

    QByteArray bytes = fileW.readAll();
//    fileW.write(bytes);
    fileW.close();
    qDebug() << bytes;
    QString user_root = QString(bytes);
    if(user_root != "root"){
        QMessageBox::warning(this, "ERROR", user_root + "没有该权限！");
        return;
    }
//    QMessageBox::warning(this, "Success", "登陆成功！");
//    this->close();
}
