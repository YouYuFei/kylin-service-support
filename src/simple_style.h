#ifndef SIMPLESTYLE_H
#define SIMPLESTYLE_H

/************************************************
* 文件描述: 基础窗口框架
* 待完善:
* 待优化:
* 修改日期：2021.01.24
* 修改内容：
*   创建  HZH
*************************************************/
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
#include "menumodule.h"

class SimpleStyle : public QWidget
{
    Q_OBJECT
public:

    SimpleStyle(const WidgetParameterClass& basicParameter, const QString& dialogTitleText);

    void WidgetStyleClose();//点击关闭事件

    QWidget *title     = nullptr;//标题栏
    QWidget *body      = nullptr;//窗体
    QWidget *menuBox   = nullptr;//窗体
    QWidget *showBox   = nullptr;//窗体

    void pageChangeForTheme(const QString& str);
protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;
private slots:


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

    void allButtonNoChecked();

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

    QPushButton *m_pMainPageButton;                       //主页界面显示按钮
    QPushButton *m_pMessagePageButton;                    //留言咨询界面显示按钮
    QPushButton *m_pOnlineButton;                         //在线客服界面显示按钮
    QPushButton *m_pContactButton;                        //在线客服界面显示按钮
    QPushButton *m_pDIYButton;                            //在线客服界面显示按钮


    int currentPageIndex = 0;

    bool paintOnce=false;//只绘制一次

    MainPage *mainPage = nullptr;
    MessagePage *messagePage = nullptr;
    ContactPage *contactPage = nullptr;
    DIYSupportPage *diySupportPage = nullptr;

};
#endif // SIMPLESTYLE_H
