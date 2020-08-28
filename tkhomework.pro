

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = tkhomework
INCLUDEPATH += .

# Input
HEADERS += backend.h wnd.h
FORMS += wnd.ui
SOURCES += backend.cpp main.cpp wnd.cpp
