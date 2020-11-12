/************************************************
* 文件描述: 程序主进程
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QStandardPaths>
#include <QGSettings>
#include <QTranslator>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <xcb/xcb.h>

#include "widget_parameter_class.h"
#include "base_style.h"

//gsetting获取主题样式关键字
#define FITTHEMEWINDOW "org.ukui.style"
//窗体长宽
#define WINDOW_WIDTH 958
#define WINDOW_HEIGHT 640
//窗体圆角
#define HASRADIUS 1                //是否有圆角
#define WINRADIUS 5                //圆角半径
//窗体阴影
#define WINSHADOW 0                //窗体阴影宽度
#define WINSHADOWALPHA 0.00        //阴影透明度
//标题高度
#define TITLE_HEIGHT 60
//左侧菜单栏长宽
#define LEFTBOX_WIDTH 640
#define LEFTBOX_HEIGHT 640
//右侧交互页面长宽
#define RIGHTBOXHEIGHT 640
#define RIGHTBOXWIDTH  640

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    void checkSingle();

private:
    //WidgetParameterClass basicParameter;
    BaseStyle      *basicWindow   = nullptr;

    QStackedWidget *stackedWidget = nullptr;
    // getstting初始化、值获取、 设置getsetting值
    void initGsetting();
    void setThemeStyle();

    QGSettings  *m_pThemeStyle= nullptr;
};
#endif // MAINWINDOW_H
