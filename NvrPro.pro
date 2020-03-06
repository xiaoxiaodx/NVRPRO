#-------------------------------------------------
#
# Project created by QtCreator 2020-01-14T09:44:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NvrPro
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
    timezonesetting.cpp \
    passwordsetting.cpp \
    welcome.cpp \
    customerevent.cpp \
    nvrConfig/nvrconfig.cpp \
    nvrConfig/devicesetting.cpp \
    nvrConfig/systemmanager.cpp \
    nvrConfig/cameramenu.cpp \
    nvrConfig/alarmtypemenu.cpp \
    masterPreview/videowindow.cpp \
    videoReplay/replaywindow.cpp \
    videoReplay/mycalendar.cpp \
    videoReplay/replaytimeline.cpp \
    nvrConfig/timeselectdialog.cpp \
    nvrConfig/dcalendardialog.cpp \
    virtualkeyboard.cpp \
    inputeditkeyeventfilter.cpp \
    mykeypressevent.cpp \
    systemconfigeventfilter.cpp \
    nvrConfig/confirmdialog.cpp \
    messagedialog.cpp

HEADERS += \
        mainwindow.h \
    timezonesetting.h \
    passwordsetting.h \
    welcome.h \
    customerevent.h \
    nvrConfig/nvrconfig.h \
    nvrConfig/devicesetting.h \
    nvrConfig/systemmanager.h \
    nvrConfig/cameramenu.h \
    nvrConfig/alarmtypemenu.h \
    masterPreview/videowindow.h \
    videoReplay/replaywindow.h \
    videoReplay/mycalendar.h \
    videoReplay/replaytimeline.h \
    util.h \
    nvrConfig/timeselectdialog.h \
    nvrConfig/dcalendardialog.h \
    virtualkeyboard.h \
    inputeditkeyeventfilter.h \
    mykeypressevent.h \
    systemconfigeventfilter.h \
    nvrConfig/confirmdialog.h \
    messagedialog.h

FORMS += \
        mainwindow.ui \
    timezonesetting.ui \
    passwordsetting.ui \
    welcome.ui \
    nvrConfig/devicesetting.ui \
    nvrConfig/nvrconfig.ui \
    nvrConfig/systemmanager.ui \
    nvrConfig/cameramenu.ui \
    nvrConfig/alarmtypemenu.ui \
    masterPreview/videowindow.ui \
    videoReplay/replaywindow.ui \
    videoReplay/mycalendar.ui \
    videoReplay/replaytimeline.ui \
    nvrConfig/timeselectdialog.ui \
    nvrConfig/dcalendardialog.ui \
    virtualkeyboard.ui \
    nvrConfig/confirmdialog.ui \
    messagedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
