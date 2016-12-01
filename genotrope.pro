QT += core gui widgets

TARGET = Genotrope
TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/ui/mainwindow.cpp \
    src/ui/imagegridwidget.cpp \
    src/ui/coord2dinput.cpp \
    src/ui/gridsettingswidget.cpp

FORMS += \
    src/ui/mainwindow.ui \
    src/ui/coord2dinput.ui \
    src/ui/gridsettingswidget.ui

HEADERS += \
    src/ui/mainwindow.h \
    src/ui/imagegridwidget.h \
    src/ui/coord2dinput.h \
    src/ui/gridsettingswidget.h
