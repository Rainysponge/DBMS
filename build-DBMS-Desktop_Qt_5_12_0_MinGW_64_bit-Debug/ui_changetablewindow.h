/********************************************************************************
** Form generated from reading UI file 'changetablewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGETABLEWINDOW_H
#define UI_CHANGETABLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_changeTableWindow
{
public:
    QLabel *label;
    QPushButton *pushButtonShowTable;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBoxType;
    QComboBox *comboBoxNULL;
    QLineEdit *lineEditFieldName;
    QLabel *label_5;
    QComboBox *comboBoxPrimary;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditTableName;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonDel;

    void setupUi(QDialog *changeTableWindow)
    {
        if (changeTableWindow->objectName().isEmpty())
            changeTableWindow->setObjectName(QString::fromUtf8("changeTableWindow"));
        changeTableWindow->resize(640, 480);
        label = new QLabel(changeTableWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 30, 141, 51));
        pushButtonShowTable = new QPushButton(changeTableWindow);
        pushButtonShowTable->setObjectName(QString::fromUtf8("pushButtonShowTable"));
        pushButtonShowTable->setGeometry(QRect(500, 90, 111, 41));
        textBrowser = new QTextBrowser(changeTableWindow);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(130, 160, 311, 121));
        layoutWidget = new QWidget(changeTableWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 300, 561, 67));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBoxType = new QComboBox(layoutWidget);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName(QString::fromUtf8("comboBoxType"));

        gridLayout->addWidget(comboBoxType, 1, 1, 1, 1);

        comboBoxNULL = new QComboBox(layoutWidget);
        comboBoxNULL->addItem(QString());
        comboBoxNULL->addItem(QString());
        comboBoxNULL->setObjectName(QString::fromUtf8("comboBoxNULL"));

        gridLayout->addWidget(comboBoxNULL, 1, 3, 1, 1);

        lineEditFieldName = new QLineEdit(layoutWidget);
        lineEditFieldName->setObjectName(QString::fromUtf8("lineEditFieldName"));

        gridLayout->addWidget(lineEditFieldName, 1, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        comboBoxPrimary = new QComboBox(layoutWidget);
        comboBoxPrimary->addItem(QString());
        comboBoxPrimary->addItem(QString());
        comboBoxPrimary->setObjectName(QString::fromUtf8("comboBoxPrimary"));

        gridLayout->addWidget(comboBoxPrimary, 1, 2, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        widget = new QWidget(changeTableWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 90, 371, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditTableName = new QLineEdit(widget);
        lineEditTableName->setObjectName(QString::fromUtf8("lineEditTableName"));

        horizontalLayout->addWidget(lineEditTableName);

        widget1 = new QWidget(changeTableWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(370, 390, 261, 61));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonSave = new QPushButton(widget1);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonDel = new QPushButton(widget1);
        pushButtonDel->setObjectName(QString::fromUtf8("pushButtonDel"));

        horizontalLayout_2->addWidget(pushButtonDel);


        retranslateUi(changeTableWindow);

        QMetaObject::connectSlotsByName(changeTableWindow);
    } // setupUi

    void retranslateUi(QDialog *changeTableWindow)
    {
        changeTableWindow->setWindowTitle(QApplication::translate("changeTableWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("changeTableWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\347\274\226 \350\276\221 \350\241\250</span></p></body></html>", nullptr));
        pushButtonShowTable->setText(QApplication::translate("changeTableWindow", "\346\230\276\347\244\272\350\241\250\347\273\223\346\236\204", nullptr));
        comboBoxType->setItemText(0, QApplication::translate("changeTableWindow", "char()", nullptr));
        comboBoxType->setItemText(1, QApplication::translate("changeTableWindow", "int", nullptr));
        comboBoxType->setItemText(2, QApplication::translate("changeTableWindow", "bool", nullptr));

        comboBoxNULL->setItemText(0, QApplication::translate("changeTableWindow", "\346\230\257", nullptr));
        comboBoxNULL->setItemText(1, QApplication::translate("changeTableWindow", "\345\220\246", nullptr));

        label_5->setText(QApplication::translate("changeTableWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\346\230\257\345\220\246\344\270\272\344\270\273\351\224\256</span></p></body></html>", nullptr));
        comboBoxPrimary->setItemText(0, QApplication::translate("changeTableWindow", "\346\230\257", nullptr));
        comboBoxPrimary->setItemText(1, QApplication::translate("changeTableWindow", "\345\220\246", nullptr));

        label_7->setText(QApplication::translate("changeTableWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\346\230\257\345\220\246\345\217\257\344\270\272\347\251\272</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("changeTableWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\347\261\273\345\236\213</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("changeTableWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\345\255\227\346\256\265\345\220\215</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("changeTableWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\350\241\250   \345\220\215</span></p></body></html>", nullptr));
        pushButtonSave->setText(QApplication::translate("changeTableWindow", "\344\277\256\346\224\271", nullptr));
        pushButtonDel->setText(QApplication::translate("changeTableWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeTableWindow: public Ui_changeTableWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGETABLEWINDOW_H
