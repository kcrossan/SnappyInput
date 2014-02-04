#-------------------------------------------------
#
# Project created by QtCreator 2014-02-02T14:56:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SnappyInput
TEMPLATE = app


SOURCES += main.cpp\
        applicationlist.cpp \
    application.cpp \
    persistentapplicationlist.cpp \
    util.cpp \
    persistentapplicationlistmodel.cpp

HEADERS  += applicationlist.h \
    application.h \
    persistentapplicationlist.h \
    util.h \
    persistentapplicationlistmodel.h

FORMS    += applicationlist.ui

OTHER_FILES += \
    SnappyInput.rc \
    cursor.ico

RESOURCES += \
    SnappyInput.qrc

RC_FILE = SnappyInput.rc
