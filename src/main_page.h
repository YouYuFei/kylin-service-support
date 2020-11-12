/************************************************
* 文件描述: 程序首页内容类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include "widget_parameter_class.h"

class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(WidgetParameterClass basicParam);
    void pageChangeForTheme(QString str);

signals:
private:

    WidgetParameterClass mainPageBasicParameter;
    QString currentTheme;
    void pageLocationInit();

    QLabel *m_pKylinPic;
    QLabel *m_pMoreInfoLink;
    QLabel *m_pPageTitle;

    QWidget *m_pOnline;
    QLabel *m_pOnline_1;
    QLabel *m_pOnline_2;
    QLabel *m_pOnline_3;

    QWidget *m_pTelphone;
    QLabel *m_pTelphone_1;
    QLabel *m_pTelphone_2;
    QLabel *m_pTelphone_3;

    QWidget *m_pMail;
    QLabel *m_pMail_1;
    QLabel *m_pMail_2;
    QLabel *m_pMail_3;

    QWidget *m_pWeChat;
    QLabel *m_pWeChat_1;
    QLabel *m_pWeChat_2;
    QLabel *m_pWeChat_3;

    QWidget *m_pDIY;
    QLabel *m_pDIY_1;
    QLabel *m_pDIY_2;
    QLabel *m_pDIY_3;

};

#endif // MAINPAGE_H
