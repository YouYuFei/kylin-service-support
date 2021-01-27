/************************************************
* 文件描述: 联系我们页的类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "contact_page.h"
/************************************************
* 函数名称：ContactPage
* 功能描述：构造函数
* 输入参数：窗口各参数类
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
ContactPage::ContactPage(const WidgetParameterClass& basicParam)
    :contactPageBasicParameter(basicParam)
{

    m_pContactUs   = nullptr;

    m_pKylinTeam_1 = nullptr;
    m_pKylinTeam_2 = nullptr;
    m_pKylinTeam_3 = nullptr;

    m_pTel_1       = nullptr;
    m_pTel_2       = nullptr;
    m_pTel_3       = nullptr;

    m_pMail_1      = nullptr;
    m_pMail_2      = nullptr;
    m_pMail_3      = nullptr;

    m_pQRCode_1    = nullptr;
    m_pQRCode_2    = nullptr;

    body           = nullptr;

    this->setWindowTitle("contact_page");
    contactPageBasicParameter = basicParam;

    contactPageUIInit();
}
/************************************************
* 函数名称：pageChangeForTheme
* 功能描述：构造函数
* 输入参数：界面参数类
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void ContactPage::pageChangeForTheme(const QString& str)
{

    if("ukui-dark" == str || "ukui-black" == str)
    {
        QString bodyStyleSheet="QWidget #body{background-color:rgba(49, 50, 52, 1);}";
        body->setStyleSheet(bodyStyleSheet);
        m_pContactUs->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:16px;");
//        m_pKylinTeam_1->setStyleSheet("border-image:url(:/data/icon_team_d.png);border:0px;");
        m_pKylinTeam_2->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pKylinTeam_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
//        m_pTel_1->setStyleSheet("border-image:url(:/data/icon_contact_d.png);border:0px;");
        m_pTel_2->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pTel_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
//        m_pMail_1->setStyleSheet("border-image:url(:/data/mail_d.png);border:0px;");
        m_pMail_2->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pMail_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
        m_pQRCode_2->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
    }
    else
    {
        QString bodyStyleSheet="QWidget #body{background-color:rgba(246, 247, 247, 1);}";
        body->setStyleSheet(bodyStyleSheet);
        m_pContactUs->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:16px;");
//        m_pKylinTeam_1->setStyleSheet("border-image:url(:/data/icon_team.png);border:0px;");
        m_pKylinTeam_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pKylinTeam_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
//        m_pTel_1->setStyleSheet("border-image:url(:/data/icon_contact.png);border:0px;");
        m_pTel_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pTel_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
//        m_pMail_1->setStyleSheet("border-image:url(:/data/mail.png);border:0px;");
        m_pMail_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pMail_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
        m_pQRCode_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    }
}
/************************************************
* 函数名称：contactPageUIInit
* 功能描述：界面ui初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void ContactPage::contactPageUIInit()
{
    body = new QWidget(this);
    body->setFixedSize(720,268);
    body->setObjectName("body");


    m_pContactUs = new QLabel(this);
    //m_pContactUs->setFixedSize(64,22);
    m_pContactUs->adjustSize();
    m_pContactUs->setText(tr("Contact Us"));
//    m_pContactUs->setText("联系我们");
    m_pContactUs->setAlignment(Qt::AlignLeft);
    m_pContactUs->setAlignment(Qt::AlignVCenter);

    m_pKylinTeam_1 = new QLabel;
    m_pKylinTeam_1->setFixedSize(18,18);
    QIcon icon = QIcon::fromTheme("stock-people-symbolic");
    m_pKylinTeam_1->setProperty("useIconHighlightEffect", 0x8);
    m_pKylinTeam_1->setPixmap(icon.pixmap(QSize(18,18)));


    m_pKylinTeam_2 = new QLabel;
    m_pKylinTeam_2->adjustSize();//->setFixedSize(98,20);
    m_pKylinTeam_2->setText(tr("Support Team"));
//    m_pKylinTeam_2->setText("服务与支持团队");
    m_pKylinTeam_2->setAlignment(Qt::AlignLeft);
    m_pKylinTeam_2->setAlignment(Qt::AlignVCenter);

    m_pKylinTeam_3 = new QLabel;
    m_pKylinTeam_3->setFixedSize(148,20);
    m_pKylinTeam_3->setText(tr("KylinOS Support Team"));
    m_pKylinTeam_3->setAlignment(Qt::AlignLeft);
    m_pKylinTeam_3->setAlignment(Qt::AlignVCenter);

    m_pTel_1 = new QLabel;
    m_pTel_1->setFixedSize(18,18);
    QIcon icon1 = QIcon::fromTheme("call-stop-symbolic");
    m_pTel_1->setProperty("useIconHighlightEffect", 0x8);
    m_pTel_1->setPixmap(icon1.pixmap(QSize(18,18)));

    m_pTel_2 = new QLabel;
    m_pTel_2->adjustSize();//setFixedSize(28,20);
//    m_pTel_2->setText("电话");
    m_pTel_2->setText(tr("Tel"));
    m_pTel_2->setAlignment(Qt::AlignLeft);
    m_pTel_2->setAlignment(Qt::AlignVCenter);

    m_pTel_3 = new QLabel;
    m_pTel_3->setFixedSize(148,20);
    m_pTel_3->setText("400-089-1870");
    m_pTel_3->setAlignment(Qt::AlignLeft);
    m_pTel_3->setAlignment(Qt::AlignVCenter);

    m_pMail_1 = new QLabel;
    m_pMail_1->setFixedSize(18,18);
    QIcon icon2 = QIcon::fromTheme("mail-send-receive-symbolic");
    m_pMail_1->setProperty("useIconHighlightEffect", 0x8);
    m_pMail_1->setPixmap(icon2.pixmap(QSize(18,18)));

    m_pMail_2 = new QLabel;
    m_pMail_2->adjustSize();//setFixedSize(28,20);
    m_pMail_2->setText(tr("E-mail"));//"邮件");
    m_pMail_2->setAlignment(Qt::AlignLeft);
    m_pMail_2->setAlignment(Qt::AlignVCenter);

    m_pMail_3 = new QLabel;
    m_pMail_3->setFixedSize(148,20);
    m_pMail_3->setText("support@kylinos.cn");
    m_pMail_3->setAlignment(Qt::AlignLeft);
    m_pMail_3->setAlignment(Qt::AlignVCenter);

    m_pQRCode_1 = new QLabel;
    m_pQRCode_1->setFixedSize(118,118);
    m_pQRCode_1->setStyleSheet("border-image:url(:/data/qcpic.png);border:0px;");

    m_pQRCode_2 = new QLabel;
    m_pQRCode_2->adjustSize();//setFixedSize(154,20);
    m_pQRCode_2->setText(tr("Kylin WeChat Official Account"));//"公众号麒麟软件技术服务");
    m_pQRCode_2->setAlignment(Qt::AlignLeft);
    m_pQRCode_2->setAlignment(Qt::AlignVCenter);

    QHBoxLayout *HContactLayout_1 = new QHBoxLayout;
    HContactLayout_1->setMargin(0);
    HContactLayout_1->setSpacing(0);
    HContactLayout_1->addSpacing(30);
    HContactLayout_1->addWidget(m_pContactUs,1);
    //HContactLayout_1->addSpacing(694);
    HContactLayout_1->addStretch(99);

    QHBoxLayout *HTeamLayout_1 = new QHBoxLayout;
    HTeamLayout_1->setMargin(0);
    HTeamLayout_1->setSpacing(0);
    HTeamLayout_1->addSpacing(0);
    HTeamLayout_1->addWidget(m_pKylinTeam_1,1);
    HTeamLayout_1->addSpacing(4);
    HTeamLayout_1->addWidget(m_pKylinTeam_2,1);
    HTeamLayout_1->addSpacing(26);
    HTeamLayout_1->addStretch(99);

    QHBoxLayout *HTeleLayout_1 = new QHBoxLayout;
    HTeleLayout_1->setMargin(0);
    HTeleLayout_1->setSpacing(0);
    HTeleLayout_1->addSpacing(0);
    HTeleLayout_1->addWidget(m_pTel_1,1);
    HTeleLayout_1->addSpacing(4);
    HTeleLayout_1->addWidget(m_pTel_2,1);
    HTeleLayout_1->addSpacing(48);
    HTeleLayout_1->addStretch(99);

    QHBoxLayout *HMailLayout_1 = new QHBoxLayout;
    HMailLayout_1->setMargin(0);
    HMailLayout_1->setSpacing(0);
    HMailLayout_1->addSpacing(0);
    HMailLayout_1->addWidget(m_pMail_1,1);
    HMailLayout_1->addSpacing(4);
    HMailLayout_1->addWidget(m_pMail_2,1);
    HMailLayout_1->addSpacing(48);
    HMailLayout_1->addStretch(99);

    QVBoxLayout *VBoxLayout_1 = new QVBoxLayout;
    VBoxLayout_1->setMargin(0);
    VBoxLayout_1->setSpacing(0);
    VBoxLayout_1->addSpacing(50);
    VBoxLayout_1->addLayout(HTeamLayout_1,1);
    VBoxLayout_1->addSpacing(4);
    VBoxLayout_1->addWidget(m_pKylinTeam_3,1);
    VBoxLayout_1->addSpacing(20);
    VBoxLayout_1->addLayout(HTeleLayout_1,1);
    VBoxLayout_1->addSpacing(2);
    VBoxLayout_1->addWidget(m_pTel_3,1);
    VBoxLayout_1->addSpacing(20);
    VBoxLayout_1->addLayout(HMailLayout_1,1);
    VBoxLayout_1->addSpacing(2);
    VBoxLayout_1->addWidget(m_pMail_3,1);
    VBoxLayout_1->addSpacing(50);
    VBoxLayout_1->addStretch(99);

    QHBoxLayout *HQRLayout_1 = new QHBoxLayout;
    HQRLayout_1->setMargin(0);
    HQRLayout_1->setSpacing(0);
    HQRLayout_1->addSpacing(18);
    HQRLayout_1->addWidget(m_pQRCode_1,1);
    HQRLayout_1->addStretch(99);

    QHBoxLayout *HQRLayout_2 = new QHBoxLayout;
    HQRLayout_2->setMargin(0);
    HQRLayout_2->setSpacing(0);
    HQRLayout_2->addWidget(m_pQRCode_2,1);
    HQRLayout_2->addStretch(99);

    QVBoxLayout *VBoxLayout_2 = new QVBoxLayout;
    VBoxLayout_2->setMargin(0);
    VBoxLayout_2->setSpacing(0);
    VBoxLayout_2->addSpacing(60);
    VBoxLayout_2->addLayout(HQRLayout_1,1);
    VBoxLayout_2->addSpacing(10);
    VBoxLayout_2->addLayout(HQRLayout_2,1);
    VBoxLayout_2->addSpacing(60);
    VBoxLayout_2->addStretch(99);

    QHBoxLayout *HBoxLayout = new QHBoxLayout;
    HBoxLayout->setMargin(0);
    HBoxLayout->setSpacing(0);
    HBoxLayout->addSpacing(70);
    HBoxLayout->addLayout(VBoxLayout_1,1);
    HBoxLayout->addSpacing(278);
    HBoxLayout->addLayout(VBoxLayout_2,1);
    HBoxLayout->addSpacing(70);
    HBoxLayout->addStretch(99);

    body->setLayout(HBoxLayout);

    QHBoxLayout *HAllLayout = new QHBoxLayout;
    HAllLayout->setMargin(0);
    HAllLayout->setSpacing(0);
    HAllLayout->addSpacing(30);
    HAllLayout->addWidget(body,1);
    HAllLayout->addSpacing(30);
    HAllLayout->addStretch(99);


    QVBoxLayout *VAllLayout = new QVBoxLayout;
    VAllLayout->setMargin(0);
    VAllLayout->setSpacing(0);
    VAllLayout->addSpacing(0);
    VAllLayout->addLayout(HContactLayout_1,1);
    VAllLayout->addSpacing(8);
    VAllLayout->addLayout(HAllLayout,1);
//    VAllLayout->addSpacing(302);
    VAllLayout->addStretch(99);

    this->setLayout(VAllLayout);
}


