/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonCancel;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditUserName;
    QLabel *label_3;
    QLineEdit *lineEditPassWord;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QString::fromUtf8("loginWindow"));
        loginWindow->resize(485, 346);
        label = new QLabel(loginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 20, 81, 31));
        layoutWidget = new QWidget(loginWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(220, 240, 241, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonLogin = new QPushButton(layoutWidget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));

        horizontalLayout->addWidget(pushButtonLogin);

        pushButtonCancel = new QPushButton(layoutWidget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        widget = new QWidget(loginWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 70, 391, 131));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditUserName = new QLineEdit(widget);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));

        gridLayout->addWidget(lineEditUserName, 0, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEditPassWord = new QLineEdit(widget);
        lineEditPassWord->setObjectName(QString::fromUtf8("lineEditPassWord"));
        lineEditPassWord->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassWord, 1, 1, 1, 1);


        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("loginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        pushButtonLogin->setText(QApplication::translate("loginWindow", "\347\231\273\345\275\225", nullptr));
        pushButtonCancel->setText(QApplication::translate("loginWindow", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("loginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("loginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
