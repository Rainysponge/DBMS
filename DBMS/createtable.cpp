#include "createtable.h"
#include "ui_createtable.h"

createTable::createTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createTable)
{
    ui->setupUi(this);

    //connect
    connect(ui->comboBoxType, SIGNAL(currentIndexChanged(QString)),this,SLOT(print_Type()));
}

createTable::~createTable()
{
    delete ui;
}


void createTable::print_Type()
{
//    if(ui->comboBox->currentIndex()==0) ui->lineEdit->setText("小振国");
    if(ui->comboBoxType->currentIndex()==0) qDebug() << "char()";
    if(ui->comboBoxType->currentIndex()==1) qDebug() << "int";
    if(ui->comboBoxType->currentIndex()==2) qDebug() << "bool";

}




void createTable::on_pushButtonCreate_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString DBused = path + "/database_use.csv";
    QString table_name = ui->tableNameEdit->text();
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    qDebug() << ba;
    QString database_used = QString(ba);
    file.close();
    // table_name用于记录表名，database_used记录正在使用的数据库

    if(database_used.isEmpty())
    {
        QMessageBox::warning(this, "ERROR", "请先选择要使用的数据库！");
    }


    QString istrFileName = path + '/' + database_used + '/' + table_name + ".csv";
    QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";
    QFile * tempFile = new QFile;
    if(tempFile->exists(istrFileName))
    {
        qDebug()<<QObject::tr("文件存在");
        QMessageBox::warning(this, "ERROR", "该表已经存在！");
        return;
    }
    else
    {
        tempFile->setFileName(istrFileName);
        QFile * datatmpFile = new QFile;
        datatmpFile->setFileName(dataFile);
        if(!tempFile->open(QIODevice::WriteOnly|QIODevice::Text))
        {
            qDebug()<<QObject::tr("打开失败");
            QMessageBox::warning(this, "ERROR", "Something wrong happened!");
        }
        tempFile->close();
        if(!datatmpFile->open(QIODevice::WriteOnly|QIODevice::Text))
        {
            qDebug()<<QObject::tr("打开失败");
            QMessageBox::warning(this, "ERROR", "Something wrong happened!");
        }
        datatmpFile->close();
    }


    QString field_name = ui->lineEditFieldName->text();
    QFile csvFile(istrFileName);
    if(!csvFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<QObject::tr("打开失败");
        QMessageBox::warning(this, "ERROR", "Something wrong happened!");
    }else{
        QString lineInfo = "";
        lineInfo += ui->lineEditFieldName->text();
        lineInfo += ',' + ui->comboBoxType->currentText();
        lineInfo += ',' + ui->comboBoxPrimary->currentText();
        lineInfo += ',' + ui->comboBoxNULL->currentText();
        lineInfo += "\n";
        QTextStream in(&csvFile);
        in<<lineInfo;


        QMessageBox::warning(this, "Success", "该表已经成功被创建！");
    }
    csvFile.close();
    QFile datacsvFile(dataFile);
    datacsvFile.open(QIODevice::WriteOnly);
    QString outputTodata = ui->lineEditFieldName->text() + "\n";
    QByteArray bytes = outputTodata.toUtf8();
    datacsvFile.write(bytes);  // 写入
    datacsvFile.close();

}

void createTable::on_pushButtonAddCon_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString DBused = path + "/database_use.csv";
    QString table_name = ui->tableNameEdit->text();
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    qDebug() << ba;
    QString database_used = QString(ba);
    file.close();
    // table_name用于记录表名，database_used记录正在使用的数据库

    QString istrFileName = path + '/' + database_used + '/' + table_name + ".csv";
    QFile * tempFile = new QFile;
    //如果存在
    if(tempFile->exists(istrFileName))
    {
        QString field_name = ui->lineEditFieldName->text();
        QFile csvFile(istrFileName);
        if(!csvFile.open(QIODevice::WriteOnly|QIODevice::Text| QIODevice::Append))
        {
            qDebug()<<QObject::tr("打开失败");
            QMessageBox::warning(this, "ERROR", "Something wrong happened!");
        }else{
            QString lineInfo = "";
            lineInfo += ui->lineEditFieldName->text();
            lineInfo += ',' + ui->comboBoxType->currentText();
            lineInfo += ',' + ui->comboBoxPrimary->currentText();
            lineInfo += ',' + ui->comboBoxNULL->currentText();
            lineInfo += "\n";
            QTextStream in(&csvFile);
            in<<lineInfo;

            // 1 2 3 4
//            QMessageBox::warning(this, "Success", "该表已经成功被修改！");
        }
        csvFile.close();
    }else{
        QMessageBox::warning(this, "Error", "该表似乎不存在！");
    }


    QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";


//    QFile datacsvFile(dataFile);
//    datacsvFile.open(QIODevice::ReadOnly);
//    ba = datacsvFile.readAll();
    QFile csvFile(dataFile);
    csvFile.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream * out = new QTextStream(&csvFile);
    QStringList tempOption = out->readAll().split("\n");//每行以\n区分
    qDebug() << out->readAll();
//    QString output = "";

    QString outputToFile = "";

    for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
    {
         QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分

        if(i == 0)
        {
            outputToFile += tempOption.at(i) + "," + ui->lineEditFieldName->text() + "\n";
        }else {
            outputToFile += tempOption.at(i) + "\n";
        }



    }
    csvFile.close();//操作完成后记得关闭文件

    QFile fileW(dataFile);
    fileW.open(QIODevice::WriteOnly);

    QByteArray bytes = outputToFile.toUtf8();
    fileW.write(bytes);  // 写入
    fileW.close();

    QMessageBox::warning(this, "Success", "增加完成！");
    return;

//    QString outputTodata = ui->lineEditFieldName->text();
//    QByteArray bytes = outputTodata.toUtf8();
//    datacsvFile.write(bytes);  // 写入
//    datacsvFile.close();


}

