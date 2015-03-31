QT       += core
QT       -= gui
CONFIG += C++11

TARGET = riverView
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp io.cpp \
    matrix.cpp

HEADERS += \
    matrix.h
