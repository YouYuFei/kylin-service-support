/************************************************
* 文件描述: 主界面参数类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "widget_parameter_class.h"

WidgetParameterClass::WidgetParameterClass()
{

}

WidgetParameterClass::WidgetParameterClass(int pWinWidth, int pWinHeight,
                     bool pHasRadius, int pWinRadius,
                     int pWinShadow ,double pWinShadowAlpha,
                     int pTitleHeight,
                     int pLeftMenuBoxHeight , int pLeftMenuBoxWidth ,
                     int pRightBoxHeight ,int pRightBoxWidth )
{
    winWidth = pWinWidth + 2 * pWinShadow;
    winHeight = pWinHeight + 2 * pWinShadow;

    if(pHasRadius)
        winRadius = pWinRadius;
    else
        winRadius = 0;

    winShadowAlpha = pWinShadowAlpha;

    titleHeight = pTitleHeight;

    leftMenuBoxHeight = pLeftMenuBoxHeight;
    leftMenuBoxWidth  = pLeftMenuBoxWidth;

    rightBoxHeight    = pRightBoxHeight;
    rightBoxWidth     = pRightBoxWidth;

}

