QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    questionparser.cpp \
    questionwindow.cpp \
    resultswindow.cpp

HEADERS += \
    gamewindow.h \
    mainwindow.h \
    questionparser.h \
    questionwindow.h \
    resultswindow.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui \
    questionwindow.ui \
    resultswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../assets/img/bg.png \
    assets/img/bg.png \
    assets/img/down.png \
    assets/img/up.png

RESOURCES += \
    resources.qrc
