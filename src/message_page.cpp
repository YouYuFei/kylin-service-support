/************************************************
* 文件描述: 留言页面类
* 待完善:   界面未完成
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "message_page.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QHttpPart>
#include <QSettings>
/************************************************
* 函数名称：MessagePage
* 功能描述：构造函数
* 输入参数：界面参数类
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
MessagePage::MessagePage(const WidgetParameterClass& basicParam)
    : mainPageBasicParameter(basicParam)
{
    this->setWindowTitle("message_page");

    messagePageUIInit();

    httpclientInit();

    submitting_timer = new QTimer();
    submitting_timer->setInterval(100);
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
void MessagePage::pageChangeForTheme(const QString& str)
{
    currentTheme = str;
    qDebug() << currentTheme;
    success_dialog->pageChangeForTheme(str);
    fail_dialog->pageChangeForTheme(str);

    if("ukui-dark" == str || "ukui-black" == str)
    {
        QString widgetStyleOfAskSheet="QWidget #StyleOfAsk{background-color:rgba(31, 32, 34, 1);border-radius:6px;}";
        m_pWidgetStyleOfAsk->setStyleSheet(widgetStyleOfAskSheet);
        m_pStyleOfAsk->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pStyleOfAskCombobox->setThemeDark();

        QString widgetTitleOfAskSheet="QWidget #TitleOfAsk{background-color:rgba(31, 32, 34, 1);border-radius:6px;}";
        m_pWidgetTitleOfAsk->setStyleSheet(widgetTitleOfAskSheet);
        m_pTitleOfAsk->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pContentTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;");
        m_pDetailTextLetterLimit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 14px;color: rgba(96, 98, 101, 1);"));
        QString widgetUserDataSheet="QWidget #UserData{background-color:rgba(31, 32, 34, 1);border-radius:6px;}";
        m_pWidgetUserData->setStyleSheet(widgetUserDataSheet);
        m_pUserData->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pUserDataPushButton->setStyleSheet("QPushButton#m_pUserDataPushButton{background-color:rgba(112, 149, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:hover{background-color:rgba(149, 176, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:pressed{background-color:rgba(73, 112, 222, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        QString widgetMailSheet="QWidget #WidgetMail{background-color:rgba(31, 32, 34, 1);border-radius:6px;}";
        m_pWidgetMail->setStyleSheet(widgetMailSheet);
        m_pMail->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;");
        QString widgetLogSheet="QWidget #WidgetLog{background-color:rgba(31, 32, 34, 1);border-radius:6px;}";
        m_pWidgetLog->setStyleSheet(widgetLogSheet);
        m_pLog->setStyleSheet("background-color:transparent;color:rgba(192, 196, 204, 1);font-size:14px;");
        m_pTrueSyslogCheckBox->setStyleSheet(QString::fromUtf8("font: 14px;color:rgba(143, 147, 153, 1);\n"));
        m_pFalseSyslogCheckBox->setStyleSheet(QString::fromUtf8("font: 14px;color:rgba(143, 147, 153, 1);\n"));
        QString widgetUserDataWidgetSheet="QWidget #UserData{background-color:rgba(31, 32, 34, 1);border-radius:6px;}";
        m_pWidgetUserDataWidget->setStyleSheet(widgetUserDataWidgetSheet);

        resetButton->setStyleSheet("QPushButton#resetButton{background:rgba(31, 32, 34, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-width:1px;border-color:rgba(96, 98, 101, 1);border-style: solid;border-radius:4px;}"
                                   "QPushButton#resetButton:hover{background:rgba(72, 72, 76, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-width:1px;border-color:rgba(96, 98, 101, 1);border-style: solid;border-radius:4px;}"
                                   "QPushButton#resetButton:pressed{background:rgba(72, 72, 76, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-width:1px;border-color:rgba(96, 98, 101, 1);border-style: solid;border-radius:4px;}");
        m_pUserPermission->setStyleSheet(QString::fromUtf8("font: 12px;color:rgba(96, 98, 101, 1);\n"
                                                  ""));
        showInfoButton->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 12px;color:rgba(112, 149, 255, 1)"));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(61, 61, 65, 1);\n"
                                                        "border-top-left-radius:4px;\n"
                                                        "\n"
                                                        "border-top-right-radius:4px;\n"
                                                        "\n"
                                                        "border-bottom-left-radius:4px;\n"
                                                        "\n"
                                                        "border-bottom-right-radius:4px;\n"
                                                        "border:0.5px solid black;\n"
                                                        ""));
        frameSysInfo->setStyleSheet("border-color: rgba(0, 0, 0, 0.16);");
        labelSystemVersion_1->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(249, 249, 249, 1);font:12px;"));
        labelDesktopVersion_1->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(249, 249, 249, 1);font:12px;"));
        labelLanguage_1->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(249, 249, 249, 1);font:12px;"));
        labelSystemVersion_2->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(249, 249, 249, 1);font:12px;"));
        labelDesktopVersion_2->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(249, 249, 249, 1);font:12px;"));
        labelLanguage_2->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(249, 249, 249, 1);font:12px;"));

    }
    else
    {
        QString widgetStyleOfAskSheet="QWidget #StyleOfAsk{background-color:rgba(255, 255, 255, 1);border-radius:6px;}";
        m_pWidgetStyleOfAsk->setStyleSheet(widgetStyleOfAskSheet);
        m_pStyleOfAsk->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");

        m_pStyleOfAskCombobox->setThemeLight();

        QString widgetTitleOfAskSheet="QWidget #TitleOfAsk{background-color:rgbargba(255, 255, 255, 1);border-radius:6px;}";
        m_pWidgetTitleOfAsk->setStyleSheet(widgetTitleOfAskSheet);
        m_pTitleOfAsk->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pContentTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;");
        m_pDetailTextLetterLimit->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 14px;color: rgba(192, 196, 204, 1);"));
        QString widgetUserDataSheet="QWidget #UserData{background-color:rgbargba(255, 255, 255, 1);border-radius:6px;}";
        m_pWidgetUserData->setStyleSheet(widgetUserDataSheet);
        m_pUserData->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pUserDataPushButton->setStyleSheet("QPushButton#m_pUserDataPushButton{background-color:rgba(112, 149, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:hover{background-color:rgba(149, 176, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:pressed{background-color:rgba(73, 112, 222, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        QString widgetMailSheet="QWidget #WidgetMail{background-color:rgba(255, 255, 255, 1);border-radius:6px;}";
        m_pWidgetMail->setStyleSheet(widgetMailSheet);
        m_pMail->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;");
        QString widgetLogSheet="QWidget #WidgetLog{background-color:rgba(255, 255, 255, 1);border-radius:6px;}";
        m_pWidgetLog->setStyleSheet(widgetLogSheet);
        m_pLog->setStyleSheet("background-color:transparent;color:rgba(48, 49, 51, 1);font-size:14px;");
        m_pTrueSyslogCheckBox->setStyleSheet(QString::fromUtf8("font: 14px;color:rgba(143, 147, 153, 1);\n"));
        m_pFalseSyslogCheckBox->setStyleSheet(QString::fromUtf8("font: 14px;color:rgba(143, 147, 153, 1);\n"));
        QString widgetUserDataWidgetSheet="QWidget #UserData{background-color:rgba(255, 255, 255, 1);border-radius:6px;}";
        m_pWidgetUserDataWidget->setStyleSheet(widgetUserDataWidgetSheet);

        resetButton->setStyleSheet("QPushButton#resetButton{background:rgba(221, 223, 231, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-width:1px;border-color:#DDDFE7;border-style: solid;border-radius:4px;}"
                                           "QPushButton#resetButton:hover{background:rgba(242, 246, 253, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-width:1px;border-color:#DDDFE7;border-style: solid;border-radius:4px;}"
                                           "QPushButton#resetButton:pressed{background:rgba(242, 246, 253, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-width:1px;border-color:#DDDFE7;border-style: solid;border-radius:4px;}");
        m_pUserPermission->setStyleSheet(QString::fromUtf8("font: 12px;color:rgba(96, 98, 101, 1);\n"
                                                  ""));
        showInfoButton->setStyleSheet(QString::fromUtf8("background-color:transparent;font: 12px;color:rgba(112, 149, 255, 1)"));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255);\n"
                                                        "border-top-left-radius:4px;\n"
                                                        "\n"
                                                        "border-top-right-radius:4px;\n"
                                                        "\n"
                                                        "border-bottom-left-radius:4px;\n"
                                                        "\n"
                                                        "border-bottom-right-radius:4px;\n"
                                                        "border:0.5px solid black;\n"
                                                        ""));
        frameSysInfo->setStyleSheet("border-color: rgba(0, 0, 0, 0.16);");
        labelSystemVersion_1->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(96, 98, 101, 1);font:12px;"));
        labelDesktopVersion_1->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(96, 98, 101, 1);font:12px;"));
        labelLanguage_1->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(96, 98, 101, 1);font:12px;"));
        labelSystemVersion_2->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(96, 98, 101, 1);font:12px;"));
        labelDesktopVersion_2->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(96, 98, 101, 1);font:12px;"));
        labelLanguage_2->setStyleSheet(QString::fromUtf8("border-color: transparent;color:rgba(96, 98, 101, 1);font:12px;"));

    }

}

/************************************************
* 函数名称：messagePageUIInit
* 功能描述：界面布局
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::messagePageUIInit()
{
    pageStyleOfAskRowLocationInit();
    pageContentOfAskRowLocationInit();
    pageMailRowLocationInit();
    pageSysLogRowLocationInit();
    pageUploadFilesRowLocationInit();
    pageUserDataRowLocationInit();

    pageAllRowLocationInit();
    getSysteminfo();
    on_resetButton_clicked();
}
/************************************************
* 函数名称：httpclientInit
* 功能描述：网络链接管理
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::httpclientInit()
{
    accessManager = new QNetworkAccessManager(this);
}
/************************************************
* 函数名称：pageStyleOfAskRowLocationInit
* 功能描述：咨询类别行初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageStyleOfAskRowLocationInit()
{
    //咨询类别一栏的底板widget宽度
    m_pWidgetStyleOfAsk = new QWidget;
    m_pWidgetStyleOfAsk->setFixedHeight(40);
    m_pWidgetStyleOfAsk->setObjectName("StyleOfAsk");



    m_pStyleOfAsk = new QLabel;
    m_pStyleOfAsk->adjustSize();//->setFixedSize(68,20);
    m_pStyleOfAsk->setText(tr("Question *"));//"咨询类别 *");
    m_pStyleOfAsk->setAlignment(Qt::AlignLeft);
    m_pStyleOfAsk->setAlignment(Qt::AlignVCenter);

    m_pStyleOfAskCombobox = new MyComboBox();
    m_pStyleOfAskCombobox->listWidget->installEventFilter(this);

    m_pStyleOfAskCombobox->addItem((tr("System")));//("系统问题")));
    m_pStyleOfAskCombobox->addItem((tr("Suggestion")));//("意见建议")));
    m_pStyleOfAskCombobox->addItem((tr("Bussiness")));//("商务合作")));
    m_pStyleOfAskCombobox->addItem((tr("Others")));//"其他")));
    connect(m_pStyleOfAskCombobox,SIGNAL(buttonTextChanged()),this,SLOT(styleOfAskCombobox_currentIndexChanged()));

    QHBoxLayout *HStyleOfAskLayout = new QHBoxLayout;
    HStyleOfAskLayout->setMargin(0);
    HStyleOfAskLayout->setSpacing(0);
    HStyleOfAskLayout->addSpacing(30);
    HStyleOfAskLayout->addWidget(m_pStyleOfAsk,1);
    HStyleOfAskLayout->addSpacing(18);
    HStyleOfAskLayout->addWidget(m_pStyleOfAskCombobox,1);

    HStyleOfAskLayout->addStretch(99);

    m_pWidgetStyleOfAsk->setLayout(HStyleOfAskLayout);

}
/************************************************
* 函数名称：pageContentOfAskRowLocationInit
* 功能描述：咨询内容行初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageContentOfAskRowLocationInit()
{
    //第二行widget高度调整
    m_pWidgetTitleOfAsk = new QWidget;
    m_pWidgetTitleOfAsk->setFixedHeight(180);
    m_pWidgetTitleOfAsk->setObjectName("TitleOfAsk");





    m_pTitleOfAsk = new QLabel;
    m_pTitleOfAsk->setFixedSize(68,20);
    m_pTitleOfAsk->setText(tr("Content *"));//"咨询内容 *");
    m_pTitleOfAsk->setAlignment(Qt::AlignLeft);
    m_pTitleOfAsk->setAlignment(Qt::AlignVCenter);

    m_pContentTextEdit = new QTextEdit(m_pTitleOfAsk);

    m_pContentTextEdit->setFixedSize(634,180);
    m_pContentTextEdit->setFrameShape(QFrame::NoFrame);
    m_pContentTextEdit->setAlignment(Qt::AlignVCenter);
    m_pContentTextEdit->setPlaceholderText(tr("* Please describe your problem, also can add attachments.\n* Now support format *.gif *.jpg *.png *.pptx *.wps *.xlsx *.pdf *.txt *.docx"));
    //tr("* 请详细描述要咨询的问题详情,必要可添加附件\n* 目前支持的格式仅有*.gif *.jpg *.png *.pptx *.wps *.xlsx *.pdf *.txt *.docx"));
    connect(m_pContentTextEdit,SIGNAL(textChanged()),this,SLOT(detailTextEdit_textChanged()));

    m_pDetailTextLetterLimit = new QLabel(m_pContentTextEdit);
    m_pDetailTextLetterLimit->setFixedSize(60,30);
    m_pDetailTextLetterLimit->setText("0/200");
    m_pDetailTextLetterLimit->setAlignment(Qt::AlignLeft);
    m_pDetailTextLetterLimit->setAlignment(Qt::AlignVCenter);

    QVBoxLayout *VStyleOfAskLayout = new QVBoxLayout;
    VStyleOfAskLayout->setMargin(0);
    VStyleOfAskLayout->setSpacing(0);
    VStyleOfAskLayout->addSpacing(12);
    VStyleOfAskLayout->addWidget(m_pTitleOfAsk);
    VStyleOfAskLayout->addStretch(99);

    QVBoxLayout *VQuestionLayout = new QVBoxLayout;
    VQuestionLayout->setMargin(0);
    VQuestionLayout->setSpacing(0);
    VQuestionLayout->addWidget(m_pContentTextEdit);
    VQuestionLayout->addStretch(99);

    QHBoxLayout *HStyleOfAskLayout = new QHBoxLayout;
    HStyleOfAskLayout->setMargin(0);
    HStyleOfAskLayout->setSpacing(0);
    HStyleOfAskLayout->addSpacing(30);
    HStyleOfAskLayout->addLayout(VStyleOfAskLayout);
    HStyleOfAskLayout->addSpacing(18);
    HStyleOfAskLayout->addLayout(VQuestionLayout);
    HStyleOfAskLayout->addStretch(99);

    m_pWidgetTitleOfAsk->setLayout(HStyleOfAskLayout);

}
/************************************************
* 函数名称：pageUploadFilesRowLocationInit
* 功能描述：上传文件行初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageUploadFilesRowLocationInit()
{
    //上传附件widget宽度
    m_pWidgetUserData = new QWidget;
    m_pWidgetUserData->setFixedHeight(30);
    m_pWidgetUserData->setObjectName("UserData");


    m_pUserData = new QLabel;
    m_pUserData->setFixedSize(56,20);
    m_pUserData->setText(tr("Upload"));//"上传附件");
    m_pUserData->setAlignment(Qt::AlignLeft);
    m_pUserData->setAlignment(Qt::AlignVCenter);

    m_pUserDataPushButton = new QPushButton(m_pWidgetUserData);
    m_pUserDataPushButton->setFixedSize(64,30);
    m_pUserDataPushButton->setObjectName("m_pUserDataPushButton");
    m_pUserDataPushButton->setText(tr("Browse"));//("浏览"));
    //m_pUserDataPushButton->setFlat(true);
    connect(m_pUserDataPushButton,SIGNAL(clicked()),this,SLOT(userDataPushButton_clicked()));

    m_pUserDataLimit = new QLabel(m_pWidgetUserData);
    m_pUserDataLimit->setFixedSize(560,30);
    m_pUserDataLimit->setText(tr("All attachmens size should smaller than 10mb,and numbers less than 5."));//("总附件大小不超过10mb，附件数量不超过5个"));

    QHBoxLayout *HStyleOfAskLayout = new QHBoxLayout;
    HStyleOfAskLayout->setMargin(0);
    HStyleOfAskLayout->setSpacing(0);
    HStyleOfAskLayout->addSpacing(30);
    HStyleOfAskLayout->addWidget(m_pUserData,1);
    HStyleOfAskLayout->addSpacing(30);
    HStyleOfAskLayout->addWidget(m_pUserDataLimit,1);
    HStyleOfAskLayout->addSpacing(10);
    HStyleOfAskLayout->addWidget(m_pUserDataPushButton,1);
    HStyleOfAskLayout->addStretch(99);

    m_pWidgetUserData->setLayout(HStyleOfAskLayout);
}
/************************************************
* 函数名称：pageMailRowLocationInit
* 功能描述：留邮箱行初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageMailRowLocationInit()
{
    //填写邮件的widget宽度
    m_pWidgetMail = new QWidget;
    m_pWidgetMail->setFixedHeight(61);
    m_pWidgetMail->setObjectName("WidgetMail");


    m_pMail = new QLabel;
    m_pMail->setFixedSize(40,20);
    m_pMail->setText(tr("Mail *"));//"邮件 *");
    m_pMail->setAlignment(Qt::AlignLeft);
    m_pMail->setAlignment(Qt::AlignVCenter);

    m_pMailTextEdit = new MyQTextEdit(m_pWidgetMail);
    m_pMailTextEdit->setFixedSize(634,40);
    m_pMailTextEdit->setPlaceholderText(tr("Leave your E-mail to get response."));//("KylinOS服务与支持团队将通过您预留的邮件反馈处理进度和结果"));
    connect(m_pMailTextEdit,SIGNAL(textChanged()),this,SLOT(mailTextEdit_textChanged()));
    connect(m_pMailTextEdit, SIGNAL(focusOut()), this, SLOT(mailTextEditFoucusOut()));
    connect(m_pMailTextEdit, SIGNAL(focusIn()), this, SLOT(mailTextEditFoucusIn()));

    m_pMailFormatErr = new QLabel;
    m_pMailFormatErr->setFixedSize(84,17);
    m_pMailFormatErr->setText(tr("Incorrect E-mail address."));//"邮箱格式不正确");
    m_pMailFormatErr->setStyleSheet(QString::fromUtf8("font: 12px;color: rgba(237, 100, 100, 1);"));
    m_pMailFormatErr->setAlignment(Qt::AlignLeft);
    m_pMailFormatErr->setAlignment(Qt::AlignVCenter);
    m_pMailFormatErr->hide();

    QHBoxLayout *HStyleOfAskLayout_I = new QHBoxLayout;
    HStyleOfAskLayout_I->setSpacing(0);
    HStyleOfAskLayout_I->setMargin(0);
    HStyleOfAskLayout_I->addSpacing(30);
    HStyleOfAskLayout_I->addWidget(m_pMail);
    HStyleOfAskLayout_I->addSpacing(46);
    HStyleOfAskLayout_I->addWidget(m_pMailTextEdit);
    HStyleOfAskLayout_I->addStretch(99);

    QHBoxLayout *HStyleOfAskLayout_II = new QHBoxLayout;
    HStyleOfAskLayout_II->setSpacing(0);
    HStyleOfAskLayout_II->setMargin(0);
    HStyleOfAskLayout_II->addSpacing(30);
    HStyleOfAskLayout_II->addSpacing(40);
    HStyleOfAskLayout_II->addSpacing(46);
    HStyleOfAskLayout_II->addSpacing(15);
    HStyleOfAskLayout_II->addWidget(m_pMailFormatErr);
    HStyleOfAskLayout_II->addStretch(99);

    QVBoxLayout *VStyleOfAskLayout = new QVBoxLayout;
    VStyleOfAskLayout->setSpacing(0);
    VStyleOfAskLayout->setMargin(0);
    VStyleOfAskLayout->addLayout(HStyleOfAskLayout_I);
    VStyleOfAskLayout->addSpacing(4);
    VStyleOfAskLayout->addLayout(HStyleOfAskLayout_II);
    VStyleOfAskLayout->addStretch(99);

    m_pWidgetMail->setLayout(VStyleOfAskLayout);
}
/************************************************
* 函数名称：pageSysLogRowLocationInit
* 功能描述：系统日志行初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageSysLogRowLocationInit()
{
    //上传日志行widget
    m_pWidgetLog = new QWidget;
    m_pWidgetLog->setFixedHeight(20);
    m_pWidgetLog->setObjectName("WidgetLog");


    m_pLog = new QLabel;
    m_pLog->adjustSize();//setFixedSize(56,20);
    m_pLog->setText(tr("Upload Log"));//"上传日志");
    m_pLog->setAlignment(Qt::AlignLeft);
    m_pLog->setAlignment(Qt::AlignVCenter);

    m_pTrueSyslogCheckBox = new QCheckBox(this);
    m_pTrueSyslogCheckBox->setText(tr("Yes"));//"是"));
    m_pTrueSyslogCheckBox->setChecked(true);
    m_pTrueSyslogCheckBox->setObjectName(QString::fromUtf8("checkBox"));
    connect(m_pTrueSyslogCheckBox,SIGNAL(stateChanged(int)),this,SLOT(trueSyslogCheckBox_stateChanged()));

    m_pFalseSyslogCheckBox = new QCheckBox(this);
    m_pFalseSyslogCheckBox->setText(tr("No"));//"否"));
    m_pFalseSyslogCheckBox->setObjectName(QString::fromUtf8("checkBox"));
    connect(m_pFalseSyslogCheckBox,SIGNAL(stateChanged(int)),this,SLOT(falseSyslogCheckBox_stateChanged()));

    QString locale = QLocale::system().name();

    QHBoxLayout *HStyleOfAskLayout = new QHBoxLayout;
    HStyleOfAskLayout->setMargin(0);
    HStyleOfAskLayout->setSpacing(0);
    HStyleOfAskLayout->addSpacing(30);
    HStyleOfAskLayout->addWidget(m_pLog);
    if (locale == "en_US")
    {
        HStyleOfAskLayout->addSpacing(20);
    }
    else if (locale == "zh_CN")
    {
        HStyleOfAskLayout->addSpacing(45);
    }

    HStyleOfAskLayout->addWidget(m_pTrueSyslogCheckBox);
    HStyleOfAskLayout->addSpacing(16);
    HStyleOfAskLayout->addWidget(m_pFalseSyslogCheckBox);

    HStyleOfAskLayout->addStretch(99);

    m_pWidgetLog->setLayout(HStyleOfAskLayout);


}

/************************************************
* 函数名称：pageUserDataRowLocationInit
* 功能描述：用户数据行初始化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageUserDataRowLocationInit()
{
    m_pWidgetUserDataWidget = new QWidget;

    m_pWidgetUserDataWidget->setObjectName("UserData");


    FileListWidget = new QListWidget(m_pWidgetUserDataWidget);
    FileListWidget->setFixedWidth(560);
    FileListWidget->setFixedHeight(21);

    FileListWidget->setAttribute(Qt::WA_TranslucentBackground);
    FileListWidget->setFrameShape(QListWidget::NoFrame);

    FileListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    FileListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    FileListWidget->setSelectionMode(QAbstractItemView::NoSelection);

    FileListWidget->hide();

    QHBoxLayout *HStyleOfAskLayout = new QHBoxLayout;
    HStyleOfAskLayout->setSpacing(0);
    HStyleOfAskLayout->setMargin(0);
    HStyleOfAskLayout->addSpacing(116);
    HStyleOfAskLayout->addWidget(FileListWidget);
    HStyleOfAskLayout->addStretch(99);

    m_pWidgetUserDataWidget->setLayout(HStyleOfAskLayout);

}
/************************************************
* 函数名称：pageAllRowLocationInit
* 功能描述：所有行垂直布局
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::pageAllRowLocationInit()
{
    success_dialog = new submit_success(this);

    fail_dialog = new submit_fail(this);


    commitButton = new QPushButton(this);
    commitButton->setFixedSize(64,30);
    commitButton->setObjectName("commitButton");
    commitButton->setText(tr("Commit"));//"提交"));
    connect(commitButton,SIGNAL(clicked()),this,SLOT(on_commitButton_clicked()));
    commitButtonClickable = false;

    resetButton = new QPushButton(this);
    resetButton->setFixedSize(64,30);
    resetButton->setObjectName("resetButton");
    resetButton->setText(tr("Reset"));//"重置"));
    resetButton->setEnabled(true);
    connect(resetButton,SIGNAL(clicked()),this,SLOT(on_resetButton_clicked()));

    m_pUserPermission = new QCheckBox(this);
    m_pUserPermission->setFixedSize(120,17);
    m_pUserPermission->setText(tr("Upload my "));//"同意获取我的"));
    m_pUserPermission->setObjectName(QString::fromUtf8("checkBox"));
    connect(m_pUserPermission,SIGNAL(stateChanged(int)),this,SLOT(userPermission_stateChanged(int)));
    //获取系统信息的小弹窗
    verticalWidget = new QWidget();
    verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
    verticalWidget->setWindowFlags(Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
    verticalWidget->setProperty("blurRegion", QRegion(QRect(1, 1, 1, 1)));
    verticalWidget->hide();

    //设置窗口透明
    //Set window transparency
    verticalWidget->setAttribute(Qt::WA_TranslucentBackground);
    frameSysInfo = new QFrame(verticalWidget);
    frameSysInfo->setObjectName(QString::fromUtf8("frameSysInfo"));
    frameSysInfo->setGeometry(QRect(0, 0, 157,87));
    frameSysInfo->setFrameShape(QFrame::StyledPanel);
    frameSysInfo->setFrameShadow(QFrame::Raised);

    effect = new QGraphicsDropShadowEffect;
    effect->setOffset(1,1);
    effect->setColor(QColor(80,80,80));
    effect->setBlurRadius(10);
    frameSysInfo->setGraphicsEffect(effect);

    showInfoButton = new systemInfoButton(this);
    showInfoButton->setText(tr("System Info"));//"系统信息"));
    showInfoButton->move(172,525);
    showInfoButton->setFeedBack(this);
    showInfoButton->setFlat(true);
    showInfoButton->setEnabled(false);


    labelSystemVersion_2 = new QLabel(frameSysInfo);
    labelSystemVersion_2->setObjectName(QString::fromUtf8("labelSystemVersion2"));
    labelSystemVersion_2->setGeometry(QRect(60, 10, 90, 20));
    labelDesktopVersion_2 = new QLabel(frameSysInfo);
    labelDesktopVersion_2->setObjectName(QString::fromUtf8("labelDesktopVersion2"));
    labelDesktopVersion_2->setGeometry(QRect(60, 31, 90, 20));
    labelLanguage_2 = new QLabel(frameSysInfo);
    labelLanguage_2->setObjectName(QString::fromUtf8("labelLanguage2"));
    labelLanguage_2->setGeometry(QRect(60, 52, 90, 20));

    labelSystemVersion_1 = new QLabel(frameSysInfo);
    labelSystemVersion_1->setObjectName(QString::fromUtf8("labelSystemVersion1"));
    labelSystemVersion_1->setText(tr("Os_rel"));
    labelSystemVersion_1->setGeometry(QRect(5, 10, 55, 20));
    labelDesktopVersion_1 = new QLabel(frameSysInfo);
    labelDesktopVersion_1->setObjectName(QString::fromUtf8("labelDesktopVersion1"));
    labelDesktopVersion_1->setText(tr("Deskenv"));
    labelDesktopVersion_1->setGeometry(QRect(5, 31, 55, 20));
    labelLanguage_1 = new QLabel(frameSysInfo);
    labelLanguage_1->setText(tr("Lang"));
    labelLanguage_1->setObjectName(QString::fromUtf8("labelLanguage1"));
    labelLanguage_1->setGeometry(QRect(5, 52, 55, 20));

    QVBoxLayout *VmainLayout = new QVBoxLayout;
    VmainLayout->setSpacing(0);
    VmainLayout->setMargin(0);
    VmainLayout->addWidget(m_pWidgetStyleOfAsk, 1);
    VmainLayout->addSpacing(12);
    VmainLayout->addWidget(m_pWidgetTitleOfAsk, 1);
    VmainLayout->addSpacing(12);
    VmainLayout->addWidget(m_pWidgetUserData, 1);
    VmainLayout->addSpacing(6);
    VmainLayout->addWidget(m_pWidgetUserDataWidget, 1);
    VmainLayout->addSpacing(6);
    VmainLayout->addWidget(m_pWidgetLog, 1);
    VmainLayout->addSpacing(12);
    VmainLayout->addWidget(m_pWidgetMail);

    VmainLayout->addStretch(99);

    m_pDetailTextLetterLimit->move(577,144);
    m_pUserPermission->move(105,531);
    resetButton->move(603,531);
    commitButton->move(687,531);
    this->setLayout(VmainLayout);
}
/************************************************
* 函数名称：styleOfAskCombobox_currentIndexChanged
* 功能描述：问题类别combobox值变化槽函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::styleOfAskCombobox_currentIndexChanged()
{
    qDebug() << m_pStyleOfAskCombobox->getCurrentText();

    textStyleOfAsk = m_pStyleOfAskCombobox->getCurrentText();
    qDebug() << textStyleOfAsk;

}
/************************************************
* 函数名称：detailTextEdit_textChanged
* 功能描述：问题详细描述文本框文字变化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::detailTextEdit_textChanged()
{
    if( "" == m_pContentTextEdit->toPlainText())
    {
        qDebug() << "titleText为空！";
        detailTextFlag = false;
        m_pDetailTextLetterLimit->setText("0/200");
    }
    else
    {
        detailTextFlag = true;
        detailText = m_pContentTextEdit->toPlainText();
        qDebug() << detailText;
        int length = detailText.count();
        int maxLength = 200;
        if (length > maxLength) {
            QTextCursor cursor = m_pContentTextEdit->textCursor();
            cursor.movePosition(QTextCursor::End);
            if (cursor.hasSelection()) {
                cursor.clearSelection();
            }
            cursor.deletePreviousChar();
            //设置当前的光标为更改后的光标
            //Set the current cursor to the changed cursor
            m_pContentTextEdit->setTextCursor(cursor);
        }
        length = m_pContentTextEdit->toPlainText().count();
        m_pDetailTextLetterLimit->setText(QString::number(length)+"/200");
    }
    if((false == allFileSizeLargerThan10M()) && detailTextFlag && mailFormatFlag)
    {
        commitButtonClickable = true;
    }
    else
    {
        commitButtonClickable = false;
    }
    commitButtonStyleSet();
}
/************************************************
* 函数名称：mailTextEdit_textChanged
* 功能描述：邮件地址文本框文字变化
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::mailTextEdit_textChanged()
{
    if("" == m_pMailTextEdit->toPlainText())// || (!m_pMailTextEdit->toPlainText().contains("@")))
    {
        qDebug() << "mailText为空！";
        m_pMailFormatErr->hide();
        mailFormatFlag = false;
        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;");
        }
        else
        {
            m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;");
        }
    }
    else if(false == mailFormatFlag)
    {
        mailText = m_pMailTextEdit->toPlainText();
        qDebug() << mailText;

        QRegExp rx("^[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+");
        int pos=0;
        QRegExpValidator v(rx, 0);
        if (2==v.validate(mailText,pos))
        {

            if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
            {
                m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;");
            }
            else
            {
                m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;");
            }
            m_pMailFormatErr->hide();
            mailFormatFlag = true;

        }
    }
    if((false == allFileSizeLargerThan10M()) && detailTextFlag && mailFormatFlag)
    {
        commitButtonClickable = true;
    }
    else
    {
        commitButtonClickable = false;
    }
    commitButtonStyleSet();
}
/************************************************
* 函数名称：trueSyslogCheckBox_stateChanged
* 功能描述：是否允许上传系统日志checkbox改变，是否互锁
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::trueSyslogCheckBox_stateChanged()
{
    if (m_pTrueSyslogCheckBox->isChecked() == true)
    {
        syslogFlag = 1;
        m_pTrueSyslogCheckBox->setChecked(true);
        m_pFalseSyslogCheckBox->setChecked(false);
    }
    else if (m_pTrueSyslogCheckBox->isChecked() == false)
    {
        syslogFlag = 0;
        m_pTrueSyslogCheckBox->setChecked(false);
        m_pFalseSyslogCheckBox->setChecked(true);
    }

    checkBox_stateCheck();
}
/************************************************
* 函数名称：falseSyslogCheckBox_stateChanged
* 功能描述：是否允许上传系统日志checkbox改变，是否互锁
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::falseSyslogCheckBox_stateChanged()
{
    if (m_pFalseSyslogCheckBox->isChecked() == true)
    {
        syslogFlag = 0;
        m_pTrueSyslogCheckBox->setChecked(false);
        m_pFalseSyslogCheckBox->setChecked(true);
    }
    else if (m_pTrueSyslogCheckBox->isChecked() == false)
    {
        syslogFlag = 1;
        m_pTrueSyslogCheckBox->setChecked(true);
        m_pFalseSyslogCheckBox->setChecked(false);
    }

    checkBox_stateCheck();
}
/************************************************
* 函数名称：userPermission_stateChanged
* 功能描述：用户是否允许上传本地信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::userPermission_stateChanged(int state)
{
    if (state == Qt::Checked)
    {
        get_systeminfoflag = 1;
    }
    else
    {
        get_systeminfoflag = 0;
    }
    return;
}
/************************************************
* 函数名称：allFileSizeLargerThan10M
* 功能描述：添加的文件总大小是否大于10M
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
bool MessagePage::allFileSizeLargerThan10M()
{
    int allFilesize = 0;
    QFileInfo fileInfo;
    for (int filenum = 0; filenum < uploadFilePathList.size(); filenum++) {
        fileInfo.setFile(uploadFilePathList.at(filenum));
        allFilesize += fileInfo.size();
    }
    if (syslogFlag == 1) {
        fileInfo.setFile("/var/log/dpkg.log");
        allFilesize += fileInfo.size();
        fileInfo.setFile("/var/log/apport.log");
        allFilesize += fileInfo.size();
        fileInfo.setFile("/var/log/syslog");
        allFilesize += fileInfo.size();
    }

    qDebug() << "所有文件大小" << allFilesize/(1024) << "KB";
    if (allFilesize >= 10*1024*1024)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/************************************************
* 函数名称：userDataPushButton_clicked
* 功能描述：添加的文件的按钮点击槽函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::userDataPushButton_clicked()
{
    QSettings settingPath("./Setting.ini", QSettings::IniFormat);
    QString lastPath = settingPath.value("LastFilePath").toString();

    userUploadFileName=QFileDialog::getOpenFileName(this,tr("select file"),lastPath,"(*.gif *.jpg *.png *.pptx *.wps *.xlsx *.pdf *.txt *.docx)",0);

    if (userUploadFileName.isEmpty())
        return;
    //判断文件个数， 最多传五个附件
    //Determine the number of documents and upload up to five attachments
    if(allFileSizeLargerThan10M())
    {
        qDebug() << "所有文件大小超过10M！";
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(245, 108, 108, 1);font-size:14px;}");
    }
    else
    {
        qDebug() << "所有文件大小不到10M！";
        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        }
        else
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        }
    }

    uploadFile_afterButtonClicked();
}
/************************************************
* 函数名称：addFileInfoModel
* 功能描述：添加的文件的列表函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::addFileInfoModel()
{
    qDebug() << "添加文件到上传列表！";

    if (userUploadFileName.isEmpty())
    {
        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        }
        else
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        }
        return;
    }

    int nIndex = userUploadFileName.lastIndexOf('/');
    QString file_name = userUploadFileName.mid(nIndex+1);
    QFileInfo info;
    QString file_size;
    info.setFile(userUploadFileName);

    file_size = QString::number((float)info.size()/(float)1024,'f',1) + "K";

    if((float)info.size()/(float)1000 > 1000)
        file_size = QString::number((float)info.size()/(float)1048576,'f',1) + "M";

    qDebug()<<"向stringlist 添加数据"<<uploadFileNameList.size()<<"--"<<uploadFileSizeList.size()<<"---"<<uploadFilePathList.size();

    for (int i = 0; i < uploadFileNameList.size(); i++)
    {
        FileListWidget->removeItemWidget(file_listwidget_item[i]);
        delete file_listwidget_item[i];
        file_listwidget_item[i] = nullptr;
        delete file_widget[i];
        file_widget[i] = nullptr;
    }
    if (uploadFileNameList.size() < 5)
    {
        uploadFileNameList.append(file_name);
        uploadFileSizeList.append(file_size);
        uploadFilePathList.append(userUploadFileName);
    }

    update_add_file_window();
}

/************************************************
* 函数名称：update_add_file_window
* 功能描述：添加删除文件后更新列表函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::update_add_file_window()
{
    if(allFileSizeLargerThan10M())
    {
        qDebug() << "所有文件大小超过10M！";
        commitButtonClickable = false;
    }
    else
    {
        qDebug() << "所有文件大小不到10M！";
        if(detailTextFlag && mailFormatFlag)
        {
            commitButtonClickable = true;
        }
        else
        {
            commitButtonClickable = false;
        }
    }

    if(uploadFileNameList.size() > 0)
    {
        FileListWidget->show();
    }
    else
    {
        FileListWidget->hide();
    }
    QString filename_labelstr;
    FileListWidget->setFixedHeight(21 * uploadFileNameList.size());
    for (int filenum = 0; filenum < uploadFileNameList.size(); filenum++) {
        file_listwidget_item[filenum] = new QListWidgetItem;
        //file_listwidget_item[filenum]->setSizeHint(QSize(320,20));
        file_listwidget_item[filenum]->setSizeHint(QSize(560,21));
        FileListWidget->addItem(file_listwidget_item[filenum]);
        file_widget[filenum] = new FileItemInit(FileListWidget);
        FileListWidget->setItemWidget(file_listwidget_item[filenum],file_widget[filenum]);
        filename_labelstr=uploadFileNameList.at(filenum);
        //如果文件过长，只显示前30个字符，后面省略
        //If the file is too long, show only the first 30 characters and omit the last
        if (uploadFileNameList.at(filenum).length() > 33) {
            filename_labelstr = uploadFileNameList.at(filenum).left(30) + "...";
        }

        file_widget[filenum]->filename_label0->setText(filename_labelstr);
        file_widget[filenum]->filename_label0->setStyleSheet("font: 12px ;");
        file_widget[filenum]->filename_label0->adjustSize();
        file_widget[filenum]->filename_label0->setAlignment(Qt::AlignHCenter);

        int filename_width = file_widget[filenum]->filename_label0->geometry().width();

        file_widget[filenum]->filesize_label0->setText(uploadFileSizeList.at(filenum));
        file_widget[filenum]->filesize_label0->setStyleSheet("font: 12px ;");
        file_widget[filenum]->filesize_label0->adjustSize();
        file_widget[filenum]->filesize_label0->setAlignment(Qt::AlignHCenter);

        //int filesize_width = file_widget[filenum]->filesize_label0->geometry().width();

        file_widget[filenum]->deletebtn0->setText(tr("Del"));
        file_widget[filenum]->deletebtn0->setFixedSize(36,21);
        file_widget[filenum]->deletebtn0->setStyleSheet("font:12px;");

        file_widget[filenum]->deletebtn0->setFlat(true);


        file_widget[filenum]->filename_label0->move(16,0);
        file_widget[filenum]->filesize_label0->move(filename_width+26,0);
        file_widget[filenum]->deletebtn0->move(500,0);

        connect( file_widget[filenum]->deletebtn0, SIGNAL(clicked()), this, SLOT(del_file_button_clicked()) );
    }
}

/************************************************
* 函数名称：del_file_button_clicked
* 功能描述：删除文件按钮点击槽函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::del_file_button_clicked()
{
    //返回发送信号的对象的指针
    //Returns a pointer to the object that sent the signal.
    QPushButton *btn = qobject_cast<QPushButton*>(QObject::sender());

    qDebug()<<uploadFileNameList.size()<<"before";

    int listnum = uploadFileNameList.size();

    removeUploadFileNameListFile(btn);


    qDebug()<<uploadFileNameList.size()<<"-----after";
    foreach (auto item,uploadFileNameList)
        qDebug()<<item<<"after";
    for (int i=0; i<listnum; i++) {
        delete file_listwidget_item[i];
        delete file_widget[i];
    }

    update_add_file_window();
    //删除文件后 把上传附件中内容更新
    //After deleting the file, update the contents of the uploaded attachment.
    update_linedit_add_or_del_file();

    //再次判断大小是否超过10M,如果不超过并且详细描述和邮箱都填写  激活提交
    /*
     Once again, determine if the size exceeds 10M, if not,
     and fill in the detailed description and
     email address to activate the submission.
    */
    if ((false == allFileSizeLargerThan10M()) && detailTextFlag && mailFormatFlag )
    {
        commitButtonClickable = true;
    }
    else
    {
        commitButtonClickable = false;
    }
    commitButtonStyleSet();
}
/************************************************
* 函数名称：update_linedit_add_or_del_file
* 功能描述：
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::update_linedit_add_or_del_file()
{
    int rowNum = uploadFileNameList.size();
    if (rowNum == 0) {
    } else {
    }
}

/************************************************
* 函数名称：on_resetButton_clicked
* 功能描述：重置按钮点击槽函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::on_resetButton_clicked()
{
    m_pStyleOfAskCombobox->setCurrentText(tr("System"));
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pStyleOfAskCombobox->setThemeDark();
    }
    else
    {
        m_pStyleOfAskCombobox->setThemeLight();
    }
    m_pContentTextEdit->clear();
    m_pMailTextEdit->clear();
    syslogFlag = 1;
    m_pTrueSyslogCheckBox->setChecked(true);
    m_pFalseSyslogCheckBox->setChecked(false);
    m_pUserPermission->setChecked(false);
    //清空list
    for (int i = 0; i < uploadFileNameList.size(); i++) {
        delete file_listwidget_item[i];
        delete file_widget[i];
    }
    foreach (auto item, uploadFileNameList) {
        uploadFileNameList.removeOne(item);
    }
    foreach (auto item,uploadFileSizeList) {
        uploadFileSizeList.removeOne(item);
    }
    foreach(auto item,uploadFilePathList) {
        uploadFilePathList.removeOne(item);
    }
    //隐藏页面上的附件列表
    FileListWidget->hide();
}
/************************************************
* 函数名称：on_commitButton_clicked
* 功能描述：提交按钮点击槽函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::on_commitButton_clicked()
{
    if(false == commitButtonClickable)
    {
        return;
    }
    //判断邮箱格式
    //Determining Email Format
    QRegExp rx("^[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+");
    int pos=0;
    QRegExpValidator v(rx, 0);
    if (2==v.validate(mailText,pos))
    {
        m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;");
        m_pMailFormatErr->hide();
        mailFormatFlag = true;
    }
    else {
        m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border:1px solid:rgba(245, 108, 108, 1);border-radius:4px");
        mailFormatFlag = false;
        m_pMailFormatErr->show();
    }

    //判断文件总大小是否超过10M，如果超过，提示
    //Determine if the total file size exceeds 10M, if so, prompt
    if (allFileSizeLargerThan10M() == true)
    {
        qDebug() << "所有文件大小超过10M！";
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(245, 108, 108, 1);font-size:14px;}");

        commitButtonClickable = false;
        return;
    }

    commitButtonClickable = false;

    qDebug()<<"submitting_timer->start();";
    submitting_timer->start();

    set_all_disable_in_submit();

    //超时
    //timeout
    QTimer timer_http;
    timer_http.setInterval(30000);  // 设置超时时间 30 秒
    timer_http.setSingleShot(true);  // 单次触发

    QJsonObject feedback_info_json;
    qDebug() << textStyleOfAsk;
    feedback_info_json.insert("subject",textStyleOfAsk);

    feedback_info_json.insert("description",detailText);

    feedback_info_json.insert("email",mailText);

    if (get_systeminfoflag) {
        feedback_info_json.insert("version",send_os_info);
        feedback_info_json.insert("desktop",send_dekstop_info);
        feedback_info_json.insert("language",send_encoding_info);
    } else {
        feedback_info_json.insert("version","");
        feedback_info_json.insert("desktop","");
        feedback_info_json.insert("language","");
    }
    QString url_filepath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +"/.config/ukui/url.conf";
    qDebug () << "url_filepath-->" << url_filepath;
    //从配置文件中读服务器地址
    //Read the server address from the configuration file
    QFile  file_url(url_filepath);
    QFileInfo url_fileinfo(url_filepath);
    if (!url_fileinfo.isFile()) {
        file_url.open(QIODevice::ReadWrite | QIODevice::Text);
        file_url.write("http://feedback.ubuntukylin.com/v1/issue/");
        urlstring.append("http://feedback.ubuntukylin.com/v1/issue/");
    } else {
        file_url.open(QIODevice::ReadWrite | QIODevice::Text);
        urlstring = file_url.readLine();
    }
    file_url.close();
    set_request_header();
    request.setUrl(QUrl(urlstring));
    qDebug()<<"url:"<<urlstring;
    QJsonDocument json_doc;
    json_doc.setObject(feedback_info_json);
    QByteArray post_feedback_info_array = json_doc.toJson(QJsonDocument::Compact);
    qDebug()<<post_feedback_info_array;
    QNetworkReply *pReply = accessManager->post(request,post_feedback_info_array);

    QEventLoop loop;
    connect(&timer_http, &QTimer::timeout, &loop, &QEventLoop::quit);
    connect(pReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    timer_http.start();
    loop.exec();

    if (timer_http.isActive()) {
//        if (window_is_close_flag == false) {
            timer_http.stop();
            finishedSlot(pReply);
//        }
    } else {
//        if (window_is_close_flag ==false) {
            timeout_http_flag=true;
            finishedSlot(pReply);
            timer_http.stop();
            disconnect(pReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
            pReply->abort();
            pReply->deleteLater();
            qDebug() << "Timeout";
//        }
    }
}
/************************************************
* 函数名称：finishedSlot
* 功能描述：http请求完成后动作
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::finishedSlot(QNetworkReply *reply)
{
    //定时器结束
    //Timer ends.
    submitting_timer->stop();
    commitButton->setText(tr("Submit"));//"提交"));
    commitButtonClickable = false;

    commitButtonStyleSet();
    commitButton->setIcon(QIcon());



    qDebug() << "this is send feedbackinfo finished";

    // 获取http状态码
    //Get http status code
    statusCode_info = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (statusCode_info.isValid())
        qDebug() << "status code info =" << statusCode_info.toInt();
    if (statusCode_info.toInt() == 201) {
        reason_info = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        if (reason_info.isValid())
            qDebug() << "reason info =" << reason_info.toString();
        bytes_info = reply->readAll();
        //panduan ==200
        qDebug() << bytes_info;


        success_dialog->setModal(false);


        QTimer::singleShot(3000, [=](){

            set_all_enable_after_submit();
            on_resetButton_clicked();
        });
        //解析JSON 获取uid annex_uid
        //Parsing JSON to get uid annex_uid
        QString uid_value;
        QJsonParseError jsonerror;
        QJsonDocument document = QJsonDocument::fromJson(bytes_info,&jsonerror);
        qDebug()<<"this is send file _httpserver";

        if (!document.isNull() && (jsonerror.error == QJsonParseError::NoError)) {
            if (document.isObject()) {
                QJsonObject object = document.object();
                uid_value = object["uid"].toString();
            }
        }

        send_file_httpserver(uid_value);
    } else {
        qDebug() << "finishedSlot errors here";
        qDebug( "found error .... code: %d\n", (int)reply->error());
        qDebug()<<qPrintable(reply->errorString());
        //打印错误类型信息，QWarning信息，会记录在log中
        if(!timeout_http_flag)
            fail_dialog->show_faillinfo((int)reply->error());
        else
            fail_dialog->show_faillinfo(4); //timeout
        fail_dialog->setModal(false);

        //fail_dialog->show();
        QTimer::singleShot(3000, [=](){

            set_all_enable_after_submit();
        });
    }
    timeout_http_flag=false;
    reply->deleteLater();
}

/************************************************
* 函数名称：get_today_syslog
* 功能描述：截取今天的syslog
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
QByteArray MessagePage::get_today_syslog()
{
    QDate date(QDate::currentDate());
    QList<QString> month_str = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    QProcess process;
    QString shell ;
    shell.append("cat /var/log/syslog | grep ");
    shell.append("'");
    shell.append(month_str.at(date.month()-1));
    shell.append(" ");
    shell.append(QString::number(date.day()));
    shell.append("'");

    qDebug()<<"shell=========" <<shell;
    process.start(shell);
    process.waitForFinished();
    QByteArray output = process.readAllStandardOutput();

    return output;
}
/************************************************
* 函数名称：add_file_to_Part
* 功能描述：上传文件到服务器
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::add_file_to_Part(QString filepath,QString file_type,QString file_name)
{
    qDebug()<<"this is add_file_to_Part";
    QHttpPart upload_part;
    upload_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data; name=\"%1\";filename=\"%2\"").arg(file_type).arg(file_name)));
    QFile *upload_file =  new QFile(filepath);
    if (!(upload_file->open(QIODevice::ReadOnly))) {
        qDebug()<<"file open fail";
    }
    if (file_name.compare("syslog") == 0) {
        upload_part.setBody(get_today_syslog());
    } else {
        upload_part.setBody(upload_file->readAll());
    }

    multiPart->append(upload_part);
    delete upload_file;
    return ;
}
/************************************************
* 函数名称：send_file_httpserver
* 功能描述：上传文件到服务器
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::send_file_httpserver(QString uid)
{
    file_send_failed_flag = false;
    qDebug()<<"this is send file httpserver";
    qDebug()<<"uid:"<<uid;
    //初始化http发送文件请求
    //Initialize HTTP file sending request
    accessManager_file = new QNetworkAccessManager(this);
    connect(accessManager_file, SIGNAL(finished(QNetworkReply*)), this, SLOT(sendfile_finished(QNetworkReply* )));

    request_file.setHeader(QNetworkRequest::ContentTypeHeader,"multipart/form-data");
    QString urlstring_file =   urlstring + "annex/";
    request_file.setUrl(QUrl(urlstring_file));

    qDebug()<<urlstring_file<<"---";
    multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QString bd = "X-INSOMNIA-BOUNDARY";
    multiPart->setBoundary(bd.toLatin1());
    request_file.setHeader(QNetworkRequest::ContentTypeHeader,"multipart/form-data;boundary="+bd);

    //把发送反馈信息服务器返回的uid 加入此次发送中
    //Add the UID returned by the sending feedback server to this send
    QHttpPart uid_part;

    uid_part.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"issue_uid\""));
    uid_part.setBody(uid.toUtf8());
    multiPart->append(uid_part);


    //判断三个log文件哪个点选了
    //Determine which of the three LOG files is clicked.
    if(syslogFlag)
    {
        //var/log/dpkg.log
        add_file_to_Part("/var/log/dpkg.log","dpkg","dpkg.log");

        //var/log/apport.log
        add_file_to_Part("/var/log/apport.log","apport","apport.log");

        //var/log/syslog.log
        add_file_to_Part("/var/log/syslog","syslog","syslog");

        //var/log/lightdm/lightdm.log
        add_file_to_Part("/var/log/lightdm/lightdm.log","lightdm","lightdm.log");

        //var/log/Xorg.0.log
        add_file_to_Part("/var/log/Xorg.0.log","Xorg","Xorg.0.log");
    }

    //获取添加的附件，文件名
    //Get the added attachment, file name
    for (int filenum=0; filenum<uploadFilePathList.size(); filenum++) {
        add_file_to_Part(uploadFilePathList.at(filenum),"img"+QString::number(filenum+1),uploadFileNameList.at(filenum));
    }
    accessManager_file->post(request_file,multiPart);
}

/************************************************
* 函数名称：发送文件请求结束槽函数
* 功能描述：sendfile_finished
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::sendfile_finished(QNetworkReply* reply)
{
    file_send_failed_flag = true;
    qDebug()<<"this is send file finished";

    statusCode_file = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (statusCode_file.isValid())
        qDebug() << "status code file =" << statusCode_file.toInt();

    reason_file = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
    if (reason_file.isValid())
        qDebug() << "reason file =" << reason_file.toString();

    bytes_file = reply->readAll();
    qDebug() << bytes_file;

    if (window_is_close_flag)
        this->close();
}

/************************************************
* 函数名称：systeminfo_show
* 功能描述：显示本机系统信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::systeminfo_show(QPointF pt)
{
    //verticalWidget->setGeometry(pt.x(),pt.y(),220,80);
    verticalWidget->setFixedSize(157,87);

    verticalWidget->move(pt.x() - 10 ,pt.y() - 100);
    verticalWidget->show();
}

/************************************************
* 函数名称：systeminfo_hide
* 功能描述：隐藏本机系统信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::systeminfo_hide()
{
    verticalWidget->hide();
}

/************************************************
* 函数名称：getSysteminfo
* 功能描述：获取本机系统信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::getSysteminfo()
{
    //获取系统信息
    //Access to system information
    //1.获取系统版本
    //Get the system version
    getSysVersion();
    //2.获取桌面环境信息
    //Access to desktop environment information
    getDesktopInfo();
    //3.获取编码格式
    //Get the coding format
    getCodingFormat();
}

/************************************************
* 函数名称：set_all_disable_in_submit
* 功能描述：提交过程中禁止操作
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::set_all_disable_in_submit()
{
    m_pContentTextEdit->setEnabled(false);
    m_pMailTextEdit->setEnabled(false);
    m_pTrueSyslogCheckBox->setEnabled(false);
    m_pFalseSyslogCheckBox->setEnabled(false);
    m_pUserPermission->setEnabled(false);
    resetButton->setEnabled(false);
    m_pUserDataPushButton->setEnabled(false);
    commitButtonClickable = false;
    commitButtonStyleSet();

    for (int filenum = 0; filenum < uploadFileNameList.size(); filenum++)
        file_widget[filenum]->deletebtn0->setEnabled(false);
}

/************************************************
* 函数名称：set_all_enable_after_submitt
* 功能描述：提交完成后功能还原
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::set_all_enable_after_submit()
{
    m_pContentTextEdit->setEnabled(true);
    m_pMailTextEdit->setEnabled(true);
    m_pTrueSyslogCheckBox->setEnabled(true);
    m_pFalseSyslogCheckBox->setEnabled(true);
    m_pUserPermission->setEnabled(true);

    m_pUserDataPushButton->setEnabled(true);
    resetButton->setEnabled(true);


    commitButtonClickable = true;
    commitButtonStyleSet();

    for (int filenum = 0; filenum< uploadFileNameList.size();filenum++)
    {
        file_widget[filenum]->deletebtn0->setEnabled(true);
    }
}
/************************************************
* 函数名称：set_request_header
* 功能描述：设置http报头
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::set_request_header()
{
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}


/************************************************
* 函数名称：resend_info_when_sendfail
* 功能描述：该函数暂时注释
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::resend_info_when_sendfail()
{
//    this->on_pushButton_2_clicked();
}
/************************************************
* 函数名称：checkBox_stateCheck
* 功能描述：checkbox勾选后文件状态检查
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::checkBox_stateCheck()
{
    qDebug() << syslogFlag;
    if(allFileSizeLargerThan10M())
    {
        qDebug() << "所有文件大小超过10M！";
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(245, 108, 108, 1);font-size:14px;}");

    }
    else
    {
        qDebug() << "所有文件大小不到10M！";
        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        }
        else
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        }
    }
    if((false == allFileSizeLargerThan10M()) && detailTextFlag && mailFormatFlag )
    {
        commitButtonClickable = true;
    }
    else
    {
        commitButtonClickable = false;
    }
    commitButtonStyleSet();
}

/************************************************
* 函数名称：uploadFile_afterButtonClicked
* 功能描述：提交按钮点击后，根据文件数量进行对应动作
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::uploadFile_afterButtonClicked()
{
    if (uploadFileNameList.size() ==0)
    {
        qDebug() << "所有文件数量不到5个！";

        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        }
        else
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        }

        addFileInfoModel();
    }
    else if(uploadFileNameList.size() >= 5)
    {
        qDebug() << "所有文件数量超过5个！";

        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(245, 108, 108, 1);font-size:14px;}");
        return ;
    }
    else
    {
        qDebug() << "所有文件数量不到5个！";
        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        }
        else
        {
            m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        }
        int file_diff_flags = 0;
        for (int fileNum = 0; fileNum < uploadFilePathList.size(); fileNum++) {
            //添加的文件已经添加过
            //Added files have been added.
            if (userUploadFileName.compare(uploadFilePathList.at(fileNum)) == 0)
                file_diff_flags++;
        }
        if (file_diff_flags == 0) {
            //添加附件框改变
            //Add attachment box changes
            addFileInfoModel();
        }
        if(uploadFileNameList.size()>=5)
        {
            m_pUserDataPushButton->setEnabled(false);
            m_pUserDataPushButton->setStyleSheet("QPushButton#resetButton{background:rgba(192, 196, 204, 1);font-size:14px;color:rgba(143, 147, 153, 1);border-radius:4px;}");
        }
    }
}

/************************************************
* 函数名称：removeUploadFileNameListFile
* 功能描述：点击listwidget中的del按钮，删除对应项
* 输入参数：QPushButton* btn 按钮指针
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::removeUploadFileNameListFile(QPushButton* btn)
{
    if ( btn == file_widget[0]->deletebtn0 ) {
        qDebug()<<uploadFileNameList.size()<<"delete before";
        uploadFileNameList.removeAt(0);
        uploadFileSizeList.removeAt(0);
        uploadFilePathList.removeAt(0);
        qDebug()<<uploadFileNameList.size()<<"delete after";
        qDebug() << "delete 0";
        m_pUserDataPushButton->setEnabled(true);
    } else if( btn == file_widget[1]->deletebtn0 ) {
        uploadFileNameList.removeAt(1);
        uploadFileSizeList.removeAt(1);
        uploadFilePathList.removeAt(1);
        m_pUserDataPushButton->setEnabled(true);
        qDebug() << "delete 1";
    } else if( btn == file_widget[2]->deletebtn0 ) {
        uploadFileNameList.removeAt(2);
        uploadFileSizeList.removeAt(2);
        uploadFilePathList.removeAt(2);
        m_pUserDataPushButton->setEnabled(true);
        qDebug() << "delete 2";
    } else if( btn == file_widget[3]->deletebtn0 ) {
        uploadFileNameList.removeAt(3);
        uploadFileSizeList.removeAt(3);
        uploadFilePathList.removeAt(3);
        m_pUserDataPushButton->setEnabled(true);
        qDebug() << "delete 3";
    } else if( btn == file_widget[4]->deletebtn0) {
        uploadFileNameList.removeAt(4);
        uploadFileSizeList.removeAt(4);
        uploadFilePathList.removeAt(4);
        m_pUserDataPushButton->setEnabled(true);
        qDebug() << "delete 4";
    }
    else
    {
        qDebug() << "函数异常错误！";
        return;
    }

    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(143, 147, 153, 1);font-size:14px;}");
        m_pUserDataPushButton->setStyleSheet("QPushButton#m_pUserDataPushButton{background-color:rgba(112, 149, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:hover{background-color:rgba(149, 176, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:pressed{background-color:rgba(73, 112, 222, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
    }
    else
    {
        m_pUserDataLimit->setStyleSheet("background-color:transparent;color:rgba(96, 98, 101, 1);font-size:14px;}");
        m_pUserDataPushButton->setStyleSheet("QPushButton#m_pUserDataPushButton{background-color:rgba(112, 149, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:hover{background-color:rgba(149, 176, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                             "QPushButton#m_pUserDataPushButton:pressed{background-color:rgba(73, 112, 222, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
    }
}

/************************************************
* 函数名称：getCodingFormat
* 功能描述：获取系统信息的语言格式信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::getCodingFormat()
{
    string encoding_info = ": ";
    char *encoding = getenv("LANG");
    char *emcoding_2;
    emcoding_2 = (char *)malloc(8);
    if(NULL == emcoding_2)
    {
        qDebug() << "emcoding_2申请内存失败！";
        return;
    }
    if (encoding == NULL) {
        QString locale = QLocale::system().name();
        if (locale == "en_US")
        {
            strcpy(emcoding_2, "en_US");
        }
        else if (locale == "zh_CN")
        {
            strcpy(emcoding_2, "zh_CN");
        }
        else if (locale == "bo_CN")
        {
            strcpy(emcoding_2, "bo_CN");
        }
        encoding = emcoding_2;
    }
    qDebug() << "encoding" << encoding;
    encoding_info.append(encoding);
    send_encoding_info.append(encoding);
    encoding_info_str = QString::fromStdString(encoding_info);
    if(encoding_info_str.contains(".")){
        QStringList list = encoding_info_str.split(".");
        labelLanguage_2->setText(list.at(0));

        if(send_encoding_info.contains(".")){
            QStringList list2 = send_encoding_info.split(".");
            send_encoding_info.clear();
            send_encoding_info.append(list2.at(0));
        }

    }
    else
    {
        labelLanguage_2->setText(encoding_info_str);
    }
    if(emcoding_2 != NULL)
    {
        free(emcoding_2);
    }
}

/************************************************
* 函数名称：getSysVersion
* 功能描述：获取系统版本信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::getSysVersion()
{
    string os_info = ": ";
    string system_info;
    string system_name;
    string system_version_id;
    string s;
    ifstream fp("/etc/os-release");
    if (!fp) {
        system_info = "None";
    } else {
        while (getline(fp,s)) {
            string::size_type idx;
            idx = s.find("=");
            if (idx == string::npos) {
                //不存在
            } else {
                string str2 = s.substr(0,idx);
                if (str2 == "NAME") {
                    system_name = s.substr(5);
                } else if(str2 =="VERSION_ID") {
                    system_version_id = s.substr(11);
                }
            }
        }
        system_info = os_info +system_name +" " + system_version_id;
    }
    send_os_info = QString::fromStdString(system_name +" " + system_version_id);
    system_info_str = QString::fromStdString(system_info);
    system_info_str.remove(QChar('"'), Qt::CaseInsensitive);
    labelSystemVersion_2->setText(system_info_str);
}

/************************************************
* 函数名称：getDesktopInfo
* 功能描述：获取桌面版本信息
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::getDesktopInfo()
{
    string desktop_info = ": ";
    char * desktop = getenv("DESKTOP_SESSION");
    desktop_info.append(desktop);
    send_dekstop_info.append(desktop);
    desktop_info_str = QString::fromStdString(desktop_info);
    labelDesktopVersion_2->setText(desktop_info_str);
}
/************************************************
* 函数名称：event
* 功能描述：事件过滤，下拉框自动收回
* 输入参数：QEvent *event
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
bool MessagePage::event(QEvent *event)
{
    if(m_pStyleOfAskCombobox == nullptr)
    {
        return QWidget::event(event);
    }
    if(m_pStyleOfAskCombobox->listWidget == nullptr)
    {
        return QWidget::event(event);
    }

    if (event->type() == QEvent::Leave)
    {
        if(mouseIsOutofList())
        {
            m_pStyleOfAskCombobox->closeListWidget();
            m_pStyleOfAskCombobox->setFocus(Qt::ActiveWindowFocusReason);
        }
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        m_pStyleOfAskCombobox->closeListWidget();
        m_pStyleOfAskCombobox->setFocus(Qt::ActiveWindowFocusReason);
    }

    return QWidget::event(event);
}
/************************************************
* 函数名称：eventFilter
* 功能描述：事件过滤，下拉框自动收回
* 输入参数：QEvent *event
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
bool MessagePage::eventFilter(QObject *obj, QEvent *ev)
{
    if(m_pStyleOfAskCombobox == nullptr)
    {
        return QWidget::eventFilter(obj,ev);
    }
    if(m_pStyleOfAskCombobox->listWidget == nullptr)
    {
        return QWidget::eventFilter(obj,ev);
    }

    if(ev->type() == QEvent::Leave)
    {
        if(obj == m_pStyleOfAskCombobox->listWidget)
        {
            m_pStyleOfAskCombobox->closeListWidget();
            m_pStyleOfAskCombobox->setFocus(Qt::ActiveWindowFocusReason);
        }
    }
    else if (ev->type() == QEvent::KeyPress)
    {
            m_pStyleOfAskCombobox->closeListWidget();
            m_pStyleOfAskCombobox->setFocus(Qt::ActiveWindowFocusReason);
    }

    if(obj != m_pStyleOfAskCombobox->listWidget)
    {
        m_pStyleOfAskCombobox->closeListWidget();
        m_pStyleOfAskCombobox->setFocus(Qt::ActiveWindowFocusReason);
    }

    //其余的事件按照默认(未覆写)的处理方式处理
    return QWidget::eventFilter(obj,ev);
}
/************************************************
* 函数名称：mouseIsOutofList
* 功能描述：鼠标离开下拉框判断
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.08
* 修改内容：
*   创建  HZH
*
*************************************************/
bool MessagePage::mouseIsOutofList()
{
    QPoint mouse=QCursor::pos();
    QPoint thisWidget=this->mapToGlobal(this->pos());
    QSize thisWidgetSize=this->size();
    if(mouse.rx()<=thisWidget.rx() || mouse.rx()>=thisWidget.rx()+thisWidgetSize.width() || mouse.ry()<=thisWidget.ry() || mouse.ry()>=thisWidget.ry()+thisWidgetSize.height())
        return true;
    else
        return false;
}

