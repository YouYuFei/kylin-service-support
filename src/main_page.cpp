/************************************************
* 文件描述: 程序首页内容类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "main_page.h"
/************************************************
* 函数名称：MainPage
* 功能描述：构造函数
* 输入参数：程序参数类
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
MainPage::MainPage(const WidgetParameterClass& basicParam)
{
    m_pKylinPic = nullptr;
    m_pMoreInfoLink_1 = nullptr;
    m_pMoreInfoLink_2 = nullptr;
    m_pMoreInfoLink_3 = nullptr;
    m_pPageTitle = nullptr;

    m_pOnline = nullptr;
    m_pOnline_1 = nullptr;
    m_pOnline_2 = nullptr;
    m_pOnline_3 = nullptr;

    m_pTelphone = nullptr;
    m_pTelphone_1 = nullptr;
    m_pTelphone_2 = nullptr;
    m_pTelphone_3 = nullptr;

    m_pMail = nullptr;
    m_pMail_1 = nullptr;
    m_pMail_2 = nullptr;
    m_pMail_3 = nullptr;

    m_pWeChat = nullptr;
    m_pWeChat_1 = nullptr;
    m_pWeChat_2 = nullptr;
    m_pWeChat_3 = nullptr;

    m_pDIY = nullptr;
    m_pDIY_1 = nullptr;
    m_pDIY_2 = nullptr;
    m_pDIY_3 = nullptr;

    this->setWindowTitle("main_page");
    mainPageBasicParameter = basicParam;
    pageLocationInit();
}
/************************************************
* 函数名称：pageLocationInit
* 功能描述：页面布局函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainPage::pageLocationInit()
{
    m_pKylinPic = new QLabel;
    m_pKylinPic->setFixedSize(718,331);
    m_pKylinPic->setStyleSheet("border-image:url(:/data/banner.png);border:0px;");

    m_pMoreInfoLink_1 = new QLabel;
    m_pMoreInfoLink_1->adjustSize();//setFixedSize(368,17);
    m_pMoreInfoLink_1->setText(tr("Click "));

//    m_pMoreInfoLink->setText(tr("点击<style> a {text-decoration: none} </style> <a href=\"http://www.kylinos.cn\">了解更多服务与支持内容</a>，跳转至KylinOS官方网站技术支持页面"));
    m_pMoreInfoLink_2 = new QLabel;
    m_pMoreInfoLink_2->adjustSize();
    m_pMoreInfoLink_2->setText(tr("to know more about support"));
    m_pMoreInfoLink_2->installEventFilter(this);

    m_pMoreInfoLink_3 = new QLabel;
    m_pMoreInfoLink_3->adjustSize();
    m_pMoreInfoLink_3->setText(tr("，to KylinOS Official Web"));

    m_pPageTitle = new QLabel;
    m_pPageTitle->adjustSize();//setFixedSize(216,17);
    m_pPageTitle->setStyleSheet("color:rgba(96, 98, 101, 1);font-size:12px;");
    m_pPageTitle->setText(tr("You can get your answers through the ways below"));//"用户可通过以下方式寻求技术支持和服务");
    m_pPageTitle->setAlignment(Qt::AlignHCenter);

    m_pOnline_1 = new QLabel;
    m_pOnline_1->setFixedSize(16,16);
    QIcon icon = QIcon::fromTheme("address-book-new-symbolic");
    m_pOnline_1->setProperty("useIconHighlightEffect", 0x8);
    m_pOnline_1->setPixmap(icon.pixmap(QSize(16,16)));
    m_pOnline_1->setScaledContents(true);
//    m_pOnline_1->setStyleSheet("border-image:url(:/data/icon_wx.png);border:0px;");

    m_pOnline_2 = new QLabel;
    m_pOnline_2->adjustSize();//->setFixedSize(56,20);
    m_pOnline_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pOnline_2->setText(tr("Offical WeChat Account"));//"企业微信");
    m_pOnline_2->setAlignment(Qt::AlignLeft);
    m_pOnline_2->setAlignment(Qt::AlignVCenter);
    m_pOnline_2->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pOnline_3 = new QLabel;
    m_pOnline_3->adjustSize();//->setFixedSize(206,34);
    m_pOnline_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pOnline_3->setText(tr("You can add our Team's WeChat\n Get an online response."));//"用户通过微信添加服务与支持团队成员\n企业微信号，寻求在线响应");
    m_pOnline_3->setAlignment(Qt::AlignLeft);
    m_pOnline_3->setAlignment(Qt::AlignVCenter);
    m_pOnline_3->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *KylinOnline_I = new QHBoxLayout;
    KylinOnline_I->setMargin(0);
    KylinOnline_I->setSpacing(0);
    KylinOnline_I->addSpacing(0);
    KylinOnline_I->addWidget(m_pOnline_1,1);
    KylinOnline_I->addSpacing(3);
    KylinOnline_I->addWidget(m_pOnline_2,1);
    KylinOnline_I->addStretch(99);

    QVBoxLayout *KylinOnline_II = new QVBoxLayout;
    KylinOnline_II->setMargin(0);
    KylinOnline_II->setSpacing(0);
    KylinOnline_II->addSpacing(0);
    KylinOnline_II->addLayout(KylinOnline_I,1);
    KylinOnline_II->addSpacing(4);
    KylinOnline_II->addWidget(m_pOnline_3,1);
    KylinOnline_II->addStretch(99);

    m_pOnline = new QWidget;
    m_pOnline->setFixedSize(206,62);
    m_pOnline->setLayout(KylinOnline_II);

    m_pTelphone_1 = new QLabel;
    m_pTelphone_1->setFixedSize(16,16);
    QIcon icon1 = QIcon::fromTheme("audio-headset-symbolic");
    m_pTelphone_1->setProperty("useIconHighlightEffect", 0x8);
    m_pTelphone_1->setPixmap(icon1.pixmap(QSize(16,16)));
    m_pTelphone_1->setScaledContents(true);
//    m_pTelphone_1->setStyleSheet("border-image:url(:/data/icon_kefu.png);border:0px;");

    m_pTelphone_2 = new QLabel;
    m_pTelphone_2->adjustSize();//setFixedSize(56,20);
    m_pTelphone_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pTelphone_2->setText(tr("Online"));//"在线咨询");
    m_pTelphone_2->setAlignment(Qt::AlignLeft);
    m_pTelphone_2->setAlignment(Qt::AlignVCenter);
    m_pTelphone_2->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pTelphone_3 = new QLabel;
    m_pTelphone_3->adjustSize();//->setFixedSize(206,34);
    m_pTelphone_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pTelphone_3->setText(tr("Leave message to get support."));//"提供IM和反馈两种在线咨询方式");
    m_pTelphone_3->setAlignment(Qt::AlignLeft);
    m_pTelphone_3->setAlignment(Qt::AlignVCenter);
    m_pTelphone_3->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *KylinTelphone_I = new QHBoxLayout;
    KylinTelphone_I->setMargin(0);
    KylinTelphone_I->setSpacing(0);
    KylinTelphone_I->addSpacing(0);
    KylinTelphone_I->addWidget(m_pTelphone_1,1);
    KylinTelphone_I->addSpacing(3);
    KylinTelphone_I->addWidget(m_pTelphone_2,1);
    KylinTelphone_I->addStretch(99);

    QVBoxLayout *KylinTelphone_II = new QVBoxLayout;
    KylinTelphone_II->setMargin(0);
    KylinTelphone_II->setSpacing(0);
    KylinTelphone_II->addSpacing(0);
    KylinTelphone_II->addLayout(KylinTelphone_I,1);
    KylinTelphone_II->addSpacing(4);
    KylinTelphone_II->addWidget(m_pTelphone_3,1);
    KylinTelphone_II->addStretch(99);

    m_pTelphone = new QWidget;
    m_pTelphone->setFixedSize(206,62);
    m_pTelphone->setLayout(KylinTelphone_II);

    m_pMail_1 = new QLabel;
    m_pMail_1->setFixedSize(16,16);
    QIcon icon2 = QIcon::fromTheme("mail-app-symbolic");
    m_pMail_1->setProperty("useIconHighlightEffect", 0x8);
    m_pMail_1->setPixmap(icon2.pixmap(QSize(16,16)));
    m_pMail_1->setScaledContents(true);
//    m_pMail_1->setStyleSheet("border-image:url(:/data/mail.png);border:0px;");

    m_pMail_2 = new QLabel;
    m_pMail_2->adjustSize();//->setFixedSize(56,20);
    m_pMail_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pMail_2->setText(tr("Mail"));//"邮件咨询");
    m_pMail_2->setAlignment(Qt::AlignLeft);
    m_pMail_2->setAlignment(Qt::AlignVCenter);
    m_pMail_2->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pMail_3 = new QLabel;
    m_pMail_3->adjustSize();//->setFixedSize(206,34);
    m_pMail_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pMail_3->setText(tr("Send mail to get support."));//"用户通过发送邮件到指定官方邮件，寻\n求服务与技术响应");
    m_pMail_3->setAlignment(Qt::AlignLeft);
    m_pMail_3->setAlignment(Qt::AlignVCenter);
    m_pMail_3->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *KylinMail_I = new QHBoxLayout;
    KylinMail_I->setMargin(0);
    KylinMail_I->setSpacing(0);
    KylinMail_I->addSpacing(0);
    KylinMail_I->addWidget(m_pMail_1,1);
    KylinMail_I->addSpacing(3);
    KylinMail_I->addWidget(m_pMail_2,1);
    KylinMail_I->addStretch(99);

    QVBoxLayout *KylinMail_II = new QVBoxLayout;
    KylinMail_II->setMargin(0);
    KylinMail_II->setSpacing(0);
    KylinMail_II->addSpacing(0);
    KylinMail_II->addLayout(KylinMail_I,1);
    KylinMail_II->addSpacing(4);
    KylinMail_II->addWidget(m_pMail_3,1);
    KylinMail_II->addStretch(99);

    m_pMail = new QWidget;
    m_pMail->setFixedSize(206,62);
    m_pMail->setLayout(KylinMail_II);

    m_pWeChat_1 = new QLabel;
    m_pWeChat_1->setFixedSize(16,16);
    QIcon icon3 = QIcon::fromTheme("call-stop-symbolic");
    m_pWeChat_1->setProperty("useIconHighlightEffect", 0x8);
    m_pWeChat_1->setPixmap(icon3.pixmap(QSize(16,16)));
    m_pWeChat_1->setScaledContents(true);
//    m_pWeChat_1->setStyleSheet("border-image:url(:/data/icon_contact.png);border:0px;");

    m_pWeChat_2 = new QLabel;
    m_pWeChat_2->adjustSize();//->setFixedSize(56,20);
    m_pWeChat_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pWeChat_2->setText(tr("Telephone"));//"电话咨询");
    m_pWeChat_2->setAlignment(Qt::AlignLeft);
    m_pWeChat_2->setAlignment(Qt::AlignVCenter);
    m_pWeChat_2->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pWeChat_3 = new QLabel;
    m_pWeChat_3->adjustSize();//->setFixedSize(206,34);
    m_pWeChat_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pWeChat_3->setText(tr("5*8 hours hotline."));//"5x8小时或7x24小时呼叫中心电话支持\n响应");
    m_pWeChat_3->setAlignment(Qt::AlignLeft);
    m_pWeChat_3->setAlignment(Qt::AlignVCenter);
    m_pWeChat_3->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *KylinWeChat_I = new QHBoxLayout;
    KylinWeChat_I->setMargin(0);
    KylinWeChat_I->setSpacing(0);
    KylinWeChat_I->addSpacing(0);
    KylinWeChat_I->addWidget(m_pWeChat_1,1);
    KylinWeChat_I->addSpacing(3);
    KylinWeChat_I->addWidget(m_pWeChat_2,1);
    KylinWeChat_I->addStretch(99);

    QVBoxLayout *KylinWeChat_II = new QVBoxLayout;
    KylinWeChat_II->setMargin(0);
    KylinWeChat_II->setSpacing(0);
    KylinWeChat_II->addSpacing(0);
    KylinWeChat_II->addLayout(KylinWeChat_I,1);
    KylinWeChat_II->addSpacing(4);
    KylinWeChat_II->addWidget(m_pWeChat_3,1);
    KylinWeChat_II->addStretch(99);

    m_pWeChat = new QWidget;
    m_pWeChat->setFixedSize(206,62);
    m_pWeChat->setLayout(KylinWeChat_II);


    m_pDIY_1 = new QLabel;
    m_pDIY_1->setFixedSize(16,16);
    QIcon icon4 = QIcon::fromTheme("view-paged-symbolic");
    m_pDIY_1->setProperty("useIconHighlightEffect", 0x8);
    m_pDIY_1->setPixmap(icon4.pixmap(QSize(16,16)));
    m_pDIY_1->setScaledContents(true);
//    m_pDIY_1->setStyleSheet("border-image:url(:/data/icon_support1.png);border:0px;");

    m_pDIY_2 = new QLabel;
    m_pDIY_2->adjustSize();//->setFixedSize(56,20);
    m_pDIY_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pDIY_2->setText(tr("Guidance"));//"自助支持");
    m_pDIY_2->setAlignment(Qt::AlignLeft);
    m_pDIY_2->setAlignment(Qt::AlignVCenter);
    m_pDIY_2->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pDIY_3 = new QLabel;
    m_pDIY_3->adjustSize();//->setFixedSize(206,34);
    m_pDIY_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pDIY_3->setText(tr("Users can check Manuals to solve\nthe problem by self."));//用户通过搜索和查询帮助手册、文档中\n心、FAQ内容和已排除疑问解决问题");
    m_pDIY_3->setAlignment(Qt::AlignLeft);
    m_pDIY_3->setAlignment(Qt::AlignVCenter);
    m_pDIY_3->setAttribute(Qt::WA_TransparentForMouseEvents);

    QHBoxLayout *KylinDIY_I = new QHBoxLayout;
    KylinDIY_I->setMargin(0);
    KylinDIY_I->setSpacing(0);
    KylinDIY_I->addSpacing(0);
    KylinDIY_I->addWidget(m_pDIY_1,1);
    KylinDIY_I->addSpacing(3);
    KylinDIY_I->addWidget(m_pDIY_2,1);
    KylinDIY_I->addStretch(99);

    QVBoxLayout *KylinDIY_II = new QVBoxLayout;
    KylinDIY_II->setMargin(0);
    KylinDIY_II->setSpacing(0);
    KylinDIY_II->addSpacing(0);
    KylinDIY_II->addLayout(KylinDIY_I,1);
    KylinDIY_II->addSpacing(4);
    KylinDIY_II->addWidget(m_pDIY_3,1);
    KylinDIY_II->addStretch(99);

    m_pDIY = new QWidget;
    m_pDIY->setFixedSize(206,62);
    m_pDIY->setLayout(KylinDIY_II);

    QHBoxLayout *HmainLayout_I = new QHBoxLayout;
    HmainLayout_I->addSpacing(0);
    HmainLayout_I->setMargin(0);
    HmainLayout_I->addSpacing(30);
    HmainLayout_I->addWidget(m_pOnline,1);
    HmainLayout_I->addSpacing(42);
    HmainLayout_I->addWidget(m_pTelphone,1);
    HmainLayout_I->addSpacing(42);
    HmainLayout_I->addWidget(m_pMail,1);
    HmainLayout_I->addSpacing(30);
    HmainLayout_I->addStretch(99);

    QHBoxLayout *HmainLayout_II = new QHBoxLayout;
    HmainLayout_II->addSpacing(0);
    HmainLayout_II->setMargin(0);
    //HmainLayout_II->addStretch(99);
    HmainLayout_II->addSpacing(30);
    HmainLayout_II->addWidget(m_pWeChat,1);
    HmainLayout_II->addSpacing(42);
    HmainLayout_II->addWidget(m_pDIY,1);
    HmainLayout_II->addSpacing(290);
    HmainLayout_II->addStretch(99);

    QHBoxLayout *HmainLayout_KylinPic = new QHBoxLayout;
    HmainLayout_KylinPic->addSpacing(0);
    HmainLayout_KylinPic->setMargin(0);
    HmainLayout_KylinPic->addStretch(99);
    HmainLayout_KylinPic->addSpacing(30);
    HmainLayout_KylinPic->addWidget(m_pKylinPic,1);
    HmainLayout_KylinPic->addSpacing(30);
    HmainLayout_KylinPic->addStretch(99);

    QHBoxLayout *HmainLayout_MoreInfoLink = new QHBoxLayout;
    HmainLayout_MoreInfoLink->setSpacing(0);
    HmainLayout_MoreInfoLink->setMargin(0);
    HmainLayout_MoreInfoLink->addStretch(99);
    HmainLayout_MoreInfoLink->addSpacing(380);
    HmainLayout_MoreInfoLink->addWidget(m_pMoreInfoLink_1,1);
    HmainLayout_MoreInfoLink->addWidget(m_pMoreInfoLink_2,1);
    HmainLayout_MoreInfoLink->addWidget(m_pMoreInfoLink_3,1);
    HmainLayout_MoreInfoLink->addSpacing(30);
    HmainLayout_MoreInfoLink->addStretch(99);

    QHBoxLayout *HmainLayout_PageTitle = new QHBoxLayout;
    HmainLayout_PageTitle->addSpacing(0);
    HmainLayout_PageTitle->setMargin(0);
    HmainLayout_PageTitle->addStretch(99);
    HmainLayout_PageTitle->addSpacing(30);
    HmainLayout_PageTitle->addWidget(m_pPageTitle,1);
    HmainLayout_PageTitle->addSpacing(532);
    HmainLayout_PageTitle->addStretch(99);

    QVBoxLayout *VmainLayout = new QVBoxLayout;
    VmainLayout->setSpacing(0);
    VmainLayout->setMargin(0);
    VmainLayout->addLayout(HmainLayout_KylinPic,1);
    VmainLayout->addSpacing(8);
    VmainLayout->addLayout(HmainLayout_MoreInfoLink, 1);
    VmainLayout->addSpacing(14);
    VmainLayout->addLayout(HmainLayout_PageTitle,1);
    VmainLayout->addSpacing(10);
    VmainLayout->addLayout(HmainLayout_I,1);
    VmainLayout->addSpacing(10);
    VmainLayout->addLayout(HmainLayout_II,1);
    VmainLayout->addStretch(99);
    this->setLayout(VmainLayout);
}
/************************************************
* 函数名称：eventFilter
* 功能描述：m_pMoreInfoLink_2点击跳转到ubuntukylin主页
* 输入参数：
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
bool MainPage::eventFilter(QObject *obj, QEvent *ev)
{
    if(obj == m_pMoreInfoLink_2)
    {
        if(ev->type() == QEvent::MouseButtonPress)
        {
            QDesktopServices::openUrl(QUrl("http://www.kylinos.cn/support/problem.html"));

        }
    }

    return QWidget::eventFilter(obj,ev);
}
/************************************************
* 函数名称：pageChangeForTheme
* 功能描述：主题适配函数
* 输入参数：
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MainPage::pageChangeForTheme(const QString& str)
{
    currentTheme = str;

    if("ukui-dark" == str || "ukui-black" == str)
    {
        m_pMoreInfoLink_1->setStyleSheet("color:rgba(143, 147, 153, 1);font-size:12px;");
        m_pMoreInfoLink_2->setStyleSheet("color:rgba(112, 149, 255, 1);font-size:12px;");
        m_pMoreInfoLink_3->setStyleSheet("color:rgba(143, 147, 153, 1);font-size:12px;");
        m_pPageTitle->setStyleSheet("color:rgba(192, 196, 204, 1);font-size:12px;");
//        m_pOnline_1->setStyleSheet("border-image:url(:/data/icon_wx_d.png);border:0px;");
        m_pOnline_2->setStyleSheet("background-color:transparent;color:rgba(249, 249, 249, 1);font-size:14px;");
        m_pOnline_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pTelphone_1->setStyleSheet("border-image:url(:/data/icon_kefu_d.png);border:0px;");
        m_pTelphone_2->setStyleSheet("background-color:transparent;color:rgba(249, 249, 249, 1);font-size:14px;");
        m_pTelphone_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pMail_1->setStyleSheet("border-image:url(:/data/mail_d.png);border:0px;");
        m_pMail_2->setStyleSheet("background-color:transparent;color:rgba(249, 249, 249, 1);font-size:14px;");
        m_pMail_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pWeChat_1->setStyleSheet("border-image:url(:/data/icon_contact_d.png);border:0px;");
        m_pWeChat_2->setStyleSheet("background-color:transparent;color:rgba(249, 249, 249, 1);font-size:14px;");
        m_pWeChat_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pDIY_1->setStyleSheet("border-image:url(:/data/icon_support1_d.png);border:0px;");
        m_pDIY_2->setStyleSheet("background-color:transparent;color:rgba(249, 249, 249, 1);font-size:14px;");
        m_pDIY_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");

    }
    else
    {
        m_pMoreInfoLink_1->setStyleSheet("color:rgba(48, 49, 51, 1);font-size:12px;");
        m_pMoreInfoLink_2->setStyleSheet("color:rgba(112, 149, 255, 1);font-size:12px;");
        m_pMoreInfoLink_3->setStyleSheet("color:rgba(48, 49, 51, 1);font-size:12px;");
        m_pPageTitle->setStyleSheet("color:rgba(96, 98, 101, 1);font-size:12px;");
//        m_pOnline_1->setStyleSheet("border-image:url(:/data/icon_wx.png);border:0px;");
        m_pOnline_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pOnline_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pTelphone_1->setStyleSheet("border-image:url(:/data/icon_kefu.png);border:0px;");
        m_pTelphone_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pTelphone_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pMail_1->setStyleSheet("border-image:url(:/data/mail.png);border:0px;");
        m_pMail_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pMail_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pWeChat_1->setStyleSheet("border-image:url(:/data/icon_contact.png);border:0px;");
        m_pWeChat_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pWeChat_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
//        m_pDIY_1->setStyleSheet("border-image:url(:/data/icon_support1.png);border:0px;");
        m_pDIY_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pDIY_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");

    }
}
