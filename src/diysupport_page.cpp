#include "diysupport_page.h"
#include <QDebug>

DIYSupportPage::DIYSupportPage(WidgetParameterClass basicParam)
{
    this->setWindowTitle("diysupport_page");
    diySupportPageBasicParameter = basicParam;
    pageLocationInit();
    // 响应用户手册
    mDaemonIpcDbus = new DaemonIpcDbus();
}

void DIYSupportPage::pageLocationInit()
{
    m_pKylinPic = new QLabel;
    m_pKylinPic->setFixedSize(718,331);
    m_pKylinPic->setStyleSheet("border-image:url(:/data/banner.png);border:0px;");

    m_pMoreInfoLink = new QLabel;
    m_pMoreInfoLink->setFixedSize(368,17);
    m_pMoreInfoLink->setStyleSheet("color:rgba(48, 49, 51, 1);font-size:12px;");
    m_pMoreInfoLink->setOpenExternalLinks(true);
    m_pMoreInfoLink->setText(tr("点击"
                                "<style> a {text-decoration: none} </style> <a href=\"http://www.kylinos.cn\">了解更多服务与支持内容</a>"
                                "，跳转至KylinOS官方网站技术支持页面"));

    m_pPageTitle = new QLabel;
    m_pPageTitle->setFixedSize(168,17);
    m_pPageTitle->setStyleSheet("color:rgba(96, 98, 101, 1);font-size:12px;");
    m_pPageTitle->setText("用户还可通过以下方式解决问题");
    m_pPageTitle->setAlignment(Qt::AlignHCenter);

    officialWeb = new MyClickWidget(this);
    officialWeb->setFixedSize(349,100);
    officialWeb->setObjectName("officialWeb");

    QString officialWebStyleSheet="MyClickWidget{background-color:rgba(246, 247, 247, 1);border-radius:6px;}"
            "MyClickWidget:hover{background-color:rgba(149, 176, 255, 1);border-radius:6px;}"
            "MyClickWidget:pressed{background-color:rgba(149, 176, 255, 1);border-radius:6px;}";
    officialWeb->setStyleSheet(officialWebStyleSheet);

    connect(officialWeb,&MyClickWidget::clicked,this,&DIYSupportPage::on_officialWeb_clicked);

    m_pKylinOfficialWeb_1 = new QLabel;
    m_pKylinOfficialWeb_1->setFixedSize(18,18);
    m_pKylinOfficialWeb_1->setStyleSheet("border-image:url(:/data/icon_wx.png);border:0px;");
    m_pKylinOfficialWeb_1->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pKylinOfficialWeb_2 = new QLabel;
    m_pKylinOfficialWeb_2->setFixedSize(84,20);
    m_pKylinOfficialWeb_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pKylinOfficialWeb_2->setText("前往麒麟官网");
    m_pKylinOfficialWeb_2->setAlignment(Qt::AlignLeft);
    m_pKylinOfficialWeb_2->setAlignment(Qt::AlignVCenter);
    m_pKylinOfficialWeb_2->setAttribute(Qt::WA_TransparentForMouseEvents);

    m_pKylinOfficialWeb_3 = new QLabel;
    m_pKylinOfficialWeb_3->setFixedSize(263,17);
    m_pKylinOfficialWeb_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pKylinOfficialWeb_3->setText("用户通过访问官网，自助寻求技术与帮助。");
    m_pKylinOfficialWeb_3->setAlignment(Qt::AlignLeft);
    m_pKylinOfficialWeb_3->setAlignment(Qt::AlignVCenter);
    m_pKylinOfficialWeb_3->setAttribute(Qt::WA_TransparentForMouseEvents);

    kylinManual = new MyClickWidget(this);
    kylinManual->setFixedSize(349,100);
    kylinManual->setObjectName("kylinManual");

    QString kylinManualStyleSheet="MyClickWidget{background-color:rgba(246, 247, 247, 1);border-radius:6px;}"
            "MyClickWidget:hover{background-color:rgba(149, 176, 255, 1);border-radius:6px;}"
            "MyClickWidget:pressed{background-color:rgba(149, 176, 255, 1);border-radius:6px;}";
    kylinManual->setStyleSheet(kylinManualStyleSheet);

    connect(kylinManual,&MyClickWidget::clicked,this,&DIYSupportPage::on_kylinManual_clicked);

    m_pKylinManual_1 = new QLabel;
    m_pKylinManual_1->setFixedSize(18,18);
    m_pKylinManual_1->setStyleSheet("border-image:url(:/data/mail.png);border:0px;");

    m_pKylinManual_2 = new QLabel;
    m_pKylinManual_2->setFixedSize(56,20);
    m_pKylinManual_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pKylinManual_2->setText("帮助手册");
    m_pKylinManual_2->setAlignment(Qt::AlignLeft);
    m_pKylinManual_2->setAlignment(Qt::AlignVCenter);

    m_pKylinManual_3 = new QLabel;
    m_pKylinManual_3->setFixedSize(309,17);
    m_pKylinManual_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:12px;");
    m_pKylinManual_3->setText("用户通过查询桌面集成帮助手册，自助寻求支持与帮助。");
    m_pKylinManual_3->setAlignment(Qt::AlignLeft);
    m_pKylinManual_3->setAlignment(Qt::AlignVCenter);

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
    HmainLayout_PageTitle->setSpacing(0);
    HmainLayout_PageTitle->setMargin(0);
    HmainLayout_PageTitle->addSpacing(30);
    HmainLayout_PageTitle->addWidget(m_pPageTitle,1);

    HmainLayout_PageTitle->addStretch(99);

    QHBoxLayout *KylinOfficialWebLayout_I = new QHBoxLayout;
    KylinOfficialWebLayout_I->setMargin(0);
    KylinOfficialWebLayout_I->setSpacing(0);
    KylinOfficialWebLayout_I->addSpacing(0);
    KylinOfficialWebLayout_I->addWidget(m_pKylinOfficialWeb_1,1);
    KylinOfficialWebLayout_I->addSpacing(4);
    KylinOfficialWebLayout_I->addWidget(m_pKylinOfficialWeb_2,1);
    KylinOfficialWebLayout_I->addStretch(99);

    QVBoxLayout *KylinOfficialWebLayout_II = new QVBoxLayout;
    KylinOfficialWebLayout_II->setMargin(20);
    KylinOfficialWebLayout_II->setSpacing(0);
    KylinOfficialWebLayout_II->addSpacing(0);
    KylinOfficialWebLayout_II->addLayout(KylinOfficialWebLayout_I,1);
    KylinOfficialWebLayout_II->addSpacing(4);
    KylinOfficialWebLayout_II->addWidget(m_pKylinOfficialWeb_3,1);
    KylinOfficialWebLayout_II->addStretch(99);

    officialWeb->setLayout(KylinOfficialWebLayout_II);

    QHBoxLayout *kylinManualLayout_I = new QHBoxLayout;
    kylinManualLayout_I->setMargin(0);
    kylinManualLayout_I->setSpacing(0);
    kylinManualLayout_I->addSpacing(0);
    kylinManualLayout_I->addWidget(m_pKylinManual_1,1);
    kylinManualLayout_I->addSpacing(4);
    kylinManualLayout_I->addWidget(m_pKylinManual_2,1);
    kylinManualLayout_I->addStretch(99);

    QVBoxLayout *kylinManualLayout_II = new QVBoxLayout;
    kylinManualLayout_II->setMargin(20);
    kylinManualLayout_II->setSpacing(0);
    kylinManualLayout_II->addSpacing(0);
    kylinManualLayout_II->addLayout(kylinManualLayout_I,1);
    kylinManualLayout_II->addSpacing(4);
    kylinManualLayout_II->addWidget(m_pKylinManual_3,1);
    kylinManualLayout_II->addStretch(99);

    kylinManual->setLayout(kylinManualLayout_II);

    QHBoxLayout *HmainLayout = new QHBoxLayout;
    HmainLayout->setSpacing(0);
    HmainLayout->setMargin(0);
    HmainLayout->addSpacing(30);
    HmainLayout->addWidget(officialWeb);
    HmainLayout->addSpacing(20);
    HmainLayout->addWidget(kylinManual);
    HmainLayout->addStretch(99);

    QVBoxLayout *VmainLayout = new QVBoxLayout;
    VmainLayout->setSpacing(0);
    VmainLayout->setMargin(0);
    VmainLayout->addLayout(HmainLayout_KylinPic);
    VmainLayout->addSpacing(8);
    VmainLayout->addLayout(HmainLayout_MoreInfoLink);
    VmainLayout->addSpacing(20);
    VmainLayout->addLayout(HmainLayout_PageTitle);
    VmainLayout->addSpacing(10);
    VmainLayout->addLayout(HmainLayout);


    VmainLayout->addStretch(99);
    this->setLayout(VmainLayout);
}

void DIYSupportPage::on_officialWeb_clicked()
{
    qDebug() << "=============================================";
    QDesktopServices::openUrl(QUrl("https://www.ubuntukylin.com/qa/"));
}

void DIYSupportPage::on_kylinManual_clicked()
{
    qDebug() << "+++++++++++++++++++++++++++++++++++++++++++++";
    if (!mDaemonIpcDbus->daemonIsNotRunning()){
        //增加标题栏帮助菜单、F1快捷键打开用户手册
        mDaemonIpcDbus->showGuide("");
    }
}
