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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_L;
    QAction *action_R;
    QAction *action_C;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_U;
    QMenu *menu_R;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        action_L = new QAction(MainWindow);
        action_L->setObjectName(QString::fromUtf8("action_L"));
        action_R = new QAction(MainWindow);
        action_R->setObjectName(QString::fromUtf8("action_R"));
        action_C = new QAction(MainWindow);
        action_C->setObjectName(QString::fromUtf8("action_C"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 17));
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
        menu_R->addAction(action_C);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_L->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225(&L)", nullptr));
        action_R->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214(&R)", nullptr));
        action_C->setText(QApplication::translate("MainWindow", "\345\210\233\345\273\272\346\225\260\346\215\256\345\272\223(&C)", nullptr));
        menu_U->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267(&U)", nullptr));
        menu_R->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\346\223\215\344\275\234(&D)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
