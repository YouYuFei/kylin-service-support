#include "contact_page.h"

ContactPage::ContactPage(WidgetParameterClass basicParam)
{
    this->setWindowTitle("contact_page");
    contactPageBasicParameter = basicParam;

    contactPageUIInit();
}

void ContactPage::contactPageUIInit()
{
    body = new QWidget(this);
    body->setFixedSize(720,268);
    body->setObjectName("body");

    QString bodyStyleSheet="QWidget #body{background-color:rgba(246, 247, 247, 1);}";
    body->setStyleSheet(bodyStyleSheet);

    m_pContactUs = new QLabel(this);
    m_pContactUs->setFixedSize(56,20);
    m_pContactUs->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;");
    m_pContactUs->setText("联系我们");
    m_pContactUs->setAlignment(Qt::AlignLeft);
    m_pContactUs->setAlignment(Qt::AlignVCenter);

    m_pKylinTeam_1 = new QLabel;
    m_pKylinTeam_1->setFixedSize(18,18);
    m_pKylinTeam_1->setStyleSheet("border-image:url(:/data/icon_team.png);border:0px;");

    m_pKylinTeam_2 = new QLabel;
    m_pKylinTeam_2->setFixedSize(98,20);
    m_pKylinTeam_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pKylinTeam_2->setText("服务与支持团队");
    m_pKylinTeam_2->setAlignment(Qt::AlignLeft);
    m_pKylinTeam_2->setAlignment(Qt::AlignVCenter);

    m_pKylinTeam_3 = new QLabel;
    m_pKylinTeam_3->setFixedSize(148,20);
    m_pKylinTeam_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
    m_pKylinTeam_3->setText("KylinOS Support Team");
    m_pKylinTeam_3->setAlignment(Qt::AlignLeft);
    m_pKylinTeam_3->setAlignment(Qt::AlignVCenter);

    m_pTel_1 = new QLabel;
    m_pTel_1->setFixedSize(18,18);
    m_pTel_1->setStyleSheet("border-image:url(:/data/icon_contact.png);border:0px;");

    m_pTel_2 = new QLabel;
    m_pTel_2->setFixedSize(28,20);
    m_pTel_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pTel_2->setText("电话");
    m_pTel_2->setAlignment(Qt::AlignLeft);
    m_pTel_2->setAlignment(Qt::AlignVCenter);

    m_pTel_3 = new QLabel;
    m_pTel_3->setFixedSize(148,20);
    m_pTel_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
    m_pTel_3->setText("400-089-1870");
    m_pTel_3->setAlignment(Qt::AlignLeft);
    m_pTel_3->setAlignment(Qt::AlignVCenter);

    m_pMail_1 = new QLabel;
    m_pMail_1->setFixedSize(18,18);
    m_pMail_1->setStyleSheet("border-image:url(:/data/mail.png);border:0px;");

    m_pMail_2 = new QLabel;
    m_pMail_2->setFixedSize(28,20);
    m_pMail_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pMail_2->setText("邮件");
    m_pMail_2->setAlignment(Qt::AlignLeft);
    m_pMail_2->setAlignment(Qt::AlignVCenter);

    m_pMail_3 = new QLabel;
    m_pMail_3->setFixedSize(148,20);
    m_pMail_3->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;");
    m_pMail_3->setText("support@kylinos.cn");
    m_pMail_3->setAlignment(Qt::AlignLeft);
    m_pMail_3->setAlignment(Qt::AlignVCenter);

    m_pQRCode_1 = new QLabel;
    m_pQRCode_1->setFixedSize(118,118);
    m_pQRCode_1->setStyleSheet("border-image:url(:/data/weixin.png);border:0px;");

    m_pQRCode_2 = new QLabel;
    m_pQRCode_2->setFixedSize(154,20);
    m_pQRCode_2->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
    m_pQRCode_2->setText("公众号麒麟软件技术服务");
    m_pQRCode_2->setAlignment(Qt::AlignLeft);
    m_pQRCode_2->setAlignment(Qt::AlignVCenter);

    QHBoxLayout *HContactLayout_1 = new QHBoxLayout;
    HContactLayout_1->setMargin(0);
    HContactLayout_1->setSpacing(0);
    HContactLayout_1->addSpacing(30);
    HContactLayout_1->addWidget(m_pContactUs,1);
    HContactLayout_1->addSpacing(694);
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


