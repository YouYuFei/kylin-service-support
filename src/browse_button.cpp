/************************************************
* 文件描述: 自建浏览按钮类
* 待完善:
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "browse_button.h"
/************************************************
* 函数名称：BrowseButton
* 功能描述：构造函数
* 输入参数：父类指针
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
BrowseButton::BrowseButton(QWidget* parent) :QPushButton(parent)
{

}

BrowseButton::~BrowseButton()
{

}
/************************************************
* 函数名称：enterEvent
* 功能描述：鼠标进入后动画效果
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BrowseButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e);

    QFont font;
    font.setUnderline(true);
    setFont(font);

}
/************************************************
* 函数名称：leaveEvent
* 功能描述：鼠标离开后动画效果
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void BrowseButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);

    QFont font;
    font.setUnderline(false);
    setFont(font);

}
