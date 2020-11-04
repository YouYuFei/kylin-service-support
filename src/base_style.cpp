#include "base_style.h"

BaseStyle::BaseStyle(WidgetParameterClass basicParameter, QString dialogTitleText)
{
    local_basicParameter = basicParameter;

    m_pstackWidget = new QStackedWidget();

    mainPage = new MainPage(basicParameter);
    messagePage = new MessagePage(basicParameter);
    contactPage = new ContactPage(basicParameter);
    diySupportPage = new DIYSupportPage(basicParameter);

    myWidgetStyle(local_basicParameter);
    text->setText(dialogTitleText);
    QFont ft;
    ft.setPixelSize(14);
    text->setFont(ft);

}

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

void BaseStyle::WidgetStyleClose()
{
    this->close();
}

void BaseStyle::myWidgetStyle(WidgetParameterClass basicParameter)
{
    myWidgetSizeDesign(basicParameter.winWidth ,basicParameter.winHeight);

    myWidgetBasicInit(basicParameter.titleHeight);

    myWidgetTabInit();

    QSize smallWidgetSize(30,30);//小按钮大小
    widgetMin =new QPushButton;//最小化按钮
    widgetMin->setObjectName("widgetMin");
    widgetMin->setIconSize(smallWidgetSize);
    widgetMin->setFixedSize(smallWidgetSize);

    connect(widgetMin,&QPushButton::clicked,this,[=]{this->setWindowState(Qt::WindowMinimized);});

    widgetClose =new QPushButton;//关闭按钮
    widgetClose->setObjectName("widgetClose");
    widgetClose->setIconSize(smallWidgetSize);
    widgetClose->setFixedSize(smallWidgetSize);

    connect(widgetClose,&QPushButton::clicked,this,&BaseStyle::WidgetStyleClose);

    widgetMin->setStyleSheet("BaseStyle #widgetMin{background-color:rgba(255,255,255,0);border-image:url(:/data/min_d.png);border-radius:4px;}"
                             "BaseStyle #widgetMin:hover{background-color:rgba(100,105,241,1);border-image:url(:/data/min_h.png);border-radius:4px;}"
                             "BaseStyle #widgetMin:pressed{background-color:rgba(82,87,217,1);border-image:url(:/data/min_h.png);border-radius:4px;}");
    widgetClose->setStyleSheet("BaseStyle #widgetClose{background-color:rgba(255,255,255,0);border-image:url(:/data/close_d.png);border-radius:4px;}"
                               "BaseStyle #widgetClose:hover{background-color:rgba(240,64,52,1);border-image:url(:/data/close_h.png);border-radius:4px;}"
                               "BaseStyle #widgetClose:pressed{background-color:rgba(215,51,53,1);border-image:url(:/data/close_p.png);border-radius:4px;}");



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
    hlt2->addSpacing(60);
    hlt2->addWidget(title);
    //hlt2->addSpacing(50);//2004加上这个切换主题后，有一个字会显示不全，后续需要注意其他版本是否有类似问题
    hlt2->addStretch(99);

    QVBoxLayout *vlt_menu_btn=new QVBoxLayout;
    vlt_menu_btn->setMargin(0);
    vlt_menu_btn->setSpacing(0);

    vlt_menu_btn->addWidget(m_pMainPageButton, 1);
    vlt_menu_btn->addSpacing(16);
    vlt_menu_btn->addWidget(m_pMessagePageButton, 1);
    vlt_menu_btn->addSpacing(20);
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
    //hltbutton3->addSpacing(15);

    QVBoxLayout *hlt3=new QVBoxLayout;//标题栏外部
    hlt3->setMargin(0);
    hlt3->setSpacing(0);
    hlt3->addLayout(hltbutton3);
    //hlt3->addSpacing(15);
    hlt3->addWidget(m_pstackWidget);
    hlt3->addStretch(99);

    showBox->setLayout(hlt3);


    QHBoxLayout *hlt_menu=new QHBoxLayout;//窗体内部，水平布局
    hlt_menu->setMargin(0);
    hlt_menu->setSpacing(0);

    //hlt_menu->addSpacing(15);
    hlt_menu->addWidget(menuBox, 1);
    //hlt_menu->addSpacing(10);
    hlt_menu->addWidget(showBox, 1);
    //hlt_menu->addSpacing(10);
    //hlt_menu->addWidget(showPage, 1);
    //hlt_menu->addWidget(tabWidget);
    hlt_menu->addStretch(99);

//    QVBoxLayout *hlt4=new QVBoxLayout;//窗体
//    hlt4->setMargin(0);
//    hlt4->setSpacing(0);
//    //hlt4->addSpacing(15);
//    hlt4->addLayout(hlt_menu);
//    hlt4->addStretch(99);

//    body->setLayout(hlt4);

//    hlt3->addWidget(body);

    QVBoxLayout *vl=new QVBoxLayout;//总体
    vl->setMargin(0);
    vl->setSpacing(0);
    //vl->addLayout(hlt2);
    vl->addLayout(hlt_menu);
    this->setLayout(vl);

    QPoint mainWPoint = this->mapToGlobal(QPoint(0,0));
    qDebug() << mainWPoint;
    //qDebug() << m_pMainPageButton->mapToParent(QPoint(0,0));

    introIcon = new QLabel(this);
    introIcon->setStyleSheet("border-image:url(:/data/icon_intro.png);border:0px;");
    introIcon->setFixedSize(16,16);
    introIcon->move(40,89);

    messageIcon = new QLabel(this);
    messageIcon->setStyleSheet("border-image:url(:/data/icon_message.png);border:0px;");
    messageIcon->setFixedSize(16,16);
    messageIcon->move(40,138);

    contactIcon = new QLabel(this);
    contactIcon->setStyleSheet("border-image:url(:/data/icon_tele.png);border:0px;");
    contactIcon->setFixedSize(16,16);
    contactIcon->move(40,187);

    supportIcon = new QLabel(this);
    supportIcon->setStyleSheet("border-image:url(:/data/icon_support.png);border:0px;");
    supportIcon->setFixedSize(16,16);
    supportIcon->move(40,236);

    titleIcon = new QLabel(this);
    titleIcon->setStyleSheet("border-image:url(:/data/kylin-service-and-support.png);border:0px;");
    titleIcon->setFixedSize(24,24);
    titleIcon->move(26,16);
    this->setWindowIcon(QIcon(":/data/kylin-service-and-support.png"));
    this->setWindowTitle(tr("服务与支持"));
    this->show();
}

