/********************************************************************************
** Form generated from reading UI file 'createtable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETABLE_H
#define UI_CREATETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createTable
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *tableNameEdit;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditFieldName;
    QLabel *label_4;
    QComboBox *comboBoxType;
    QComboBox *comboBoxPrimary;
    QComboBox *comboBoxNULL;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonCreate;
    QPushButton *pushButtonAddCon;
    QLabel *label_7;

    void setupUi(QDialog *createTable)
    {
        if (createTable->objectName().isEmpty())
            createTable->setObjectName(QString::fromUtf8("createTable"));
        createTable->resize(640, 480);
        label = new QLabel(createTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 20, 161, 41));
        layoutWidget = new QWidget(createTable);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 80, 391, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        tableNameEdit = new QLineEdit(layoutWidget);
        tableNameEdit->setObjectName(QString::fromUtf8("tableNameEdit"));

        horizontalLayout->addWidget(tableNameEdit);

        layoutWidget1 = new QWidget(createTable);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(37, 160, 561, 67));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        lineEditFieldName = new QLineEdit(layoutWidget1);
        lineEditFieldName->setObjectName(QString::fromUtf8("lineEditFieldName"));

        gridLayout->addWidget(lineEditFieldName, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        comboBoxType = new QComboBox(layoutWidget1);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));

        gridLayout->addWidget(comboBoxType, 1, 1, 1, 1);

        comboBoxPrimary = new QComboBox(layoutWidget1);
        comboBoxPrimary->addItem(QString());
        comboBoxPrimary->addItem(QString());
        comboBoxPrimary->setObjectName(QString::fromUtf8("comboBoxPrimary"));

        gridLayout->addWidget(comboBoxPrimary, 1, 2, 1, 1);

        comboBoxNULL = new QComboBox(layoutWidget1);
        comboBoxNULL->addItem(QString());
        comboBoxNULL->addItem(QString());
        comboBoxNULL->setObjectName(QString::fromUtf8("comboBoxNULL"));

        gridLayout->addWidget(comboBoxNULL, 1, 3, 1, 1);

        layoutWidget2 = new QWidget(createTable);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(180, 330, 441, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonCreate = new QPushButton(layoutWidget2);
        pushButtonCreate->setObjectName(QString::fromUtf8("pushButtonCreate"));

        horizontalLayout_2->addWidget(pushButtonCreate);

        pushButtonAddCon = new QPushButton(layoutWidget2);
        pushButtonAddCon->setObjectName(QString::fromUtf8("pushButtonAddCon"));

        horizontalLayout_2->addWidget(pushButtonAddCon);

        label_7 = new QLabel(createTable);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(370, 240, 241, 61));

        retranslateUi(createTable);

        QMetaObject::connectSlotsByName(createTable);
    } // setupUi

    void retranslateUi(QDialog *createTable)
    {
        createTable->setWindowTitle(QApplication::translate("createTable", "Dialog", nullptr));
        label->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\345\210\233\345\273\272\350\241\250</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\350\241\250   \345\220\215</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\255\227\346\256\265\345\220\215</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\346\230\257\345\220\246\344\270\272\344\270\273\351\224\256</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\346\230\257\345\220\246\345\217\257\344\270\272\347\251\272</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\347\261\273\345\236\213</span></p></body></html>", nullptr));
        comboBoxType->setItemText(0, QApplication::translate("createTable", "char()", nullptr));
        comboBoxType->setItemText(1, QApplication::translate("createTable", "int", nullptr));
        comboBoxType->setItemText(2, QApplication::translate("createTable", "bool", nullptr));

        comboBoxPrimary->setItemText(0, QApplication::translate("createTable", "0", nullptr));
        comboBoxPrimary->setItemText(1, QApplication::translate("createTable", "1", nullptr));

        comboBoxNULL->setItemText(0, QApplication::translate("createTable", "0", nullptr));
        comboBoxNULL->setItemText(1, QApplication::translate("createTable", "1", nullptr));

        pushButtonCreate->setText(QApplication::translate("createTable", "\346\226\260\345\273\272", nullptr));
        pushButtonAddCon->setText(QApplication::translate("createTable", "\347\273\247\347\273\255\346\267\273\345\212\240", nullptr));
        label_7->setText(QApplication::translate("createTable", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">0\344\273\243\350\241\250\345\220\246\357\274\2141\344\273\243\350\241\250\346\230\257</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createTable: public Ui_createTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETABLE_H