/************************************************
* 函数名称：mailTextEditFoucusIn
* 功能描述：mailText被选中判断
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.19
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::mailTextEditFoucusIn()
{
    qDebug() << "mailTextEditFoucusIn";
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;border-width:1px;border-color:rgba(112, 149, 255, 1);border-style: solid;border-radius:4px;");
    }
    else
    {
        m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;border-width:1px;border-color:rgba(112, 149, 255, 1);border-style: solid;border-radius:4px;");
    }
}
/************************************************
* 函数名称：mailTextEditFoucusIn
* 功能描述：mailText被选中判断
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.19
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::mailTextEditFoucusOut()
{
    if("" == m_pMailTextEdit->toPlainText())
    {
        qDebug() << "mailText为空！";
        m_pMailFormatErr->hide();
        mailFormatFlag = false;
        if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
        {
            m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;");
        }
        else
        {
            m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;");
        }
    }
    else
    {
        mailText = m_pMailTextEdit->toPlainText();
        qDebug() << mailText;

        QRegExp rx("^[\\w-]+(\\.[\\w-]+)*@[\\w-]+(\\.[\\w-]+)+");
        int pos=0;
        QRegExpValidator v(rx, 0);
        if (2==v.validate(mailText,pos))
        {

            if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
            {
                m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;");
            }
            else
            {
                m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;");
            }
            m_pMailFormatErr->hide();
            mailFormatFlag = true;

        }
        else
        {
            if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
            {
                m_pMailTextEdit->setStyleSheet("background-color:rgba(49, 50, 52, 1);color:rgba(96, 98, 101, 1);font-size:14px;border-radius:4px;border-width:1px;border-color:rgba(237, 100, 100, 1);border-style: solid;border-radius:4px;");
            }
            else
            {
                m_pMailTextEdit->setStyleSheet("background-color:rgba(143, 147, 153, 0.08);color:rgba(143, 147, 153, 1);font-size:14px;border-radius:4px;border-width:1px;border-color:rgba(237, 100, 100, 1);border-style: solid;border-radius:4px;");
            }
            mailFormatFlag = false;
            m_pMailFormatErr->show();

        }
    }
    if((false == allFileSizeLargerThan10M()) && detailTextFlag && mailFormatFlag )
    {
        commitButtonClickable = true;
    }
    else
    {
        commitButtonClickable = false;
    }
    commitButtonStyleSet();
}
/************************************************
* 函数名称：commitButtonStyleSet
* 功能描述：commitButton样式修改函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.12.19
* 修改内容：
*   创建  HZH
*
*************************************************/
void MessagePage::commitButtonStyleSet()
{
    if(false == commitButtonClickable)
    {
        qDebug() << "当前提交按钮不可点击";
    }
    if("ukui-dark" == currentTheme || "ukui-black" == currentTheme)
    {
        qDebug() << "当前为深色主题";
        if(false == commitButtonClickable)
        {
            commitButton->setStyleSheet("QPushButton#commitButton{background:#48484C;font-size:14px;color:rgba(143, 147, 153, 1);}");
            commitButton->setEnabled(false);
        }
        else
        {
            commitButton->setEnabled(true);
            commitButton->setStyleSheet("QPushButton#commitButton{background:rgba(112, 149, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                        "QPushButton#commitButton:hover{background:rgba(149, 176, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                        "QPushButton#commitButton:pressed{background:rgba(73, 112, 222, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
        }
    }
    else
    {
        if(false == commitButtonClickable)
        {
            commitButton->setStyleSheet("QPushButton#commitButton{background:rgba(192, 196, 204, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
            commitButton->setEnabled(false);
        }
        else
        {
            commitButton->setEnabled(true);
            commitButton->setStyleSheet("QPushButton#commitButton{background:rgba(112, 149, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                        "QPushButton#commitButton:hover{background:rgba(149, 176, 255, 1);font-size:14px;color:rgba(255, 255, 255, 1);}"
                                        "QPushButton#commitButton:pressed{background:rgba(73, 112, 222, 1);font-size:14px;color:rgba(255, 255, 255, 1);}");
        }
    }
}