void BaseStyle::myWidgetSizeDesign(int width,int height)
{
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明
    this->setFixedSize(width, height);

    QRect availableGeometry = qApp->primaryScreen()->availableGeometry();
    this->move((availableGeometry.width() - this->width())/2, (availableGeometry.height() - this->height())/2);
}

void BaseStyle::myWidgetBasicInit(int titleHeight)
{
    text = new QLabel;
    text->setStyleSheet("rgba(255, 255, 255, 1);");
//    QPalette pal_text(text->palette());

//    //设置背景黑色
//    pal_text.setColor(QPalette::WindowText, Qt::red);
//    text->setAutoFillBackground(true);
//    text->setPalette(pal_text);


    //标题栏
    title = new QWidget;
    title->setMaximumHeight(titleHeight);
    title->setMinimumHeight(titleHeight);
    title->setObjectName("title");

//    QPalette pal_title(title->palette());
//    pal_title.setColor(QPalette::Background, QColor(255, 255, 255, 0.8));//设置背景米色
//    title->setAutoFillBackground(true);
//    title->setPalette(pal_title);
//    QString titleStyleSheet="QWidget #title{background-color:rgba(255,255,255,0.8);}";
//    title->setStyleSheet(titleStyleSheet);

    //窗体
    body = new QWidget;
    body->setFixedHeight(this->height());
    body->setObjectName("body");

    QPalette pal_body(body->palette());
    //pal_body.setColor(QPalette::Background, QColor(255, 255, 255, 0.8));//设置背景米色
    //body->setAutoFillBackground(true);
    body->setPalette(pal_body);

    QString bodyStyleSheet="QWidget #body{border-bottom-left-radius:"+QString::number(12)+"px;\
                    border-top-left-radius:"+QString::number(12)+"px;}";
    body->setStyleSheet(bodyStyleSheet);

    //左菜单背景
    menuBox = new QWidget;
    menuBox->setFixedSize(180,640);
    menuBox->setObjectName("menuBox");

//    QPalette pal_menuBox(menuBox->palette());
//    pal_menuBox.setColor(QPalette::Background, Qt::black);//设置背景黑色
//    menuBox->setAutoFillBackground(true);
//    menuBox->setPalette(pal_menuBox);

    QString menuStyleSheet="QWidget #menuBox{background-color:rgba(255,255,255,0.8);border-bottom-left-radius:"+QString::number(12)+"px;\
                    border-top-left-radius:"+QString::number(12)+"px;}";
    menuBox->setStyleSheet(menuStyleSheet);

    //右对话框背景
    showBox = new QWidget;
    showBox->setFixedSize(778,640);
    showBox->setObjectName("showBox");

//    QPalette pal_showBox(showBox->palette());
//    pal_showBox.setColor(QPalette::Background, Qt::black);//设置背景黑色
//    showBox->setAutoFillBackground(true);
//    showBox->setPalette(pal_showBox);
    QString showStyleSheet="QWidget #showBox{background-color:rgba(255,255,255,1);border-bottom-right-radius:"+QString::number(12)+"px;\
                    border-top-right-radius:"+QString::number(12)+"px;}";
    showBox->setStyleSheet(showStyleSheet);

}

