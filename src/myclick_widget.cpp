/************************************************
* 文件描述: MyClickWidget
* 待完善:  可点击widget
* 待优化:
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*************************************************/
#include "myclick_widget.h"
/************************************************
* 函数名称：MyClickWidget
* 功能描述：构造函数
* 输入参数：界面参数类
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
MyClickWidget::MyClickWidget(QWidget *parent) : QWidget(parent)
{

}
/************************************************
* 函数名称：paintEvent(QPaintEvent *)
* 功能描述：重绘，hover，pressed等无效
* 输入参数：绘制事件
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MyClickWidget::paintEvent(QPaintEvent *)
{
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
/************************************************
* 函数名称：mouseReleaseEvent
* 功能描述：重写鼠标释放事件
* 输入参数：绘制事件
* 输出参数：无
* 修改日期：2020.11.04
* 修改内容：
*   创建  HZH
*
*************************************************/
void MyClickWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    if(ev->button() == Qt::LeftButton)
    {
        emit clicked();	// 发射信号
    }
}
