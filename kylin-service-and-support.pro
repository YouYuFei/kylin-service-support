QT       += core gui network  dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += link_pkgconfig
PKGCONFIG += gsettings-qt

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/browse_button.cpp \
    src/contact_page.cpp \
    src/daemonipcdbus.cpp \
    src/diysupport_page.cpp \
    src/file_item_init.cpp \
    src/base_style.cpp \
    src/main.cpp \
    src/main_page.cpp \
    src/mainwindow.cpp \
    src/message_page.cpp \
    src/my_tab_widget.cpp \
    src/myclick_widget.cpp \
    src/submitFail.cpp \
    src/submitSuccess.cpp \
    src/systeminfo_button.cpp \
    src/tabmenu_button.cpp \
    src/widget_parameter_class.cpp

HEADERS += \
    src/browse_button.h \
    src/contact_page.h \
    src/daemonipcdbus.h \
    src/diysupport_page.h \
    src/file_item_init.h \
    src/base_style.h \
    src/main_page.h \
    src/mainwindow.h \
    src/message_page.h \
    src/my_tab_widget.h \
    src/myclick_widget.h \
    src/submitFail.h \
    src/submitSuccess.h \
    src/systeminfo_button.h \
    src/tabmenu_button.h \
    src/widget_parameter_class.h

FORMS +=

TRANSLATIONS += \

TARGET = kylin-service-and-support

target.path = /usr/bin
target.source += $$TARGET
icon.path = /usr/share/pixmaps
icon.files = data/kylin-service-and-support.png
desktop.path = /usr/share/applications/
desktop.files = kylin-service-and-support.desktop

INSTALLS += target \
            icon \
            desktop

DISTFILES +=

RESOURCES += \
    data.qrc
