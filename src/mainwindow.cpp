/************************************************
* 文件描述: 程序主进程
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "mainwindow.h"
#include "xatom-helper.h"
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

    getSysVersion();

    if(multiFunc)
    {
        basicWindow = new BaseStyle(basicParameter , windowTitle);

        // 添加窗管协议
        MotifWmHints hints;
        hints.flags = MWM_HINTS_FUNCTIONS|MWM_HINTS_DECORATIONS;
        hints.functions = MWM_FUNC_ALL;
        hints.decorations = MWM_DECOR_BORDER;
        XAtomHelper::getInstance()->setWindowMotifHint(basicWindow->winId(), hints);

        basicWindow->show();
    }
    else
    {
        exit(0);
    }

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
/************************************************
* 函数名称：getSysVersion
* 功能描述：获取系统版本
* 输入参数：
* 输出参数：
* 修改日期：2021.01.06
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainWindow::getSysVersion()
{
    string os_info = ": ";
    QString system_info;
    QString system_name;
    QString system_version_id;
    string s;
    ifstream fp("/etc/os-release");
    if (!fp)
    {
        system_info = "None";
        multiFunc = false;
    }
    else
    {
        while (getline(fp,s))
        {
            string::size_type idx;
            idx = s.find("=");
            if (idx == string::npos)
            {
                //不存在
                multiFunc = false;
            }
            else
            {
                string str2 = s.substr(0,idx);
                if (str2 == "NAME")
                {
                    system_name = QString::fromStdString(s.substr(5));
                    if(system_name.contains("Kylin",Qt::CaseInsensitive))
                    {
                        multiFunc = true;
                    }
                    else
                    {
                        multiFunc = false;
                    }
                }
                else if(str2 =="VERSION_ID")
                {
                    system_version_id = QString::fromStdString(s.substr(11));
                    if(system_version_id.contains("v10",Qt::CaseInsensitive))
                    {
                        multiFunc = true;
                    }
                    else
                    {
                        multiFunc = false;
                    }
                }
            }
        }
    }
}
