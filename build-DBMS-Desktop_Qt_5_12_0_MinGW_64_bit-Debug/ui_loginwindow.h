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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonLogin;
    QPushButton *pushButtonCancel;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditForname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditForpass;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName(QString::fromUtf8("loginWindow"));
        loginWindow->resize(400, 300);
        label = new QLabel(loginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 81, 31));
        widget = new QWidget(loginWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 230, 201, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonLogin = new QPushButton(widget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));

        horizontalLayout->addWidget(pushButtonLogin);

        pushButtonCancel = new QPushButton(widget);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        widget1 = new QWidget(loginWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(70, 80, 281, 111));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditForname = new QLineEdit(widget1);
        lineEditForname->setObjectName(QString::fromUtf8("lineEditForname"));

        horizontalLayout_2->addWidget(lineEditForname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEditForpass = new QLineEdit(widget1);
        lineEditForpass->setObjectName(QString::fromUtf8("lineEditForpass"));

        horizontalLayout_3->addWidget(lineEditForpass);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QApplication::translate("loginWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("loginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\347\231\273\345\275\225</span></p></body></html>", nullptr));
        pushButtonLogin->setText(QApplication::translate("loginWindow", "\347\231\273\345\275\225", nullptr));
        pushButtonCancel->setText(QApplication::translate("loginWindow", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("loginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("loginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\257\206   \347\240\201</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
