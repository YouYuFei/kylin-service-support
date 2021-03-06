#include "mainwindow.h"
#include "dbusadaptor.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTranslator>
#include <QLibraryInfo>
#include <QApplication>
#define DOUBLE 2
#define MAX_FILE_SIZE 1024
#define LOG_FILE0 "demo_0.log"
#define LOG_FILE1 "demo_1.log"
#define LOG_FILE_PATH "/.cache/kylin-service-support/log"
/************************************************
* 函数名称：qtMessagePutIntoLog
* 功能描述：日志记录函数
* 输入参数：qDebug标准输出
* 输出参数：BootRepairLog.txt
* 修改日期：2020.11.07
* 修改内容：
*   创建  HZH
*
*************************************************/
void messageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    QByteArray currentTime = QTime::currentTime().toString().toLocal8Bit();

    QString name[DOUBLE] = {LOG_FILE0, LOG_FILE1};
    FILE *log_file = nullptr;
    QString logFilePath;
    int fileSize;
    static int i = 0;
    QDir dir;
    bool flag = false;

    logFilePath = QDir::homePath() + LOG_FILE_PATH;
    if (dir.mkpath(logFilePath)) {
        flag = true;
    }

    if (flag) {
        logFilePath = logFilePath + "/" + name[i];
        log_file = fopen(logFilePath.toLocal8Bit().constData(), "a+");
    }

    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        if (!log_file) {
            break;
        }
        fprintf(log_file, "Debug: %s: %s (%s:%u, %s)\n", currentTime.constData(), localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(log_file? log_file: stdout, "Info: %s: %s (%s:%u, %s)\n", currentTime.constData(), localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(log_file? log_file: stderr, "Warning: %s: %s (%s:%u, %s)\n", currentTime.constData(), localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(log_file? log_file: stderr, "Critical: %s: %s (%s:%u, %s)\n", currentTime.constData(), localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(log_file? log_file: stderr, "Fatal: %s: %s (%s:%u, %s)\n", currentTime.constData(), localMsg.constData(), file, context.line, function);
        break;
    }

    if (log_file) {
        fileSize = ftell(log_file);
        if (fileSize >= MAX_FILE_SIZE) {
            i = (i + 1) % DOUBLE;
            logFilePath = QDir::homePath() + LOG_FILE_PATH + "/" + name[i];
            if (QFile::exists(logFilePath)) {
                QFile temp(logFilePath);
                temp.remove();
            }
        }
        fclose(log_file);
    }
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
    //qInstallMessageHandler(messageOutput);
    //高清屏幕自适应
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication a(argc, argv);
    a.setApplicationVersion("1.0.16");
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
