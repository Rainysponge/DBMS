/********************************************************************************
** Form generated from reading UI file 'createdatabasewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDATABASEWINDOW_H
#define UI_CREATEDATABASEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createDatabaseWindow
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCreateDB;
    QPushButton *pushButtonChoose;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditDBName;

    void setupUi(QDialog *createDatabaseWindow)
    {
        if (createDatabaseWindow->objectName().isEmpty())
            createDatabaseWindow->setObjectName(QString::fromUtf8("createDatabaseWindow"));
        createDatabaseWindow->resize(640, 480);
        label = new QLabel(createDatabaseWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 30, 191, 61));
        layoutWidget = new QWidget(createDatabaseWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(370, 300, 261, 101));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonCreateDB = new QPushButton(layoutWidget);
        pushButtonCreateDB->setObjectName(QString::fromUtf8("pushButtonCreateDB"));

        horizontalLayout->addWidget(pushButtonCreateDB);

        pushButtonChoose = new QPushButton(layoutWidget);
        pushButtonChoose->setObjectName(QString::fromUtf8("pushButtonChoose"));

        horizontalLayout->addWidget(pushButtonChoose);

        layoutWidget1 = new QWidget(createDatabaseWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(130, 120, 381, 121));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditDBName = new QLineEdit(layoutWidget1);
        lineEditDBName->setObjectName(QString::fromUtf8("lineEditDBName"));

        horizontalLayout_2->addWidget(lineEditDBName);


        retranslateUi(createDatabaseWindow);

        QMetaObject::connectSlotsByName(createDatabaseWindow);
    } // setupUi

    void retranslateUi(QDialog *createDatabaseWindow)
    {
        createDatabaseWindow->setWindowTitle(QApplication::translate("createDatabaseWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("createDatabaseWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\345\210\233\345\273\272/\351\200\211\346\213\251\346\225\260\346\215\256\345\272\223</span></p></body></html>", nullptr));
        pushButtonCreateDB->setText(QApplication::translate("createDatabaseWindow", "\345\210\233\345\273\272", nullptr));
        pushButtonChoose->setText(QApplication::translate("createDatabaseWindow", "\351\200\211\346\213\251", nullptr));
        label_2->setText(QApplication::translate("createDatabaseWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\225\260\346\215\256\345\272\223\345\220\215</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createDatabaseWindow: public Ui_createDatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDATABASEWINDOW_H
