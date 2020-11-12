/************************************************
* 文件描述: 联系我们页的类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef CONTACTPAGE_H
#define CONTACTPAGE_H

#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
#include <QFileInfo>
#include <QListWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTimer>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "file_item_init.h"
#include "widget_parameter_class.h"

class ContactPage : public QWidget
{
    Q_OBJECT
public:
    explicit ContactPage(WidgetParameterClass basicParam);
    void pageChangeForTheme(QString str);
signals:

private:
    void contactPageUIInit();

    WidgetParameterClass contactPageBasicParameter;

    QLabel *m_pContactUs = nullptr;

    QLabel *m_pKylinTeam_1;
    QLabel *m_pKylinTeam_2;
    QLabel *m_pKylinTeam_3;

    QLabel *m_pTel_1;
    QLabel *m_pTel_2;
    QLabel *m_pTel_3;

    QLabel *m_pMail_1;
    QLabel *m_pMail_2;
    QLabel *m_pMail_3;

    QLabel *m_pQRCode_1;
    QLabel *m_pQRCode_2;

    QWidget *body      = nullptr;

};

#endif // CONTACTPAGE_H
