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

QT_BEGIN_NAMESPACE

class Ui_regWindow
{
public:

    void setupUi(QDialog *regWindow)
    {
        if (regWindow->objectName().isEmpty())
            regWindow->setObjectName(QString::fromUtf8("regWindow"));
        regWindow->resize(400, 300);

        retranslateUi(regWindow);

        QMetaObject::connectSlotsByName(regWindow);
    } // setupUi

    void retranslateUi(QDialog *regWindow)
    {
        regWindow->setWindowTitle(QApplication::translate("regWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regWindow: public Ui_regWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGWINDOW_H
