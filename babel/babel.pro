#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T19:52:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = babel
TEMPLATE = app


SOURCES += main.cpp\
    login.cpp \
    register.cpp \
    about.cpp \
    listdelegate.cpp \
    mainview.cpp \
    contactmanager.cpp \
    tcpsocket.cpp \
    udpsocket.cpp

HEADERS  += \
    login.h \
    register.h \
    about.h \
    listdelegate.h \
    mainview.h \
    contactmanager.h \
    inetworkmanager.h \
    tcpsocket.h \
    udpsocket.h

FORMS    += \
    login.ui \
    register.ui \
    mainview.ui \
    about.ui

RESOURCES     = resources.qrc
