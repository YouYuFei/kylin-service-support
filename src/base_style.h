/************************************************
* 文件描述: 基础窗口框架
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef BASESTYLE_H
#define BASESTYLE_H

#include <QWidget>
#include <QStackedWidget>
#include <QGraphicsDropShadowEffect>
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
#include "widget_parameter_class.h"
#include "main_page.h"
#include "message_page.h"
#include "tabmenu_button.h"
#include "contact_page.h"
#include "diysupport_page.h"
#include "stylewidgetattribute.h"
#include "stylewidgetshadow.h"
#include "menumodule.h"
//窗体长宽
#define SHAWINDOW_WIDTH (958)
#define SHAWINDOW_HEIGHT (640)
//窗体圆角
#define SHAHASRADIUS (1)                //是否有圆角
#define SHAWINRADIUS (5)                //圆角半径
//窗体阴影
#define SHAWINSHADOW (10)                //窗体阴影宽度
#define SHAWINSHADOWALPHA (0.08)        //阴影透明度
//标题高度
#define SHATITLE_HEIGHT (60)
//左侧菜单栏长宽
#define SHALEFTBOX_WIDTH (640)
#define SHALEFTBOX_HEIGHT (640)
//右侧交互页面长宽
#define SHARIGHTBOXHEIGHT (640)
#define SHARIGHTBOXWIDTH  (640)

class BaseStyle : public QWidget
{
    Q_OBJECT
public:

    BaseStyle(const WidgetParameterClass& basicParameter, const QString& dialogTitleText);

    void WidgetStyleClose();//点击关闭事件

    QWidget *title     = nullptr;//标题栏
    QWidget *body      = nullptr;//窗体
    QWidget *menuBox   = nullptr;//窗体
    QWidget *showBox   = nullptr;//窗体

    void pageChangeForTheme(const QString& str);
protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;
private slots:

    void m_MainPageButtonSlots();           //点击“软件介绍”对应槽函数
    void m_MessagePageButtonSlots();        //点击“留言咨询”对应槽函数
    void m_OnlinePageButtonSlots();         //点击“在线咨询”对应槽函数
    void m_ContactPageButtonSlots();        //点击“联系我们”对应槽函数
    void m_DIYPageButtonSlots();            //点击“自助支持”对应槽函数

private:
    //virtual void paintEvent(QPaintEvent *ev);//重绘窗口
    QStackedWidget  *m_pstackWidget;

    QString currentTheme;

    void myWidgetStyle(const WidgetParameterClass& basicParameter);
    void myWidgetSizeDesign(int width,int height);
    void myWidgetBasicInit(const WidgetParameterClass& parameter);
    void myWidgetTabInit();

    void setMainPageButtonBackgroundBlue();
    void setMessagePageButtonBackgroudIsBlue();
    void setOnlinePageButtonBackgroudIsBlue();
    void setContactPageButtonBackgroudIsBlue();
    void setDIYPageButtonBackgroudIsBlue();

    bool mainPageButtonQss(QEvent *ev);
    bool messagePageButtonQss(QEvent *ev);
    bool contactPageButtonQss(QEvent *ev);
    bool diyPageButtonQss(QEvent *ev);
    bool onlinePageButtonQss(QEvent *ev);

    void mainPageButtonDefault();
    void mainPageButtonHover();
    void mainPageButtonClick();
    void mainPageButtonRelease();

    void messagePageButtonDefault();
    void messagePageButtonHover();
    void messagePageButtonClick();
    void messagePageButtonRelease();

    void contactPageButtonDefault();
    void contactPageButtonHover();
    void contactPageButtonClick();
    void contactPageButtonRelease();

    void diyPageButtonDefault();
    void diyPageButtonHover();
    void diyPageButtonClick();
    void diyPageButtonRelease();

    void onlinePageButtonDefault();
    void onlinePageButtonHover();
    void onlinePageButtonClick();
    void onlinePageButtonRelease();

    QPoint dragPosition;                                    //拖动坐标

    WidgetParameterClass local_basicParameter;

    DaemonIpcDbus *m_pDaemonIpcDbus;
    void keyPressEvent(QKeyEvent *event);

    QLabel *text = nullptr;//标题

    QLabel *titleIcon = nullptr;
    QLabel *introIcon = nullptr;
    QLabel *messageIcon = nullptr;
    QLabel *contactIcon = nullptr;
    QLabel *supportIcon = nullptr;
    QLabel *customerIcon = nullptr;

    QPushButton *widgetClose = nullptr;                     //关闭窗口
    QPushButton *widgetMin   = nullptr;                     //最小化窗口
    menuModule *menu = nullptr;                             //三联按钮菜单按钮

    TabMenuButton *m_pMainPageButton;                       //主页界面显示按钮
    TabMenuButton *m_pMessagePageButton;                    //留言咨询界面显示按钮
    TabMenuButton *m_pOnlineButton;                         //在线客服界面显示按钮
    TabMenuButton *m_pContactButton;                        //在线客服界面显示按钮
    TabMenuButton *m_pDIYButton;                            //在线客服界面显示按钮


    int currentPageIndex = 0;

    bool paintOnce=false;//只绘制一次

    MainPage *mainPage = nullptr;
    MessagePage *messagePage = nullptr;
    ContactPage *contactPage = nullptr;
    DIYSupportPage *diySupportPage = nullptr;

    QString qssDefaultMenuBar = tr("QPushButton{background:transparent;color:rgba(48, 49, 51, 1);font-size:14px;}"
                              "QPushButton:hover{background:rgba(149, 176, 255, 1);color:rgba(249, 249, 249, 1);font-size:14px;}"
                              "QPushButton:pressed{background:rgba(73, 112, 222, 1);color:rgba(249, 249, 249, 1);font-size:14px;}");
    QString qssChooseMenuBar = tr("QPushButton{background:rgba(112, 149, 255, 1);color:rgba(249, 249, 249, 1);font-size:14px;}");
    QString qssPressedMenuBar = tr("QPushButton{background:rgba(73, 112, 222, 1);color:rgba(249, 249, 249, 1);font-size:14px;}");

    QString qssDefaultMenuBar_d = tr("QPushButton{background:transparent;color:rgba(192, 196, 204, 1);font-size:14px;}"
                              "QPushButton:hover{background:rgba(149, 176, 255, 1);color:rgba(249, 249, 249, 1);font-size:14px;}"
                              "QPushButton:pressed{background:rgba(73, 112, 222, 1);color:rgba(249, 249, 249, 1);font-size:14px;}");
    QString qssChooseMenuBar_d = tr("QPushButton{background:rgba(112, 149, 255, 1);color:rgba(249, 249, 249, 1);font-size:14px;}");
    QString qssPressedMenuBar_d = tr("QPushButton{background:rgba(73, 112, 222, 1);color:rgba(249, 249, 249, 1);font-size:14px;}");
};
#endif // BASESTYLE_H
