/********************************************************************************
** Form generated from reading UI file 'changelimitw.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGELIMITW_H
#define UI_CHANGELIMITW_H

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

class Ui_changeLimitW
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *pushButtonShow;
    QPushButton *pushButtonSummit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditUserName;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboBoxShow;
    QComboBox *comboBoxR;
    QComboBox *comboBoxC;
    QComboBox *comboBoxIn;
    QComboBox *comboBoxdel;
    QComboBox *comboBoxup;
    QComboBox *comboBoxS;
    QComboBox *comboBox_8;

    void setupUi(QDialog *changeLimitW)
    {
        if (changeLimitW->objectName().isEmpty())
            changeLimitW->setObjectName(QString::fromUtf8("changeLimitW"));
        changeLimitW->resize(640, 480);
        label = new QLabel(changeLimitW);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 30, 111, 41));
        textBrowser = new QTextBrowser(changeLimitW);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 170, 441, 91));
        pushButtonShow = new QPushButton(changeLimitW);
        pushButtonShow->setObjectName(QString::fromUtf8("pushButtonShow"));
        pushButtonShow->setGeometry(QRect(489, 90, 121, 41));
        pushButtonSummit = new QPushButton(changeLimitW);
        pushButtonSummit->setObjectName(QString::fromUtf8("pushButtonSummit"));
        pushButtonSummit->setGeometry(QRect(419, 404, 151, 41));
        widget = new QWidget(changeLimitW);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 80, 411, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditUserName = new QLineEdit(widget);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));

        horizontalLayout->addWidget(lineEditUserName);

        widget1 = new QWidget(changeLimitW);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 280, 571, 81));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 4, 1, 1);

        label_8 = new QLabel(widget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 5, 1, 1);

        label_9 = new QLabel(widget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 6, 1, 1);

        label_10 = new QLabel(widget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 7, 1, 1);

        comboBoxShow = new QComboBox(widget1);
        comboBoxShow->addItem(QString());
        comboBoxShow->addItem(QString());
        comboBoxShow->setObjectName(QString::fromUtf8("comboBoxShow"));

        gridLayout->addWidget(comboBoxShow, 1, 0, 1, 1);

        comboBoxR = new QComboBox(widget1);
        comboBoxR->addItem(QString());
        comboBoxR->addItem(QString());
        comboBoxR->setObjectName(QString::fromUtf8("comboBoxR"));

        gridLayout->addWidget(comboBoxR, 1, 1, 1, 1);

        comboBoxC = new QComboBox(widget1);
        comboBoxC->addItem(QString());
        comboBoxC->addItem(QString());
        comboBoxC->setObjectName(QString::fromUtf8("comboBoxC"));

        gridLayout->addWidget(comboBoxC, 1, 2, 1, 1);

        comboBoxIn = new QComboBox(widget1);
        comboBoxIn->addItem(QString());
        comboBoxIn->addItem(QString());
        comboBoxIn->setObjectName(QString::fromUtf8("comboBoxIn"));

        gridLayout->addWidget(comboBoxIn, 1, 3, 1, 1);

        comboBoxdel = new QComboBox(widget1);
        comboBoxdel->addItem(QString());
        comboBoxdel->addItem(QString());
        comboBoxdel->setObjectName(QString::fromUtf8("comboBoxdel"));

        gridLayout->addWidget(comboBoxdel, 1, 4, 1, 1);

        comboBoxup = new QComboBox(widget1);
        comboBoxup->addItem(QString());
        comboBoxup->addItem(QString());
        comboBoxup->setObjectName(QString::fromUtf8("comboBoxup"));

        gridLayout->addWidget(comboBoxup, 1, 5, 1, 1);

        comboBoxS = new QComboBox(widget1);
        comboBoxS->addItem(QString());
        comboBoxS->addItem(QString());
        comboBoxS->setObjectName(QString::fromUtf8("comboBoxS"));

        gridLayout->addWidget(comboBoxS, 1, 6, 1, 1);

        comboBox_8 = new QComboBox(widget1);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));

        gridLayout->addWidget(comboBox_8, 1, 7, 1, 1);


        retranslateUi(changeLimitW);

        QMetaObject::connectSlotsByName(changeLimitW);
    } // setupUi

    void retranslateUi(QDialog *changeLimitW)
    {
        changeLimitW->setWindowTitle(QApplication::translate("changeLimitW", "Dialog", nullptr));
        label->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">\344\277\256\346\224\271\346\235\203\351\231\220</span></p></body></html>", nullptr));
        pushButtonShow->setText(QApplication::translate("changeLimitW", "\346\237\245\347\234\213\346\235\203\351\231\220", nullptr));
        pushButtonSummit->setText(QApplication::translate("changeLimitW", "\346\217\220\344\272\244\344\277\256\346\224\271", nullptr));
        label_2->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\206\231</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\350\257\273</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\210\233\345\273\272</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\346\217\222\345\205\245</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">\345\210\240\351\231\244</span></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\346\233\264\346\226\260</span></p></body></html>", nullptr));
        label_9->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\347\255\233\351\200\211</span></p></body></html>", nullptr));
        label_10->setText(QApplication::translate("changeLimitW", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:600;\">\346\237\245\347\234\213</span></p></body></html>", nullptr));
        comboBoxShow->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxShow->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBoxR->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxR->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBoxC->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxC->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBoxIn->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxIn->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBoxdel->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxdel->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBoxup->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxup->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBoxS->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBoxS->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

        comboBox_8->setItemText(0, QApplication::translate("changeLimitW", "1", nullptr));
        comboBox_8->setItemText(1, QApplication::translate("changeLimitW", "0", nullptr));

    } // retranslateUi

};

namespace Ui {
    class changeLimitW: public Ui_changeLimitW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGELIMITW_H
