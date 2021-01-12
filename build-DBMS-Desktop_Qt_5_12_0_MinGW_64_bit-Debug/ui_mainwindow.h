/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_L;
    QAction *action_R;
    QAction *action_C;
    QAction *action_CreateTable;
    QAction *action_E;
    QAction *action_Q;
    QWidget *centralWidget;
    QPushButton *pushButtonCommitQ;
    QTextEdit *textEditSQL;
    QMenuBar *menuBar;
    QMenu *menu_U;
    QMenu *menu_R;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(828, 586);
        action_L = new QAction(MainWindow);
        action_L->setObjectName(QString::fromUtf8("action_L"));
        action_R = new QAction(MainWindow);
        action_R->setObjectName(QString::fromUtf8("action_R"));
        action_C = new QAction(MainWindow);
        action_C->setObjectName(QString::fromUtf8("action_C"));
        action_CreateTable = new QAction(MainWindow);
        action_CreateTable->setObjectName(QString::fromUtf8("action_CreateTable"));
        action_E = new QAction(MainWindow);
        action_E->setObjectName(QString::fromUtf8("action_E"));
        action_Q = new QAction(MainWindow);
        action_Q->setObjectName(QString::fromUtf8("action_Q"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonCommitQ = new QPushButton(centralWidget);
        pushButtonCommitQ->setObjectName(QString::fromUtf8("pushButtonCommitQ"));
        pushButtonCommitQ->setGeometry(QRect(700, 230, 111, 31));
        textEditSQL = new QTextEdit(centralWidget);
        textEditSQL->setObjectName(QString::fromUtf8("textEditSQL"));
        textEditSQL->setGeometry(QRect(33, 43, 761, 151));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 828, 17));
        menu_U = new QMenu(menuBar);
        menu_U->setObjectName(QString::fromUtf8("menu_U"));
        menu_R = new QMenu(menuBar);
        menu_R->setObjectName(QString::fromUtf8("menu_R"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_U->menuAction());
        menuBar->addAction(menu_R->menuAction());
        menu_U->addAction(action_L);
        menu_U->addAction(action_R);
        menu_U->addAction(action_Q);
        menu_R->addAction(action_C);
        menu_R->addAction(action_CreateTable);
        menu_R->addAction(action_E);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_L->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225(&L)", nullptr));
        action_R->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214(&R)", nullptr));
        action_C->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272/\351\200\211\346\213\251\346\225\260\346\215\256\345\272\223(&C)", nullptr));
        action_CreateTable->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272\350\241\250(&T)", nullptr));
        action_E->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\350\241\250(&E)", nullptr));
        action_Q->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\346\235\203\351\231\220(&Q)", nullptr));
        pushButtonCommitQ->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\346\237\245\350\257\242", nullptr));
        menu_U->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267(&U)", nullptr));
        menu_R->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\346\223\215\344\275\234(&D)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
