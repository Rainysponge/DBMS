/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_table
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditTableName;
    QTableWidget *tableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_S;
    QPushButton *pushButton_insert;
    QPushButton *pushButton_delete;

    void setupUi(QDialog *table)
    {
        if (table->objectName().isEmpty())
            table->setObjectName(QString::fromUtf8("table"));
        table->resize(781, 496);
        pushButton = new QPushButton(table);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 30, 80, 41));
        layoutWidget = new QWidget(table);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 30, 551, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditTableName = new QLineEdit(layoutWidget);
        lineEditTableName->setObjectName(QString::fromUtf8("lineEditTableName"));

        horizontalLayout->addWidget(lineEditTableName);

        tableWidget = new QTableWidget(table);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 100, 701, 271));
        widget = new QWidget(table);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(330, 390, 411, 91));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_S = new QPushButton(widget);
        pushButton_S->setObjectName(QString::fromUtf8("pushButton_S"));

        horizontalLayout_2->addWidget(pushButton_S);

        pushButton_insert = new QPushButton(widget);
        pushButton_insert->setObjectName(QString::fromUtf8("pushButton_insert"));

        horizontalLayout_2->addWidget(pushButton_insert);

        pushButton_delete = new QPushButton(widget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));

        horizontalLayout_2->addWidget(pushButton_delete);


        retranslateUi(table);

        QMetaObject::connectSlotsByName(table);
    } // setupUi

    void retranslateUi(QDialog *table)
    {
        table->setWindowTitle(QApplication::translate("table", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("table", "\346\211\223\345\274\200\350\257\245\350\241\250", nullptr));
        label->setText(QApplication::translate("table", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\350\241\250  \345\220\215</span></p></body></html>", nullptr));
        pushButton_S->setText(QApplication::translate("table", "\344\277\235\345\255\230\344\277\256\346\224\271", nullptr));
        pushButton_insert->setText(QApplication::translate("table", "\346\217\222\345\205\245\350\241\214", nullptr));
        pushButton_delete->setText(QApplication::translate("table", "\345\210\240\351\231\244\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class table: public Ui_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
