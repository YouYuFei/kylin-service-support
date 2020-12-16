#include "mainwindow.h"
#include "dbusadaptor.h"
#include <QTranslator>
#include <QLibraryInfo>
#include <QApplication>


void responseCommand(QApplication &a) //响应外部dbus命令
{
    //提供DBus接口，添加show参数
    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("main", "kylinservicesupport"));
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption swOption(QStringLiteral("show"),QCoreApplication::translate("main", "show kylin-service-support test"));

    parser.addOptions({swOption});
    parser.process(a);

    if(parser.isSet(swOption) || !QDBusConnection::sessionBus().registerService("com.kylin.servicesupport"))
    {
//        if(!a.isRunning())return;
            QDBusInterface *interface = new QDBusInterface("com.kylin.servicesupport",
                                                           "/com/kylin/servicesupport",
                                                           "com.kylin.servicesupport",
                                                           QDBusConnection::sessionBus(),
                                                           NULL);

            interface->call(QStringLiteral("showMainWindow"));
    }
}
int main(int argc, char *argv[])
{
    //高清屏幕自适应
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);
    responseCommand(a);

    QTranslator app_trans;
    QTranslator qt_trans;
    QString locale = QLocale::system().name();
    QString trans_path;
    if (QDir("/usr/share/kylin-service-support/translations").exists()) {
        trans_path = "/usr/share/kylin-service-support/translations";
    }
    else {
        trans_path = qApp->applicationDirPath() + "/translations";
    }
    QString qt_trans_path;
    qt_trans_path = QLibraryInfo::location(QLibraryInfo::TranslationsPath);

    if (locale == "zh_CN")
    {
        if(!app_trans.load("kylin-service-support_" + locale + ".qm", trans_path))
            qDebug() << "Load translation file："<< "kylin-service-support_" + locale + ".qm from" << trans_path << "failed!";
        else
            a.installTranslator(&app_trans);

        if(!qt_trans.load("qt_" + locale + ".qm", qt_trans_path))
            qDebug() << "Load translation file："<< "qt_" + locale + ".qm from" << qt_trans_path << "failed!";
        else
            a.installTranslator(&qt_trans);
    }

    MainWindow w;
    DbusAdaptor adaptor(&w);
    Q_UNUSED(adaptor);
    auto connection = QDBusConnection::sessionBus();
    qDebug()<<"建立DBus服务状态： "<< (connection.registerService("com.kylin.servicesupport")&&connection.registerObject("/com/kylin/servicesupport", &w));

//    // 添加窗管协议
//    MotifWmHints hints;
//    hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
//    hints.functions = MWM_FUNC_ALL;
//    hints.decorations = MWM_DECOR_BORDER;
//    XAtomHelper::getInstance()->setWindowMotifHint(w.basicWindow->winId(), hints);
    //w.show();
    return a.exec();
}
