#-------------------------------------------------
#
# Project created by QtCreator 2021-01-09T21:57:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBMS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    loginwindow.cpp \
    regwindow.cpp \
    createdatabasewindow.cpp \
    createtable.cpp \
    changetablewindow.cpp \
    changelimitw.cpp

HEADERS += \
        mainwindow.h \
    loginwindow.h \
    regwindow.h \
    createdatabasewindow.h \
    createtable.h \
    changetablewindow.h \
    changelimitw.h

FORMS += \
        mainwindow.ui \
    loginwindow.ui \
    regwindow.ui \
    createdatabasewindow.ui \
    createtable.ui \
    changetablewindow.ui \
    changelimitw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
