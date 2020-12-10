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
    //WidgetParameterClass shadowParameter(SHAWINDOW_WIDTH ,SHAWINDOW_HEIGHT,SHAHASRADIUS,SHAWINRADIUS,SHAWINSHADOW,SHAWINSHADOWALPHA,SHATITLE_HEIGHT,SHALEFTBOX_WIDTH,SHALEFTBOX_HEIGHT,SHARIGHTBOXHEIGHT,SHARIGHTBOXWIDTH);

    swshadow = new StyleWidgetShadow(local_basicParameter);

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
//    paintOnce=true;
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
    swshadow->deleteLater();

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
    myWidgetSizeDesign(basicParameter.winWidth ,basicParameter.winHeight);

    myWidgetBasicInit(basicParameter);

    myWidgetTabInit();

    QSize smallWidgetSize(30,30);//小按钮大小
    widgetMin =new QPushButton;//最小化按钮
    widgetMin->setObjectName("widgetMin");
    widgetMin->setIconSize(smallWidgetSize);
    widgetMin->setFixedSize(smallWidgetSize);

    connect(widgetMin,&QPushButton::clicked,this,[=]{
        this->setWindowState(Qt::WindowMinimized);
        this->swshadow->setWindowState(Qt::WindowMinimized);
    });

    widgetClose =new QPushButton;//关闭按钮
    widgetClose->setObjectName("widgetClose");
    widgetClose->setIconSize(smallWidgetSize);
    widgetClose->setFixedSize(smallWidgetSize);

    connect(widgetClose,&QPushButton::clicked,this,&BaseStyle::WidgetStyleClose);


    //this->show();

    //布局
    QHBoxLayout *hlt0=new QHBoxLayout;//右上角按钮内部，水平布局
    hlt0->setMargin(0);
    hlt0->setSpacing(0);
    hlt0->addStretch(99);
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

    title->setLayout(hlt);

    QHBoxLayout *hlt2=new QHBoxLayout;//标题栏外部
    hlt2->setMargin(0);
    hlt2->setSpacing(0);
    hlt2->addSpacing(57);
    hlt2->addWidget(title);
    //hlt2->addSpacing(50);//2004加上这个切换主题后，有一个字会显示不全，后续需要注意其他版本是否有类似问题
    hlt2->addStretch(99);

    QVBoxLayout *vlt_menu_btn=new QVBoxLayout;
    vlt_menu_btn->setMargin(0);
    vlt_menu_btn->setSpacing(0);

    vlt_menu_btn->addWidget(m_pMainPageButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pMessagePageButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pContactButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pDIYButton, 1);
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

    //hlt_menu->addStretch(99);
    hlt_menu->addSpacing(10);
    hlt_menu->addWidget(menuBox, 1);
    hlt_menu->addWidget(showBox, 1);
    hlt_menu->addSpacing(10);
    //hlt_menu->addStretch(99);

    QVBoxLayout *vl=new QVBoxLayout;//总体
    vl->setMargin(0);
    vl->setSpacing(0);
    //vl->addStretch(99);
    vl->addSpacing(10);
    vl->addLayout(hlt_menu);
    vl->addSpacing(10);
    //vl->addStretch(99);
    this->setLayout(vl);

    QPoint mainWPoint = this->mapToGlobal(QPoint(0,0));
    qDebug() << mainWPoint;

    introIcon = new QLabel(menuBox);
    introIcon->setFixedSize(16,16);
    introIcon->move(40,89);

    messageIcon = new QLabel(menuBox);
    messageIcon->setFixedSize(16,16);
    messageIcon->move(40,138);

    contactIcon = new QLabel(menuBox);
    contactIcon->setFixedSize(16,16);
    contactIcon->move(40,185);

    supportIcon = new QLabel(menuBox);
    supportIcon->setFixedSize(16,16);
    supportIcon->move(40,234);

    titleIcon = new QLabel(menuBox);
    titleIcon->setPixmap(QPixmap(":/data/kylin-service-support.png"));
    titleIcon->setFixedSize(24,24);
    titleIcon->move(26,16);


    this->setWindowIcon(QIcon(":/data/kylin-service-support.png"));
    this->setWindowTitle(tr("Service&Support"));
