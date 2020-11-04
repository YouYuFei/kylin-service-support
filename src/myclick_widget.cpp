#include "myclick_widget.h"

MyClickWidget::MyClickWidget(QWidget *parent) : QWidget(parent)
{

}

void MyClickWidget::paintEvent(QPaintEvent *) {
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
// 重写鼠标释放时间 mouseReleaseEvent()
void MyClickWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    if(ev->button() == Qt::LeftButton)
    {
        emit clicked();	// 发射信号
    }
}