void BaseStyle::myWidgetTabInit()
{
    //主页界面显示按钮
    m_pMainPageButton = new TabMenuButton();
    m_pMainPageButton->setText("软件介绍");
    m_pMainPageButton->setObjectName("MainPageButton");
    m_pMainPageButton->setFixedSize(132,32);
    m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);
    m_pMainPageButton->setStyleSheet(qssChooseMenuBar);

    connect(m_pMainPageButton, &TabMenuButton::clicked, this, &BaseStyle::m_MainPageButtonSlots);

    //留言咨询界面显示按钮
    m_pMessagePageButton = new TabMenuButton();
    m_pMessagePageButton->setText(tr("留言咨询"));
    m_pMessagePageButton->setObjectName("MessagePageButton");
    m_pMessagePageButton->setFixedSize(132,32);
    m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);
    connect(m_pMessagePageButton, &TabMenuButton::clicked, this, &BaseStyle::m_MessagePageButtonSlots);

    //在线客服界面显示按钮
    m_pOnlineButton = new TabMenuButton();
    m_pOnlineButton->setText(tr("在线客服"));
    m_pOnlineButton->setObjectName("OnlineButton");
    m_pOnlineButton->setFixedSize(132,32);
    m_pOnlineButton->setStyleSheet(qssDefaultMenuBar);
    connect(m_pOnlineButton, &TabMenuButton::clicked, this, &BaseStyle::m_OnlinePageButtonSlots);

    //联系我们界面显示按钮
    m_pContactButton = new TabMenuButton();
    m_pContactButton->setText(tr("联系我们"));
    m_pContactButton->setObjectName("ContactButton");
    m_pContactButton->setFixedSize(132,32);
    m_pContactButton->setStyleSheet(qssDefaultMenuBar);
    connect(m_pContactButton, &TabMenuButton::clicked, this, &BaseStyle::m_ContactPageButtonSlots);

    //自助支持界面显示按钮
    m_pDIYButton = new TabMenuButton();
    m_pDIYButton->setText(tr("自助支持"));
    m_pDIYButton->setObjectName("DIYButton");
    m_pDIYButton->setFixedSize(132,32);
    m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
    connect(m_pDIYButton, &TabMenuButton::clicked, this, &BaseStyle::m_DIYPageButtonSlots);

}