//    this->setWindowTitle(tr("服务与支持"));


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
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明
    this->setFixedSize(width, height);

    QRect availableGeometry = qApp->primaryScreen()->availableGeometry();
    this->move((availableGeometry.width() - this->width())/2, (availableGeometry.height() - this->height())/2);

    //设置阴影
    QHBoxLayout *hblayout=new QHBoxLayout(swshadow);
    hblayout->setMargin(0);//控件间距
    hblayout->setSpacing(0);//控件间距
    hblayout->addWidget(this);
    swshadow->show();

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

    text = new QLabel;
    text->setStyleSheet("rgba(255, 255, 255, 1);");


    //标题栏
    title = new QWidget;
    title->setMaximumHeight(parameter.titleHeight);
    title->setMinimumHeight(parameter.titleHeight);
    title->setObjectName("title");

    //左菜单背景
    menuBox = new QWidget;
    menuBox->setFixedSize(180,this->height()-2*parameter.winShadow);
    menuBox->setObjectName("menuBox");



    //右对话框背景
    showBox = new QWidget;
    showBox->setFixedSize(778,this->height()-2*parameter.winShadow);
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
    m_pMainPageButton = new TabMenuButton();
    m_pMainPageButton->setText(tr("Intro"));
    //m_pMainPageButton->setText("软件介绍");
    m_pMainPageButton->setObjectName("MainPageButton");
    m_pMainPageButton->setFixedSize(132,32);

    m_pMainPageButton->installEventFilter(this);
    connect(m_pMainPageButton, &TabMenuButton::clicked, this, &BaseStyle::m_MainPageButtonSlots);

    //留言咨询界面显示按钮
    m_pMessagePageButton = new TabMenuButton();
    m_pMessagePageButton->setText(tr("Message"));
    //m_pMessagePageButton->setText(tr("留言咨询"));
    m_pMessagePageButton->setObjectName("MessagePageButton");
    m_pMessagePageButton->setFixedSize(132,32);
    m_pMessagePageButton->installEventFilter(this);

    connect(m_pMessagePageButton, &TabMenuButton::clicked, this, &BaseStyle::m_MessagePageButtonSlots);

    //联系我们界面显示按钮
    m_pContactButton = new TabMenuButton();
    m_pContactButton->setText(tr("Contact"));
//    m_pContactButton->setText(tr("联系我们"));
    m_pContactButton->setObjectName("ContactButton");
    m_pContactButton->setFixedSize(132,32);
    m_pContactButton->installEventFilter(this);

    connect(m_pContactButton, &TabMenuButton::clicked, this, &BaseStyle::m_ContactPageButtonSlots);

    //自助支持界面显示按钮
    m_pDIYButton = new TabMenuButton();
    m_pDIYButton->setText(tr("Guidance"));
