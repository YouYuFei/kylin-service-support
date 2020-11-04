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
#include "widget_parameter_class.h"

class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(WidgetParameterClass basicParam);

signals:
private:

    WidgetParameterClass mainPageBasicParameter;

    void pageLocationInit();

    QLabel *m_pKylinPic;
    QLabel *m_pMoreInfoLink;
    QLabel *m_pPageTitle;
    QLabel *m_pOnline;
    QLabel *m_pTelphone;
    QLabel *m_pMail;
    QLabel *m_pWeChat;
    QLabel *m_pDIY;

};

#endif // MAINPAGE_H
