/********************************************************************************
** Form generated from reading UI file 'regwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGWINDOW_H
#define UI_REGWINDOW_H

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

class Ui_regWindow
{
public:
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditUserName;
    QLabel *label_3;
    QLineEdit *lineEditPass;
    QLabel *label_4;
    QLineEdit *lineEditPassAgain;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *commitButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *regWindow)
    {
        if (regWindow->objectName().isEmpty())
            regWindow->setObjectName(QString::fromUtf8("regWindow"));
        regWindow->resize(436, 310);
        label = new QLabel(regWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 20, 111, 41));
        widget = new QWidget(regWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 90, 361, 121));
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

        lineEditPass = new QLineEdit(widget);
        lineEditPass->setObjectName(QString::fromUtf8("lineEditPass"));
        lineEditPass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPass, 1, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEditPassAgain = new QLineEdit(widget);
        lineEditPassAgain->setObjectName(QString::fromUtf8("lineEditPassAgain"));
        lineEditPassAgain->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEditPassAgain, 2, 1, 1, 1);

        widget1 = new QWidget(regWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(175, 226, 241, 61));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        commitButton = new QPushButton(widget1);
        commitButton->setObjectName(QString::fromUtf8("commitButton"));

        horizontalLayout->addWidget(commitButton);

        cancelButton = new QPushButton(widget1);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        retranslateUi(regWindow);

        QMetaObject::connectSlotsByName(regWindow);
    } // setupUi

    void retranslateUi(QDialog *regWindow)
    {
        regWindow->setWindowTitle(QApplication::translate("regWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("regWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\346\263\250   \345\206\214</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("regWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("regWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\257\206 \347\240\201</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("regWindow", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">\345\206\215\346\254\241\350\276\223\345\205\245</span></p></body></html>", nullptr));
        commitButton->setText(QApplication::translate("regWindow", "\346\263\250\345\206\214", nullptr));
        cancelButton->setText(QApplication::translate("regWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regWindow: public Ui_regWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
