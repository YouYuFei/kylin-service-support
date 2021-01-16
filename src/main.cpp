#include "mainwindow.h"
#include "dbusadaptor.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTranslator>
#include <QLibraryInfo>
#include <QApplication>

void msgHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    static FILE *fp = NULL; // 使用静态变量，进行数据持久保持
    static char logPath[255] = {0};
    static int uid = -1;

    Q_UNUSED(context);

    // 初始执行时，设置log文件路径
    if (uid == -1) {
        uid = getuid();
        sprintf(logPath, "/run/user/%d/%s.log", uid, "kylin-service-support");
    }

    if (access(logPath, F_OK|W_OK) == 0) {
        // log文件存在且可写
        if (fp == NULL) {
            // log文件未被打开过
            fp = fopen(logPath, "a+");
        }
    } else {
        // log文件不存在或者不可写，则需要判断是否被打开过，被打开过就需要关闭
        if (fp != NULL)
            fclose(fp);
        fp = NULL;
    }

    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeStr = currentTime.toString("yy.MM.dd hh:mm:ss +zzz");

    // 获取用于控制命令行输出的环境变量
    char *ctrlEnv = getenv("XXXX_DEBUG");
    QString env;

    // 格式化输出字符串，添加消息发生时间、消息等级
    QString outMsg;
    switch (type) {
    case QtDebugMsg:
        outMsg = QString("[%1 D]: %2").arg(timeStr).arg(msg);
        break;
    case QtInfoMsg:
        outMsg = QString("[%1 I]: %2").arg(timeStr).arg(msg);
        break;
    case QtWarningMsg:
        outMsg = QString("[%1 W]: %2").arg(timeStr).arg(msg);
        break;
    case QtCriticalMsg:
        outMsg = QString("[%1 C]: %2").arg(timeStr).arg(msg);
        break;
    case QtFatalMsg:
        outMsg = QString("[%1 F]: %2").arg(timeStr).arg(msg);
    }

    if (fp != NULL) {
        // 日志文件存在，则输出到日志文件中
        fprintf(fp, "%s\n", outMsg.toUtf8().data());
        fflush(fp);
    }

    if (ctrlEnv != NULL) {
        // 环境变量为true或者1，则将信息输出到命令行
        env = QString(ctrlEnv).toLower();
        if ((env == "true") || (env == "1")) {
            fprintf(stdout, "%s\n", outMsg.toStdString().c_str());
            fflush(stdout);
        }
    }

    // 遇到致命错误，需要终止程序（这里终止程序是可选的）
    if (type == QtFatalMsg)
        abort();
}

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
    qInstallMessageHandler(msgHandler);
    //高清屏幕自适应
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);
    a.setApplicationVersion("1.0.16kord~rc9");
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

    //w.show();
    return a.exec();
}
