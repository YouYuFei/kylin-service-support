/************************************************
* 文件描述: 基础窗口框架
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "base_style.h"

/************************************************
* 函数名称：BaseStyle(WidgetParameterClass basicParameter, QString dialogTitleText)
* 功能描述：构造函数
* 输入参数：参数的类及窗口标题
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
BaseStyle::BaseStyle(const WidgetParameterClass& basicParameter, const QString& dialogTitleText)
    :local_basicParameter(basicParameter)
{

    m_pDaemonIpcDbus = new DaemonIpcDbus();

    m_pstackWidget = new QStackedWidget();

    mainPage = new MainPage(local_basicParameter);
    messagePage = new MessagePage(local_basicParameter);
    contactPage = new ContactPage(local_basicParameter);
    diySupportPage = new DIYSupportPage(local_basicParameter);

    myWidgetStyle(local_basicParameter);
    text->setText(dialogTitleText);
    QFont ft;
    ft.setPixelSize(14);
    text->setFont(ft);
    currentPageIndex = 0;
}
/************************************************
* 函数名称：
* 功能描述：重绘函数，暂注释
* 输入参数：重绘event
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
//void BaseStyle::paintEvent(QPaintEvent *event)//重绘窗口
//{
//    if(paintOnce)return;
//    //设置字体字号
//    QFont ft;
//    ft.setPixelSize(14);
//    ft.setFamily(QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/data/PingFang-SC-Semibold-2.ttf")).at(0));//读取字体
//    text->setFont(ft);
//    paintOnce=true;"lastPath"
//}
/************************************************
* 函数名称：WidgetStyleClose
* 功能描述：窗口关闭函数，关闭程序
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::WidgetStyleClose()
{
    if(menu->aboutWindow)
    {
        menu->aboutWindow->close();
    }

    this->close();
}
/************************************************
* 函数名称：myWidgetStyle
* 功能描述：界面布局
* 输入参数：参数类
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::myWidgetStyle(const WidgetParameterClass& basicParameter)
{
    myWidgetSizeDesign(960 ,640);

    myWidgetBasicInit(basicParameter);

    myWidgetTabInit();

    menu  = new menuModule(this);

    connect(menu,&menuModule::menuModuleClose,[=](){
        if(menu->aboutWindow)
        {
            menu->aboutWindow->close();
        }
        this->close();
    });

    widgetMin =new QPushButton();//最小化按钮
    widgetMin->setIcon(QIcon::fromTheme("window-minimize-symbolic"));//主题库的最小化图标
    widgetMin->setProperty("isWindowButton", 0x1);

    widgetMin->setProperty("useIconHighlightEffect", 0x2);

    widgetMin->setFlat(true);
    widgetMin->setFixedSize(30, 30);
    widgetMin->setIconSize(QSize(16, 16));

    connect(widgetMin,&QPushButton::clicked,this,[=]{
        this->setWindowState(Qt::WindowMinimized);
    });

    widgetClose =new QPushButton();//关闭按钮
    widgetClose->setIcon(QIcon::fromTheme("window-close-symbolic"));
    widgetClose->setObjectName("widgetClose");
    widgetClose->setProperty("isWindowButton", 0x2) ;
    widgetClose->setProperty("useIconHighlightEffect", 0x8);

    widgetClose->setFlat(true);

    widgetClose->setFixedSize(30, 30);
    widgetClose->setIconSize(QSize(16, 16));

    connect(widgetClose,&QPushButton::clicked,this,&BaseStyle::WidgetStyleClose);

    this->setFixedSize(960,640);
//    this->show();

    //布局
    QHBoxLayout *hlt0=new QHBoxLayout;//右上角按钮内部，水平布局
    hlt0->setMargin(0);
    hlt0->setSpacing(0);
    hlt0->addStretch(99);
    hlt0->addWidget(menu->menuButton, 1);
    hlt0->addSpacing(4);
    hlt0->addWidget(widgetMin, 1);
    hlt0->addSpacing(4);
    hlt0->addWidget(widgetClose, 1);
    hlt0->addSpacing(4);

    QVBoxLayout *vlt0=new QVBoxLayout;//右上角按钮外部，垂直布局
    vlt0->setMargin(0);
    vlt0->setSpacing(0);
    vlt0->addSpacing(4);
    vlt0->addLayout(hlt0);
    vlt0->addSpacing(6);
    vlt0->addStretch(99);

    QHBoxLayout *hlt=new QHBoxLayout;//标题栏内部，水平布局
    hlt->setMargin(0);
    hlt->setSpacing(0);
    hlt->addWidget(text,1);
    hlt->addStretch(99);

    QVBoxLayout *vlt=new QVBoxLayout;//标题栏内部，水平布局
    vlt->setMargin(0);
    vlt->setSpacing(0);
    vlt->addSpacing(8);
    vlt->addLayout(hlt,1);
    vlt->addStretch(99);

    title->setLayout(vlt);

    QHBoxLayout *hlt2=new QHBoxLayout;//标题栏外部
    hlt2->setMargin(0);
    hlt2->setSpacing(0);
    hlt2->addSpacing(40);
    hlt2->addWidget(title);
    //hlt2->addSpacing(50);//2004加上这个切换主题后，有一个字会显示不全，后续需要注意其他版本是否有类似问题
    hlt2->addStretch(99);

    QVBoxLayout *vlt_menu_btn=new QVBoxLayout;
    vlt_menu_btn->setMargin(0);
    vlt_menu_btn->setSpacing(0);
    vlt_menu_btn->addSpacing(0);
    vlt_menu_btn->addWidget(m_pMainPageButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pMessagePageButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pContactButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pDIYButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pOnlineButton, 1);
    vlt_menu_btn->addStretch(99);

    QHBoxLayout *hlt_menu_btn=new QHBoxLayout;//标题栏内部，水平布局
    hlt_menu_btn->setMargin(0);
    hlt_menu_btn->setSpacing(0);
    hlt_menu_btn->addSpacing(24);
    hlt_menu_btn->addStretch(99);
    hlt_menu_btn->addLayout(vlt_menu_btn);
    hlt_menu_btn->addStretch(99);
    hlt_menu_btn->addSpacing(24);


    QVBoxLayout *vlt_menu=new QVBoxLayout;//窗体内部，垂直布局
    //vlt_menu->setMargin(15);
    vlt_menu->setMargin(0);
    vlt_menu->setSpacing(0);
    vlt_menu->addSpacing(0);
    vlt_menu->addLayout(hlt2,1);
    vlt_menu->setSpacing(20);
    vlt_menu->addLayout(hlt_menu_btn,1);
    vlt_menu->addStretch(99);

    menuBox->setLayout(vlt_menu);

    m_pstackWidget->setFixedHeight(600);
    m_pstackWidget->setContentsMargins(0, 0, 0, 0);
    m_pstackWidget->addWidget(mainPage);
    m_pstackWidget->addWidget(messagePage);
    m_pstackWidget->addWidget(contactPage);
    m_pstackWidget->addWidget(diySupportPage);

    QHBoxLayout *hltbutton3=new QHBoxLayout;//标题栏外部
    hltbutton3->setMargin(0);
    hltbutton3->setSpacing(0);
    hltbutton3->addStretch(99);
    hltbutton3->addLayout(vlt0,1);

    QVBoxLayout *hlt3=new QVBoxLayout;//标题栏外部
    hlt3->setMargin(0);
    hlt3->setSpacing(0);
    hlt3->addLayout(hltbutton3);
    hlt3->addWidget(m_pstackWidget);
    hlt3->addStretch(99);

    showBox->setLayout(hlt3);


    QHBoxLayout *hlt_menu=new QHBoxLayout;//窗体内部，水平布局
    hlt_menu->setMargin(0);
    hlt_menu->setSpacing(0);
    hlt_menu->addSpacing(0);
    hlt_menu->addWidget(menuBox, 1);
    hlt_menu->addWidget(showBox, 1);
    hlt_menu->addSpacing(0);
    //hlt_menu->addStretch(99);

    QVBoxLayout *vl=new QVBoxLayout;//总体
    vl->setMargin(0);
    vl->setSpacing(0);
    vl->addSpacing(0);
    vl->addLayout(hlt_menu);
    vl->addSpacing(0);
    //vl->addStretch(99);
    this->setLayout(vl);

    QPoint mainWPoint = this->mapToGlobal(QPoint(0,0));
    qDebug() << mainWPoint;

    titleIcon = new QLabel(menuBox);
    titleIcon->setFixedSize(24,24);

    QIcon icon = QIcon::fromTheme("kylin-service-support");
    titleIcon->setPixmap(icon.pixmap(QSize(24,24)));
    titleIcon->setScaledContents(true);

    titleIcon->move(8,8);

    this->setWindowIcon(QIcon::fromTheme("kylin-service-support"));
    this->setWindowTitle(tr("Service&Support"));
}
/************************************************
* 函数名称：myWidgetSizeDesign
* 功能描述：界面大小设定
* 输入参数：参数类中的长宽
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::myWidgetSizeDesign(int width,int height)
{
    Q_UNUSED(width);
    Q_UNUSED(height);
    QRect availableGeometry = qApp->primaryScreen()->availableGeometry();
    this->move((availableGeometry.width() - this->width())/2, (availableGeometry.height() - this->height())/2);
}
/************************************************
* 函数名称：myWidgetBasicInit
* 功能描述：界面布局初始化
* 输入参数：参数类中的标题高
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::myWidgetBasicInit(const WidgetParameterClass& parameter)
{
    Q_UNUSED(parameter);
    text = new QLabel;
    text->setStyleSheet("rgba(255, 255, 255, 1);");


    //标题栏
    title = new QWidget;
    title->setMaximumHeight(40);
    title->setMinimumHeight(40);
    title->setObjectName("title");

    //左菜单背景
    menuBox = new QWidget;
    menuBox->setFixedSize(180,640);
    menuBox->setObjectName("menuBox");



    //右对话框背景
    showBox = new QWidget;
    showBox->setFixedSize(778,640);
    showBox->setObjectName("showBox");



}
/************************************************
* 函数名称：myWidgetTabInit
* 功能描述：界面左侧按钮初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::myWidgetTabInit()
{
    //主页界面显示按钮
    m_pMainPageButton = new QPushButton();
    m_pMainPageButton->setText(tr("Intro"));
    //m_pMainPageButton->setText("软件介绍");
    m_pMainPageButton->setObjectName("MainPageButton");
    m_pMainPageButton->setFixedSize(132,32);
    m_pMainPageButton->setIcon(QIcon::fromTheme("view-dual-symbolic"));//主题库的图标
    m_pMainPageButton->setProperty("isWindowButton", QPalette::Highlight);
    m_pMainPageButton->setProperty("useIconHighlightEffect", 0x08);
    m_pMainPageButton->setFlat(true);
    m_pMainPageButton->setCheckable(true);
    m_pMainPageButton->setAutoExclusive(true);

    connect(m_pMainPageButton, &QPushButton::clicked, this, &BaseStyle::m_MainPageButtonSlots);

    //留言咨询界面显示按钮
    m_pMessagePageButton = new QPushButton();
    m_pMessagePageButton->setText(tr("Message"));
    //m_pMessagePageButton->setText(tr("留言咨询"));
    m_pMessagePageButton->setObjectName("MessagePageButton");
    m_pMessagePageButton->setFixedSize(132,32);
    m_pMessagePageButton->setIcon(QIcon::fromTheme("document-edit-symbolic"));//主题库的图标
    m_pMessagePageButton->setProperty("isWindowButton", QPalette::Highlight);
    m_pMessagePageButton->setProperty("useIconHighlightEffect", 0x08);
    m_pMessagePageButton->setFlat(true);
    m_pMessagePageButton->setCheckable(true);
    m_pMessagePageButton->setAutoExclusive(true);

    connect(m_pMessagePageButton, &QPushButton::clicked, this, &BaseStyle::m_MessagePageButtonSlots);

    //联系我们界面显示按钮
    m_pContactButton = new QPushButton();
    m_pContactButton->setText(tr("Contact"));
//    m_pContactButton->setText(tr("联系我们"));
    m_pContactButton->setObjectName("ContactButton");
    m_pContactButton->setFixedSize(132,32);
    m_pContactButton->setIcon(QIcon::fromTheme("call-start-symbolic"));//主题库的图标
    m_pContactButton->setProperty("isWindowButton", QPalette::Highlight);
    m_pContactButton->setProperty("useIconHighlightEffect", 0x08);
    m_pContactButton->setFlat(true);
    m_pContactButton->setCheckable(true);
    m_pContactButton->setAutoExclusive(true);

    connect(m_pContactButton, &QPushButton::clicked, this, &BaseStyle::m_ContactPageButtonSlots);

    //自助支持界面显示按钮
    m_pDIYButton = new QPushButton();
    m_pDIYButton->setText(tr("Guidance"));
    //m_pMessagePageButton->setText("在线客服");
    m_pDIYButton->setObjectName("GuidancePageButton");
    m_pDIYButton->setFixedSize(132,32);
    m_pDIYButton->setIcon(QIcon::fromTheme("system-search-symbolic"));//主题库的图标
    m_pDIYButton->setProperty("isWindowButton", QPalette::Highlight);
    m_pDIYButton->setProperty("useIconHighlightEffect", 0x08);
    m_pDIYButton->setFlat(true);
    m_pDIYButton->setCheckable(true);
    m_pDIYButton->setAutoExclusive(true);

    connect(m_pDIYButton, &QPushButton::clicked, this, &BaseStyle::m_DIYPageButtonSlots);

    //在线客服按钮
    m_pOnlineButton = new QPushButton();
    m_pOnlineButton->setText(tr("Customer"));
    //m_pMessagePageButton->setText("在线客服");
    m_pOnlineButton->setObjectName("OnlinePageButton");
    m_pOnlineButton->setFixedSize(132,32);
    m_pOnlineButton->setIcon(QIcon::fromTheme("contact-new-symbolic"));//主题库的最小化图标
    m_pOnlineButton->setProperty("isWindowButton", QPalette::Highlight);
    m_pOnlineButton->setProperty("useIconHighlightEffect", 0x08);
    m_pOnlineButton->setFlat(true);
    m_pOnlineButton->setCheckable(true);
    m_pOnlineButton->setAutoExclusive(true);

    connect(m_pOnlineButton, &QPushButton::clicked, this, &BaseStyle::m_OnlinePageButtonSlots);

}
/************************************************
* 函数名称：m_MainPageButtonSlots
* 功能描述：翻页到主界面函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::m_MainPageButtonSlots()
{
    allButtonNoChecked();
    m_pMainPageButton->setChecked(true);
    currentPageIndex = 0;
    m_pstackWidget->setCurrentIndex(0);
}

/************************************************
* 函数名称：m_MessagePageButtonSlots
* 功能描述：翻页到留言界面函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::m_MessagePageButtonSlots()
{
    allButtonNoChecked();
    m_pMessagePageButton->setChecked(true);
    m_pstackWidget->setCurrentIndex(1);
    currentPageIndex = 1;
}
/************************************************
* 函数名称：m_OnlinePageButtonSlots
* 功能描述：翻页到在线咨询界面函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::m_OnlinePageButtonSlots()
{
    allButtonNoChecked();
    m_pOnlineButton->setChecked(true);
    m_pstackWidget->setCurrentIndex(0);
    currentPageIndex = 0;
    QDesktopServices::openUrl(QUrl("https://webchat-bj.clink.cn/chat.html?accessId=8f4d87f6-6f18-4c4a-b6ad-2376d128e346&language=zh_CN"));
}
/************************************************
* 函数名称：m_ContactPageButtonSlots
* 功能描述：翻页到联系我们界面函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::m_ContactPageButtonSlots()
{
    allButtonNoChecked();
    m_pContactButton->setChecked(true);
    m_pstackWidget->setCurrentIndex(2);
    currentPageIndex = 2;
}
/************************************************
* 函数名称：m_DIYPageButtonSlots
* 功能描述：翻页到自助界面函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::m_DIYPageButtonSlots()
{
    allButtonNoChecked();
    m_pDIYButton->setChecked(true);
    //setDIYPageButtonBackgroudIsBlue();
    m_pstackWidget->setCurrentIndex(3);
    currentPageIndex = 3;
}
/************************************************
* 函数名称：allButtonNoChecked
* 功能描述：所有按钮恢复非选中状态
* 输入参数：侧边menu的按钮响应鼠标悬停，点击，按钮上图标反色
* 输出参数：无
* 修改日期：2021.01.26
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::allButtonNoChecked()
{
    m_pDIYButton->setChecked(false);
    m_pContactButton->setChecked(false);
    m_pOnlineButton->setChecked(false);
}

/************************************************
* 函数名称：eventFilter
* 功能描述：事件过滤，重写
* 输入参数：侧边menu的按钮响应鼠标悬停，点击，按钮上图标反色
* 输出参数：无
* 修改日期：2020.11.23
* 修改内容：
*   创建  HZH
*
*************************************************/
bool BaseStyle::eventFilter(QObject *obj, QEvent *ev)
{

    //其余的事件按照默认(未覆写)的处理方式处理
    return QWidget::eventFilter(obj,ev);
}