/* 移动到剪贴板按钮需要修改的界面 */
void BaseStyle::m_MainPageButtonSlots()
{
//    m_pBlueBackgroundButton->setVisible(false);
    setMainPageButtonBackgroundBlue();
    m_pstackWidget->setCurrentIndex(0);
//    setSmallPluginsButtonBackgroudIsBlank();
//    return;
}

/* 移动到小插件界面按钮需要做的界面修改 */
void BaseStyle::m_MessagePageButtonSlots()
{
//    m_pBlueBackgroundButton->setVisible(false);
//    setClipboardButtonBackgroundIsBlank();
    setMessagePageButtonBackgroudIsBlue();
    m_pstackWidget->setCurrentIndex(1);
//    return;
}

void BaseStyle::m_OnlinePageButtonSlots()
{
//    m_pBlueBackgroundButton->setVisible(false);
//    setClipboardButtonBackgroundIsBlank();
    setOnlinePageButtonBackgroudIsBlue();
//    return;
}

void BaseStyle::m_ContactPageButtonSlots()
{
//    m_pBlueBackgroundButton->setVisible(false);
//    setClipboardButtonBackgroundIsBlank();
    setContactPageButtonBackgroudIsBlue();
    m_pstackWidget->setCurrentIndex(2);
//    return;
}

void BaseStyle::m_DIYPageButtonSlots()
{
//    m_pBlueBackgroundButton->setVisible(false);
//    setClipboardButtonBackgroundIsBlank();
    setDIYPageButtonBackgroudIsBlue();
    m_pstackWidget->setCurrentIndex(3);
//    return;
}

void BaseStyle::setMainPageButtonBackgroundBlue()
{
    m_pMainPageButton->setStyleSheet(qssChooseMenuBar);

    m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);

    m_pOnlineButton->setStyleSheet(qssDefaultMenuBar);

    m_pContactButton->setStyleSheet(qssDefaultMenuBar);

    m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
}

void BaseStyle::setMessagePageButtonBackgroudIsBlue()
{
    m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);

    m_pMessagePageButton->setStyleSheet(qssChooseMenuBar);

    m_pOnlineButton->setStyleSheet(qssDefaultMenuBar);

    m_pContactButton->setStyleSheet(qssDefaultMenuBar);

    m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
}

void BaseStyle::setOnlinePageButtonBackgroudIsBlue()
{
    m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);

    m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);

    m_pOnlineButton->setStyleSheet(qssChooseMenuBar);

    m_pContactButton->setStyleSheet(qssDefaultMenuBar);

    m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
}

void BaseStyle::setContactPageButtonBackgroudIsBlue()
{
    m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);

    m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);

    m_pOnlineButton->setStyleSheet(qssDefaultMenuBar);

    m_pContactButton->setStyleSheet(qssChooseMenuBar);

    m_pDIYButton->setStyleSheet(qssDefaultMenuBar);
}

void BaseStyle::setDIYPageButtonBackgroudIsBlue()
{
    m_pMainPageButton->setStyleSheet(qssDefaultMenuBar);

    m_pMessagePageButton->setStyleSheet(qssDefaultMenuBar);

    m_pOnlineButton->setStyleSheet(qssDefaultMenuBar);

    m_pContactButton->setStyleSheet(qssDefaultMenuBar);

    m_pDIYButton->setStyleSheet(qssChooseMenuBar);
}

void BaseStyle::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->dragPosition = event->globalPos() - frameGeometry().topLeft();
        this->mousePressed = true;
    }
    QWidget::mousePressEvent(event);
}

void BaseStyle::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->mousePressed = false;
    }
    QWidget::mouseReleaseEvent(event);
}

void BaseStyle::mouseMoveEvent(QMouseEvent *event)
{
    if (this->mousePressed) {
        move(event->globalPos() - this->dragPosition);
    }
    QWidget::mouseMoveEvent(event);
}


