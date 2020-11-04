/************************************************
* 文件描述: 主界面参数类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#ifndef WIDGETPARAMETERCLASS_H
#define WIDGETPARAMETERCLASS_H


class WidgetParameterClass
{
public:
    WidgetParameterClass();
    WidgetParameterClass(int winWidth, int winHeight,
                         bool hasRadius=1, int winRadius=0,
                         int winShadow =0,double winShadowAlpha=0.00,
                         int titleHeight=0,
                         int leftMenuBoxHeight = 0, int leftMenuBoxWidth  = 0,
                         int rightBoxHeight = 0,int rightBoxWidth  = 0);

    //窗体长宽
    int winWidth;
    int winHeight;

    //窗体圆角
    bool hasRadius = 1;               //是否有圆角
    int  winRadius = 0;               //圆角半径

    //窗体阴影
    int winShadow = 0;                //窗体阴影宽度
    double winShadowAlpha = 0.00;     //阴影透明度

    //标题高度
    int titleHeight = 0;

    //左侧菜单栏长宽
    int leftMenuBoxHeight = 0;
    int leftMenuBoxWidth  = 0;

    //右侧交互页面长宽
    int rightBoxHeight = 0;
    int rightBoxWidth  = 0;
};

#endif // WIDGETPARAMETERCLASS_H
