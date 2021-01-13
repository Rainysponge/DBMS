#include "table.h"
#include "ui_table.h"

table::table(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
}

table::~table()
{
    delete ui;
}

void table::on_pushButton_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString user_now_path = path + "/user_now.csv";
    QString user_path = path + "/user.csv";
    QFile user_nowFile(user_now_path);
    if(!user_nowFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "ERROR", "文件打开失败！");
        return ;
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
        return ;
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
            qDebug() << userlimitlist.at(3);
            if(userlimitlist.at(3) != "1")
            {
                QMessageBox::warning(this, "ERROR", user_now + "没有该权限！");
                return ;
            }
        }


    }
    if(!user_exist)
    {
        QMessageBox::warning(this, "ERROR", "用户不存在！");
        return ;
    }
    user_file.close();





    QString DBused = path + "/database_use.csv";
    QString table_name = ui->lineEditTableName->text();
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    qDebug() << ba;
    QString database_used = QString(ba);
    file.close();
    // table_name用于记录表名，database_used记录正在使用的数据库
    QString fileName = path + "/" + database_used + "/" + table_name + "_data.csv";
    filename = fileName;
    if(!fileName.isEmpty())
    {
       x.clear(); //x的值
       qv2.clear();

       QFile file(fileName); // 新建QFile对象
       if (!file.open(QFile::ReadOnly | QFile::Text))
       {
           QMessageBox::warning(this, "ERROR", "该表不存在！");
           return ;
       }
       QTextStream in(&file); // 新建文本流对象
       QStringList list;//用于存储逐行数据
       QString fileLine=in.readLine();//逐行读取数据
       list=fileLine.split(",");
       list1=list;
       qDebug()<<list1;
       //逐行读取*.csv数据并将每列分别存入x、y数组中
       while(!in.atEnd())
       {
           fileLine=in.readLine();//逐行读取数据
           list=fileLine.split(",");//一行中的单元格以，区分
            col =list.count();//列数
           qDebug()<<"list="<<list;
           qDebug()<<list.count();
           x.clear();
           for (int i=0;i<col;i++)
           {
               QString A = list.at(i);//获取该行第1个单元格内容
               x.append(A);
           }

           qv2.append(x);

       }
       qDebug()<<"x="<<x;
       qDebug()<<"qv2="<<qv2;
       file.close();
    }


    int row =qv2.size();//行数

    qDebug()<<row;


    this->ui->tableWidget->setRowCount(row);    //设置行数
    this->ui->tableWidget->setColumnCount(col); //设置列数
    this->ui->tableWidget->setHorizontalHeaderLabels(list1);
    this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->ui->tableWidget ->setItem(0,0,new QTableWidgetItem("1"));

    for (int i=0;i<row;i++)
    {
      for(int j=0;j<col;j++)
        this->ui->tableWidget ->setItem(i,j,new QTableWidgetItem(qv2[i][j]));
    }
}

void table::on_pushButton_insert_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString user_now_path = path + "/user_now.csv";
    QString user_path = path + "/user.csv";
    QFile user_nowFile(user_now_path);
    if(!user_nowFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "ERROR", "文件打开失败！");
        return ;
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
        return ;
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
            if(userlimitlist.at(5) != "1")
            {
                QMessageBox::warning(this, "ERROR", user_now + "没有该权限！");
                return ;
            }
        }


    }
    if(!user_exist)
    {
        QMessageBox::warning(this, "ERROR", "用户不存在！");
        return ;
    }
    user_file.close();



    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    for(int j=0;j<col;j++)
    this->ui->tableWidget ->setItem(row,j,new QTableWidgetItem(""));

}

void table::on_pushButton_delete_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString user_now_path = path + "/user_now.csv";
    QString user_path = path + "/user.csv";
    QFile user_nowFile(user_now_path);
    if(!user_nowFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "ERROR", "文件打开失败！");
        return ;
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
        return ;
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
            if(userlimitlist.at(6) != "1")
            {
                QMessageBox::warning(this, "ERROR", user_now + "没有该权限！");
                return ;
            }
        }


    }
    if(!user_exist)
    {
        QMessageBox::warning(this, "ERROR", "用户不存在！");
        return ;
    }
    user_file.close();
    int i = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(i);
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
}

void table::on_pushButton_S_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString user_now_path = path + "/user_now.csv";
    QString user_path = path + "/user.csv";
    QFile user_nowFile(user_now_path);
    if(!user_nowFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "ERROR", "文件打开失败！");
        return ;
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
        return ;
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
            if(userlimitlist.at(7) != "1")
            {
                QMessageBox::warning(this, "ERROR", user_now + "没有该权限！");
                return ;
            }
        }


    }
    if(!user_exist)
    {
        QMessageBox::warning(this, "ERROR", "用户不存在！");
        return ;
    }
    user_file.close();






    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(this, "critical", tr("文件保存失败！"),
        QMessageBox::Yes, QMessageBox::Yes);
    }
    else
    {
        QTextStream stream(&file);
        QString conTents;
        QHeaderView * header = ui->tableWidget->horizontalHeader() ;
        if (header)
        {
            for ( int i = 0; i < header->count(); i++ )
            {
                QTableWidgetItem *item = ui->tableWidget->horizontalHeaderItem(i);
                if (!item)
                {
                    continue;
                }
                conTents += item->text() + ",";
            }
            conTents += "\n";
        }

        for ( int i = 0 ; i < ui->tableWidget->rowCount(); i++ )
        {
            for ( int j = 0; j < ui->tableWidget->columnCount(); j++ )
            {

                QTableWidgetItem* item = ui->tableWidget->item(i, j);
                if ( !item )
                {
                    continue;
                }

                QString str = item->text();
                str.replace(","," ");
                conTents += str + ",";
            }
            conTents += "\n";
        }
        stream << conTents;
        file.close();
        }
}
