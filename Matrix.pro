#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T20:53:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Matrix
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matrixdialog.cpp \
    matrixitemdelegate.cpp \
    validator.cpp \
    validatordouble.cpp \
    validatorint.cpp \
    matrixitemdelegatedouble.cpp

HEADERS  += mainwindow.h \
    matrixdialog.h \
    matrixitemdelegate.h \
    validator.h \
    validatordouble.h \
    validatorint.h \
    matrixitemdelegatedouble.h

FORMS    += mainwindow.ui
