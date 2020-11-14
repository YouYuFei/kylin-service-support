#include "mainwindow.h"
#include <QTranslator>
#include <QLibraryInfo>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifndef QT_NO_TRANSLATION
    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator();
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        a.installTranslator(translator);
    else
        qDebug() << "加载中文失败";
#endif

    MainWindow w;
    //w.show();
    return a.exec();
}
