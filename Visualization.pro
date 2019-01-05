#-------------------------------------------------
#
# Project created by QtCreator 2018-08-09T07:53:00
#
#-------------------------------------------------

QT       += core gui
QT       +=charts
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Visualization
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


SOURCES += \
        main.cpp \
        maininterface.cpp \
    menuall.cpp \
    chartviewer.cpp \
    barchart.cpp \
    piechart.cpp \
    function.cpp \
    Graph/cosine.cpp \
    Graph/graphshow.cpp \
    Graph/logarithm.cpp \
    Graph/polynomial.cpp \
    Graph/qcustomplot.cpp \
    Graph/sine.cpp \
    scatterchart.cpp \
    splinechart.cpp \
    linechart.cpp \
    areachart.cpp \
    readfile.cpp

HEADERS += \
        maininterface.h \
    copycell.h \
    menuall.h \
    chartviewer.h \
    chart.h \
    barchart.h \
    piechart.h \
    function.h \
    Graph/cosine.h \
    Graph/graphshow.h \
    Graph/logarithm.h \
    Graph/polynomial.h \
    Graph/qcustomplot.h \
    Graph/sine.h \
    scatterchart.h \
    splinechart.h \
    linechart.h \
    areachart.h \
    readfile.h

FORMS += \
        maininterface.ui \
    menuall.ui \
    chartviewer.ui \
    function.ui \
    Graph/graphshow.ui

RESOURCES += \
    icon.qrc \
    completer.qrc

DISTFILES +=
