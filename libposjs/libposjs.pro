#-------------------------------------------------
#
# Project created by QtCreator 2015-07-15T16:17:59
#
#-------------------------------------------------

QT       -= gui
QT += widgets testlib

LIBS += -L/usr/lib/$$system(uname -i)-linux-gnu
LIBS += -lusb

TARGET = posjs
TEMPLATE = lib

DESTDIR = ../lib   # *.so  dir

SOURCES += \
    posdriver.cpp \
    linuxusb.cpp \
    generichidscanner.cpp \
    escposprinter.cpp \
    device.cpp

HEADERS += posdriverinterface.h \
    posdriver.h \
    linuxusb.h \
    itransport.h \
    iticketprinter.h \
    hidtable.h \
    generichidscanner.h \
    escposprinter.h \
    escposcommands.h \
    errors.h \
    device.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
