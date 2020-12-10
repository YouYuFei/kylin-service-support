/************************************************
* 文件描述: 程序主进程
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "mainwindow.h"
/************************************************
* 函数名称：MainWindow
* 功能描述：构造函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
MainWindow::MainWindow()
{
    //单例运行
    checkSingle();

    WidgetParameterClass basicParameter(WINDOW_WIDTH ,WINDOW_HEIGHT,HASRADIUS,WINRADIUS,WINSHADOW,WINSHADOWALPHA,TITLE_HEIGHT,LEFTBOX_WIDTH,LEFTBOX_HEIGHT,RIGHTBOXHEIGHT,RIGHTBOXWIDTH);

    QString windowTitle = tr("Service&Support");

    basicWindow = new BaseStyle(basicParameter , windowTitle);



    QHBoxLayout *hblayout=new QHBoxLayout(basicWindow->body);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距

    //内部样式
    stackedWidget =new QStackedWidget;

    hblayout->addWidget(stackedWidget);

    initGsetting();
}
/************************************************
* 函数名称：MainWindow
* 功能描述：析构函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
MainWindow::~MainWindow()
{
}

/************************************************
* 函数名称：单例模式
* 功能描述：检查是否单例运行
* 输入参数：
* 输出参数：
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainWindow::checkSingle()
{
    QStringList homePath = QStandardPaths::standardLocations(QStandardPaths::HomeLocation);

    int fd = open(QString(homePath.at(0) + "/.config/kylin-service-support%1.lock").arg(getenv("DISPLAY")).toUtf8().data(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    if (fd < 0) { exit(1); }

    if (lockf(fd, F_TLOCK, 0)) {
        qDebug()<<"Can't lock single file, kylin-service-support is already running!";
        exit(0);
    }
}

/************************************************
* 函数名称：gsetting初始化
* 功能描述：
* 输入参数：
* 输出参数：
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainWindow::initGsetting()
{
    qDebug() << "gsetting开始初始化！";
    if(QGSettings::isSchemaInstalled(FITTHEMEWINDOW))
    {
        qDebug() << "配置文件存在！";
        m_pThemeStyle = new QGSettings(FITTHEMEWINDOW);
        qDebug() << "当前系统主题模式为：" << m_pThemeStyle->get("styleName").toString();
        connect(m_pThemeStyle,&QGSettings::changed,this, [=] (const QString &key)
        {
            if(key == "styleName")
            {

                    setThemeStyle();
            }
        });
    }
    setThemeStyle();
    return;

}

/************************************************
* 函数名称：setThemeStyle
* 功能描述：主题样式设计
* 输入参数：
* 输出参数：
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainWindow::setThemeStyle()
{
    QString nowThemeStyle = "";
    if(m_pThemeStyle==nullptr)                  //V10系统不能进行主题切换，需要进行空指针判断
    {
        nowThemeStyle = "ukui-default";
    }
    else
    {
        nowThemeStyle = m_pThemeStyle->get("styleName").toString();
    }

    qDebug() << "设置程序主题模式为" << nowThemeStyle;
    basicWindow->pageChangeForTheme(nowThemeStyle);
//    styleWidget->ThemeChooseForWidget(nowThemeStyle);

//    prePage->pageChangeForTheme(nowThemeStyle);
//    startPage->pageChangeForTheme(nowThemeStyle);
//    finishPage->pageChangeForTheme(nowThemeStyle);
//    warningPage->pageChangeForTheme(nowThemeStyle);

}
/************************************************
* 函数名称：pullUpWindow
* 功能描述：窗口最小化时，点击程序图标，主窗口拉起
* 输入参数：
* 输出参数：
* 修改日期：2020.12.02
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainWindow::pullUpWindow()
{
    qDebug()<<"MainWindow::pullUpWindow  iswindowminized:" << basicWindow->isMinimized();
    basicWindow->showNormal();
    basicWindow->raise();
    basicWindow->activateWindow();
    qDebug()<<basicWindow->parent();

}

