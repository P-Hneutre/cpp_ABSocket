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
    about.cpp \
    listdelegate.cpp \
    mainview.cpp \
    tcpsocket.cpp \
    udpsocket.cpp \
    contact.cpp \
    contactmanager.cpp \
    contactactions.cpp

HEADERS  += \
    login.h \
    about.h \
    listdelegate.h \
    mainview.h \
    inetworkmanager.h \
    tcpsocket.h \
    udpsocket.h \
    contact.h \
    contactmanager.h \
    protocol.h \
    contactactions.h

FORMS    += \
    login.ui \
    mainview.ui \
    about.ui \
    contactactions.ui

RESOURCES     = resources.qrc
