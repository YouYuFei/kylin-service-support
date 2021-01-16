/************************************************
* 文件描述: 留言页面类
* 待完善:   界面未完成
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef MESSAGEPAGE_H
#define MESSAGEPAGE_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QDialog>
#include <QDebug>
#include <QFile>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <QProcess>
#include <fstream>
#include <iostream>
#include <cstring>
#include <QFileInfo>
#include <QListWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QGraphicsDropShadowEffect>
#include <QStandardPaths>
#include <QEventLoop>
#include <QStyledItemDelegate>
#include <QEvent>

#include "file_item_init.h"
#include "widget_parameter_class.h"
#include "systeminfo_button.h"
#include "submitFail.h"
#include "submitSuccess.h"
#include "my_combobox.h"
#include "my_qlineedit.h"

using namespace std;

class MessagePage : public QWidget
{
    Q_OBJECT
public:
    explicit MessagePage(const WidgetParameterClass& basicParam);
    //~MessagePage();
    void systeminfo_show(QPointF pt);
    void systeminfo_hide();
    void set_request_header();
    void pageChangeForTheme(const QString& str);
    QWidget *verticalWidget;
    QFrame *frameSysInfo;
    systemInfoButton *showInfoButton;
    QGraphicsDropShadowEffect *effect;
    QLabel *labelSystemVersion_1;
    QLabel *labelDesktopVersion_1;
    QLabel *labelLanguage_1;
    QLabel *labelSystemVersion_2;
    QLabel *labelDesktopVersion_2;
    QLabel *labelLanguage_2;
    QString currentTheme;
signals:

public slots:
    void styleOfAskCombobox_currentIndexChanged();

    void detailTextEdit_textChanged();
    void mailTextEdit_textChanged();

    void trueSyslogCheckBox_stateChanged();
    void falseSyslogCheckBox_stateChanged();
    void userPermission_stateChanged(int);

    void userDataPushButton_clicked();

    void del_file_button_clicked();

    void update_linedit_add_or_del_file();

    void on_commitButton_clicked();

    void on_resetButton_clicked();

    void finishedSlot(QNetworkReply *reply);

    void resend_info_when_sendfail();

    void send_file_httpserver(QString uid);

    void add_file_to_Part(QString filepath,QString file_type,QString file_name);

    QByteArray get_today_syslog();

    void mailTextEditFoucusOut();

    void mailTextEditFoucusIn();

private:

    WidgetParameterClass mainPageBasicParameter;

    void messagePageUIInit();

    void httpclientInit();

    void pageStyleOfAskRowLocationInit();
    void pageContentOfAskRowLocationInit();
    void pageMailRowLocationInit();
    void pageSysLogRowLocationInit();
    void pageUploadFilesRowLocationInit();
    void pageUserDataRowLocationInit();

    void pageAllRowLocationInit();

    bool allFileSizeLargerThan10M();

    void addFileInfoModel();

    void update_add_file_window();

    void getSysteminfo();

    void set_all_disable_in_submit();
    void set_all_enable_after_submit();

    void sendfile_finished(QNetworkReply* );

    void checkBox_stateCheck();

    void uploadFile_afterButtonClicked();

    void removeUploadFileNameListFile(QPushButton* btn);

    void getCodingFormat();
    void getSysVersion();
    void getDesktopInfo();

    bool event(QEvent *event);
    bool eventFilter(QObject *obj, QEvent *ev);
    bool mouseIsOutofList();

    QWidget *m_pWidgetStyleOfAsk;
    QWidget *m_pWidgetTitleOfAsk;
    QWidget *m_pWidgetDetailOfAsk;
    QWidget *m_pWidgetMail;
    QWidget *m_pWidgetLog;
    QWidget *m_pWidgetUserData;
    QWidget *m_pWidgetUserDataWidget;

    QTimer *submitting_timer=nullptr;

    QLabel *m_pStyleOfAsk;
    QLabel *m_pTitleOfAsk;
    QLabel *m_pContent;
    QLabel *m_pMail;
    QLabel *m_pLog;
    QLabel *m_pUserData;
    QLabel *m_pHelp;

    QLabel *m_pMailFormatErr;

    QLabel *m_pDetailTextLetterLimit;

    QPushButton *m_pUserDataPushButton;
    QPushButton *resetButton;
    QPushButton *commitButton;

    bool timeout_http_flag = false;

    MyComboBox *m_pStyleOfAskCombobox = nullptr;
    //QComboBox *m_pStyleOfAskCombobox;
    QString textStyleOfAsk = "系统问题";

    QTextEdit *m_pTitleTextEdit;
    QString titleText = "";

    QTextEdit *m_pContentTextEdit;
    QString contentText = "";

    QTextEdit *m_pDetailTextEdit;
    QString detailText = "";

    //QTextEdit *m_pMailTextEdit;
    MyQTextEdit *m_pMailTextEdit;
    QString mailText = "";

    QTextEdit *m_pLogTextEdit;
    QCheckBox *m_pTrueSyslogCheckBox;
    QCheckBox *m_pFalseSyslogCheckBox;
    QCheckBox *m_pUserPermission;
    QString logText = "";

    QLabel *m_pUserDataLimit;
    QString userDataText = "";

    QString userUploadFileName;
    QList<QString> uploadFileNameList;
    QList<QString> uploadFileSizeList;
    QList<QString> uploadFilePathList;

    QListWidget * FileListWidget;
    QListWidgetItem * file_listwidget_item[5];
    FileItemInit* file_widget[5];

    bool detailTextFlag = false;
    bool titleTextFlag = false;
    bool mailFormatFlag = false;

    bool textStyleOfSystemFlag = false;
    bool textStyleOfDeviceFlag = false;
    bool syslogFlag = true;
    bool apportLogFlag = false;
    bool dpkgLogFlag = false;
    bool get_systeminfoflag = false;

    //httpclient
    QNetworkAccessManager *accessManager=nullptr;
    QNetworkAccessManager *accessManager_file=nullptr;
    QNetworkRequest request;
    QNetworkRequest request_file;
    QString urlstring;//服务器地址
    QVariant statusCode_file;
    QVariant reason_file ;
    QVariant statusCode_info;
    QVariant reason_info ;
    QByteArray bytes_info;
    QByteArray bytes_file;
    QJsonObject feedback_info_json;
    QJsonDocument json_doc;
    QByteArray post_feedback_info_array;
    QString uid_value;
    QJsonParseError jsonerror;
    QJsonDocument document;
    QJsonObject object;
    QHttpMultiPart *multiPart=nullptr;

    //传递系统信息给小弹窗中的字符串
    QString send_os_info;
    QString send_encoding_info;
    QString send_dekstop_info;
    QString system_info_str; //系统版本信息
    QString encoding_info_str; //系统编码格式
    QString desktop_info_str;  //系统桌面环境

    bool window_is_close_flag  = false;
    bool file_send_failed_flag = true;

    submit_fail *fail_dialog=nullptr;
    submit_success * success_dialog=nullptr;

    bool commitButtonClickable = false;
    void commitButtonStyleSet();

};

#endif // MESSAGEPAGE_H
