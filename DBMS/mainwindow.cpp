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
//        if(item){
//            qDebug() << QString(item->childCount());
//        }
        item->setText(0,database_used);
        ui->treeWidgetDB->addTopLevelItem(item);

        QDir *dir=new QDir(path);
        QStringList filter;
        QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir->entryInfoList(filter));
        for(int i = 0;i<fileInfo->count(); i++)
        {
//            qDebug()<<fileInfo->at(i).filePath();
            QRegExp rx("(.*)_data.csv");
//            qDebug() << rx.indexIn(fileInfo->at(i).fileName());

            if(rx.indexIn(fileInfo->at(i).fileName())==0)
            {
//                qDebug()<<fileInfo->at(i).fileName();

                QString value = rx.cap(1);
                qDebug() << value;
                itemD = new QTreeWidgetItem;
                itemD -> setText(0,value);
                item->addChild(itemD);

            }



        }
    }
}

void test()
{
    qDebug() << "Hello" << "\n";
}



void MainWindow::on_pushButtonCommitQ_clicked()
{
    int i = 0;
    i++;

    system("C:\\Users\\37536\\Desktop\\database_cp\\main.exe");

}
