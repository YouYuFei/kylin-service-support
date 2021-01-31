QT       += core gui network  dbus KWindowSystem x11extras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS +=-lpthread
LIBS +=-lX11

CONFIG += c++11
CONFIG += link_pkgconfig

#check Qt version
QT_VERSION = $$[QT_VERSION]
QT_VERSION = $$split(QT_VERSION, ".")
QT_VER_MAJ = $$member(QT_VERSION, 0)
QT_VER_MIN = $$member(QT_VERSION, 1)

lessThan(QT_VER_MAJ, 5) | lessThan(QT_VER_MIN, 12) {
    message(Qt版本小于5.12)
}
else{
    message(Qt版本大于或等于5.12)
    CONFIG += resources_big
}

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
    src/dbusadaptor.cpp \
    src/diysupport_page.cpp \
    src/file_item_init.cpp \
    src/base_style.cpp \
    src/main.cpp \
    src/main_page.cpp \
    src/mainwindow.cpp \
    src/menumodule.cpp \
    src/message_page.cpp \
    src/my_qlineedit.cpp \
    src/myclick_widget.cpp \
    src/smtpMailClient.cpp \
    src/submitFail.cpp \
    src/submitSuccess.cpp \
    src/systeminfo_button.cpp \
    src/tabmenu_button.cpp \
    src/widget_parameter_class.cpp \
    src/xatom-helper.cpp

HEADERS += \
    src/browse_button.h \
    src/contact_page.h \
    src/daemonipcdbus.h \
    src/dbusadaptor.h \
    src/diysupport_page.h \
    src/file_item_init.h \
    src/base_style.h \
    src/highlight-effect.h \
    src/main_page.h \
    src/mainwindow.h \
    src/menumodule.h \
    src/message_page.h \
    src/my_qlineedit.h \
    src/myclick_widget.h \
    src/smtpMailClient.h \
    src/submitFail.h \
    src/submitSuccess.h \
    src/systeminfo_button.h \
    src/tabmenu_button.h \
    src/widget_parameter_class.h \
    src/xatom-helper.h

FORMS +=

TRANSLATIONS += ./translations/kylin-service-support_zh_CN.ts \
                ./translations/kylin-service-support_bo.ts


TARGET = kylin-service-support

message($$system(./translations/generate_translations_pm.sh))
# translations
TRANSLATIONS += $$PWD/translations/kylin-service-support_zh_CN.ts
QM_FILES_INSTALL_PATH = /usr/share/kylin-service-support/translations/
CONFIG += lrelease

BEFORE_LINK_CMD_LINE = echo Hello world!
QMAKE_PRE_LINK += $$quote($$BEFORE_LINK_CMD_LINE)

target.path = /usr/bin
target.source += $$TARGET
icon.path = /usr/share/pixmaps
icon.files = kylin-service-support
desktop.path = /usr/share/applications/
desktop.files = kylin-service-support.desktop
translationsFiles.path = /usr/share/kylin-service-support/translations/
translationsFiles.files += $$PWD/translations/*
manual.path = /usr/share/kylin-user-guide/data/guide/kylin-service-support
manual.files += $$PWD/data/kylin-service-support/*


INSTALLS += target \
            icon \
            desktop \
            translationsFiles \
            manual

DISTFILES +=

RESOURCES += \
    data.qrc
