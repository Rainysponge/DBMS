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


bool changeTableWindow::limitJudge(int limitIndex)
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
//    qDebug() << user_now_ba;
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

//        qDebug() << userlimitlist.at(0);
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

void changeTableWindow::on_pushButtonSave_clicked()
{
    if(!limitJudge(3) || !limitJudge(6) || !limitJudge(7)){
        return;
    }
    bool flag = false;
    QString lineInfo = "";
    QString out_to_text;
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
    if(tempFile->exists(istrFileName))
    {
        qDebug()<<QObject::tr("文件存在");
        QString field_name = ui->lineEditFieldName->text();
        QFile csvFile(istrFileName);
        if(!csvFile.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            qDebug()<<"OPEN FILE FAILED";
        }
        else
        {
            QTextStream * out = new QTextStream(&csvFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分
            qDebug() << out->readAll();

            out_to_text = "fieldname\ttype\tPrimaryKey\tNULL\n";


            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                 QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
                 qDebug() << tempbar[0];
                 if (tempbar[0] == field_name)
                 {
                     flag = true;
                     if(tempbar[2] == "1")
                     {
                         QMessageBox::warning(this, "ERROR", "该字段为主键！");
                         return;
                     }
                     lineInfo += ui->lineEditFieldName->text();
                     lineInfo += ',' + ui->comboBoxType->currentText();
                     lineInfo += ',' + ui->comboBoxPrimary->currentText();
                     lineInfo += ',' + ui->comboBoxNULL->currentText();
                     lineInfo += "\n";
                     out_to_text += ui->lineEditFieldName->text() + "\t\t" + ui->comboBoxType->currentText() +
                             "\t" + ui->comboBoxPrimary->currentText() +"\t\t" + ui->comboBoxNULL->currentText() + "\n";
                 }
                 else
                 {
                     lineInfo += tempbar[0] + "," + tempbar[1] + "," + tempbar[2] +"," + tempbar[3] + "\n";
                     out_to_text += tempbar[0] + "\t\t" + tempbar[1] + "\t" + tempbar[2] +"\t\t" + tempbar[3] + "\n";

                 }

            }
            csvFile.close();//操作完成后记得关闭文件

        }


        if(!flag){
            QMessageBox::warning(this, "ERROR", "该字段不存在！");
            return;
        }
        else
        {
//            csvFile.open(QIODevice::WriteOnly);


//            csvFile.write(lineInfo);
//            csvFile.close();

            QFile fileW(istrFileName);
            fileW.open(QIODevice::WriteOnly);

            QByteArray bytes = lineInfo.toUtf8();
            fileW.write(bytes);  // 写入后面要使用的数据库
            fileW.close();

        }
        ui->TableStructionText->setText(out_to_text);

        csvFile.close();//操作完成后记得关闭文件
        return;
    }
    else
    {
        QMessageBox::warning(this, "ERROR", "该表不存在存在！");
        return;
    }
}

void changeTableWindow::on_pushButtonShowTable_clicked()
{
    if(!limitJudge(9)){
        return;
    }
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
    if(tempFile->exists(istrFileName))
    {
        qDebug()<<QObject::tr("文件存在");
        QString field_name = ui->lineEditFieldName->text();
        QFile csvFile(istrFileName);
        if(!csvFile.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            qDebug()<<"OPEN FILE FAILED";
        }
        else
        {
            QTextStream * out = new QTextStream(&csvFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分
            qDebug() << out->readAll();
            QString out_to_text;
            out_to_text = "fieldname\ttype\tPrimaryKey\tNULL\n";

            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                 QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
                 qDebug() << tempbar[0];
                 out_to_text += tempbar[0] + "\t\t" + tempbar[1] + "\t" + tempbar[2] +"\t\t" + tempbar[3] + "\n";

            }
            ui->TableStructionText->setText(out_to_text);

            csvFile.close();//操作完成后记得关闭文件
        }
        return;
    }
    else
    {
        QMessageBox::warning(this, "ERROR", "该表不存在存在！");
        return;
    }

//    this->close();

}

