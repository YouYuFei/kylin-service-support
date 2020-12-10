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
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include "widget_parameter_class.h"
#include "myclick_widget.h"


class MainPage : public QWidget
{
    Q_OBJECT
public:
    explicit MainPage(const WidgetParameterClass& basicParam);
    void pageChangeForTheme(const QString& str);
protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;
signals:
private:

    WidgetParameterClass mainPageBasicParameter;
    QString currentTheme;
    void pageLocationInit();

    QLabel *m_pKylinPic;
    QLabel *m_pMoreInfoLink_1;
    QLabel *m_pMoreInfoLink_2;
    QLabel *m_pMoreInfoLink_3;
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
