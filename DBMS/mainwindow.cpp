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
    connect(ui->action_EditTableInfo, &QAction::triggered,
            this, &MainWindow::changeTableInfoSlot);
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
        QStringList tempOption = out->readAll().split("\n");  // 每行以\n区分
        qDebug() << out->readAll();


        for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
        {
             QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
             if (tempbar[0] == field_name)
             {
                 index = i;
             }

        }
        csvTableInstructionFile.close();  //  操作完成后记得关闭文件

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
            csvTabledataFile.close();  // 操作完成后记得关闭文件




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

void MainWindow::useSQL(QString username, QString sql)
{
    QRegExp rx("use (.*);");
    qDebug() << username;
    if(rx.indexIn(sql)==0)
    {
        QString database_to_use = rx.cap(1);  // 保存要使用的database名

        QString path = QCoreApplication::applicationDirPath();
        QString pathForFold = path + '/' + database_to_use;
        QDir *folder = new QDir;

        bool exist = folder->exists(pathForFold);
        QString DBused = path + "/database_use.csv";  // 该CSV中保存着正在使用的database


        // exist为True时判断存在该库
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
            if(database_used == database_to_use || database_used.isEmpty())
            {
                QMessageBox::warning(this, "提示", "当前数据库为<database:"+database_used+">!");
                qDebug() << "database_used == dir";
            }else{
                QFile fileW(DBused);
                fileW.open(QIODevice::WriteOnly);

                QByteArray bytes = database_to_use.toUtf8();
                fileW.write(bytes);  // 写入后面要使用的数据库
                fileW.close();

                QMessageBox::warning(this, "提示",
                                     "已经从数据库为<database:"+database_used+">转换为<database:"+database_to_use+">!");
                qDebug() << "database_used.isNotEmpty()";
            }





        }else{
            QMessageBox::warning(this, "Warning", "不存在<database:"+database_to_use+">!");
        }



    }



}

void MainWindow::createSQL(QString username, QString sql)
{
//    create table student (id int NOT NULL PRIMARY KEY,name char(),age int);
    int primaryKey_exist = 0;

    qDebug() << username << sql << "\n";

    QRegExp rx("create table (.*) [(|（](.*)[)|）][;|；]");
    if(rx.indexIn(sql)==0)
    {
        QString table_name = rx.cap(1);
        QStringList fieldList = rx.cap(2).split(',');

        if(rx.cap(2) == "")
        {
            QMessageBox::warning(this, "warning", "该表没有任何属性！");
            return;
        }
        qDebug() << table_name << fieldList[0] << "\n";

        QString path = QCoreApplication::applicationDirPath();
        QString DBused = path + "/database_use.csv";
        QFile file(DBused);
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        qDebug() << ba;
        QString database_used = QString(ba);
        file.close();

        // database_used 存正在使用的数据库
        QString lineInfo = "";
        QString lineDataInfo = "";
        QString table_path = path + "/" + database_used + "/" + table_name + ".csv";
        QString table_data_path = path + "/" + database_used + "/" + table_name + "_data.csv";
        QFile * tempFile = new QFile;
        if(tempFile->exists(table_data_path))
        {
            qDebug()<<QObject::tr("文件存在");
            QMessageBox::warning(this, "warning", "<database:"+database_used+">中似乎已经有<table:"+table_name + ">了！");
            return;
        }

        // sql处理
        for(int i=0;i < fieldList.count();i++)
        {
            QStringList field_info_list = fieldList.at(i).split(" ");
            qDebug() << field_info_list.at(0) << field_info_list.at(1) << "\n";
            if(field_info_list.count() < 2)
            {
                QMessageBox::warning(this, "ERROR", "输入属性有误或缺失必要信息！");
                return;
            }

            // 输入仅为字段名和类型
            if(field_info_list.count()==2)
            {
                QRegExp Type("(.*) \b(int|bool|char())\b(.*)");
                if(Type.indexIn(field_info_list.at(1)))
                {
                    lineInfo += field_info_list.at(0) + "," + field_info_list.at(1) + ",0,1\n";
                    // 默认可以为空且不是主键
                    lineDataInfo += field_info_list.at(0) + ",";
                }
                else
                {
                    QMessageBox::warning(this, "ERROR", "输入属性类型有误！");
                    return;
                }
            }
            // 有主键等属性
            if(field_info_list.count()>2)
            {
                QRegExp PK("(.*) PRIMARY KEY(.*)");
                QRegExp NOTNULL("(.*) NOT NULL(.*)");

                int judge = -1;   // 0表示既不是主键，又不能为空，1表示是主键，2表示不是主键，且可以为空
                if(PK.indexIn(fieldList.at(i))==0)
                {
                    judge = 1;
                }else
                {
                    if(NOTNULL.indexIn(fieldList.at(i))==0)
                    {
                        judge = 2;
                    }
                }
                if(judge<0)
                {
                    QMessageBox::warning(this, "ERROR", "输入属性拓展有误！");
                    return;
                }

                if(judge==0)
                {
                    lineInfo += field_info_list[0] + "," + field_info_list[1] + ",0,0\n";
                    lineDataInfo += field_info_list.at(0) + ",";
                }
                if(judge==1)
                {
                    primaryKey_exist += 1;
                    if(primaryKey_exist > 1)
                    {
                        QMessageBox::warning(this, "ERROR", "主键过多！");
                        return;
                    }
                    lineInfo += field_info_list[0] + "," + field_info_list[1] + ",1,0\n";
                    lineDataInfo += field_info_list.at(0) + ",";
                }
                if(judge==2)
                {
                    lineDataInfo += field_info_list.at(0) + ",";
                    lineInfo += field_info_list[0] + "," + field_info_list[1] + ",0,1\n";
                }
            }
        }
        qDebug() << lineInfo << "\n" << lineDataInfo;

        if(primaryKey_exist < 1)
        {
            QMessageBox::warning(this, "ERROR", "未设置主键！");
            return;
        }

        tempFile->setFileName(table_path);
        QFile * datatmpFile = new QFile;
        datatmpFile->setFileName(table_data_path);
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


        QFile csvFile(table_path);
        if(!csvFile.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            qDebug()<<QObject::tr("打开失败");
            QMessageBox::warning(this, "ERROR", "Something wrong happened!");
        }else{

            QTextStream in(&csvFile);
            in<<lineInfo;


            QMessageBox::warning(this, "Success", "该表已经成功被创建！");
        }
        csvFile.close();
        QFile datacsvFile(table_data_path);
        datacsvFile.open(QIODevice::WriteOnly);
        lineDataInfo += "\n";
        QByteArray bytes = lineDataInfo.toUtf8();
        datacsvFile.write(bytes);  // 写入
        datacsvFile.close();

    }


    else
    {
        QMessageBox::warning(this, "ERROR", "SQL输入有误");
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
//    deleteSQL(username, sql);
//    useSQL(username, sql);
    createSQL(username, sql);

}

void MainWindow::on_pushButtonCMD_clicked()
{
    system("C:\\Users\\37536\\Desktop\\database_cp\\main.exe");
}

void MainWindow::changeTableInfoSlot()
{
    table *w = new table();
    w->show();
}

