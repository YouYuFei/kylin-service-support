#ifndef BASESTYLE_H
#define BASESTYLE_H

#include "widget_parameter_class.h"
#include "my_tab_widget.h"
#include "main_page.h"
#include "message_page.h"
#include "tabmenu_button.h"
#include "contact_page.h"
#include "diysupport_page.h"
#include <QWidget>
#include <QStackedWidget>
#include <QPalette>
#include <QApplication>
#include <QScreen>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QPushButton>
//读取本地字体
#include <QFontDatabase>
//鼠标拖动事件
#include <QMouseEvent>
#include <QPoint>

#include <QPainter>
#include <QProxyStyle>

#include <QColor>

class BaseStyle : public QWidget
{
    Q_OBJECT
public:

    BaseStyle(WidgetParameterClass basicParameter, QString dialogTitleText);

    void WidgetStyleClose();//点击关闭事件

    QWidget *title     = nullptr;//标题栏
    QWidget *body      = nullptr;//窗体
    QWidget *menuBox   = nullptr;//窗体
    QWidget *showBox   = nullptr;//窗体

    //void window_close();

private slots:

    void m_MainPageButtonSlots();
    void m_MessagePageButtonSlots();
    void m_OnlinePageButtonSlots();
    void m_ContactPageButtonSlots();
    void m_DIYPageButtonSlots();

private:
    //virtual void paintEvent(QPaintEvent *ev);//重绘窗口
    QStackedWidget  *m_pstackWidget;

    void myWidgetStyle(WidgetParameterClass basicParameter);
    void myWidgetSizeDesign(int windowWidth, int windowHeight);
    void myWidgetBasicInit(int titleHeight);
    void myWidgetTabInit();
    void setMainPageButtonBackgroundBlue();
    void setMessagePageButtonBackgroudIsBlue();
    void setOnlinePageButtonBackgroudIsBlue();
    void setContactPageButtonBackgroudIsBlue();
    void setDIYPageButtonBackgroudIsBlue();

    //窗口拖拽函数
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QPoint dragPosition;                                    //拖动坐标
    bool   mousePressed;                                    //鼠标是否按下

    WidgetParameterClass local_basicParameter;


    QLabel *text = nullptr;//标题

    QLabel *titleIcon = nullptr;
    QLabel *introIcon = nullptr;
    QLabel *messageIcon = nullptr;
    QLabel *contactIcon = nullptr;
    QLabel *supportIcon = nullptr;

    QPushButton *widgetClose = nullptr;                     //关闭窗口
    QPushButton *widgetMin   = nullptr;                     //最小化窗口

    TabMenuButton *m_pMainPageButton;                       //主页界面显示按钮
    TabMenuButton *m_pMessagePageButton;                    //留言咨询界面显示按钮
    TabMenuButton *m_pOnlineButton;                         //在线客服界面显示按钮
    TabMenuButton *m_pContactButton;                        //在线客服界面显示按钮
    TabMenuButton *m_pDIYButton;                            //在线客服界面显示按钮

    bool paintOnce=false;//只绘制一次

    MyTabWidget *tabWidget;

    MainPage *mainPage = nullptr;
    MessagePage *messagePage = nullptr;
    ContactPage *contactPage = nullptr;
    DIYSupportPage *diySupportPage = nullptr;

    QString qssDefaultMenuBar = tr("QPushButton{background:transparent;color:rgba(48, 49, 51, 1);border-radius: 16px;}"
                              "QPushButton:hover{background:rgba(149, 176, 255, 1);color:rgba(255, 255, 255, 1);border-radius: 16px;}"
                              "QPushButton:pressed{background:rgba(73, 112, 222, 1);color:rgba(255, 255, 255, 1);border-radius: 16px;}");
    QString qssChooseMenuBar = tr("QPushButton{background:rgba(112, 149, 255, 1);color:rgba(255, 255, 255, 1);border-radius: 16px;}");
};

#endif // BASESTYLE_H
