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
//        qDebug() << table_name << fieldList[0] << "\n";

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
                    if(i < fieldList.count()-1)
                        lineDataInfo += field_info_list.at(0) + ",";
                    else {
                        lineDataInfo += field_info_list.at(0);
                    }
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
                    if(i < fieldList.count()-1)
                        lineDataInfo += field_info_list.at(0) + ",";
                    else {
                        lineDataInfo += field_info_list.at(0);
                    }
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
                    if(i < fieldList.count()-1)
                        lineDataInfo += field_info_list.at(0) + ",";
                    else {
                        lineDataInfo += field_info_list.at(0);
                    }
                }
                if(judge==2)
                {
                    if(i < fieldList.count()-1)
                        lineDataInfo += field_info_list.at(0) + ",";
                    else {
                        lineDataInfo += field_info_list.at(0);
                    }
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

void split(const QString &strtem, const char a , QVector<QString> &res)
{
    res.clear();
    QStringList filter;
    filter = strtem.split(a);
    for(int i=0;i<filter.size();i++)
    {
        res.push_back(filter[i]);
    }
}

bool MainWindow::check_insertData(QString table_name, QString database_used,QVector<QString> all_data_name,QVector<QString> all_insert_data)
{
    QString path = QCoreApplication::applicationDirPath();
    QString tableFile = path + '/' + database_used + '/' + table_name + ".csv";
    QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";

    int record = 0; //记录主键为哪一列


    QStringList name;
    QStringList type;
    QString PrimaryKey;
    QStringList NotNull_name;

    QStringList type_record;//记录插入数据的数据类型
    for(int i=0;i<all_insert_data.size();i++)
    {
        QRegExp pattern("(true|TRUE|false|FALSE)");
        QRegExp pattern2("[0-9]+");
        int pos = pattern.indexIn(all_insert_data[i]);
        int pos2 = pattern2.indexIn(all_insert_data[i]);
        if(all_insert_data[i].indexOf('\'')>-1) type_record.append("char()");
        else if(pos>-1) type_record.append("bool");
        else if(pos2>-1) type_record.append("int");
        else {
            QMessageBox::warning(this, "ERROR", "worng with insert data's value");return false;
        }
    }



    QFile infile(tableFile);
    if(!infile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<QObject::tr("打开失败0");
            QMessageBox::warning(this, "ERROR", "Something wrong happened!");
        }
    else{
        //QString sweep = infile.readLine();
        QStringList temp_string = QString(infile.readAll()).split("\n");
        temp_string.removeAll(QString(""));
        for(int i=0;i<temp_string.size();i++)
        {
            QStringList word = temp_string[i].split(',');
            qDebug()<<"word:"<<i<<word;
            name.append(word[0]);
            type.append(word[1]);
            if (word[2]== "1") {PrimaryKey = word[0]; record = i;}
            if (word[3]== "0") NotNull_name.append(word[0]);
            word.clear();
        }

        qDebug()<<"record:" <<record << PrimaryKey << NotNull_name;

        //判断类型是否匹配
        for(int m=0;m<name.size();m++)
        {
            for(int n=0;n<all_data_name.size();n++)
            {
                if (all_data_name[n]==name[m])
                {
                    if(type_record[n]!=type[m]) {QMessageBox::warning(this, "ERROR", "worng with insert data's type");return false;}
                }
            }
        }


        //判断非空
        for(int i=0;i<NotNull_name.size();i++)
        {
            if(all_data_name.indexOf(NotNull_name[i]) <= -1) {QMessageBox::warning(this, "ERROR", NotNull_name[i]+"can't be NULL");return false;}
        }

        //判断主键不重复
        for(int j=0;j<all_data_name.size();j++)
        {
            if (all_data_name[j]==PrimaryKey)
            {
                QFile infile2(dataFile);
                if(!infile2.open(QIODevice::ReadOnly|QIODevice::Text)){
                        qDebug()<<QObject::tr("打开失败1");
                        QMessageBox::warning(this, "ERROR", "Something wrong happened!");
                    }
                else{
                    QStringList temp_data = QString(infile2.readAll()).split("\n");
                    temp_data.removeAll(QString(""));
                    for(int i=0;i<temp_data.size();i++)
                    {
                        QString sweep = infile.readLine(); //第一行不要
                        QStringList temp_data_word = temp_data[i].split(',');
                        if (temp_data_word[record]==all_insert_data[j]) {QMessageBox::warning(this, "ERROR", "can't exist same pk");return false;}
                        //if (temp_data_word[3]==1) NotNull_name.append(temp_data_word[0]);
                        temp_data_word.clear();
                    }
                    infile2.close();
                }
            }
            //else if (NOTall_data_name[j]) {}
        }
        infile.close();
    }
    return true;
}




void  MainWindow::selectData(QString sql)
{
    int x = 0;//记录行数
    int y = 0;//记录列数
    QString str = sql;
    QString csv = "_data.csv";
    QString title;// 表的属性名
    QString table_name;// 表文件名
    QString result_name;
    QString condition;
    QVector<QString> title_name;
    QVector<QString> splited_raw_data;
    QVector<QString> need_title;
    QVector<QVector<QString>> temp_answer;
    QVector<QVector<QString>> answer;//搜索结果，行列倒置？
    QVector<QString> temp;
    QVector<QString> condition_construct;
    QString final_anwser="";

    QString data_csv = "_data.csv";

    //qDebug()<<1;

    QString path = QCoreApplication::applicationDirPath();
    QString DBused = path + "/database_use.csv";
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    //qDebug() << ba;
    QString database_used = QString(ba);


    file.close();


    //QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv"; //要改

    QRegExp pattern("select (.*) from (.*);");


    QRegExp pattern2("select (.*) from (.*) where (.*);");
    int pos = pattern.indexIn(str);
    int pos2 = pattern2.indexIn(str);

    //无where查询

     if (pos>-1 && pos2<=-1)
     {

         table_name = pattern.cap(2);
         result_name = pattern.cap(1);

         QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";
         qDebug()<<2;
         QFile File2(dataFile);

         if(!File2.open(QIODevice::ReadOnly|QIODevice::Text)){
             qDebug()<<QObject::tr("打开失败");
             QMessageBox::warning(this, "ERROR", "Something wrong happened!");
         }
        else{

             title = File2.readLine();
             title = title.simplified();
             QVector<QVector<QString>> content;
             //QVector<QString> temp;
             QStringList temp_string = QString(File2.readAll()).split("\n");
             temp_string.removeAll(QString(""));
             qDebug() << "temp_tring"<<temp_string;

             for(int i=0;i<temp_string.size();i++)
             {
                 split(temp_string[i],',',temp);
                 content.push_back(temp);
                 x = temp.size(); //记录列数
                 temp.clear();
             }
             y = content.size(); //记录行数



             title = QString(title);
             split(title,',',title_name);

            if(result_name == "*"){
                for(int k=0;k<x;k++)
                {
                    qDebug()<<title_name[k]<<"|";
                    if (k!=x-1) final_anwser = final_anwser + title_name[k] + ',';
                    else final_anwser += title_name[k];
                }
                final_anwser += '\n';
                qDebug()<<'\n';
                qDebug()<<"---------------------------"<<'\n';

                for(int i=0;i<y;i++)
                {
                    for(int j=0;j<x;j++)
                    {
                        qDebug()<< content[i][j]<<"|";
                        if(j!=x-1) final_anwser += content[i][j] + ',';
                        else final_anwser += content[i][j];
                    }
                    final_anwser += '\n';
                    qDebug()<<'\n';
                }
            }
            else{
                split(result_name,',',need_title);
                for(int z=0;z<need_title.size();z++)
                {
                    qDebug()<<need_title[z]<<"|";
                    if(z!=need_title.size()-1) final_anwser += need_title[z] + ',';
                    else final_anwser += need_title[z];
                }
                qDebug()<<'\n';
                final_anwser += '\n';
                qDebug()<<"---------------------------"<<'\n';

                for(int i=0;i<x;i++)
                {
                    for(int j=0;j<need_title.size();j++)
                    {
                        if ((need_title[j]==title_name[i]))
                        {
                            for(int k=0;k<y;k++)
                            //qDebug()<< content[k][i]<<"|"<<'\n';
                            temp.push_back(QString(content[k][i]));
                            qDebug()<<temp[2]<<'\n';
                            answer.push_back(temp);//需要倒置输出
                            temp.clear();
                        }
                        //qDebug()<<'\n';
                    }
                }

               for(int i=0;i<y;i++)
                {
                    for(int j=0;j<answer.size();j++)
                     {   qDebug()<<answer[j][i]<<"|";
                        if(j!=answer.size()) final_anwser += answer[j][i] + ',';
                        else final_anwser += answer[j][i];
                     }
                    final_anwser += '\n';
                    qDebug()<<'\n';
                }
                //qDebug()<<1;
            }
            File2.close();
        }

     }

     //带where的sql查询
     else if(pos2>-1)
     {
         qDebug()<<3;
         table_name = pattern2.cap(2);
         result_name = pattern2.cap(1);
         //table_name = table_name + csv;
         condition = pattern2.cap(3);

         //连接表
         if (table_name.indexOf(",")>-1)
         {
             int x2=0;//记录表2列数
             int y2=0;

             int record1=0;//记录连接属性为表中哪一列
             int record2=0;
             QStringList all_table_name = table_name.split(',');
//             QString table1 = path + '/' + database_used + '/' + all_table_name[0] + ".csv";
//             QString table2 = path + '/' + database_used + '/' + all_table_name[1] + ".csv";
             QString table1_data = path + '/' + database_used + '/' + all_table_name[0] + "_data.csv";
             QString table2_data = path + '/' + database_used + '/' + all_table_name[1] + "_data.csv";

//             QFile mfile1(table1);
//             QFile mfile2(table2);
             QFile mfile3(table1_data);
             QFile mfile4(table2_data);

             QStringList restrict = condition.split('=');
             QStringList all_connect_title = restrict[0].split('.');
             QString connect_title = all_connect_title[1];

             mfile3.open(QIODevice::ReadOnly|QIODevice::Text);
             QString title1a;
             title1a = mfile3.readLine();
             title1a = title1a.simplified();
             QStringList title1 = title1a.split(',');
             title1.removeAll(QString(""));


             QVector<QVector<QString>> content1;
             QStringList temp_string1 = QString(mfile3.readAll()).split("\n");
             temp_string1.removeAll(QString(""));
             qDebug() <<"temp_string"<< temp_string1;

             for(int i=0;i<temp_string1.size();i++)
             {
                 split(temp_string1[i],',',temp);
                 content1.push_back(temp);
                 x = temp.size(); //记录列数
                 temp.clear();
             }
             y = content1.size(); //记录行数

             mfile4.open(QIODevice::ReadOnly|QIODevice::Text);
             QString title2a;
             title2a = mfile4.readLine();
             //qDebug()<< title2.size();
             title2a = title2a.simplified();
             QStringList title2 = title2a.split(',');
             title2.removeAll(QString(""));
             QVector<QVector<QString>> content2;
             QStringList temp_string2 = QString(mfile4.readAll()).split("\n");
             temp_string2.removeAll(QString(""));
             qDebug() <<"temp_string"<< temp_string2;

             for(int j=0;j<temp_string2.size();j++)
             {
                 split(temp_string2[j],',',temp);
                 content2.push_back(temp);
                 x2 = temp.size(); //记录列数
                 temp.clear();
             }
             y2 = content2.size(); //记录行数

             for(int m=0;m<title1.size();m++)
             {
                //qDebug()<<title1[m];
                 final_anwser += title1[m] + ",";
                if(title1[m] == connect_title) record1=m;
             }

             qDebug()<<title2.size();
             for(int n=0;n<title2.size();n++)
             {
                //qDebug()<<title2[n];
                if(title2[n] == connect_title) record2=n;
                else {if(n!=title2.size()-1) final_anwser += title2[n] + ",";
                    else  final_anwser += title2[n];}
             }

             qDebug()<<title1<<title2;
             qDebug()<<record1<<x<<y<<x2<<y2;
             final_anwser += '\n';

             for(int p=0;p<y;p++)
             {
                 for(int q=0;q<y2;q++)
                 {
                     if (content1[p][record1]==content2[q][record2])
                     {
                         //找到要存入的两行
                         for(int r=0;r<x;r++)
                         {
                             final_anwser += content1[p][r] + ',';
                         }

                         for(int s=0;s<x2;s++)
                         {
                             if(s!=record2) //排除连接列
                             {
                                 if(s!=x2-1) final_anwser += content2[q][s] + ',';
                                 else final_anwser += content2[q][s];
                             }
                         }
                         final_anwser += '\n';
                     }
                 }
             }
             mfile3.close();
             mfile4.close();
             qDebug()<< "duobiao"<<final_anwser;

         }
         //单表
         else{
             QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";

             qDebug()<< dataFile;

             QFile File2(dataFile);

             if(!File2.open(QIODevice::ReadOnly|QIODevice::Text)){
                 qDebug()<<QObject::tr("打开失败");
                 //QMessageBox::warning(this, "ERROR", "Something wrong happened!");
             }
            else{
                 title = File2.readLine();
                 title = title.simplified();
                 qDebug() <<"title"<< title;
                 QVector<QVector<QString>> content;
                 //QVector<QString> temp;
                 QStringList temp_string = QString(File2.readAll()).split("\n");
                 temp_string.removeAll(QString(""));
                 qDebug() <<"temp_string"<< temp_string;

                 for(int i=0;i<temp_string.size();i++)
                 {
                     split(temp_string[i],',',temp);
                     content.push_back(temp);
                     x = temp.size(); //记录列数
                     temp.clear();
                 }
                 y = content.size(); //记录行数

                 //infile >> title;
                 title = QString(title);
                 split(title,',',title_name);


                if (condition.indexOf("and")>-1)
                    qDebug()<<"unsupported function"<<'\n';
                else if (condition.indexOf("or")> -1)
                    qDebug()<<"unsupported function"<<'\n';
                else{
    //                if(table_name.indexOf(",")>-1)
    //                {

    //                }
    //                else{
                         if(condition.indexOf("=")>-1)
                         {
                             split(condition,'=',condition_construct);
                             if (result_name == "*")//放最外面
                             {
                                for(int k=0;k<x;k++)
                                {
                                    qDebug()<<title_name[k]<<"|";
                                    if(k!=x-1) final_anwser += title_name[k] + ',';
                                    else final_anwser += title_name[k];
                                }
                                final_anwser += '\n';
                                qDebug()<<'\n';
                                qDebug()<<"---------------------------"<<'\n';

                                for(int i=0;i<title_name.size();i++)
                                {
                                        if (condition_construct[0]==title_name[i])  //寻找条件对应的属性,i控制列相同
                                        {
                                            for(int k=0;k<y;k++)
                                            {
                                                if(condition_construct[1]== content[k][i])   //寻找满足条件的值
                                                {
                                                    //qDebug()<<2<<'\n';
                                                    for(int m=0;m<x;m++)
                                                    {
                                                        temp.push_back(content[k][m]);
                                                        //qDebug()<<content[k][m];
                                                    }
                                                    answer.push_back(temp);//把这一行存放到anwser中
                                                    temp.clear();
                                                }
                                            }
                                        }
                                }
                                for(int i=0;i<answer.size();i++)
                                {
                                    for(int j=0;j<x;j++)
                                    {
                                        qDebug()<< answer[i][j]<<"|";
                                        if(j!=x-1) final_anwser += answer[i][j] + ',';
                                        else  final_anwser += answer[i][j];
                                    }
                                    qDebug()<<'\n';
                                    final_anwser += '\n';
                                }
                             }
                             else
                             {
                                 split(result_name,',',need_title);
                                 //先如上挑选数据
                                 for(int i=0;i<title_name.size();i++)
                                 {
                                        if (condition_construct[0]==title_name[i])  //寻找条件对应的属性,i控制列相同
                                        {
                                            for(int k=0;k<y;k++)
                                            {
                                                if(condition_construct[1]== content[k][i])   //寻找满足条件的值
                                                {
                                                    //qDebug()<<2<<'\n';
                                                    for(int m=0;m<x;m++)
                                                    {
                                                        temp.push_back(content[k][m]);
                                                        //qDebug()<<content[k][m];
                                                    }
                                                    temp_answer.push_back(temp);//把这一行存放到anwser中
                                                    temp.clear();
                                                }
                                            }
                                        }
                                 }

                                for(int i=0;i<x;i++)
                                {
                                    for(int j=0;j<need_title.size();j++)
                                    {
                                        if ((need_title[j]==title_name[i]))
                                        {
                                            for(int k=0;k<temp_answer.size();k++)
                                            //qDebug()<< content[k][i]<<"|"<<'\n';
                                            temp.push_back(temp_answer[k][i]);
                                            //qDebug()<<temp[2]<<'\n';
                                            answer.push_back(temp);//需要倒置输出
                                            temp.clear();
                                        }
                                        //qDebug()<<'\n';
                                    }
                                }
                                for(int z=0;z<need_title.size();z++)
                                {
                                    qDebug()<<need_title[z]<<"|";
                                    if(z!=need_title.size()) final_anwser += need_title[z] + ',';
                                    else  final_anwser += need_title[z];
                                }
                                qDebug()<<'\n';
                                final_anwser += '\n';
                                qDebug()<<"---------------------------"<<'\n';

                                //qDebug()<<temp_answer.size()<<'\n';
                                //qDebug()<<answer.size();

                                for(int i=0;i<temp_answer.size();i++)
                                {
                                    for(int j=0;j<answer.size();j++)
                                    {
                                        qDebug()<<answer[j][i]<<"|";
                                        if (j!=answer.size()-1) final_anwser += answer[j][i] + ',';
                                        else  final_anwser += answer[j][i];
                                    }
                                    qDebug()<<'\n';
                                    final_anwser += '\n';
                                }

                             }
                         }

                    }
                // }
                File2.close();
            }
         }
     }
     else
        qDebug()<<"wrong with sql"<<'\n';
     qDebug()<<final_anwser;
     QString result_File = path + "/result.csv";

     QFile File3(result_File);
     File3.open(QIODevice::WriteOnly);
     File3.write(final_anwser.toStdString().data());
     File3.close();

}






void MainWindow::insertData(QString sql)
{
   QString str = sql;
   QString table_name;
   QString insert_data;
   QString data_name;
   QString tail = "_data.csv";
   QString tail2 = ".csv";
   QString temp;
   QString temp_data;
   QString temp_data_name;
   QString filename;
   QString table_filename; //表名
//   QFile outfile;
//   QFile infile;

   QString title;// 表的属性名
   QVector<QString> title_name;
   QVector<QString> all_data_name;
   QVector<QString> all_insert_data;

   QString path = QCoreApplication::applicationDirPath();
   QString DBused = path + "/database_use.csv";
   QFile file(DBused);
   file.open(QIODevice::ReadOnly);
   QByteArray ba = file.readAll();
   QString database_used = QString(ba);

   file.close();


   //QString path = QCoreApplication::applicationDirPath();
   //QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";

   QRegExp pattern("insert into (.*) [(](.*)[)] values [(](.*)[)];");
   int pos = pattern.indexIn(str);

   if (pos>-1){
        table_name = pattern.cap(1);
        data_name = pattern.cap(2);;
        insert_data = pattern.cap(3);;

//        temp = (char*)(table_name.data());
//        temp_data = (char*)(table_name.data());
//        temp_data_name = (char*)(data_name.data());
        filename = table_name+tail;
        split(data_name,',',all_data_name);
        split(insert_data,',',all_insert_data);
        QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";
//        qDebug()<<dataFile;
//        qDebug()<<data_name;
//        qDebug()<<insert_data;

        if(check_insertData(table_name, database_used,all_data_name,all_insert_data)){

            QFile infile(dataFile);

            //读取title名字
            //infile.open(QIODevice::ReadOnly);
            if(!infile.open(QIODevice::ReadOnly|QIODevice::Text)){
                    qDebug()<<QObject::tr("打开失败2");
                    QMessageBox::warning(this, "ERROR", "Something wrong happened!");
                }
            else{
                title =infile.readLine();
                qDebug()<<title;
                title = title.simplified();
                split(title,',',title_name);
                qDebug()<<title_name;

                infile.close();

                qDebug()<<title;
            }

            QFile outfile(dataFile);
            QString final_anwser = "";

            QString record[10000]; //记录最终存放的data样子
            if(!outfile.open(QIODevice::WriteOnly|QIODevice::Append)){
                    qDebug()<<QObject::tr("打开失败3");
                    QMessageBox::warning(this, "ERROR", "Something wrong happened!");
                }
            else
            {
                for(int i = 0; i < title_name.size(); i++)
                {
                    record[i] ="NULL";
                    for(int j=0;j<all_data_name.size();j++)
                    {
    //                   cout<<"1"<<all_data_name[j]<<endl;
    //                   cout<<"2"<<title_name[i]<<endl;
                       if(all_data_name[j]==title_name[i]) {record[i]= all_insert_data[j];break;}
                    }

                    //outfile << record[i] <<"," ;
                    if(i!=title_name.size()-1)
                    {
                       QRegExp strrx("'(.*)'");
                       if(strrx.indexIn(record[i])==0)
                       {
                           final_anwser += strrx.cap(1) + ',';
                       }
                       else{
                            final_anwser += record[i] + ',';
                       }



                    }

                    else{
                        QRegExp strrx("'(.*)'");
                        if(strrx.indexIn(record[i])==0)
                        {
                            final_anwser += strrx.cap(1);
                        }
                        else{
                             final_anwser += record[i];
                        }
                    }

//                        final_anwser += record[i];
                }
                //outfile << endl;
                final_anwser += '\n';
                //qDebug() << final_anwser;
                outfile.write(final_anwser.toStdString().data());
                outfile.close();
                QMessageBox::warning(this, "Success", "Successfully insert");
            }
          }

       }
   else
        QMessageBox::warning(this, "ERROR", "wrong with sql");

}

void MainWindow::grantLimit(QString sql)
{
    QString changeUser;//被修改权限的用户
    int userFlag=0;//检测是否存在要修改的用户

    //检测是否为root用户，否则无权限更改
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QFile fileW(userlogining);
    fileW.open(QIODevice::ReadOnly);

    QByteArray bytes = fileW.readAll();

    fileW.close();

    QString user_root = QString(bytes);
    if(user_root != "root")
    {
        QMessageBox::warning(this, "ERROR", user_root + "没有修改权限！");
        return;
    }

    //sql解析部分
    //qDebug() << user_root << sql << "\n";
    QRegExp rx("grant (.*) to (.*);");
    int flag = rx.indexIn(sql);


    if (flag>-1)
    {
        QStringList changePer = rx.cap(1).split(",");//要修改的权限
        //qDebug() << changePer[0];
        changeUser=rx.cap(2);
        //qDebug() << changeUser;
        QString outputToFile = "";

            QFile csvFile(userpath);
            csvFile.open(QIODevice::ReadWrite|QIODevice::Text);
            QTextStream * out = new QTextStream(&csvFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分
            //qDebug() << out->readAll();
            QString output = "";

            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                 QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
                 if (tempbar[0] == changeUser)
                 {
                     userFlag = 1;
                     for(int j=0; j<changePer.size(); j++)
                     {
                         if(changePer[j]=="write")
                         {
                             tempbar[2]='1';
                             tempbar[4]='1';
                             tempbar[5]='1';
                             tempbar[6]='1';
                             tempbar[7]='1';
                         }
                         else if(changePer[j]=="read")
                         {
                             tempbar[3]='1';
                             tempbar[8]='1';
                             tempbar[9]='1';
                         }
                         else if(changePer[j]=="create")
                             tempbar[4]='1';
                         else if(changePer[j]=="insert")
                             tempbar[5]='1';
                         else if(changePer[j]=="delete")
                             tempbar[6]='1';
                         else if(changePer[j]=="update")
                             tempbar[7]='1';
                         else if(changePer[j]=="select")
                             tempbar[8]='1';
                         else if(changePer[j]=="help")
                             tempbar[9]='1';
                         else if(changePer[j]=="*")
                         {
                             tempbar[2]='1';
                             tempbar[3]='1';
                             tempbar[4]='1';
                             tempbar[5]='1';
                             tempbar[6]='1';
                             tempbar[7]='1';
                             tempbar[8]='1';
                             tempbar[9]='1';
                         }
                         else
                         {
                             QMessageBox::warning(this, "ERROR", "wrong with sql!");
                             return;
                         }
                      }

                            //写入更改

                         outputToFile += changeUser + "," + tempbar[1]+ ",";
                         outputToFile += tempbar[2] + "," + tempbar[3] + "," + tempbar[4];
                         outputToFile += "," + tempbar[5] + "," + tempbar[6] + "," + tempbar[7] + "," + tempbar[8] + "," + tempbar[9] + "\n";
                         csvFile.close();//操作完成后记得关闭文件

                    }else{

                         // ToFile

                         outputToFile += tempbar[0] + "," + tempbar[1];
                         outputToFile += "," + tempbar[2] + "," + tempbar[3] + "," + tempbar[4];
                         outputToFile += "," + tempbar[5] + "," + tempbar[6] + "," + tempbar[7] + "," + tempbar[8] + "," + tempbar[9] + "\n";
                    }

           }
            if(userFlag)
            {
                QFile fileW(userpath);
                fileW.open(QIODevice::WriteOnly);

                QByteArray bytes = outputToFile.toUtf8();
                fileW.write(bytes);  // 写入
                fileW.close();
                QMessageBox::warning(this, "Success", changeUser + "权限修改完成！");
                return;
            }
            else
            {
               QMessageBox::warning(this, "ERROR", "该用户不存在！");
                return;
            }
      }
    else
        QMessageBox::warning(this, "ERROR", "wrong with sql");
}

void MainWindow::revokeLimit(QString sql)
{
    QString changeUser;//被修改权限的用户
    int userFlag=0;//检测是否存在要修改的用户

    //检测是否为root用户，否则无权限更改
    QString path = QCoreApplication::applicationDirPath();
    QString userpath = path + "/user.csv";
    QString userlogining = path + "/user_now.csv";

    QFile fileW(userlogining);
    fileW.open(QIODevice::ReadOnly);

    QByteArray bytes = fileW.readAll();

    fileW.close();

    QString user_root = QString(bytes);
    if(user_root != "root")
    {
        QMessageBox::warning(this, "ERROR", user_root + "没有修改权限！");
        return;
    }

    //sql解析部分
    qDebug() << user_root << sql << "\n";
    QRegExp rx("revoke (.*) from (.*);");
    int flag = rx.indexIn(sql);


    if (flag>-1)
    {
        QStringList changePer = rx.cap(1).split(",");//要修改的权限
        qDebug() << changePer[0];
        changeUser=rx.cap(2);
        qDebug() << changeUser;
        QString outputToFile = "";

            QFile csvFile(userpath);
            csvFile.open(QIODevice::ReadWrite|QIODevice::Text);
            QTextStream * out = new QTextStream(&csvFile);
            QStringList tempOption = out->readAll().split("\n");//每行以\n区分
            //qDebug() << out->readAll();
            QString output = "";

            for(int i = 0 ; i < tempOption.count() - 1 ; i++)  // 去除最后一行
            {
                 QStringList tempbar = tempOption.at(i).split(",");//一行中的单元格以，区分
                 if (tempbar[0] == changeUser)
                 {
                     userFlag = 1;
                     for(int j=0; j<changePer.size(); j++)
                     {
                         if(changePer[j]=="write")
                         {
                             tempbar[2]='0';
                             tempbar[4]='0';
                             tempbar[5]='0';
                             tempbar[6]='0';
                             tempbar[7]='0';
                         }
                         else if(changePer[j]=="read")
                         {
                             tempbar[3]='0';
                             tempbar[8]='0';
                             tempbar[9]='0';
                         }
                         else if(changePer[j]=="create")
                             tempbar[4]='0';
                         else if(changePer[j]=="insert")
                             tempbar[5]='0';
                         else if(changePer[j]=="delete")
                             tempbar[6]='0';
                         else if(changePer[j]=="update")
                             tempbar[7]='0';
                         else if(changePer[j]=="select")
                             tempbar[8]='0';
                         else if(changePer[j]=="help")
                             tempbar[9]='0';
                         else if(changePer[j]=="*")
                         {
                             tempbar[2]='0';
                             tempbar[3]='0';
                             tempbar[4]='0';
                             tempbar[5]='0';
                             tempbar[6]='0';
                             tempbar[7]='0';
                             tempbar[8]='0';
                             tempbar[9]='0';
                         }
                         else
                         {
                             QMessageBox::warning(this, "ERROR", "wrong with sql!");
                             return;
                         }
                      }

                            //写入更改

                         outputToFile += changeUser + "," + tempbar[1]+ ",";
                         outputToFile += tempbar[2] + "," + tempbar[3] + "," + tempbar[4];
                         outputToFile += "," + tempbar[5] + "," + tempbar[6] + "," + tempbar[7] + "," + tempbar[8] + "," + tempbar[9] + "\n";
                         csvFile.close();//操作完成后记得关闭文件

                    }else{

                     // ToFile

                     outputToFile += tempbar[0] + "," + tempbar[1];
                     outputToFile += "," + tempbar[2] + "," + tempbar[3] + "," + tempbar[4];
                     outputToFile += "," + tempbar[5] + "," + tempbar[6] + "," + tempbar[7] + "," + tempbar[8] + "," + tempbar[9] + "\n";
                 }

           }
            if(userFlag)
            {
                QFile fileW(userpath);
                fileW.open(QIODevice::WriteOnly);

                QByteArray bytes = outputToFile.toUtf8();
                fileW.write(bytes);  // 写入
                fileW.close();
                QMessageBox::warning(this, "Success", changeUser + "权限修改完成！");
                return;
            }
            else
            {
               QMessageBox::warning(this, "ERROR", "该用户不存在！");
                return;
            }
      }
        else
            QMessageBox::warning(this, "ERROR", "wrong with sql");
}

void MainWindow::updateData(QString sql)
{
    int x=0;//记录列数
    int y=0;//记录行数
    QString str = sql;
    QString csv = "_data.csv";
    QString title;// 表的属性名
    QString table_name;// 表文件名
    QString result_name;
    QString condition;
    QString final_anwser="";
    QVector<QString> title_name;
    QVector<QString> splited_raw_data;
    QVector<QString> need_title;
    QVector<QVector<QString>> temp_answer;
    //QVector<QVector<QString>> answer;//搜索结果，行列倒置？
    QVector<QString> temp;
    QVector<QString> condition_construct;

    QString path = QCoreApplication::applicationDirPath();
    QString DBused = path + "/database_use.csv";
    QFile file(DBused);
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    QString database_used = QString(ba);

    file.close();

//    ofstream outfile;
//    ifstream infile;

    QRegExp pattern("update (.*) set (.*) where (.*);");
    int pos = pattern.indexIn(str);


    if (pos>-1)
     {
         //ofstream outfile;

         table_name = pattern.cap(1);
         result_name = pattern.cap(2);
         condition = pattern.cap(3);
         //table_name = table_name + csv;

         QString dataFile = path + '/' + database_used + '/' + table_name + "_data.csv";
         qDebug()<<dataFile;

         QFile infile(dataFile);

         //char * temp_table_name = (char*)(table_name.data());

         //infile.open(temp_table_name);

         if(!infile.open(QIODevice::ReadOnly|QIODevice::Text)){
             qDebug()<<QObject::tr("打开失败1");
             QMessageBox::warning(this, "ERROR", "Something wrong happened!");
         }
        else{
             title = infile.readLine();;
             title = title.simplified();
             split(title,',',title_name);

             QVector<QVector<QString>> content;
             //QVector<QString> temp;
             QStringList temp_string = QString(infile.readAll()).split("\n");
             temp_string.removeAll(QString(""));
             qDebug() << "temp_tring"<<temp_string;

             for(int i=0;i<temp_string.size();i++)
             {
                 split(temp_string[i],',',temp);
                 content.push_back(temp);
                 x = temp.size(); //记录列数
                 temp.clear();
             }
             y = content.size(); //记录行数

            infile.close();

            QFile outfile(dataFile);

            if(!outfile.open(QIODevice::WriteOnly)){
                qDebug()<<QObject::tr("打开失败1");
                QMessageBox::warning(this, "ERROR", "Something wrong happened!");
            }
            else
            {
                split(result_name,',',need_title);//存放含有等于号的等式
                for(int i=0;i<need_title.size();i++)
                {
                    split(need_title[i],'=',temp);
                    temp_answer.push_back(temp);
                    temp.clear();
                }

                for(int i=0;i<title_name.size();i++)
                {
                    //outfile << title_name[i]<<",";
                    if(i!=title_name.size()) final_anwser += title_name[i] + ',';
                    else final_anwser += title_name[i];
                }
                final_anwser += '\n';

                qDebug() <<"content:" << content;

                if(condition.indexOf("=")>-1)
                     {
                          split(condition,'=',condition_construct);

                          for(int i=0;i<title_name.size();i++)
                            {
                                    if (condition_construct[0]==title_name[i])  //寻找条件对应的属性,i控制列相同
                                    {
                                        for(int k=0;k<y;k++)
                                        {
                                            if(condition_construct[1]== content[k][i])   //寻找满足条件的值的行
                                            {
                                                //cout<<2<<endl;
                                                for(int m=0;m<x;m++)
                                                {
                                                    for(int n=0;n<temp_answer.size();n++)
                                                        {if(temp_answer[n][0]==title_name[m]) content[k][m]=temp_answer[n][1];}
                                                    //cout<<content[k][m];
                                                }
                                                //answer.push_back(temp);//把这一行存放到anwser中
                                               // temp.clear();
                                            }
                                        }
                                    }
                            }
                     }
                     else  QMessageBox::warning(this, "ERROR", "unsupported funcition!");

                     //写回数据库中
                     for(int i=0;i<y;i++)
                     {
                        for(int j=0;j<x;j++)
                            //outfile<< content[i][j] <<",";
                        {
                            if(j!=x-1) final_anwser += content[i][j] + ',';
                            else  final_anwser += content[i][j];
                        }
                        final_anwser += '\n';
                     }
                     qDebug() <<"anwser" << final_anwser;
                     outfile.write(final_anwser.toStdString().data());
                     outfile.close();
                     QMessageBox::warning(this, "Success", "Successfully update!");
            }
        }

     }
     else
        QMessageBox::warning(this, "ERROR", "wrong with sql");

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


    if (sql.startsWith("insert"))
            insertData(sql);
        else if (sql.startsWith("update"))
            updateData(sql);
        else if (sql.startsWith("select"))
        {
            selectData(sql);
            QVector<QString> x;  // 存储csv文件第1列数据
            QVector<QVector<QString>> qv2;
            int row;
            int col;
            QStringList list1;
            QString path1 = QCoreApplication::applicationDirPath();
            QString resultpath = path1 + "/result.csv";
            QFile fileR(resultpath);
            fileR.open(QIODevice::ReadOnly);
            x.clear(); //x的值
            qv2.clear();


            QTextStream in(&fileR); // 新建文本流对象
            QStringList list;//用于存储逐行数据
            QString fileLine=in.readLine();//逐行读取数据
            list=fileLine.split(",");
            list1=list;
            qDebug()<<list1;
             col =list.count();//列数
            //逐行读取*.csv数据并将每列分别存入x、y数组中
            while(!in.atEnd())
            {
                fileLine=in.readLine();//逐行读取数据
                list=fileLine.split(",");//一行中的单元格以，区分

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
            fileR.close();



            row =qv2.size();//行数

            qDebug()<<row;


            this->ui->tableWidget->setRowCount(row);    //设置行数
            this->ui->tableWidget->setColumnCount(col); //设置列数
            this->ui->tableWidget->setHorizontalHeaderLabels(list1);
            this->ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:grey;}");
            this->ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            this->ui->tableWidget ->setItem(0,0,new QTableWidgetItem("1"));

            for (int i=0;i<row;i++)
            {
            for(int j=0;j<col;j++)
             this->ui->tableWidget ->setItem(i,j,new QTableWidgetItem(qv2[i][j]));
            }
        }

        else if (sql.startsWith("delete"))
            deleteSQL(username, sql);
        else if (sql.startsWith("use"))
            useSQL(username, sql);
        else if (sql.startsWith("create"))
            createSQL(username, sql);
        else if (sql.startsWith("grant"))
            grantLimit(sql);
        else if (sql.startsWith("revoke"))
            revokeLimit(sql);
        else
            QMessageBox::warning(this, "ERROR", "wrong with sql");
//    deleteSQL(username, sql);
//    useSQL(username, sql);
//    createSQL(username, sql);





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

