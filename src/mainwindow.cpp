#include "mainwindow.h"

MainWindow::MainWindow()
{
    //this->setWindowFlags(Qt::FramelessWindowHint);//无边框
    //this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明

    WidgetParameterClass basicParameter(WINDOW_WIDTH ,WINDOW_HEIGHT,HASRADIUS,WINRADIUS,WINSHADOW,WINSHADOWALPHA,TITLE_HEIGHT,LEFTBOX_WIDTH,LEFTBOX_HEIGHT,RIGHTBOXHEIGHT,RIGHTBOXWIDTH);

    QString windowTitle = "服务与支持";

    basicWindow = new BaseStyle(basicParameter , windowTitle);



    QHBoxLayout *hblayout=new QHBoxLayout(basicWindow->body);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距

    //内部样式
    stackedWidget =new QStackedWidget;

    hblayout->addWidget(stackedWidget);


}

MainWindow::~MainWindow()
{
}

