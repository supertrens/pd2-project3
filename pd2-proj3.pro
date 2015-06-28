#-------------------------------------------------
#
# Project created by QtCreator 2015-06-27T16:52:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-proj3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    destroy_vertical.cpp \
    grille.cpp \
    central.cpp \
    selection_color.cpp \
    destroy_horizontal.cpp \
    selection3_v.cpp \
    selection3_h.cpp \
    selection4_v.cpp \
    selection4_h.cpp \
    selection5_h.cpp \
    selection5_v.cpp \
    destroy.cpp \
    selection_block.cpp

HEADERS  += mainwindow.h \
    destroy_vertical.h \
    grille.h \
    central.h \
    destroy.h \
    destroy_horizontal.h \
    selection3_v.h \
    selection3_h.h \
    selection4_h.h \
    selection4_v.h \
    selection5_v.h \
    selection5_h.h \
    selection_block.h \
    selection_color.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES +=
