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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonCreateDB;
    QPushButton *pushButtonCancel;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditDBName;

    void setupUi(QDialog *createDatabaseWindow)
    {
        if (createDatabaseWindow->objectName().isEmpty())
            createDatabaseWindow->setObjectName(QString::fromUtf8("createDatabaseWindow"));
        createDatabaseWindow->resize(400, 300);
        label = new QLabel(createDatabaseWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 30, 111, 41));
        widget = new QWidget(createDatabaseWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 220, 201, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonCreateDB = new QPushButton(widget);
        pushButtonCreateDB->setObjectName(QString::fromUtf8("pushButtonCreateDB"));

        horizontalLayout->addWidget(pushButtonCreateDB);

        pushButtonCancel = new QPushButton(widget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        widget1 = new QWidget(createDatabaseWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(60, 120, 291, 51));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditDBName = new QLineEdit(widget1);
        lineEditDBName->setObjectName(QString::fromUtf8("lineEditDBName"));

        horizontalLayout_2->addWidget(lineEditDBName);


        retranslateUi(createDatabaseWindow);

        QMetaObject::connectSlotsByName(createDatabaseWindow);
    } // setupUi

    void retranslateUi(QDialog *createDatabaseWindow)
    {
        createDatabaseWindow->setWindowTitle(QApplication::translate("createDatabaseWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("createDatabaseWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\345\210\233\345\273\272\346\225\260\346\215\256\345\272\223</span></p></body></html>", nullptr));
        pushButtonCreateDB->setText(QApplication::translate("createDatabaseWindow", "\345\210\233\345\273\272", nullptr));
        pushButtonCancel->setText(QApplication::translate("createDatabaseWindow", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("createDatabaseWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\225\260\346\215\256\345\272\223\345\220\215</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createDatabaseWindow: public Ui_createDatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDATABASEWINDOW_H
