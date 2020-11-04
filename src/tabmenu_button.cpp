/************************************************
* 文件描述: 主界面按钮特殊类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "tabmenu_button.h"

TabMenuButton::TabMenuButton(QWidget *parent):QPushButton(parent)
{
    connect(this, &TabMenuButton::clicked, this, &TabMenuButton::enterButtonSignal);
}

TabMenuButton::~TabMenuButton()
{

}

void TabMenuButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e);
//    emit enterButtonSignal();
}

void TabMenuButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);
}

void TabMenuButton::SendSingal()
{
    emit enterButtonSignal();
}
