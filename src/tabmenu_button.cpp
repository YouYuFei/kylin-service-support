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
