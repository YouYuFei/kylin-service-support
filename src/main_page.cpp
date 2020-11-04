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
MainPage::MainPage(WidgetParameterClass basicParam)
{
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

//    QPalette pal_KylinPic(m_pKylinPic->palette());
//    pal_KylinPic.setColor(QPalette::Background, Qt::black);//设置背景黑色
//    m_pKylinPic->setAutoFillBackground(true);
//    m_pKylinPic->setPalette(pal_KylinPic);
    //m_pPageTitle->setStyleSheet("color:rgba(255, 0, 0, 0.85);font-size:20px;");

    m_pMoreInfoLink = new QLabel;
    m_pMoreInfoLink->setFixedSize(368,17);
    m_pMoreInfoLink->setStyleSheet("color:rgba(48, 49, 51, 1);font-size:12px;");
    m_pMoreInfoLink->setOpenExternalLinks(true);
    m_pMoreInfoLink->setText(tr("点击"
                                "<style> a {text-decoration: none} </style> <a href=\"http://www.kylinos.cn\">了解更多服务与支持内容</a>"
                                "，跳转至KylinOS官方网站技术支持页面"));

    m_pPageTitle = new QLabel;
    m_pPageTitle->setFixedSize(216,17);
    m_pPageTitle->setStyleSheet("color:rgba(96, 98, 101, 1);font-size:12px;");
    m_pPageTitle->setText("用户可通过以下方式寻求技术支持和服务");
    m_pPageTitle->setAlignment(Qt::AlignHCenter);

    m_pOnline = new QLabel;
    m_pOnline->setFixedSize(206,62);
    m_pOnline->setText("<img src = ':/data/icon_wx.png' height='16' width='16' />"
                       "<font style = 'font-size:14px; color:rgba(rgba(48, 49, 51, 1));'> 企业微信 </font>"
                       "<br/>"
                       "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 用户通过微信添加服务与支持团队成员</font>"
                       "<br/>"
                       "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 企业微信号，寻求在线响应 </font>");
    m_pOnline->setAlignment(Qt::AlignLeft);

    //m_pOnline->setStyleSheet("border:2px solid blue; border-radius:10px");

    m_pTelphone = new QLabel;
    m_pTelphone->setFixedSize(206,62);
    m_pTelphone->setText("<img src = ':/data/icon_kefu.png' height='16' width='16' />"
                         "<font style = 'font-size:14px; color:rgba(rgba(48, 49, 51, 1));'> 在线咨询 </font>"
                         "<br/>"
                         "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 提供IM和反馈两种在线咨询方式</font>");
    m_pTelphone->setAlignment(Qt::AlignLeft);
    //m_pTelphone->setStyleSheet("border:2px solid blue; border-radius:10px");

    m_pMail = new QLabel;
    m_pMail->setFixedSize(206,62);
    m_pMail->setText("<img src = ':/data/mail.png' height='16' width='16' />"
                     "<font style = 'font-size:14px; color:rgba(rgba(48, 49, 51, 1));'> 邮件咨询 </font>"
                     "<br/>"
                     "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 用户通过发送邮件到指定官方邮件，寻</font>"
                     "<br/>"
                     "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 求服务与技术响应 </font>");
    m_pMail->setAlignment(Qt::AlignLeft);
    //m_pMail->setStyleSheet("border:2px solid blue; border-radius:10px");

//    QLabel *m_pWeChat;
    m_pWeChat = new QLabel;
    m_pWeChat->setFixedSize(206,62);
    m_pWeChat->setText("<img src = ':/data/icon_contact.png' height='16' width='16' />"
                       "<font style = 'font-size:14px; color:rgba(rgba(48, 49, 51, 1));'> 电话咨询 </font>"
                       "<br/>"
                       "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 5x8小时或7x24小时呼叫中心电话支持</font>"
                       "<br/>"
                       "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 响应 </font>");
    m_pWeChat->setAlignment(Qt::AlignLeft);
    //m_pWeChat->setStyleSheet("border:2px solid blue; border-radius:10px");
//    QLabel *m_pDIY;
    m_pDIY = new QLabel;
    m_pDIY->setFixedSize(206,62);
    m_pDIY->setText("<img src = ':/data/icon_support1.png' height='16' width='16' />"
                    "<font style = 'font-size:14px; color:rgba(rgba(48, 49, 51, 1));'> 自助支持 </font>"
                    "<br/>"
                    "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 用户通过搜索和查询帮助手册、文档中</font>"
                    "<br/>"
                    "<font style = 'font-size:12px; color:rgba(143, 147, 153, 1);'> 心、FAQ内容和已排除疑问解决问题 </font>");
    m_pDIY->setAlignment(Qt::AlignLeft);
    //m_pDIY->setStyleSheet("border:2px solid blue; border-radius:10px");

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
    HmainLayout_MoreInfoLink->addSpacing(0);
    HmainLayout_MoreInfoLink->setMargin(0);
    HmainLayout_MoreInfoLink->addStretch(99);
    HmainLayout_MoreInfoLink->addSpacing(380);
    HmainLayout_MoreInfoLink->addWidget(m_pMoreInfoLink,1);
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
    VmainLayout->addSpacing(0);
    VmainLayout->setMargin(0);
    VmainLayout->addLayout(HmainLayout_KylinPic);
    VmainLayout->addSpacing(6);
    VmainLayout->addLayout(HmainLayout_MoreInfoLink);
    VmainLayout->addSpacing(14);
    VmainLayout->addLayout(HmainLayout_PageTitle);
    VmainLayout->addSpacing(10);
    VmainLayout->addLayout(HmainLayout_I);
    VmainLayout->addSpacing(10);
    VmainLayout->addLayout(HmainLayout_II);
    VmainLayout->addStretch(99);
    this->setLayout(VmainLayout);
}
