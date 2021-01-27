/************************************************
* 文件描述: 显示系统信息的定制按钮类
* 待完善:  变量未修改
* 待优化:  尚未读懂代码
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "systeminfo_button.h"

#include "message_page.h"
#include <QPointF>

/************************************************
* 函数名称：systemInfoButton
* 功能描述：构造函数
* 输入参数：父类指针
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
systemInfoButton::systemInfoButton(QWidget* parent) :QPushButton(parent)
{
    pBaseWindow = nullptr;
}
/************************************************
* 函数名称：systemInfoButton
* 功能描述：析构函数
* 输入参数：无
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
systemInfoButton::~systemInfoButton()
{

}
/************************************************
* 函数名称：enterEvent
* 功能描述：鼠标进入函数重写，显示弹出窗口
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void systemInfoButton::enterEvent(QEvent *e)
{
    Q_UNUSED(e);
    QPointF position = QCursor::pos();
    pBaseWindow->systeminfo_show(position);
}
/************************************************
* 函数名称：leaveEvent
* 功能描述：鼠标离开函数重写，关闭弹出窗口
* 输入参数：鼠标事件
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void systemInfoButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);
    pBaseWindow->systeminfo_hide();
}

/************************************************
* 函数名称：setFeedBack
* 功能描述：获取父窗口指针
* 输入参数：MessagePage *p
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void systemInfoButton::setFeedBack(MessagePage *p)
{
    pBaseWindow = p;
}