void changeTableWindow::on_pushButtonDel_clicked()
{
    if(!limitJudge(3) || !limitJudge(6) || !limitJudge(7)){
        return;
    }
    bool flag = false;
    int dataIndex = -1;
    QString lineInfo = "";
    QString out_to_text;
    QString outputTodatafile = "";
    QString path = QCoreApplication::applicationDirPath();
    QString DBused = path + "/database_use.csv";
    QString table_name = ui->tableNameEdit->text();
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();

    QString database_used = QString(ba);
    file.close();
    // table_name用于记录表名，database_used记录正在使用的数据库
    QString istrFileName = path + '/' + database_used + '/' + table_name + ".csv";
    QString isdataFileName = path + '/' + database_used + '/' + table_name + "_data.csv";

    QFile * tempFile = new QFile;
    if(tempFile->exists(istrFileName))
    {
        qDebug()<<QObject::tr("文件存在");
        QString field_name = ui->lineEditFieldName->text();
        QFile csvFile(istrFileName);
        if(!csvFile.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            qDebug()<<"OPEN FILE FAILED";
        }
        else
        {
            QTextStream * out = new QTextStream(&csvFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分

            out_to_text = "fieldname\ttype\tPrimaryKey\tNULL\n";


            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                 QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
                 qDebug() << tempbar[0];
                 if (tempbar[0] == field_name)
                 {
                     dataIndex = i;
                     flag = true;
                     if(tempbar[2] == "1")
                     {
                         QMessageBox::warning(this, "ERROR", "该字段为主键！");
                         return;
                     }

                 }
                 else
                 {
                     lineInfo += tempbar[0] + "," + tempbar[1] + "," + tempbar[2] +"," + tempbar[3] + "\n";
                     out_to_text += tempbar[0] + "\t\t" + tempbar[1] + "\t" + tempbar[2] +"\t\t" + tempbar[3] + "\n";

                 }

            }
            csvFile.close();//操作完成后记得关闭文件

        }


//        int wi = 0;

        QFile datafile(isdataFileName);
        if(!datafile.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "ERROR", "文件打开失败！");
            return ;
        }
        QTextStream datafile_in(&datafile); // 新建文本流对象
        QStringList datafilelist;//用于存储逐行数据
        QString datafileLine;//逐行读取数据

        while(!datafile_in.atEnd())
        {
            datafileLine=datafile_in.readLine();//逐行读取数据
            datafilelist=datafileLine.split(",");//一行中的单元格以，区分
//            if(wi==0)
//            {
//                wi++;
//                for(int i=0; i < datafilelist.count(); i++)
//                {
//                    if(field_name==datafilelist.at(i))
//                    {
//                        dataIndex = i;  // 记录行下标
//                    }
//                }
//            }
            if(dataIndex<0)
            {
                QMessageBox::warning(this, "ERROR", "该字段不存在键！");
                return;
            }
//            qDebug() << "要删除的属性下标为" << dataIndex << "\n";
            for(int i=0; i < datafilelist.count(); i++)
            {
//                qDebug() << "在循环中";
                if(i!=dataIndex)
                {
                    outputTodatafile += datafilelist.at(i) + ",";
                }
            }
            outputTodatafile.chop(1);
            outputTodatafile += "\n";

//            qDebug() << userlimitlist.at(0);



        }
        datafile.close();


        if(!flag){
            QMessageBox::warning(this, "ERROR", "该字段不存在！");
            return;
        }
        else
        {



        }
        ui->TableStructionText->setText(out_to_text);

        csvFile.close();//操作完成后记得关闭文件

    }
    else
    {
        QMessageBox::warning(this, "ERROR", "该表不存在存在！");
        return;
    }

    QFile fileW(istrFileName);
    fileW.open(QIODevice::WriteOnly);

    QByteArray bytes = lineInfo.toUtf8();
    fileW.write(bytes);
    fileW.close();

    QFile fileDW(isdataFileName);
    fileDW.open(QIODevice::WriteOnly);

    QByteArray bytesD = outputTodatafile.toUtf8();
    fileDW.write(bytesD);
    fileDW.close();

//    qDebug() << outputTodatafile;

}

void changeTableWindow::on_pushButtonDelTable_clicked()
{
    if(!limitJudge(3) || !limitJudge(6) || !limitJudge(7)){
        return;
    }


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
    QString dataFileName = path + '/' + database_used + '/' + table_name + "_data.csv";
    QFile * tempFile = new QFile;
    if(tempFile->exists(istrFileName))
    {
        qDebug()<<QObject::tr("文件存在");
          QFile fileRemove(istrFileName);
          fileRemove.remove();
          ui->TableStructionText->setText("Delete Successfully!");
    }
    else {
        QMessageBox::warning(this, "ERROR", "该表不存在！");
        return;
    }


    QFile * datatempFile = new QFile;
    if(datatempFile->exists(dataFileName))
    {
        qDebug()<<QObject::tr("文件存在");
          QFile fileRemove(dataFileName);
          fileRemove.remove();
          ui->TableStructionText->setText("Delete Successfully!");
    }




}
