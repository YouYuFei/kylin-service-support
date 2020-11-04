#ifndef WIDGETPARAMETERSTRUCT_H
#define WIDGETPARAMETERSTRUCT_H

typedef struct widgetParameterStruct
{
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
}widgetParameterStruct;

#endif // WIDGETPARAMETERSTRUCT_H
