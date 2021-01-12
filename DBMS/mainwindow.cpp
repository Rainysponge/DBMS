#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect
    connect(ui->action_L, &QAction::triggered, this, &MainWindow::loginActionsSlot);
    connect(ui->action_R, &QAction::triggered, this, &MainWindow::regActionsSlot);
    connect(ui->action_C, &QAction::triggered, this, &MainWindow::createDatabaseActionsSlot);
    connect(ui->action_CreateTable, &QAction::triggered, this,
            &MainWindow::createTableActionsSlot);
    connect(ui->action_E, &QAction::triggered, this, &MainWindow::changeTableActionsSlot);
    connect(ui->action_Q, &QAction::triggered, this, &MainWindow::changeLimitActionsSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginActionsSlot()
{
    loginWindow *loginw = new loginWindow();
    loginw->show();
}


void MainWindow::regActionsSlot()
{
    regWindow *regw = new regWindow();
    regw->show();
}


void MainWindow::createDatabaseActionsSlot()
{
    createDatabaseWindow *w = new createDatabaseWindow();
    w->show();
}


void MainWindow::createTableActionsSlot()
{
    createTable *w = new createTable();
    w->show();
}

void MainWindow::changeTableActionsSlot()
{
    changeTableWindow *w = new changeTableWindow();
    w->show();
}


void MainWindow::changeLimitActionsSlot()
{
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QFile fileW(userlogining);
    fileW.open(QIODevice::ReadOnly);

    QByteArray bytes = fileW.readAll();

    fileW.close();
    qDebug() << bytes;
    QString user_root = QString(bytes);
    if(user_root != "root")
    {
        QMessageBox::warning(this, "ERROR", user_root + "没有修改权限！");
        return;
    }
    changeLimitW *w = new changeLimitW();
    w->show();
}

void del(QTreeWidgetItem* node)
{
    if(node->childCount() > 0)
    {
        for(int i = 0; i < node->childCount(); i ++)
        {
            del(node->child(i));
        }
    }
    else
    {
        delete node;
    }
}



void MainWindow::keyPressEvent(QKeyEvent *k)
{
    //刷新树

    if(k->modifiers() == Qt::ControlModifier && k->key() == Qt::Key_F)
    {
        QString path = QCoreApplication::applicationDirPath();
        QString DBused = path + "/database_use.csv";
        QFile file(DBused);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        qDebug() << ba;
        QString database_used = QString(ba);
        file.close();
        // table_name用于记录表名，database_used记录正在使用的数据库



        path = path + '/' + database_used;
        qDebug() << "F键被按下" << path << "\n";
        if(item){
            if(item->childCount() > 0)
                {
                    for(int i = 0; i < item->childCount(); i ++)
                    {
                        del(item->child(i));
                    }
                }
                delete item;
        }
        item = new QTreeWidgetItem;

        item->setText(0,database_used);
        ui->treeWidgetDB->addTopLevelItem(item);

        QDir *dir=new QDir(path);
        QStringList filter;
        QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
        for(int i = 0;i<fileInfo->count(); i++)
        {

            QRegExp rx("(.*)_data.csv");


            if(rx.indexIn(fileInfo->at(i).fileName())==0)
            {

                QString value = rx.cap(1);
                qDebug() << value;
                itemD = new QTreeWidgetItem;
                itemD -> setText(0,value);
                item->addChild(itemD);

            }



        }
    }
}

void MainWindow::deleteSQL(QString username, QString sql)
{
    int count = 0;  //记录受影响行数
    int index = -1;  // 用于记录下标
    QString path = QCoreApplication::applicationDirPath();
    QString DBused = path + "/database_use.csv";
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    qDebug() << ba;
    QString database_used = QString(ba);
    file.close();


    // table_name用于记录表名，database_used记录正在使用的数据库

    qDebug() << username << sql << "\n";
//    delete from student where id=2;
    QRegExp rx("delete from (.*) where (.*)=(.*);");
    if(rx.indexIn(sql)==0)
    {

        QString table_name = rx.cap(1);
        QString field_name = rx.cap(2);
        QString value = rx.cap(3);
        qDebug() << table_name << field_name << value << "\n";

        QString istrFileName = path + '/' + database_used + '/' + table_name + ".csv";
        QString dataFileName = path + '/' + database_used + '/' + table_name + "_data.csv";

        QFile file(istrFileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "ERROR", "该表不存在与<database:"+database_used+">");
            return;
        }
        file.close();

        //判断列是否存在

        QFile csvTableInstructionFile(istrFileName);
        csvTableInstructionFile.open(QIODevice::ReadWrite|QIODevice::Text);
        QTextStream * out = new QTextStream(&csvTableInstructionFile);
        QStringList tempOption = out->readAll().split("\n");//每行以\n区分
        qDebug() << out->readAll();


        for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
        {
             QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
             if (tempbar[0] == field_name)
             {
                 index = i;
             }

        }
        csvTableInstructionFile.close();//操作完成后记得关闭文件

        // 删除
        bool flag = false;
        QString output = "";
        if(index>=0)
        {
            QFile csvTabledataFile(dataFileName);
            csvTabledataFile.open(QIODevice::ReadWrite|QIODevice::Text);
            QTextStream * out = new QTextStream(&csvTabledataFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分
            qDebug() << out->readAll();




            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                if(i==0)
                {
                    output += tempOption.at(i) + "\n";
                    continue;
                }
                 QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
        //         qDebug() << tempbar[0];
                 if (tempbar[index] != value)
                 {
                     output += tempOption.at(i) + "\n";
                 }else
                 {
                     flag = true;
                     count++;
                 }

            }
            csvTabledataFile.close();//操作完成后记得关闭文件




        }else{
            QMessageBox::warning(this, "Error", "未发现匹配字段！");
            return;
        }

        if(flag)
        {
            QFile fileW(dataFileName);
            fileW.open(QIODevice::WriteOnly);

            QByteArray bytes = output.toUtf8();
            fileW.write(bytes);  // 写入后面要使用的数据库
            fileW.close();
            QMessageBox::warning(this, "Success", "删除<table:" + field_name + ">字段成功！\n"
                                 + QString::number(count, 10) + "行受影响！");
            return;  //QString::number(count, 10)int转为字符串
        }else{
            QMessageBox::warning(this, "Warning", "未发现匹配项！");
            return;
        }

    }else{
        QMessageBox::warning(this, "ERROR", "输入有误！");
        return;
    }




}



void MainWindow::on_pushButtonCommitQ_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QFile fileW(userlogining);
    fileW.open(QIODevice::ReadOnly);

    QByteArray bytes = fileW.readAll();
    QString username = QString(bytes);

    fileW.close();
    qDebug() << bytes;


    QString sql = ui->textEditSQL->toPlainText();
//    int m = a.find(QRegExp("123"), 0);

    int i = 0;
    i++;
    deleteSQL(username, sql);


}

void MainWindow::on_pushButtonCMD_clicked()
{
    system("C:\\Users\\37536\\Desktop\\database_cp\\main.exe");
}
