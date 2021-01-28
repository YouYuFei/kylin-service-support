#include "simple_style.h"

/************************************************
* 文件描述: 基础窗口框架
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "highlight-effect.h"

/************************************************
* 函数名称：SimpleStyle(WidgetParameterClass basicParameter, QString dialogTitleText)
* 功能描述：构造函数
* 输入参数：参数的类及窗口标题
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
SimpleStyle::SimpleStyle(const WidgetParameterClass& basicParameter, const QString& dialogTitleText)
    :local_basicParameter(basicParameter)
{

    m_pDaemonIpcDbus = new DaemonIpcDbus();

    m_pstackWidget = new QStackedWidget();

    messagePage = new MessagePage(local_basicParameter);

    myWidgetStyle(local_basicParameter);
    text->setText(dialogTitleText);
    QFont ft;
    ft.setPixelSize(14);
    text->setFont(ft);
}

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
void SimpleStyle::WidgetStyleClose()
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
void SimpleStyle::myWidgetStyle(const WidgetParameterClass& basicParameter)
{
    myWidgetSizeDesign(796 ,640);

    myWidgetBasicInit(basicParameter);

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

    connect(widgetClose,&QPushButton::clicked,this,&SimpleStyle::WidgetStyleClose);

    this->setFixedSize(796,640);
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
    hlt2->addLayout(vlt0);

    m_pstackWidget->setFixedHeight(600);
    m_pstackWidget->setContentsMargins(0, 0, 0, 0);
    m_pstackWidget->addWidget(messagePage);

//    QHBoxLayout *hltbutton3=new QHBoxLayout;//标题栏外部
//    hltbutton3->setMargin(0);
//    hltbutton3->setSpacing(0);
//    hltbutton3->addLayout(hlt2,1);
//    hltbutton3->addStretch(99);

    QVBoxLayout *hlt3=new QVBoxLayout;//标题栏外部
    hlt3->setMargin(0);
    hlt3->setSpacing(0);
    hlt3->addLayout(hlt2);
    hlt3->addWidget(m_pstackWidget);
    hlt3->addStretch(99);

    showBox->setLayout(hlt3);


    QHBoxLayout *hlt_menu=new QHBoxLayout;//窗体内部，水平布局
    hlt_menu->setMargin(0);
    hlt_menu->setSpacing(0);
    hlt_menu->addSpacing(0);
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

    titleIcon = new QLabel(this);
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
void SimpleStyle::myWidgetSizeDesign(int width,int height)
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
void SimpleStyle::myWidgetBasicInit(const WidgetParameterClass& parameter)
{
    Q_UNUSED(parameter);
    text = new QLabel;
    text->setStyleSheet("rgba(255, 255, 255, 1);");


    //标题栏
    title = new QWidget;
    title->setMaximumHeight(40);
    title->setMinimumHeight(40);
    title->setObjectName("title");

    //右对话框背景
    showBox = new QWidget;
    showBox->setFixedSize(796,640);
    showBox->setObjectName("showBox");



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
bool SimpleStyle::eventFilter(QObject *obj, QEvent *ev)
{

    //其余的事件按照默认(未覆写)的处理方式处理
    return QWidget::eventFilter(obj,ev);
}

/************************************************
* 函数名称：pageChangeForTheme
* 功能描述：主题颜色适配
* 输入参数：
* 输出参数：无
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
void SimpleStyle::pageChangeForTheme(const QString& str)
{
    currentTheme = str;
    qDebug() << currentTheme;

    messagePage->pageChangeForTheme(currentTheme);

    if("ukui-dark" == str || "ukui-black" == str)
    {

        QString showStyleSheet="#showBox{background-color:rgba(31, 32, 34, 1);}";
        showBox->setStyleSheet(showStyleSheet);
    }
    else
    {

        QString showStyleSheet="#showBox{background-color:rgba(255,255,255,1);}";
        showBox->setStyleSheet(showStyleSheet);
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
void SimpleStyle::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F1)
    {
        if(!m_pDaemonIpcDbus->daemonIsNotRunning()){
            m_pDaemonIpcDbus->showGuide("kylin-service-support");
        }
    }
}

