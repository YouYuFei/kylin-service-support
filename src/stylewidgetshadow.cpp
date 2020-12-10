/************************************************
* 文件描述: In User Settings Edit
* 待完善:
* 待优化:
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*************************************************/
#include "stylewidgetshadow.h"

/************************************************
* 函数名称：
* 功能描述：
* 输出参数：
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
StyleWidgetShadow::StyleWidgetShadow(const WidgetParameterClass& s)
    :swa(s)
{
    //窗口设置
    this->setWindowFlags(Qt::FramelessWindowHint);//无边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);//窗体透明
    this->setWindowTitle(tr("kylin-service-support"));
    this->setFixedSize(swa.winWidth,swa.winHeight);
    this->setWindowIcon(QIcon(":/data/kylin-service-support.png"));
    //this->setWindowTitle(tr("麒麟服务与支持"));
    handleIconClickedSub();//在屏幕中央显示
}

/************************************************
* 函数名称：
* 功能描述：
* 输出参数：
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
void StyleWidgetShadow::handleIconClickedSub()//在屏幕中央显示
{
    QRect availableGeometry = qApp->primaryScreen()->availableGeometry();
    this->move((availableGeometry.width() - this->width())/2, (availableGeometry.height() - this->height())/2);
}

/************************************************
* 函数名称：
* 功能描述：
* 输出参数：
* 修改日期：2020.10.12
* 修改内容：
*   创建  HZH
*
*************************************************/
void StyleWidgetShadow::paintEvent(QPaintEvent *event)//重绘窗口
{
    //if(paintOnce>swa.winRadius*2)return;//注释掉，否则多次切换页面会有一个角变成方形，然后阴影失效。
    //阴影
    QPainterPath painterPath;
    painterPath.setFillRule(Qt::WindingFill);//设置填充方式
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(painterPath, QBrush(Qt::white));

    QColor color(0, 0, 0);
    for(int i=0; i<swa.winShadow; i++)
    {
        int alpha=swa.winShadowAlpha*255/4;
        color.setAlpha(alpha - (alpha/swa.winShadow)*(i+1));
        painter.setPen(color);

        QRect rec(swa.winShadow-i,swa.winShadow-i,swa.winWidth-(swa.winShadow-i)*2,swa.winHeight-(swa.winShadow-i)*2);
        painterPath.addRoundedRect(rec,swa.winRadius,swa.winRadius);
        painter.setClipRegion(QRegion(0,0,swa.winWidth,swa.winHeight));
        painter.drawPath(painterPath);
    }
    //paintOnce++;
}
