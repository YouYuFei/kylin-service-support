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