/************************************************
* 函数名称：pageChangeForTheme
* 功能描述：主题颜色适配
* 输入参数：StyleWidgetAttribute page_swa
* 输出参数：无
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::pageChangeForTheme(const QString& str)
{
    currentTheme = str;
    qDebug() << currentTheme;

    messagePage->pageChangeForTheme(currentTheme);
    contactPage->pageChangeForTheme(currentTheme);
    diySupportPage->pageChangeForTheme(currentTheme);
    mainPage->pageChangeForTheme(currentTheme);

    allButtonNoChecked();
    m_pMainPageButton->setChecked(true);


    if("ukui-dark" == str || "ukui-black" == str)
    {

        QString showStyleSheet="#showBox{background-color:rgba(31, 32, 34, 1);}";
        showBox->setStyleSheet(showStyleSheet);

        QString menuStyleSheet="QWidget #menuBox{background-color:rgba(0, 0, 0, 0.7);}";
        menuBox->setStyleSheet(menuStyleSheet);
    }
    else
    {

        QString showStyleSheet="#showBox{background-color:rgba(255,255,255,1);}";
        showBox->setStyleSheet(showStyleSheet);

        QString menuStyleSheet="QWidget #menuBox{background-color:rgba(255,255,255,0.8);}";
        menuBox->setStyleSheet(menuStyleSheet);
    }
}

/************************************************
* 函数名称：keyPressEvent
* 功能描述：F1键打开用户手册对应页
* 输入参数：QKeyEvent *event键盘事件
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F1)
    {
        if(!m_pDaemonIpcDbus->daemonIsNotRunning()){
            m_pDaemonIpcDbus->showGuide("");
        }
    }
}