//    m_pDIYButton->setText(tr("自助支持"));
    m_pDIYButton->setObjectName("DIYButton");
    m_pDIYButton->setFixedSize(132,32);
    m_pDIYButton->installEventFilter(this);

    connect(m_pDIYButton, &TabMenuButton::clicked, this, &BaseStyle::m_DIYPageButtonSlots);

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
    currentPageIndex = 0;
    setMainPageButtonBackgroundBlue();
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
    setMessagePageButtonBackgroudIsBlue();
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
    setOnlinePageButtonBackgroudIsBlue();
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
    setContactPageButtonBackgroudIsBlue();
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
    setDIYPageButtonBackgroudIsBlue();
    m_pstackWidget->setCurrentIndex(3);
    currentPageIndex = 3;
}
/************************************************
* 函数名称：setMainPageButtonBackgroundBlue
* 功能描述：翻页到主界面时其余按钮恢复非选中状态
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::setMainPageButtonBackgroundBlue()
{
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssChooseMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_d.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_d.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_d.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssChooseMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support.png);border:0px;");
    }
}
/************************************************
* 函数名称：setMessagePageButtonBackgroudIsBlue
* 功能描述：翻页到留言界面时其余按钮恢复非选中状态
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::setMessagePageButtonBackgroudIsBlue()
{
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_d.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssChooseMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_d.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_d.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssChooseMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support.png);border:0px;");
    }
}
/************************************************
* 函数名称：setOnlinePageButtonBackgroudIsBlue
* 功能描述：翻页到在线客服界面时其余按钮恢复非选中状态
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::setOnlinePageButtonBackgroudIsBlue()
{
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_d.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_d.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_d.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_d.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support.png);border:0px;");
    }
}
/************************************************
* 函数名称：setContactPageButtonBackgroudIsBlue
* 功能描述：翻页到联系我们界面时其余按钮恢复非选中状态
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::setContactPageButtonBackgroudIsBlue()
{
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_d.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_d.png);border:0px;");

        m_pContactButton->setStyleSheet(qssChooseMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_d.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message.png);border:0px;");

        m_pContactButton->setStyleSheet(qssChooseMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support.png);border:0px;");
    }
}
/************************************************
* 函数名称：setDIYPageButtonBackgroudIsBlue
* 功能描述：翻页到自助支持界面时其余按钮恢复非选中状态
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::setDIYPageButtonBackgroudIsBlue()
{
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_d.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_d.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_d.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssChooseMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro.png);border:0px;");

        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message.png);border:0px;");

        m_pContactButton->setStyleSheet(qssDefaultMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele.png);border:0px;");

        m_pDIYButton->setStyleSheet(qssChooseMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
    }

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
    if(obj == m_pMainPageButton)
    {
        mainPageButtonQss(ev);
    }
    if(obj == m_pMessagePageButton)
    {
        messagePageButtonQss(ev);
    }
    if(obj == m_pContactButton)
    {
        contactPageButtonQss(ev);
    }
    if(obj == m_pDIYButton)
    {
        diyPageButtonQss(ev);
    }
    //其余的事件按照默认(未覆写)的处理方式处理
    return QWidget::eventFilter(obj,ev);
}
/************************************************
* 函数名称：mainPageButtonQss
* 功能描述：按钮根据鼠标动作适配
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.23
* 修改内容：
*   创建  HZH
*
*************************************************/
bool BaseStyle::mainPageButtonQss(QEvent *ev)
{
    if(ev->type() == QEvent::HoverEnter)
    {
        //qDebug() << "悬停在软件介绍按钮上";
        if(currentPageIndex != 0)
        {
            mainPageButtonDefault();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::HoverLeave)
    {
        //qDebug() << "悬停在软件介绍按钮上";
        if(currentPageIndex != 0)
        {
            mainPageButtonHover();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonPress)
    {
        //qDebug() << "按下了软件简介按钮";
        if(currentPageIndex != 0)
        {
            mainPageButtonClick();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonRelease)
    {
        mainPageButtonRelease();
        return true;    //结束传播
    }
    return true;
}
/************************************************
* 函数名称：messagePageButtonQss
* 功能描述：按钮根据鼠标动作适配
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.23
* 修改内容：
*   创建  HZH
*
*************************************************/
bool BaseStyle::messagePageButtonQss(QEvent *ev)
{
    if(ev->type() == QEvent::HoverEnter)
    {
        //qDebug() << "悬停在软件介绍按钮上";
        if(currentPageIndex != 1)
        {
            messagePageButtonDefault();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::HoverLeave)
    {
        //qDebug() << "悬停在软件介绍按钮上";
        if(currentPageIndex != 1)
        {
            messagePageButtonHover();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonPress)
    {
        //qDebug() << "按下了软件简介按钮";
        if(currentPageIndex != 1)
        {
            messagePageButtonClick();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonRelease)
    {
        messagePageButtonRelease();
        return true;    //结束传播
    }
    return true;
}
/************************************************
* 函数名称：contactPageButtonQss
* 功能描述：按钮根据鼠标动作适配
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.23
* 修改内容：
*   创建  HZH
*
*************************************************/
bool BaseStyle::contactPageButtonQss(QEvent *ev)
{
    if(ev->type() == QEvent::HoverEnter)
    {
        //qDebug() << "悬停在软件介绍按钮上";
        if(currentPageIndex != 2)
        {
            contactPageButtonDefault();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::HoverLeave)
    {
        //qDebug() << "悬停在软件介绍按钮上";
        if(currentPageIndex != 2)
        {
            contactPageButtonHover();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonPress)
    {

        //qDebug() << "按下了软件简介按钮";
        if(currentPageIndex != 2)
        {
            contactPageButtonClick();
        }
        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonRelease)
    {
        qDebug() << "松开了自助支持简介按钮";
        if(2 == currentPageIndex)
        {
            contactPageButtonRelease();
        }
        return true;    //结束传播
    }
    return true;
}
/************************************************
* 函数名称：diyPageButtonQss
* 功能描述：按钮根据鼠标动作适配
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.23
* 修改内容：
*   创建  HZH
*
*************************************************/
bool BaseStyle::diyPageButtonQss(QEvent *ev)
{
    if(ev->type() == QEvent::HoverEnter)
    {
        qDebug() << "悬停在自助支持按钮上";
        if(currentPageIndex != 3)
        {
            diyPageButtonDefault();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::HoverLeave)
    {
        qDebug() << "悬停在自助支持按钮上";
        if(currentPageIndex != 3)
        {
            diyPageButtonHover();
        }

        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "按下了软件简介按钮";
        if(currentPageIndex != 3)
        {
            diyPageButtonClick();
        }
        return true;    //结束传播
    }
    else if(ev->type() == QEvent::MouseButtonRelease)
    {
        qDebug() << "松开了自助支持简介按钮";
        if(3 == currentPageIndex)
        {
            diyPageButtonRelease();
        }
        return true;    //结束传播
    }
    return true;
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

    switch(currentPageIndex)
    {
        case 0:
            m_MainPageButtonSlots();
            break;
        case 1:
            m_MessagePageButtonSlots();
            break;
        case 2:
            m_ContactPageButtonSlots();
            break;
        case 3:
            m_DIYPageButtonSlots();
            break;
    }
    if("ukui-dark" == str || "ukui-black" == str)
    {
        widgetMin->setStyleSheet("BaseStyle #widgetMin{background-color:rgba(31, 32, 34, 1);border-image:url(:/data/min_h.png);border-radius:4px;}"
                                 "BaseStyle #widgetMin:hover{background-color:rgba(151, 151, 151, 1);border-image:url(:/data/min_h.png);border-radius:4px;}"
                                 "BaseStyle #widgetMin:pressed{background-color:rgba(151, 151, 151, 1);border-image:url(:/data/min_h.png);border-radius:4px;}");
        widgetClose->setStyleSheet("BaseStyle #widgetClose{background-color:rgba(31, 32, 34, 1);border-image:url(:/data/close_h.png);border-radius:4px;}"
                                   "BaseStyle #widgetClose:hover{background-color:rgba(253, 149, 149, 1);border-image:url(:/data/close_h.png);border-radius:4px;}"
                                   "BaseStyle #widgetClose:pressed{background-color:rgba(237, 100, 100, 1);border-image:url(:/data/close_h.png);border-radius:4px;}");

        QString showStyleSheet="#showBox{background-color:rgba(31, 32, 34, 1);border-bottom-right-radius:"+QString::number(12)+"px;\
                        border-top-right-radius:"+QString::number(12)+"px;}";
        showBox->setStyleSheet(showStyleSheet);

        QString menuStyleSheet="QWidget #menuBox{background-color:rgba(0, 0, 0, 0.7);border-bottom-left-radius:"+QString::number(12)+"px;\
                        border-top-left-radius:"+QString::number(12)+"px;}";
        menuBox->setStyleSheet(menuStyleSheet);
    }
    else
    {
        widgetMin->setStyleSheet("BaseStyle #widgetMin{background-color:rgba(255,255,255,0);border-image:url(:/data/min_d.png);border-radius:4px;}"
                                 "BaseStyle #widgetMin:hover{background-color:rgba(0, 0, 0, 0.04);border-image:url(:/data/min_d.png);border-radius:4px;}"
                                 "BaseStyle #widgetMin:pressed{background-color:rgba(48, 49, 51, 0.08);border-image:url(:/data/min_d.png);border-radius:4px;}");
        widgetClose->setStyleSheet("BaseStyle #widgetClose{background-color:rgba(255,255,255,0);border-image:url(:/data/close_d.png);border-radius:4px;}"
                                   "BaseStyle #widgetClose:hover{background-color:rgba(253, 149, 149, 1);border-image:url(:/data/close_h.png);border-radius:4px;}"
                                   "BaseStyle #widgetClose:pressed{background-color:rgba(237, 100, 100, 1);border-image:url(:/data/close_h.png);border-radius:4px;}");

        QString showStyleSheet="#showBox{background-color:rgba(255,255,255,1);border-bottom-right-radius:12px;\
                        border-top-right-radius:12px;}";
        showBox->setStyleSheet(showStyleSheet);

        QString menuStyleSheet="QWidget #menuBox{background-color:rgba(255,255,255,0.8);border-bottom-left-radius:12px;\
                        border-top-left-radius:12px;}";
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
/************************************************
* 函数名称：mainPageButtonDefault
* 功能描述：mainPageButton默认样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::mainPageButtonDefault()
{
    //qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssChooseMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssChooseMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：mainPageButtonHover
* 功能描述：mainPageButton鼠标悬停样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::mainPageButtonHover()
{
    //qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_d.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro.png);border:0px;");
    }
}

/************************************************
* 函数名称：mainPageButtonClick
* 功能描述：mainPageButton鼠标点下样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::mainPageButtonClick()
{
    m_MainPageButtonSlots();
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMainPageButton->setStyleSheet(qssPressedMenuBar_d);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");
    }
    else
    {
        m_pMainPageButton->setStyleSheet(qssPressedMenuBar);
        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");
    }

}
/************************************************
* 函数名称：mainPageButtonRelease
* 功能描述：mainPageButton鼠标松开样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::mainPageButtonRelease()
{
    qDebug() << "松开了自助支持简介按钮";
    if(0 == currentPageIndex)
    {
        m_MainPageButtonSlots();

        introIcon->setStyleSheet("border-image:url(:/data/icon_intro_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：messagePageButtonDefault
* 功能描述：messagePageButton默认样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::messagePageButtonDefault()
{
    //qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMessagePageButton->setStyleSheet(qssChooseMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");
    }
    else
    {
        m_pMessagePageButton->setStyleSheet(qssChooseMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：messagePageButtonHover
* 功能描述：messagePageButton鼠标悬停样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::messagePageButtonHover()
{
    //qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_d.png);border:0px;");
    }
    else
    {
        m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message.png);border:0px;");
    }
}
/************************************************
* 函数名称：messagePageButtonClick
* 功能描述：messagePageButton鼠标点击样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::messagePageButtonClick()
{
    m_MessagePageButtonSlots();
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMessagePageButton->setStyleSheet(qssPressedMenuBar_d);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");
    }
    else
    {
        m_pMessagePageButton->setStyleSheet(qssPressedMenuBar);
        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：messagePageButtonClick
* 功能描述：messagePageButton鼠标松开样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::messagePageButtonRelease()
{
    qDebug() << "松开了自助支持简介按钮";
    if(1 == currentPageIndex)
    {
        m_MessagePageButtonSlots();

        messageIcon->setStyleSheet("border-image:url(:/data/icon_message_h.png);border:0px;");

    }
}
/************************************************
* 函数名称：contactPageButtonDefault
* 功能描述：messagePageButton默认样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::contactPageButtonDefault()
{
    //qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pContactButton->setStyleSheet(qssChooseMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");
    }
    else
    {
        m_pContactButton->setStyleSheet(qssChooseMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：contactPageButtonHover
* 功能描述：contactPageButton鼠标悬停样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::contactPageButtonHover()
{
    //qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pContactButton->setStyleSheet(qssDefaultMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_d.png);border:0px;");
    }
    else
    {
        m_pContactButton->setStyleSheet(qssDefaultMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele.png);border:0px;");
    }
}
/************************************************
* 函数名称：contactPageButtonClick
* 功能描述：contactPageButton鼠标悬停样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::contactPageButtonClick()
{
    m_ContactPageButtonSlots();
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pContactButton->setStyleSheet(qssPressedMenuBar_d);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");
    }
    else
    {
        m_pContactButton->setStyleSheet(qssPressedMenuBar);
        contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：contactPageButtonRelease
* 功能描述：contactPageButton鼠标松开样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::contactPageButtonRelease()
{
    m_ContactPageButtonSlots();

    contactIcon->setStyleSheet("border-image:url(:/data/icon_tele_h.png);border:0px;");
}
/************************************************
* 函数名称：diyPageButtonDefault
* 功能描述：diyPageButton默认样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::diyPageButtonDefault()
{
    qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pDIYButton->setStyleSheet(qssChooseMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
    }
    else
    {
        m_pDIYButton->setStyleSheet(qssChooseMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
    }
}

/************************************************
* 函数名称：diyPageButtonHover
* 功能描述：diyPageButton鼠标悬停样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::diyPageButtonHover()
{
    qDebug() << "当前未按下悬停按钮";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pDIYButton->setStyleSheet(qssDefaultMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_d.png);border:0px;");
    }
    else
    {
        m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support.png);border:0px;");
    }
}

/************************************************
* 函数名称：diyPageButtonClick
* 功能描述：diyPageButton鼠标点击样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::diyPageButtonClick()
{
    m_DIYPageButtonSlots();
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pDIYButton->setStyleSheet(qssPressedMenuBar_d);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
    }
    else
    {
        m_pDIYButton->setStyleSheet(qssPressedMenuBar);
        supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
    }
}
/************************************************
* 函数名称：diyPageButtonRelease
* 功能描述：diyPageButton鼠标松开样式
* 输入参数：
* 输出参数：
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void BaseStyle::diyPageButtonRelease()
{
    m_DIYPageButtonSlots();

    supportIcon->setStyleSheet("border-image:url(:/data/icon_support_h.png);border:0px;");
}
